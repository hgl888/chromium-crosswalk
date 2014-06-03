// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_SERVICES_PUBLIC_CPP_VIEW_MANAGER_VIEW_MANAGER_H_
#define MOJO_SERVICES_PUBLIC_CPP_VIEW_MANAGER_VIEW_MANAGER_H_

#include <map>

#include "base/basictypes.h"
#include "base/memory/scoped_ptr.h"
#include "mojo/public/cpp/bindings/callback.h"
#include "mojo/services/public/cpp/view_manager/view_tree_node.h"

namespace mojo {
class Application;
namespace view_manager {

class View;
class ViewManagerSynchronizer;
class ViewTreeNode;

// Approximately encapsulates the View Manager service.
// Has a synchronizer that keeps a client model in sync with the service.
// Owned by the connection.
//
// TODO: displays
class ViewManager {
 public:
  // Blocks on establishing the connection and subsequently receiving a node
  // tree from the service.
  // TODO(beng): blocking is currently achieved by running a nested runloop,
  //             which will dispatch all messages on all pipes while blocking.
  //             we should instead wait on the client pipe receiving a
  //             connection established message.
  // TODO(beng): this method could optionally not block if supplied a callback.
  explicit ViewManager(Application* application);
  ~ViewManager();

  ViewTreeNode* tree() { return tree_; }

  ViewTreeNode* GetNodeById(TransportNodeId id);
  View* GetViewById(TransportViewId id);

  void Embed(const String& url, ViewTreeNode* node);

 private:
  friend class ViewManagerPrivate;
  typedef std::map<TransportNodeId, ViewTreeNode*> IdToNodeMap;
  typedef std::map<TransportViewId, View*> IdToViewMap;

  ViewManagerSynchronizer* synchronizer_;
  ViewTreeNode* tree_;

  IdToNodeMap nodes_;
  IdToViewMap views_;

  DISALLOW_COPY_AND_ASSIGN(ViewManager);
};

}  // namespace view_manager
}  // namespace mojo

#endif  // MOJO_SERVICES_PUBLIC_CPP_VIEW_MANAGER_VIEW_MANAGER_H_
