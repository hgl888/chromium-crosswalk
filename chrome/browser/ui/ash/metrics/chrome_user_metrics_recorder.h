// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_ASH_METRICS_CHROME_USER_METRICS_RECORDER_H_
#define CHROME_BROWSER_UI_ASH_METRICS_CHROME_USER_METRICS_RECORDER_H_

#include "base/macros.h"
#include "chrome/browser/ui/browser_list_observer.h"
#include "chrome/browser/ui/tabs/tab_strip_model_observer.h"

namespace content {
class WebContents;
}  // namespace content

// A bridge proxy between chrome/browser events and ash::UserMetricsRecorder.
class ChromeUserMetricsRecorder : public chrome::BrowserListObserver,
                                  public TabStripModelObserver {
 public:
  ChromeUserMetricsRecorder();
  ~ChromeUserMetricsRecorder() override;

  // chrome::BroswerListObserver:
  void OnBrowserAdded(Browser* browser) override;
  void OnBrowserRemoved(Browser* browser) override;

  // TabStripModelObserver:
  void ActiveTabChanged(content::WebContents* old_contents,
                        content::WebContents* new_contents,
                        int index,
                        int reason) override;

 private:
  // Called when a different tab becomes active due to a user gesture.
  void OnTabSwitchedByUserGesture();

  DISALLOW_COPY_AND_ASSIGN(ChromeUserMetricsRecorder);
};

#endif  // CHROME_BROWSER_UI_ASH_METRICS_CHROME_USER_METRICS_RECORDER_H_
