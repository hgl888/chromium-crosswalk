// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_DRIVE_FILE_SYSTEM_CORE_UTIL_H_
#define CHROME_BROWSER_CHROMEOS_DRIVE_FILE_SYSTEM_CORE_UTIL_H_

#include <string>

#include "base/callback_forward.h"
#include "base/files/file_path.h"
#include "components/drive/file_errors.h"
#include "url/gurl.h"

namespace drive {

class DriveAppRegistry;
class DriveServiceInterface;
class FileSystemInterface;

namespace util {

// "drive" diretory's local ID is fixed to this value.
const char kDriveGrandRootLocalId[] = "<drive>";

// "drive/other" diretory's local ID is fixed to this value.
const char kDriveOtherDirLocalId[] = "<other>";

// "drive/trash" diretory's local ID is fixed to this value.
const char kDriveTrashDirLocalId[] = "<trash>";

// The directory names used for the Google Drive file system tree. These names
// are used in URLs for the file manager, hence user-visible.
const char kDriveGrandRootDirName[] = "drive";
const char kDriveMyDriveRootDirName[] = "root";
const char kDriveOtherDirName[] = "other";
const char kDriveTrashDirName[] = "trash";

// Returns the path of the top root of the pseudo tree.
const base::FilePath& GetDriveGrandRootPath();

// Returns the path of the directory representing "My Drive".
const base::FilePath& GetDriveMyDriveRootPath();

// Returns the Drive mount point path, which looks like
// "/special/drive-<username_hash>", when provided with the |user_id_hash|.
base::FilePath GetDriveMountPointPathForUserIdHash(std::string user_id_hash);

// Returns true if the given path is under the Drive mount point.
bool IsUnderDriveMountPoint(const base::FilePath& path);

// Extracts the Drive path from the given path located under the Drive mount
// point. Returns an empty path if |path| is not under the Drive mount point.
// Examples: ExtractDrivePath("/special/drive-xxx/foo.txt") => "drive/foo.txt"
base::FilePath ExtractDrivePath(const base::FilePath& path);

// Escapes a file name in Drive cache.
// Replaces percent ('%'), period ('.') and slash ('/') with %XX (hex)
std::string EscapeCacheFileName(const std::string& filename);

// Unescapes a file path in Drive cache.
// This is the inverse of EscapeCacheFileName.
std::string UnescapeCacheFileName(const std::string& filename);

// Converts the given string to a form suitable as a file name. Specifically,
// - Normalizes in Unicode Normalization Form C.
// - Replaces slashes '/' with '_'.
// - Replaces the whole input with "_" if the all input characters are '.'.
// |input| must be a valid UTF-8 encoded string.
std::string NormalizeFileName(const std::string& input);

// Does nothing with |error|. Used with functions taking FileOperationCallback.
void EmptyFileOperationCallback(FileError error);

// Helper to destroy objects which needs Destroy() to be called on destruction.
struct DestroyHelper {
  template <typename T>
  void operator()(T* object) const {
    if (object)
      object->Destroy();
  }
};

// Creates a GDoc file with given values.
//
// GDoc files are used to represent hosted documents on local filesystems.
// A GDoc file contains a JSON whose content is a URL to view the document and
// a resource ID of the entry.
bool CreateGDocFile(const base::FilePath& file_path,
                    const GURL& url,
                    const std::string& resource_id);

// Reads URL from a GDoc file.
GURL ReadUrlFromGDocFile(const base::FilePath& file_path);

// Reads resource ID from a GDoc file.
std::string ReadResourceIdFromGDocFile(const base::FilePath& file_path);

}  // namespace util
}  // namespace drive

#endif  // CHROME_BROWSER_CHROMEOS_DRIVE_FILE_SYSTEM_CORE_UTIL_H_
