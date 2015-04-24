// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/browser/guest_view/guest_view_event.h"

#include "extensions/browser/guest_view/guest_view_base.h"
#include "extensions/browser/guest_view/guest_view_manager.h"

namespace extensions {

GuestViewEvent::GuestViewEvent(const std::string& name,
                               scoped_ptr<base::DictionaryValue> args)
    : name_(name),
      args_(args.Pass()) {
}

GuestViewEvent::~GuestViewEvent() {
}

void GuestViewEvent::Dispatch(GuestViewBase* guest, int instance_id) {
  GuestViewManager::FromBrowserContext(guest->browser_context())->
      DispatchEvent(name_, args_.Pass(), guest, instance_id);

  delete this;
}

}  // namespace extensions
