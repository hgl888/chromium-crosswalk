// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

function getAllWebViews() {
  function findAllWebViews(node, nodes) {
    if (node.role == chrome.automation.RoleType.webView)
      nodes.push(node);

    var children = node.children;
    for (var i = 0; i < children.length; i++) {
      var child = findAllWebViews(children[i], nodes);
    }
  }

  var webViews = [];
  findAllWebViews(rootNode, webViews);
  return webViews;
};

var allTests = [
  function testLoadTabs() {
    var webViews = getAllWebViews();
    assertEq(2, webViews.length);
    var subroot = webViews[1].firstChild;
    assertEq(webViews[1], subroot.parent);
    assertEq(subroot, subroot.parent.children[0]);
    var button = subroot.firstChild.firstChild;
    assertEq(chrome.automation.RoleType.button, button.role);
    var input = subroot.firstChild.lastChild.previousSibling;
    assertEq(chrome.automation.RoleType.textField, input.role);
    chrome.test.succeed();
  },

  function testSubevents() {
    var button = null;
    var webViews = getAllWebViews();
    var subroot = webViews[1].firstChild;

    rootNode.addEventListener(chrome.automation.EventType.focus,
        function(evt) {
          assertEq(button, evt.target);
          chrome.test.succeed();
        },
        false);

    button = subroot.firstChild.firstChild;
    button.focus();
  }
];

setupAndRunTests(allTests,
                 '<button>alpha</button><input type="text">hello</input>');
