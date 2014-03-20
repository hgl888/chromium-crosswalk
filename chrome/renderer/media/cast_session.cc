// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/renderer/media/cast_session.h"

#include "base/message_loop/message_loop_proxy.h"
#include "chrome/renderer/media/cast_session_delegate.h"
#include "content/public/renderer/render_thread.h"
#include "media/base/bind_to_current_loop.h"
#include "media/base/video_frame.h"
#include "media/cast/cast_config.h"
#include "media/cast/cast_sender.h"
#include "media/cast/logging/logging_defines.h"

CastSession::CastSession()
    : delegate_(new CastSessionDelegate()),
      io_message_loop_proxy_(
          content::RenderThread::Get()->GetIOMessageLoopProxy()) {}

CastSession::~CastSession() {
  // We should always be able to delete the object on the IO thread.
  CHECK(io_message_loop_proxy_->DeleteSoon(FROM_HERE, delegate_.release()));
}

void CastSession::StartAudio(const media::cast::AudioSenderConfig& config,
                             const AudioFrameInputAvailableCallback& callback,
                             const ErrorCallback& error_callback) {
  DCHECK(content::RenderThread::Get()
             ->GetMessageLoop()
             ->message_loop_proxy()
             ->BelongsToCurrentThread());

  io_message_loop_proxy_->PostTask(
      FROM_HERE,
      base::Bind(&CastSessionDelegate::StartAudio,
                 base::Unretained(delegate_.get()),
                 config,
                 media::BindToCurrentLoop(callback),
                 media::BindToCurrentLoop(error_callback)));
}

void CastSession::StartVideo(const media::cast::VideoSenderConfig& config,
                             const VideoFrameInputAvailableCallback& callback,
                             const ErrorCallback& error_callback) {
  DCHECK(content::RenderThread::Get()
             ->GetMessageLoop()
             ->message_loop_proxy()
             ->BelongsToCurrentThread());

  io_message_loop_proxy_->PostTask(
      FROM_HERE,
      base::Bind(&CastSessionDelegate::StartVideo,
                 base::Unretained(delegate_.get()),
                 config,
                 media::BindToCurrentLoop(callback),
                 media::BindToCurrentLoop(error_callback)));
}

void CastSession::StartUDP(const net::IPEndPoint& remote_endpoint) {
  io_message_loop_proxy_->PostTask(
      FROM_HERE,
      base::Bind(
          &CastSessionDelegate::StartUDP,
          base::Unretained(delegate_.get()),
          remote_endpoint));
}

void CastSession::ToggleLogging(bool is_audio, bool enable) {
  io_message_loop_proxy_->PostTask(
      FROM_HERE,
      base::Bind(&CastSessionDelegate::ToggleLogging,
                 base::Unretained(delegate_.get()),
                 is_audio,
                 enable));
}

void CastSession::GetEventLogsAndReset(
    bool is_audio, const EventLogsCallback& callback) {
  io_message_loop_proxy_->PostTask(
      FROM_HERE,
      base::Bind(&CastSessionDelegate::GetEventLogsAndReset,
                 base::Unretained(delegate_.get()),
                 is_audio,
                 media::BindToCurrentLoop(callback)));
}

void CastSession::GetStatsAndReset(bool is_audio,
                                   const StatsCallback& callback) {
  io_message_loop_proxy_->PostTask(
      FROM_HERE,
      base::Bind(&CastSessionDelegate::GetStatsAndReset,
                 base::Unretained(delegate_.get()),
                 is_audio,
                 media::BindToCurrentLoop(callback)));
}
