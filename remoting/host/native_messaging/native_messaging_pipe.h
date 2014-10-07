// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef REMOTING_HOST_NATIVE_MESSAGING_NATIVE_MESSAGING_PIPE_H_
#define REMOTING_HOST_NATIVE_MESSAGING_NATIVE_MESSAGING_PIPE_H_

#include "base/memory/scoped_ptr.h"
#include "base/memory/weak_ptr.h"
#include "extensions/browser/api/messaging/native_message_host.h"
#include "extensions/browser/api/messaging/native_messaging_channel.h"

namespace base {
class Value;
}

namespace remoting {

// Connects a extensions::NativeMessageHost to a PipeMessagingChannel.
class NativeMessagingPipe
    : public extensions::NativeMessagingChannel::EventHandler,
      public extensions::NativeMessageHost::Client {
 public:
  NativeMessagingPipe();
  virtual ~NativeMessagingPipe();

  // Starts processing messages from the pipe.
  void Start(scoped_ptr<extensions::NativeMessageHost> host,
             scoped_ptr<extensions::NativeMessagingChannel> channel,
             const base::Closure& quit_closure);

  // extensions::NativeMessageHost::Client implementation.
  virtual void PostMessageFromNativeHost(const std::string& message) override;
  virtual void CloseChannel(const std::string& error_message) override;

  // extensions::NativeMessagingChannel::EventHandler implementation.
  virtual void OnMessage(scoped_ptr<base::Value> message) override;
  virtual void OnDisconnect() override;

 private:
  base::Closure quit_closure_;
  scoped_ptr<extensions::NativeMessagingChannel> channel_;
  scoped_ptr<extensions::NativeMessageHost> host_;

  DISALLOW_COPY_AND_ASSIGN(NativeMessagingPipe);
};

}  // namespace remoting

#endif  // REMOTING_HOST_NATIVE_MESSAGING_NATIVE_MESSAGING_PIPE_H_
