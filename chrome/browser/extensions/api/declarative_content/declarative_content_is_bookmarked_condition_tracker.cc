// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/extensions/api/declarative_content/declarative_content_is_bookmarked_condition_tracker.h"

#include "base/bind.h"
#include "base/stl_util.h"
#include "chrome/browser/bookmarks/bookmark_model_factory.h"
#include "chrome/browser/profiles/profile.h"
#include "components/bookmarks/browser/bookmark_model.h"
#include "content/public/browser/web_contents.h"

namespace extensions {

//
// PerWebContentsTracker
//

DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
PerWebContentsTracker(
    content::WebContents* contents,
    const RequestEvaluationCallback& request_evaluation,
    const WebContentsDestroyedCallback& web_contents_destroyed)
    : WebContentsObserver(contents),
      request_evaluation_(request_evaluation),
      web_contents_destroyed_(web_contents_destroyed) {
  is_url_bookmarked_ = IsCurrentUrlBookmarked();
  request_evaluation_.Run(web_contents());
}

DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
~PerWebContentsTracker() {
}

void DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
BookmarkAddedForUrl(const GURL& url) {
  if (web_contents()->GetVisibleURL() == url) {
    is_url_bookmarked_ = true;
    request_evaluation_.Run(web_contents());
  }
}

void DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
BookmarkRemovedForUrls(const std::set<GURL>& urls) {
  if (ContainsKey(urls, web_contents()->GetVisibleURL())) {
    is_url_bookmarked_ = false;
    request_evaluation_.Run(web_contents());
  }
}

void DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
UpdateState(bool request_evaluation_if_unchanged) {
  bool state_changed =
      IsCurrentUrlBookmarked() != is_url_bookmarked_;
  if (state_changed)
    is_url_bookmarked_ = !is_url_bookmarked_;
  if (state_changed || request_evaluation_if_unchanged)
    request_evaluation_.Run(web_contents());
}

bool DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
IsCurrentUrlBookmarked() {
  bookmarks::BookmarkModel* bookmark_model =
      BookmarkModelFactory::GetForProfile(
          Profile::FromBrowserContext(web_contents()->GetBrowserContext()));
  // BookmarkModel can be null during unit test execution.
  return bookmark_model &&
      bookmark_model->IsBookmarked(web_contents()->GetVisibleURL());
}

void DeclarativeContentIsBookmarkedConditionTracker::PerWebContentsTracker::
WebContentsDestroyed() {
  web_contents_destroyed_.Run(web_contents());
}

//
// DeclarativeContentIsBookmarkedConditionTracker
//

DeclarativeContentIsBookmarkedConditionTracker::
DeclarativeContentIsBookmarkedConditionTracker(
    content::BrowserContext* context,
    DeclarativeContentConditionTrackerDelegate* delegate)
    : extensive_bookmark_changes_in_progress_(0),
      delegate_(delegate),
      scoped_bookmarks_observer_(this) {
  bookmarks::BookmarkModel* bookmark_model =
      BookmarkModelFactory::GetForProfile(Profile::FromBrowserContext(context));
  // Can be null during unit test execution.
  if (bookmark_model)
    scoped_bookmarks_observer_.Add(bookmark_model);
}

DeclarativeContentIsBookmarkedConditionTracker::
~DeclarativeContentIsBookmarkedConditionTracker() {
}

void DeclarativeContentIsBookmarkedConditionTracker::TrackForWebContents(
    content::WebContents* contents) {
  per_web_contents_tracker_[contents] =
      make_linked_ptr(new PerWebContentsTracker(
          contents,
          base::Bind(&DeclarativeContentConditionTrackerDelegate::
                     RequestEvaluation,
                     base::Unretained(delegate_)),
          base::Bind(&DeclarativeContentIsBookmarkedConditionTracker::
                     DeletePerWebContentsTracker,
                     base::Unretained(this))));
}

void DeclarativeContentIsBookmarkedConditionTracker::OnWebContentsNavigation(
    content::WebContents* contents,
    const content::LoadCommittedDetails& details,
    const content::FrameNavigateParams& params) {
  DCHECK(ContainsKey(per_web_contents_tracker_, contents));
  per_web_contents_tracker_[contents]->UpdateState(true);
}

bool DeclarativeContentIsBookmarkedConditionTracker::IsUrlBookmarked(
    content::WebContents* contents) {
  DCHECK(ContainsKey(per_web_contents_tracker_, contents));
  return per_web_contents_tracker_[contents]->is_url_bookmarked();
}

void DeclarativeContentIsBookmarkedConditionTracker::BookmarkModelChanged() {}

void DeclarativeContentIsBookmarkedConditionTracker::BookmarkNodeAdded(
    bookmarks::BookmarkModel* model,
    const bookmarks::BookmarkNode* parent,
    int index) {
  if (!extensive_bookmark_changes_in_progress_) {
    for (const auto& web_contents_tracker_pair : per_web_contents_tracker_) {
      web_contents_tracker_pair.second->BookmarkAddedForUrl(
          parent->GetChild(index)->url());
    }
  }
}

void DeclarativeContentIsBookmarkedConditionTracker::BookmarkNodeRemoved(
    bookmarks::BookmarkModel* model,
    const bookmarks::BookmarkNode* parent,
    int old_index,
    const bookmarks::BookmarkNode* node,
    const std::set<GURL>& no_longer_bookmarked) {
  if (!extensive_bookmark_changes_in_progress_) {
    for (const auto& web_contents_tracker_pair : per_web_contents_tracker_) {
      web_contents_tracker_pair.second->BookmarkRemovedForUrls(
          no_longer_bookmarked);
    }
  }
}

void DeclarativeContentIsBookmarkedConditionTracker::
ExtensiveBookmarkChangesBeginning(
    bookmarks::BookmarkModel* model) {
  ++extensive_bookmark_changes_in_progress_;
}

void
DeclarativeContentIsBookmarkedConditionTracker::ExtensiveBookmarkChangesEnded(
    bookmarks::BookmarkModel* model) {
  if (--extensive_bookmark_changes_in_progress_ == 0)
    UpdateAllPerWebContentsTrackers();
}

void
DeclarativeContentIsBookmarkedConditionTracker::GroupedBookmarkChangesBeginning(
    bookmarks::BookmarkModel* model) {
  ++extensive_bookmark_changes_in_progress_;
}

void
DeclarativeContentIsBookmarkedConditionTracker::GroupedBookmarkChangesEnded(
    bookmarks::BookmarkModel* model) {
  if (--extensive_bookmark_changes_in_progress_ == 0)
    UpdateAllPerWebContentsTrackers();
}

void
DeclarativeContentIsBookmarkedConditionTracker::DeletePerWebContentsTracker(
    content::WebContents* contents) {
  DCHECK(ContainsKey(per_web_contents_tracker_, contents));
  per_web_contents_tracker_.erase(contents);
}

void DeclarativeContentIsBookmarkedConditionTracker::
UpdateAllPerWebContentsTrackers() {
  for (const auto& web_contents_tracker_pair : per_web_contents_tracker_)
    web_contents_tracker_pair.second->UpdateState(false);
}

}  // namespace extensions
