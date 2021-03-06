# Copyright (c) 2013 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'includes': [
    '../../../ppapi/ppapi_nacl_test_common.gypi',
  ],
  'targets': [
    {
      'target_name': 'ppapi_tests_extensions_background_keepalive',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_background_keepalive',
        # Only newlib build is used in tests, no need to build others.
        'build_newlib': 1,
        'build_glibc': 0,
        'build_pnacl_newlib': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/background_keepalive',
        'sources': [
          'background_keepalive/background.cc',
        ],
        'test_files': [
          'background_keepalive/background.js',
          'background_keepalive/manifest.json',
        ],
      },
    },
    {
      'target_name': 'ppapi_tests_extensions_load_unload',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_load_unload',
        # Only newlib build is used in tests, no need to build others.
        'build_newlib': 1,
        'build_glibc': 0,
        'build_pnacl_newlib': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/load_unload',
        'sources': [
          'load_unload/load_unload.cc',
        ],
        'test_files': [
          'load_unload/background.js',
          'load_unload/ext_icon.png',
          'load_unload/manifest.json',
        ],
      },
    },
    {
      'target_name': 'ppapi_tests_extensions_media_galleries',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_media_galleries',
        # Only newlib build is used in tests, no need to build others.
        'build_newlib': 1,
        'build_glibc': 0,
        'build_pnacl_newlib': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/media_galleries',
        'sources': [
          '<(DEPTH)/ppapi/tests/test_utils.cc',
          '<(DEPTH)/ppapi/tests/test_utils.h',
          'media_galleries/test_galleries.cc',
        ],
        'test_files': [
          'media_galleries/background.js',
          'media_galleries/index.html',
          'media_galleries/manifest.json',
          'media_galleries/test.js',
        ],
      },
    },
    {
      'target_name': 'ppapi_tests_extensions_multicast_permissions',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_multicast_permissions',
        # Only newlib build is used in tests, no need to build others.
        'build_newlib': 1,
        'build_glibc': 0,
        'build_pnacl_newlib': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/multicast_permissions',
        'sources': [
          'multicast_permissions/test_multicast_permissions.cc',
        ],
        'test_files': [
          'multicast_permissions/controller.js',
          'multicast_permissions/index.html',
          'multicast_permissions/main.js',
          'multicast_permissions/manifest.json',
        ],
      },
    },
    {
      'target_name': 'ppapi_tests_extensions_no_socket_permissions',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_no_socket_permissions',
        # Only newlib build is used in tests, no need to build others.
        'build_newlib': 1,
        'build_glibc': 0,
        'build_pnacl_newlib': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/no_socket_permissions',
        'sources': [
          'no_socket_permissions/test_no_socket_permissions.cc',
        ],
        'test_files': [
          'no_socket_permissions/controller.js',
          'no_socket_permissions/index.html',
          'no_socket_permissions/main.js',
          'no_socket_permissions/manifest.json',
        ],
      },
    },
    {
      'target_name': 'ppapi_tests_extensions_packaged_app',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_packaged_app',
        'build_newlib': 1,
        'build_glibc': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/packaged_app',
        'sources': [
          'packaged_app/test_packaged_app.cc'
        ],
        'test_files': [
          'packaged_app/controller.js',
          'packaged_app/index.html',
          'packaged_app/main.js',
          'packaged_app/manifest.json',
          'packaged_app/test_file.txt',
          'packaged_app/test_file2.txt',
        ],
        'create_nmf_args_portable': [
          # Add 129 "files" entries to make sure that open_resource can handle
          # more files than IPC::MessageAttachmentSet::kMaxDescriptorsPerMessage
          # which is currently 128.
          '-xtest_file0:test_file.txt',
          '-xtest_file1:test_file2.txt',
          '-xtest_file2:test_file.txt',
          '-xtest_file3:test_file2.txt',
          '-xtest_file4:test_file.txt',
          '-xtest_file5:test_file2.txt',
          '-xtest_file6:test_file.txt',
          '-xtest_file7:test_file2.txt',
          '-xtest_file8:test_file.txt',
          '-xtest_file9:test_file2.txt',
          '-xtest_file10:test_file.txt',
          '-xtest_file11:test_file2.txt',
          '-xtest_file12:test_file.txt',
          '-xtest_file13:test_file2.txt',
          '-xtest_file14:test_file.txt',
          '-xtest_file15:test_file2.txt',
          '-xtest_file16:test_file.txt',
          '-xtest_file17:test_file2.txt',
          '-xtest_file18:test_file.txt',
          '-xtest_file19:test_file2.txt',
          '-xtest_file20:test_file.txt',
          '-xtest_file21:test_file2.txt',
          '-xtest_file22:test_file.txt',
          '-xtest_file23:test_file2.txt',
          '-xtest_file24:test_file.txt',
          '-xtest_file25:test_file2.txt',
          '-xtest_file26:test_file.txt',
          '-xtest_file27:test_file2.txt',
          '-xtest_file28:test_file.txt',
          '-xtest_file29:test_file2.txt',
          '-xtest_file30:test_file.txt',
          '-xtest_file31:test_file2.txt',
          '-xtest_file32:test_file.txt',
          '-xtest_file33:test_file2.txt',
          '-xtest_file34:test_file.txt',
          '-xtest_file35:test_file2.txt',
          '-xtest_file36:test_file.txt',
          '-xtest_file37:test_file2.txt',
          '-xtest_file38:test_file.txt',
          '-xtest_file39:test_file2.txt',
          '-xtest_file40:test_file.txt',
          '-xtest_file41:test_file2.txt',
          '-xtest_file42:test_file.txt',
          '-xtest_file43:test_file2.txt',
          '-xtest_file44:test_file.txt',
          '-xtest_file45:test_file2.txt',
          '-xtest_file46:test_file.txt',
          '-xtest_file47:test_file2.txt',
          '-xtest_file48:test_file.txt',
          '-xtest_file49:test_file2.txt',
          '-xtest_file50:test_file.txt',
          '-xtest_file51:test_file2.txt',
          '-xtest_file52:test_file.txt',
          '-xtest_file53:test_file2.txt',
          '-xtest_file54:test_file.txt',
          '-xtest_file55:test_file2.txt',
          '-xtest_file56:test_file.txt',
          '-xtest_file57:test_file2.txt',
          '-xtest_file58:test_file.txt',
          '-xtest_file59:test_file2.txt',
          '-xtest_file60:test_file.txt',
          '-xtest_file61:test_file2.txt',
          '-xtest_file62:test_file.txt',
          '-xtest_file63:test_file2.txt',
          '-xtest_file64:test_file.txt',
          '-xtest_file65:test_file2.txt',
          '-xtest_file66:test_file.txt',
          '-xtest_file67:test_file2.txt',
          '-xtest_file68:test_file.txt',
          '-xtest_file69:test_file2.txt',
          '-xtest_file70:test_file.txt',
          '-xtest_file71:test_file2.txt',
          '-xtest_file72:test_file.txt',
          '-xtest_file73:test_file2.txt',
          '-xtest_file74:test_file.txt',
          '-xtest_file75:test_file2.txt',
          '-xtest_file76:test_file.txt',
          '-xtest_file77:test_file2.txt',
          '-xtest_file78:test_file.txt',
          '-xtest_file79:test_file2.txt',
          '-xtest_file80:test_file.txt',
          '-xtest_file81:test_file2.txt',
          '-xtest_file82:test_file.txt',
          '-xtest_file83:test_file2.txt',
          '-xtest_file84:test_file.txt',
          '-xtest_file85:test_file2.txt',
          '-xtest_file86:test_file.txt',
          '-xtest_file87:test_file2.txt',
          '-xtest_file88:test_file.txt',
          '-xtest_file89:test_file2.txt',
          '-xtest_file90:test_file.txt',
          '-xtest_file91:test_file2.txt',
          '-xtest_file92:test_file.txt',
          '-xtest_file93:test_file2.txt',
          '-xtest_file94:test_file.txt',
          '-xtest_file95:test_file2.txt',
          '-xtest_file96:test_file.txt',
          '-xtest_file97:test_file2.txt',
          '-xtest_file98:test_file.txt',
          '-xtest_file99:test_file2.txt',
          '-xtest_file100:test_file.txt',
          '-xtest_file101:test_file2.txt',
          '-xtest_file102:test_file.txt',
          '-xtest_file103:test_file2.txt',
          '-xtest_file104:test_file.txt',
          '-xtest_file105:test_file2.txt',
          '-xtest_file106:test_file.txt',
          '-xtest_file107:test_file2.txt',
          '-xtest_file108:test_file.txt',
          '-xtest_file109:test_file2.txt',
          '-xtest_file110:test_file.txt',
          '-xtest_file111:test_file2.txt',
          '-xtest_file112:test_file.txt',
          '-xtest_file113:test_file2.txt',
          '-xtest_file114:test_file.txt',
          '-xtest_file115:test_file2.txt',
          '-xtest_file116:test_file.txt',
          '-xtest_file117:test_file2.txt',
          '-xtest_file118:test_file.txt',
          '-xtest_file119:test_file2.txt',
          '-xtest_file120:test_file.txt',
          '-xtest_file121:test_file2.txt',
          '-xtest_file122:test_file.txt',
          '-xtest_file123:test_file2.txt',
          '-xtest_file124:test_file.txt',
          '-xtest_file125:test_file2.txt',
          '-xtest_file126:test_file.txt',
          '-xtest_file127:test_file2.txt',
          '-xtest_file128:test_file.txt',
        ],
      },
      'conditions': [
        ['(target_arch=="ia32" or target_arch=="x64") and OS=="linux"', {
          # Enable nonsfi testing only on ia32-linux environment.
          # See chrome/test/data/nacl/nacl_test_data.gyp for more info.
          'variables': {
            'build_pnacl_newlib': 1,
            'translate_pexe_with_build': 1,
            'enable_x86_32_nonsfi': 1,
          },
        }],
      ],
      # Shim is a dependency for the nexe because we pre-translate.
      'dependencies': [
        '<(DEPTH)/ppapi/native_client/src/untrusted/pnacl_irt_shim/pnacl_irt_shim.gyp:aot',
      ],
    },
    {
      'target_name': 'ppapi_tests_extensions_socket_permissions',
      'type': 'none',
      'variables': {
        'nexe_target': 'ppapi_tests_extensions_socket_permissions',
        # Only newlib build is used in tests, no need to build others.
        'build_newlib': 1,
        'build_glibc': 0,
        'build_pnacl_newlib': 0,
        'nexe_destination_dir': 'test_data/ppapi/tests/extensions/socket_permissions',
        'sources': [
          'socket_permissions/test_socket_permissions.cc',
        ],
        'test_files': [
          'socket_permissions/controller.js',
          'socket_permissions/index.html',
          'socket_permissions/main.js',
          'socket_permissions/manifest.json',
        ],
      },
    },
  ],
}
