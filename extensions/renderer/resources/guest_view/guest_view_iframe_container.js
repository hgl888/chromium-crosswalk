// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// --site-per-process overrides for guest_view_container.js

var GuestViewContainer = require('guestViewContainer').GuestViewContainer;

GuestViewContainer.prototype.createInternalElement$ = function() {
  var iframeElement = document.createElement('iframe');
  iframeElement.style.width = '100%';
  iframeElement.style.height = '100%';
  privates(iframeElement).internal = this;
  return iframeElement;
};
