// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/display/chromeos/display_mode.h"

namespace ui {

DisplayMode::DisplayMode(const gfx::Size& size,
                         bool interlaced,
                         float refresh_rate)
    : size_(size),
      is_interlaced_(interlaced),
      refresh_rate_(refresh_rate) {}

DisplayMode::~DisplayMode() {}

}  // namespace ui
