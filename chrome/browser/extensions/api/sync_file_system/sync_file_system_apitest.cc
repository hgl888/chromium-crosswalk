// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/bind.h"
#include "base/command_line.h"
#include "base/path_service.h"
#include "base/run_loop.h"
#include "chrome/browser/extensions/extension_apitest.h"
#include "chrome/browser/sync_file_system/file_status_observer.h"
#include "chrome/browser/sync_file_system/local_change_processor.h"
#include "chrome/browser/sync_file_system/mock_remote_file_sync_service.h"
#include "chrome/browser/sync_file_system/sync_file_system_service.h"
#include "chrome/browser/sync_file_system/sync_file_system_service_factory.h"
#include "chrome/browser/sync_file_system/sync_status_code.h"
#include "chrome/browser/sync_file_system/syncable_file_system_util.h"
#include "chrome/common/chrome_version_info.h"
#include "chrome/test/base/test_switches.h"
#include "storage/browser/fileapi/file_system_url.h"
#include "storage/browser/quota/quota_manager.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

using ::testing::_;
using ::testing::Eq;
using ::testing::Ne;
using ::testing::Property;
using ::testing::Return;
using storage::FileSystemURL;
using sync_file_system::MockRemoteFileSyncService;
using sync_file_system::RemoteFileSyncService;
using sync_file_system::SyncFileSystemServiceFactory;

namespace {

class SyncFileSystemApiTest : public ExtensionApiTest {
 public:
  SyncFileSystemApiTest()
      : mock_remote_service_(NULL),
        real_minimum_preserved_space_(0),
        real_default_quota_(0) {}

  virtual void SetUpInProcessBrowserTestFixture() override {
    ExtensionApiTest::SetUpInProcessBrowserTestFixture();

    real_minimum_preserved_space_ =
        storage::QuotaManager::kMinimumPreserveForSystem;
    storage::QuotaManager::kMinimumPreserveForSystem = 0;

    // TODO(calvinlo): Update test code after default quota is made const
    // (http://crbug.com/155488).
    real_default_quota_ =
        storage::QuotaManager::kSyncableStorageDefaultHostQuota;
    storage::QuotaManager::kSyncableStorageDefaultHostQuota = 123456;
  }

  virtual void TearDownInProcessBrowserTestFixture() override {
    storage::QuotaManager::kMinimumPreserveForSystem =
        real_minimum_preserved_space_;
    storage::QuotaManager::kSyncableStorageDefaultHostQuota =
        real_default_quota_;
    ExtensionApiTest::TearDownInProcessBrowserTestFixture();
  }

  virtual void SetUpOnMainThread() override {
    // Must happen after the browser process is created because instantiating
    // the factory will instantiate ExtensionSystemFactory which depends on
    // ExtensionsBrowserClient setup in BrowserProcessImpl.
    mock_remote_service_ = new ::testing::NiceMock<MockRemoteFileSyncService>;
    SyncFileSystemServiceFactory::GetInstance()->set_mock_remote_file_service(
        scoped_ptr<RemoteFileSyncService>(mock_remote_service_));
    ExtensionApiTest::SetUpOnMainThread();
  }

  ::testing::NiceMock<MockRemoteFileSyncService>* mock_remote_service() {
    return mock_remote_service_;
  }

 private:
  ::testing::NiceMock<MockRemoteFileSyncService>* mock_remote_service_;
  int64 real_minimum_preserved_space_;
  int64 real_default_quota_;
};

ACTION_P(NotifyOkStateAndCallback, mock_remote_service) {
  mock_remote_service->NotifyRemoteServiceStateUpdated(
      sync_file_system::REMOTE_SERVICE_OK, "Test event description.");
  base::MessageLoopProxy::current()->PostTask(
      FROM_HERE, base::Bind(arg1, sync_file_system::SYNC_STATUS_OK));
}

ACTION_P2(UpdateRemoteChangeQueue, origin, mock_remote_service) {
  *origin = arg0;
  mock_remote_service->NotifyRemoteChangeQueueUpdated(1);
}

ACTION_P6(ReturnWithFakeFileAddedStatus,
          origin,
          mock_remote_service,
          file_type,
          sync_file_status,
          sync_action_taken,
          sync_direction) {
  FileSystemURL mock_url = sync_file_system::CreateSyncableFileSystemURL(
      *origin,
      base::FilePath(FILE_PATH_LITERAL("foo.txt")));
  mock_remote_service->NotifyRemoteChangeQueueUpdated(0);
  base::MessageLoopProxy::current()->PostTask(
      FROM_HERE, base::Bind(arg0,
                            sync_file_system::SYNC_STATUS_OK,
                            mock_url));
  mock_remote_service->NotifyFileStatusChanged(
      mock_url,
      file_type,
      sync_file_status,
      sync_action_taken,
      sync_direction);
}

}  // namespace

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, GetFileStatus) {
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/get_file_status"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, GetFileStatuses) {
  // Mocking to return IsConflicting() == true only for the path "Conflicting".
  base::FilePath conflicting = base::FilePath::FromUTF8Unsafe("Conflicting");
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/get_file_statuses"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, GetUsageAndQuota) {
  ASSERT_TRUE(RunExtensionTest("sync_file_system/get_usage_and_quota"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, OnFileStatusChanged) {
  // Mock a pending remote change to be synced.
  GURL origin;
  EXPECT_CALL(*mock_remote_service(), RegisterOrigin(_, _))
      .WillOnce(UpdateRemoteChangeQueue(&origin, mock_remote_service()));
  EXPECT_CALL(*mock_remote_service(), ProcessRemoteChange(_))
      .WillOnce(ReturnWithFakeFileAddedStatus(
          &origin,
          mock_remote_service(),
          sync_file_system::SYNC_FILE_TYPE_FILE,
          sync_file_system::SYNC_FILE_STATUS_SYNCED,
          sync_file_system::SYNC_ACTION_ADDED,
          sync_file_system::SYNC_DIRECTION_REMOTE_TO_LOCAL));
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/on_file_status_changed"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, OnFileStatusChangedDeleted) {
  // Mock a pending remote change to be synced.
  GURL origin;
  EXPECT_CALL(*mock_remote_service(), RegisterOrigin(_, _))
      .WillOnce(UpdateRemoteChangeQueue(&origin, mock_remote_service()));
  EXPECT_CALL(*mock_remote_service(), ProcessRemoteChange(_))
      .WillOnce(ReturnWithFakeFileAddedStatus(
          &origin,
          mock_remote_service(),
          sync_file_system::SYNC_FILE_TYPE_FILE,
          sync_file_system::SYNC_FILE_STATUS_SYNCED,
          sync_file_system::SYNC_ACTION_DELETED,
          sync_file_system::SYNC_DIRECTION_REMOTE_TO_LOCAL));
  ASSERT_TRUE(RunPlatformAppTest(
      "sync_file_system/on_file_status_changed_deleted"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, OnServiceStatusChanged) {
  EXPECT_CALL(*mock_remote_service(), RegisterOrigin(_, _))
      .WillOnce(NotifyOkStateAndCallback(mock_remote_service()));
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/on_service_status_changed"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, RequestFileSystem) {
  EXPECT_CALL(*mock_remote_service(), RegisterOrigin(_, _)).Times(1);
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/request_file_system"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, WriteFileThenGetUsage) {
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/write_file_then_get_usage"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, ConflictResolutionPolicy) {
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/conflict_resolution_policy"))
      << message_;
}

IN_PROC_BROWSER_TEST_F(SyncFileSystemApiTest, GetServiceStatus) {
  mock_remote_service()->SetServiceState(
      sync_file_system::REMOTE_SERVICE_AUTHENTICATION_REQUIRED);
  ASSERT_TRUE(RunPlatformAppTest("sync_file_system/get_service_status"))
      << message_;
}
