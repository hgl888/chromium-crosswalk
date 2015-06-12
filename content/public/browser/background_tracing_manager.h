// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_PUBLIC_BROWSER_BACKGROUND_TRACING_MANAGER_H_
#define CONTENT_PUBLIC_BROWSER_BACKGROUND_TRACING_MANAGER_H_

#include "base/trace_event/trace_event_impl.h"
#include "base/values.h"
#include "content/common/content_export.h"

namespace content {
struct BackgroundTracingConfig;
struct BackgroundTracingUploadConfig;

// BackgroundTracingManager is used on the browser process to trigger the
// collection of trace data and upload the results. Only the browser UI thread
// is allowed to interact with the BackgroundTracingManager. All callbacks are
// called on the UI thread.
class BackgroundTracingManager {
 public:
  CONTENT_EXPORT static BackgroundTracingManager* GetInstance();

  // ReceiveCallback will will be called on the UI thread every time the
  // BackgroundTracingManager finalizes a trace. The first parameter of
  // this callback is the trace data. The second is a callback to
  // notify the BackgroundTracingManager that you've finished processing
  // the trace data.
  //
  // Example:
  //
  // void Upload(const base::RefCountedString* data,
  //             base::Closure done_callback) {
  //   BrowserThread::PostTaskAndReply(
  //       BrowserThread::FILE,
  //       FROM_HERE,
  //       base::Bind(&DoUploadOnFileThread, data),
  //       done_callback
  //     );
  // }
  //
  typedef base::Callback<void(const scoped_refptr<base::RefCountedString>&,
                              base::Closure)> ReceiveCallback;

  // Set the triggering rules for when to start recording.
  //
  // In preemptive mode, recording begins immediately and any calls to
  // TriggerNamedEvent() will potentially trigger the trace to finalize and get
  // uploaded to the specified upload_sink. Once the trace has been uploaded,
  // tracing will be enabled again.
  //
  // In reactive mode, recording begins when TriggerNamedEvent() is called, and
  // continues until either the next call to TriggerNamedEvent, or a timeout
  // occurs. Tracing will not be re-enabled after the trace is finalized and
  // uploaded to the upload_sink.
  //
  // Calls to SetActiveScenario() with a config will fail if tracing is
  // currently on. Use WhenIdle to register a callback to get notified when
  // the manager is idle and a config can be set again.
  enum DataFiltering {
    NO_DATA_FILTERING,
    ANONYMIZE_DATA,
  };
  virtual bool SetActiveScenario(scoped_ptr<BackgroundTracingConfig> config,
                                 const ReceiveCallback& receive_callback,
                                 DataFiltering data_filtering) = 0;

  // Notifies the caller when the manager is idle (not recording or uploading),
  // so that a call to SetActiveScenario() is likely to succeed.
  typedef base::Callback<void()> IdleCallback;
  virtual void WhenIdle(IdleCallback idle_callback) = 0;

  typedef base::Callback<void(bool)> StartedFinalizingCallback;
  typedef int TriggerHandle;

  // Notifies that a manual trigger event has occurred, and we may need to
  // either begin recording or finalize the trace, depending on the config.
  // If the trigger specified isn't active in the config, this will do nothing.
  virtual void TriggerNamedEvent(
      TriggerHandle trigger_handle,
      StartedFinalizingCallback started_callback) = 0;

  // Registers a manual trigger handle, and returns a TriggerHandle which can
  // be passed to DidTriggerHappen().
  virtual TriggerHandle RegisterTriggerType(const char* trigger_name) = 0;

  // Returns a list of all registered triggers.
  virtual void GetTriggerNameList(std::vector<std::string>* trigger_names) = 0;

  virtual void InvalidateTriggerHandlesForTesting() = 0;
  virtual void SetTracingEnabledCallbackForTesting(
      const base::Closure& callback) = 0;
  virtual void FireTimerForTesting() = 0;
  virtual bool HasActiveScenarioForTesting() = 0;

 protected:
  virtual ~BackgroundTracingManager() {}
};

}  // namespace content

#endif  // CONTENT_PUBLIC_BROWSER_BACKGROUND_TRACING_MANAGER_H_
