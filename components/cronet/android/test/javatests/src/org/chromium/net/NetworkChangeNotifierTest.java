// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.net;

import android.test.suitebuilder.annotation.SmallTest;

import org.chromium.base.test.util.Feature;

/**
 * Tests that NetworkChangeNotifier is initialized.
 */
public class NetworkChangeNotifierTest extends CronetTestBase {
    /**
     * Adds a IPAddressObserver and checks whether it receives notifications.
     * This serves as an indirect way to test that Cronet has an active
     * network notifier.
     */
    @SmallTest
    @Feature({"Cronet"})
    public void testNetworkChangeNotifierIsInitialized() throws Exception {
        CronetTestActivity activity = launchCronetTestApp();
        assertNotNull(activity);
        assertTrue(NetworkChangeNotifierUtil.isTestIPAddressObserverCalled());
    }
}
