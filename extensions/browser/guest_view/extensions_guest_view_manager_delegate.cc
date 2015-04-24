// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/browser/guest_view/extensions_guest_view_manager_delegate.h"

#include "content/public/browser/browser_context.h"
#include "content/public/browser/render_process_host.h"
#include "extensions/browser/event_router.h"
#include "extensions/browser/guest_view/app_view/app_view_guest.h"
#include "extensions/browser/guest_view/extension_options/extension_options_guest.h"
#include "extensions/browser/guest_view/extension_view/extension_view_guest.h"
#include "extensions/browser/guest_view/guest_view_base.h"
#include "extensions/browser/guest_view/guest_view_manager.h"
#include "extensions/browser/guest_view/mime_handler_view/mime_handler_view_guest.h"
#include "extensions/browser/guest_view/surface_worker/surface_worker_guest.h"
#include "extensions/browser/guest_view/web_view/web_view_guest.h"
#include "extensions/browser/process_manager.h"
#include "extensions/browser/process_map.h"
#include "extensions/common/features/feature.h"
#include "extensions/common/features/feature_provider.h"

namespace extensions {

ExtensionsGuestViewManagerDelegate::ExtensionsGuestViewManagerDelegate(
    content::BrowserContext* context)
    : context_(context) {
}

ExtensionsGuestViewManagerDelegate::~ExtensionsGuestViewManagerDelegate() {
}

void ExtensionsGuestViewManagerDelegate::DispatchEvent(
    const std::string& event_name,
    scoped_ptr<base::DictionaryValue> args,
    GuestViewBase* guest,
    int instance_id) {
  EventFilteringInfo info;
  info.SetInstanceID(instance_id);
  scoped_ptr<base::ListValue> event_args(new base::ListValue());
  event_args->Append(args.release());

  EventRouter::DispatchEvent(
      guest->owner_web_contents(),
      guest->browser_context(),
      guest->owner_host(),
      event_name,
      event_args.Pass(),
      EventRouter::USER_GESTURE_UNKNOWN,
      info);
}

bool ExtensionsGuestViewManagerDelegate::IsGuestAvailableToContext(
    extensions::GuestViewBase* guest) {
  const Feature* feature =
      FeatureProvider::GetAPIFeature(guest->GetAPINamespace());
  CHECK(feature);

  ProcessMap* process_map = ProcessMap::Get(context_);
  CHECK(process_map);

  const Extension* owner_extension = ProcessManager::Get(context_)->
      GetExtensionForWebContents(guest->owner_web_contents());

  // Ok for |owner_extension| to be nullptr, the embedder might be WebUI.
  Feature::Availability availability = feature->IsAvailableToContext(
      owner_extension,
      process_map->GetMostLikelyContextType(
          owner_extension,
          guest->owner_web_contents()->GetRenderProcessHost()->GetID()),
      guest->GetOwnerSiteURL());

  return availability.is_available();
}

bool ExtensionsGuestViewManagerDelegate::IsOwnedByExtension(
    extensions::GuestViewBase* guest) {
  return !!ProcessManager::Get(context_)->
      GetExtensionForWebContents(guest->owner_web_contents());
}

void ExtensionsGuestViewManagerDelegate::RegisterAdditionalGuestViewTypes() {
  extensions::GuestViewManager* manager =
      extensions::GuestViewManager::FromBrowserContext(context_);
  manager->RegisterGuestViewType<AppViewGuest>();
  manager->RegisterGuestViewType<ExtensionOptionsGuest>();
  manager->RegisterGuestViewType<ExtensionViewGuest>();
  manager->RegisterGuestViewType<MimeHandlerViewGuest>();
  manager->RegisterGuestViewType<SurfaceWorkerGuest>();
  manager->RegisterGuestViewType<WebViewGuest>();
}

}  // namespace extensions
