// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_ANDROID_OFFLINE_PAGES_OFFLINE_PAGE_BRIDGE_H_
#define CHROME_BROWSER_ANDROID_OFFLINE_PAGES_OFFLINE_PAGE_BRIDGE_H_

#include "base/android/jni_android.h"
#include "base/android/jni_weak_ref.h"

namespace content {
class BrowserContext;
}

namespace offline_pages {

class OfflinePageModel;

namespace android {

/**
 * Bridge between C++ and Java for exposing native implementation of offline
 * pages model in managed code.
 */
class OfflinePageBridge {
 public:
  OfflinePageBridge(JNIEnv* env,
                    jobject obj,
                    content::BrowserContext* browser_context);
  void Destroy(JNIEnv*, jobject);

 private:

  JavaObjectWeakGlobalRef weak_java_ref_;
  // Not owned.
  OfflinePageModel* offline_page_model_;
  // Not owned.
  content::BrowserContext* browser_context_;
  DISALLOW_COPY_AND_ASSIGN(OfflinePageBridge);
};

bool RegisterOfflinePageBridge(JNIEnv* env);

}  // namespace android
}  // namespace offline_pages

#endif  // CHROME_BROWSER_ANDROID_OFFLINE_PAGES_OFFLINE_PAGE_BRIDGE_H_

