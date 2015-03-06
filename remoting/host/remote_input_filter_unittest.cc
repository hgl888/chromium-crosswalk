// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "remoting/host/remote_input_filter.h"

#include "remoting/proto/event.pb.h"
#include "remoting/protocol/input_event_tracker.h"
#include "remoting/protocol/protocol_mock_objects.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

using ::testing::_;
using ::testing::ExpectationSet;
using ::testing::InSequence;

namespace remoting {

using protocol::MockInputStub;
using protocol::InputEventTracker;

namespace {

MATCHER_P2(EqualsUsbEvent, usb_keycode, pressed, "") {
  return arg.usb_keycode() == (unsigned int)usb_keycode &&
         arg.pressed() == pressed;
}

static protocol::MouseEvent MouseMoveEvent(int x, int y) {
  protocol::MouseEvent event;
  event.set_x(x);
  event.set_y(y);
  return event;
}

static protocol::KeyEvent UsbKeyEvent(int usb_keycode, bool pressed) {
  protocol::KeyEvent event;
  event.set_usb_keycode(usb_keycode);
  event.set_pressed(pressed);
  return event;
}

MATCHER_P2(EqualsTouchEvent, type, id, "") {
  if (arg.event_type() != type)
    return false;

  // Expect only one touch point.
  if (arg.touch_points().size() != 1)
    return false;

  return arg.touch_points(0).id() == id;
}

protocol::TouchEvent TouchStartEvent(uint32_t id) {
  protocol::TouchEvent event;
  event.set_event_type(protocol::TouchEvent::TOUCH_POINT_START);

  protocol::TouchEventPoint* point = event.add_touch_points();
  point->set_id(id);
  point->set_x(0.0f);
  point->set_y(0.0f);
  point->set_radius_x(0.0f);
  point->set_radius_y(0.0f);
  point->set_angle(0.0f);
  point->set_pressure(0.0f);
  return event;
}

}

// Verify that events get through if there is no local activity.
TEST(RemoteInputFilterTest, NoLocalActivity) {
  MockInputStub mock_stub;
  InputEventTracker input_tracker(&mock_stub);
  RemoteInputFilter input_filter(&input_tracker);

  EXPECT_CALL(mock_stub, InjectMouseEvent(_))
        .Times(10);

  for (int i = 0; i < 10; ++i)
    input_filter.InjectMouseEvent(MouseMoveEvent(0, 0));
}

// Verify that events get through until there is local activity.
TEST(RemoteInputFilterTest, MismatchedLocalActivity) {
  MockInputStub mock_stub;
  InputEventTracker input_tracker(&mock_stub);
  RemoteInputFilter input_filter(&input_tracker);

  EXPECT_CALL(mock_stub, InjectMouseEvent(_))
      .Times(5);

  for (int i = 0; i < 10; ++i) {
    input_filter.InjectMouseEvent(MouseMoveEvent(0, 0));
    if (i == 4)
      input_filter.LocalMouseMoved(webrtc::DesktopVector(1, 1));
  }
}

// Verify that echos of injected events don't block activity.
TEST(RemoteInputFilterTest, LocalEchoesOfRemoteActivity) {
  MockInputStub mock_stub;
  InputEventTracker input_tracker(&mock_stub);
  RemoteInputFilter input_filter(&input_tracker);

  EXPECT_CALL(mock_stub, InjectMouseEvent(_))
      .Times(10);

  for (int i = 0; i < 10; ++i) {
    input_filter.InjectMouseEvent(MouseMoveEvent(0, 0));
    input_filter.LocalMouseMoved(webrtc::DesktopVector(0, 0));
  }
}

// Verify that echos followed by a mismatch blocks activity.
TEST(RemoteInputFilterTest, LocalEchosAndLocalActivity) {
  MockInputStub mock_stub;
  InputEventTracker input_tracker(&mock_stub);
  RemoteInputFilter input_filter(&input_tracker);

  EXPECT_CALL(mock_stub, InjectMouseEvent(_))
      .Times(5);

  for (int i = 0; i < 10; ++i) {
    input_filter.InjectMouseEvent(MouseMoveEvent(0, 0));
    input_filter.LocalMouseMoved(webrtc::DesktopVector(0, 0));
    if (i == 4)
      input_filter.LocalMouseMoved(webrtc::DesktopVector(1, 1));
  }
}

// Verify that local activity also causes buttons, keys, and touches to be
// released.
TEST(RemoteInputFilterTest, LocalActivityReleasesAll) {
  MockInputStub mock_stub;
  InputEventTracker input_tracker(&mock_stub);
  RemoteInputFilter input_filter(&input_tracker);

  EXPECT_CALL(mock_stub, InjectMouseEvent(_))
      .Times(5);

  // Use release of a key as a proxy for InputEventTracker::ReleaseAll()
  // having been called, rather than mocking it.
  EXPECT_CALL(mock_stub, InjectKeyEvent(EqualsUsbEvent(0, true)));
  EXPECT_CALL(mock_stub, InjectKeyEvent(EqualsUsbEvent(0, false)));
  input_filter.InjectKeyEvent(UsbKeyEvent(0, true));

  // Touch points that are down should be canceled.
  EXPECT_CALL(mock_stub, InjectTouchEvent(EqualsTouchEvent(
                             protocol::TouchEvent::TOUCH_POINT_START, 0u)));
  EXPECT_CALL(mock_stub, InjectTouchEvent(EqualsTouchEvent(
                             protocol::TouchEvent::TOUCH_POINT_CANCEL, 0u)));
  input_filter.InjectTouchEvent(TouchStartEvent(0u));

  for (int i = 0; i < 10; ++i) {
    input_filter.InjectMouseEvent(MouseMoveEvent(0, 0));
    input_filter.LocalMouseMoved(webrtc::DesktopVector(0, 0));
    if (i == 4)
      input_filter.LocalMouseMoved(webrtc::DesktopVector(1, 1));
  }
}

}  // namespace remoting
