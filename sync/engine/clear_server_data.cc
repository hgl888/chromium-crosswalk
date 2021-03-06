// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sync/engine/clear_server_data.h"

#include "base/trace_event/trace_event.h"
#include "sync/engine/syncer.h"
#include "sync/engine/syncer_proto_util.h"
#include "sync/internal_api/public/events/clear_server_data_request_event.h"
#include "sync/internal_api/public/events/clear_server_data_response_event.h"
#include "sync/sessions/sync_session.h"

namespace syncer {

ClearServerData::ClearServerData(const std::string& account_name) {
  request_.set_share(account_name);
  request_.set_message_contents(
      sync_pb::ClientToServerMessage::CLEAR_SERVER_DATA);
  request_.mutable_clear_server_data();
}

ClearServerData::~ClearServerData() {}

SyncerError ClearServerData::SendRequest(sessions::SyncSession* session) {
  if (session->context()->debug_info_getter()) {
    sync_pb::DebugInfo* debug_info = request_.mutable_debug_info();
    session->context()->debug_info_getter()->GetDebugInfo(debug_info);
  }

  DVLOG(1) << "Sending ClearServerData message.";

  const ClearServerDataRequestEvent request_event(base::Time::Now(), request_);
  session->SendProtocolEvent(request_event);

  sync_pb::ClientToServerResponse response;

  TRACE_EVENT_BEGIN0("sync", "PostClearServerData");
  const SyncerError post_result = SyncerProtoUtil::PostClientToServerMessage(
      &request_, &response, session, nullptr);
  TRACE_EVENT_END0("sync", "PostClearServerData");

  const ClearServerDataResponseEvent response_event(base::Time::Now(),
                                                    post_result, response);
  session->SendProtocolEvent(response_event);

  if (post_result != SYNCER_OK) {
    DVLOG(1) << "Post ClearServerData failed";
    return post_result;
  }

  if (!response.has_clear_server_data()) {
    DVLOG(1) << "ClearServerData response has no ClearServerData body!";
    return SERVER_RESPONSE_VALIDATION_FAILED;
  }

  if (session->context()->debug_info_getter()) {
    DVLOG(1) << "Clearing client debug info.";
    session->context()->debug_info_getter()->ClearDebugInfo();
  }

  return post_result;
}

}  // namespace syncer
