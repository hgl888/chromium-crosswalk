// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_EXTENSIONS_DISPLAY_INFO_PROVIDER_MAC_H_
#define CHROME_BROWSER_EXTENSIONS_DISPLAY_INFO_PROVIDER_MAC_H_

#include "extensions/browser/api/system_display/display_info_provider.h"

namespace extensions {

class DisplayInfoProviderMac : public DisplayInfoProvider {
 public:
  DisplayInfoProviderMac();
  ~DisplayInfoProviderMac() override;

  // DisplayInfoProvider implementation.
  bool SetInfo(const std::string& display_id,
               const api::system_display::DisplayProperties& info,
               std::string* error) override;
  void UpdateDisplayUnitInfoForPlatform(
      const gfx::Display& display,
      api::system_display::DisplayUnitInfo* unit) override;
  gfx::Screen* GetActiveScreen() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(DisplayInfoProviderMac);
};

}  // namespace extensions

#endif  // CHROME_BROWSER_EXTENSIONS_DISPLAY_INFO_PROVIDER_MAC_H_
