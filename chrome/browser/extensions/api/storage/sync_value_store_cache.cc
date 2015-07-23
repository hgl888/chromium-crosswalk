// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/extensions/api/storage/sync_value_store_cache.h"

#include "base/bind.h"
#include "base/callback.h"
#include "base/files/file_path.h"
#include "base/sequenced_task_runner.h"
#include "chrome/browser/extensions/api/storage/sync_storage_backend.h"
#include "chrome/browser/sync/glue/sync_start_util.h"
#include "content/public/browser/browser_thread.h"
#include "extensions/browser/api/storage/settings_storage_quota_enforcer.h"
#include "extensions/browser/api/storage/storage_frontend.h"
#include "extensions/common/api/storage.h"
#include "extensions/common/constants.h"
#include "extensions/common/extension.h"

using content::BrowserThread;

namespace extensions {

namespace {

// Returns the quota limit for sync storage, taken from the schema in
// extensions/common/api/storage.json.
SettingsStorageQuotaEnforcer::Limits GetSyncQuotaLimits() {
  SettingsStorageQuotaEnforcer::Limits limits = {
      static_cast<size_t>(api::storage::sync::QUOTA_BYTES),
      static_cast<size_t>(api::storage::sync::QUOTA_BYTES_PER_ITEM),
      static_cast<size_t>(api::storage::sync::MAX_ITEMS)};
  return limits;
}

}  // namespace

SyncValueStoreCache::SyncValueStoreCache(
    const scoped_refptr<SettingsStorageFactory>& factory,
    const scoped_refptr<SettingsObserverList>& observers,
    const base::FilePath& profile_path)
    : initialized_(false) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  // This post is safe since the destructor can only be invoked from the
  // same message loop, and any potential post of a deletion task must come
  // after the constructor returns.
  BrowserThread::PostTask(
      BrowserThread::FILE, FROM_HERE,
      base::Bind(&SyncValueStoreCache::InitOnFileThread,
                 base::Unretained(this),
                 factory, observers, profile_path));
}

SyncValueStoreCache::~SyncValueStoreCache() {
  DCHECK_CURRENTLY_ON(BrowserThread::FILE);
}

syncer::SyncableService* SyncValueStoreCache::GetSyncableService(
    syncer::ModelType type) const {
  DCHECK_CURRENTLY_ON(BrowserThread::FILE);
  DCHECK(initialized_);

  switch (type) {
    case syncer::APP_SETTINGS:
      return app_backend_.get();
    case syncer::EXTENSION_SETTINGS:
      return extension_backend_.get();
    default:
      NOTREACHED();
      return NULL;
  }
}

void SyncValueStoreCache::RunWithValueStoreForExtension(
    const StorageCallback& callback,
    scoped_refptr<const Extension> extension) {
  DCHECK_CURRENTLY_ON(BrowserThread::FILE);
  DCHECK(initialized_);
  SyncStorageBackend* backend =
      extension->is_app() ? app_backend_.get() : extension_backend_.get();
  callback.Run(backend->GetStorage(extension->id()));
}

void SyncValueStoreCache::DeleteStorageSoon(const std::string& extension_id) {
  DCHECK_CURRENTLY_ON(BrowserThread::FILE);
  app_backend_->DeleteStorage(extension_id);
  extension_backend_->DeleteStorage(extension_id);
}

void SyncValueStoreCache::InitOnFileThread(
    const scoped_refptr<SettingsStorageFactory>& factory,
    const scoped_refptr<SettingsObserverList>& observers,
    const base::FilePath& profile_path) {
  DCHECK_CURRENTLY_ON(BrowserThread::FILE);
  DCHECK(!initialized_);
  app_backend_.reset(new SyncStorageBackend(
      factory,
      profile_path.AppendASCII(kSyncAppSettingsDirectoryName),
      GetSyncQuotaLimits(),
      observers,
      syncer::APP_SETTINGS,
      sync_start_util::GetFlareForSyncableService(profile_path)));
  extension_backend_.reset(new SyncStorageBackend(
      factory,
      profile_path.AppendASCII(kSyncExtensionSettingsDirectoryName),
      GetSyncQuotaLimits(),
      observers,
      syncer::EXTENSION_SETTINGS,
      sync_start_util::GetFlareForSyncableService(profile_path)));
  initialized_ = true;
}

}  // namespace extensions
