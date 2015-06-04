# Copyright 2013 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'dependencies': [
    '../base/base.gyp:base',
    '../components/mime_util/mime_util.gyp:mime_util',
    '../components/tracing.gyp:tracing',
    '../components/webcrypto/webcrypto.gyp:webcrypto',
    '../mojo/mojo_base.gyp:mojo_environment_chromium',
    '../mojo/mojo_base.gyp:mojo_common_lib',
    '../skia/skia.gyp:skia',
    '../ui/base/ui_base.gyp:ui_base',
    '../ui/events/events.gyp:gestures_blink',
    '../ui/gfx/gfx.gyp:gfx',
    '../ui/gfx/gfx.gyp:gfx_geometry',
    '../url/url.gyp:url_lib',
    'content_common_mojo_bindings.gyp:content_common_mojo_bindings',
  ],
  'include_dirs': [
    '..',
  ],
  'export_dependent_settings': [
    '../base/base.gyp:base',
  ],
  'variables': {
    'public_child_sources': [
      'public/child/child_thread.h',
      'public/child/fixed_received_data.cc',
      'public/child/fixed_received_data.h',
      'public/child/image_decoder_utils.h',
      'public/child/request_peer.h',
      'public/child/resource_dispatcher_delegate.h',
      'public/child/v8_value_converter.h',
    ],
    'private_child_sources': [
      'child/appcache/appcache_backend_proxy.cc',
      'child/appcache/appcache_backend_proxy.h',
      'child/appcache/appcache_dispatcher.cc',
      'child/appcache/appcache_dispatcher.h',
      'child/appcache/appcache_frontend_impl.cc',
      'child/appcache/appcache_frontend_impl.h',
      'child/appcache/web_application_cache_host_impl.cc',
      'child/appcache/web_application_cache_host_impl.h',
      'child/assert_matching_enums.cc',
      'child/background_sync/background_sync_provider_thread_proxy.cc',
      'child/background_sync/background_sync_provider_thread_proxy.h',
      'child/background_sync/background_sync_provider.cc',
      'child/background_sync/background_sync_provider.h',
      'child/background_sync/background_sync_type_converters.cc',
      'child/background_sync/background_sync_type_converters.h',
      'child/blink_platform_impl.cc',
      'child/blink_platform_impl.h',
      'child/bluetooth/bluetooth_dispatcher.cc',
      'child/bluetooth/bluetooth_dispatcher.h',
      'child/bluetooth/bluetooth_message_filter.cc',
      'child/bluetooth/bluetooth_message_filter.h',
      'child/bluetooth/web_bluetooth_impl.cc',
      'child/bluetooth/web_bluetooth_impl.h',
      'child/browser_font_resource_trusted.cc',
      'child/browser_font_resource_trusted.h',
      'child/child_discardable_shared_memory_manager.cc',
      'child/child_discardable_shared_memory_manager.h',
      'child/child_gpu_memory_buffer_manager.cc',
      'child/child_gpu_memory_buffer_manager.h',
      'child/child_histogram_message_filter.cc',
      'child/child_histogram_message_filter.h',
      'child/child_io_surface_manager_mac.cc',
      'child/child_io_surface_manager_mac.h',
      'child/child_message_filter.cc',
      'child/child_message_filter.h',
      'child/child_process.cc',
      'child/child_process.h',
      'child/child_resource_message_filter.cc',
      'child/child_resource_message_filter.h',
      'child/child_shared_bitmap_manager.cc',
      'child/child_shared_bitmap_manager.h',
      'child/child_thread_impl.cc',
      'child/child_thread_impl.h',
      'child/content_child_helpers.cc',
      'child/content_child_helpers.h',
      'child/database_util.cc',
      'child/database_util.h',
      'child/db_message_filter.cc',
      'child/db_message_filter.h',
      'child/file_info_util.cc',
      'child/file_info_util.h',
      'child/fileapi/file_system_dispatcher.cc',
      'child/fileapi/file_system_dispatcher.h',
      'child/fileapi/webfilesystem_impl.cc',
      'child/fileapi/webfilesystem_impl.h',
      'child/fileapi/webfilewriter_base.cc',
      'child/fileapi/webfilewriter_base.h',
      'child/fileapi/webfilewriter_impl.cc',
      'child/fileapi/webfilewriter_impl.h',
      'child/ftp_directory_listing_response_delegate.cc',
      'child/ftp_directory_listing_response_delegate.h',
      'child/geofencing/geofencing_dispatcher.cc',
      'child/geofencing/geofencing_dispatcher.h',
      'child/geofencing/geofencing_message_filter.cc',
      'child/geofencing/geofencing_message_filter.h',
      'child/geofencing/web_geofencing_provider_impl.cc',
      'child/geofencing/web_geofencing_provider_impl.h',
      'child/image_decoder.cc',
      'child/image_decoder.h',
      'child/indexed_db/indexed_db_dispatcher.cc',
      'child/indexed_db/indexed_db_dispatcher.h',
      'child/indexed_db/indexed_db_key_builders.cc',
      'child/indexed_db/indexed_db_key_builders.h',
      'child/indexed_db/indexed_db_message_filter.cc',
      'child/indexed_db/indexed_db_message_filter.h',
      'child/indexed_db/webidbcursor_impl.cc',
      'child/indexed_db/webidbcursor_impl.h',
      'child/indexed_db/webidbdatabase_impl.cc',
      'child/indexed_db/webidbdatabase_impl.h',
      'child/indexed_db/webidbfactory_impl.cc',
      'child/indexed_db/webidbfactory_impl.h',
      'child/mojo/mojo_application.cc',
      'child/mojo/mojo_application.h',
      'child/multipart_response_delegate.cc',
      'child/multipart_response_delegate.h',
      'child/navigator_connect/navigator_connect_dispatcher.cc',
      'child/navigator_connect/navigator_connect_dispatcher.h',
      'child/navigator_connect/navigator_connect_provider.cc',
      'child/navigator_connect/navigator_connect_provider.h',
      'child/notifications/notification_data_conversions.cc',
      'child/notifications/notification_data_conversions.h',
      'child/notifications/notification_dispatcher.cc',
      'child/notifications/notification_dispatcher.h',
      'child/notifications/notification_image_loader.cc',
      'child/notifications/notification_image_loader.h',
      'child/notifications/notification_manager.cc',
      'child/notifications/notification_manager.h',
      'child/notifications/pending_notifications_tracker.cc',
      'child/notifications/pending_notifications_tracker.h',
      'child/npapi/np_channel_base.cc',
      'child/npapi/np_channel_base.h',
      'child/npapi/npobject_base.h',
      'child/npapi/npobject_proxy.cc',
      'child/npapi/npobject_proxy.h',
      'child/npapi/npobject_stub.cc',
      'child/npapi/npobject_stub.h',
      'child/npapi/npobject_util.cc',
      'child/npapi/npobject_util.h',
      'child/npapi/npruntime_util.cc',
      'child/npapi/npruntime_util.h',
      'child/npapi/plugin_host.cc',
      'child/npapi/plugin_host.h',
      'child/npapi/plugin_instance.cc',
      'child/npapi/plugin_instance.h',
      'child/npapi/plugin_instance_mac.mm',
      'child/npapi/plugin_lib.cc',
      'child/npapi/plugin_lib.h',
      'child/npapi/plugin_stream.cc',
      'child/npapi/plugin_stream.h',
      'child/npapi/plugin_stream_posix.cc',
      'child/npapi/plugin_stream_url.cc',
      'child/npapi/plugin_stream_url.h',
      'child/npapi/plugin_stream_win.cc',
      'child/npapi/plugin_string_stream.cc',
      'child/npapi/plugin_string_stream.h',
      'child/npapi/plugin_url_fetcher.cc',
      'child/npapi/plugin_url_fetcher.h',
      'child/npapi/plugin_web_event_converter_mac.h',
      'child/npapi/plugin_web_event_converter_mac.mm',
      'child/npapi/webplugin.h',
      'child/npapi/webplugin_accelerated_surface_mac.h',
      'child/npapi/webplugin_delegate.h',
      'child/npapi/webplugin_delegate_impl.cc',
      'child/npapi/webplugin_delegate_impl.h',
      'child/npapi/webplugin_delegate_impl_android.cc',
      'child/npapi/webplugin_delegate_impl_aura.cc',
      'child/npapi/webplugin_delegate_impl_mac.mm',
      'child/npapi/webplugin_delegate_impl_win.cc',
      'child/npapi/webplugin_ime_win.cc',
      'child/npapi/webplugin_ime_win.h',
      'child/npapi/webplugin_resource_client.h',
      'child/permissions/permission_dispatcher.cc',
      'child/permissions/permission_dispatcher.h',
      'child/permissions/permission_dispatcher_thread_proxy.cc',
      'child/permissions/permission_dispatcher_thread_proxy.h',
      'child/permissions/permission_observers_registry.cc',
      'child/permissions/permission_observers_registry.h',
      'child/plugin_message_generator.cc',
      'child/plugin_message_generator.h',
      'child/plugin_messages.h',
      'child/plugin_param_traits.cc',
      'child/plugin_param_traits.h',
      'child/power_monitor_broadcast_source.cc',
      'child/power_monitor_broadcast_source.h',
      'child/push_messaging/push_dispatcher.cc',
      'child/push_messaging/push_dispatcher.h',
      'child/push_messaging/push_provider.cc',
      'child/push_messaging/push_provider.h',
      'child/quota_dispatcher.cc',
      'child/quota_dispatcher.h',
      'child/quota_message_filter.cc',
      'child/quota_message_filter.h',
      'child/request_extra_data.cc',
      'child/request_extra_data.h',
      'child/request_info.cc',
      'child/request_info.h',
      'child/resource_dispatcher.cc',
      'child/resource_dispatcher.h',
      'child/resource_scheduling_filter.cc',
      'child/resource_scheduling_filter.h',
      'child/runtime_features.cc',
      'child/runtime_features.h',
      'child/scoped_child_process_reference.cc',
      'child/scoped_child_process_reference.h',
      'child/shared_memory_received_data_factory.cc',
      'child/shared_memory_received_data_factory.h',
      'child/service_worker/service_worker_dispatcher.cc',
      'child/service_worker/service_worker_dispatcher.h',
      'child/service_worker/service_worker_handle_reference.cc',
      'child/service_worker/service_worker_handle_reference.h',
      'child/service_worker/service_worker_message_filter.cc',
      'child/service_worker/service_worker_message_filter.h',
      'child/service_worker/service_worker_network_provider.cc',
      'child/service_worker/service_worker_network_provider.h',
      'child/service_worker/service_worker_provider_context.cc',
      'child/service_worker/service_worker_provider_context.h',
      'child/service_worker/service_worker_registration_handle_reference.cc',
      'child/service_worker/service_worker_registration_handle_reference.h',
      'child/service_worker/web_service_worker_impl.cc',
      'child/service_worker/web_service_worker_impl.h',
      'child/service_worker/web_service_worker_provider_impl.cc',
      'child/service_worker/web_service_worker_provider_impl.h',
      'child/service_worker/web_service_worker_registration_impl.cc',
      'child/service_worker/web_service_worker_registration_impl.h',
      'child/shared_worker_devtools_agent.cc',
      'child/shared_worker_devtools_agent.h',
      'child/simple_webmimeregistry_impl.cc',
      'child/simple_webmimeregistry_impl.h',
      'child/site_isolation_policy.cc',
      'child/site_isolation_policy.h',
      'child/sync_load_response.cc',
      'child/sync_load_response.h',
      'child/thread_safe_sender.cc',
      'child/thread_safe_sender.h',
      'child/threaded_data_provider.cc',
      'child/threaded_data_provider.h',
      'child/v8_value_converter_impl.cc',
      'child/v8_value_converter_impl.h',
      'child/web_data_consumer_handle_impl.cc',
      'child/web_data_consumer_handle_impl.h',
      'child/web_database_observer_impl.cc',
      'child/web_database_observer_impl.h',
      'child/web_discardable_memory_impl.cc',
      'child/web_discardable_memory_impl.h',
      'child/web_memory_allocator_dump_impl.cc',
      'child/web_memory_allocator_dump_impl.h',
      'child/web_memory_dump_provider_adapter.cc',
      'child/web_memory_dump_provider_adapter.h',
      'child/web_process_memory_dump_impl.cc',
      'child/web_process_memory_dump_impl.h',
      'child/web_url_loader_impl.cc',
      'child/web_url_loader_impl.h',
      'child/web_url_request_util.cc',
      'child/web_url_request_util.h',
      'child/webblobregistry_impl.cc',
      'child/webblobregistry_impl.h',
      'child/webfallbackthemeengine_impl.cc',
      'child/webfallbackthemeengine_impl.h',
      'child/webfileutilities_impl.cc',
      'child/webfileutilities_impl.h',
      'child/webmessageportchannel_impl.cc',
      'child/webmessageportchannel_impl.h',
      'child/websocket_bridge.cc',
      'child/websocket_bridge.h',
      'child/websocket_dispatcher.cc',
      'child/websocket_dispatcher.h',
      'child/webthemeengine_impl_android.cc',
      'child/webthemeengine_impl_android.h',
      'child/webthemeengine_impl_default.cc',
      'child/webthemeengine_impl_default.h',
      'child/webthemeengine_impl_mac.h',
      'child/weburlresponse_extradata_impl.cc',
      'child/weburlresponse_extradata_impl.h',
      'child/worker_task_runner.cc',
      'child/worker_task_runner.h',
      'child/worker_thread_message_filter.cc',
      'child/worker_thread_message_filter.h',
    ],
  },
  'sources': [
    '<@(public_child_sources)',
    '<@(private_child_sources)',
  ],
  'conditions': [
    ['use_default_render_theme==0',
      {
        'sources/': [
          ['exclude', 'child/webthemeengine_impl_default.cc'],
          ['exclude', 'child/webthemeengine_impl_default.h'],
        ],
      }
    ],
    ['OS=="android"', {
      'dependencies': [
        '../build/android/ndk.gyp:cpu_features',
      ],
    }],
    ['enable_plugins==0', {
      'sources!': [
        'child/browser_font_resource_trusted.cc',
      ],
      'sources/': [
        ['exclude', '^child/npapi/plugin_'],
        ['exclude', '^child/npapi/webplugin_'],
      ],
    }],
    ['OS=="ios"', {
      'sources/': [
        # iOS only needs a small portion of content; exclude all the
        # implementation, and re-include what is used.
        ['exclude', '\\.(cc|mm)$'],
      ],
    }, {  # OS!="ios"
      'dependencies': [
        'app/resources/content_resources.gyp:content_resources',
        'app/strings/content_strings.gyp:content_strings',
        '../components/scheduler/scheduler.gyp:scheduler',
        '../storage/storage_common.gyp:storage_common',
        '../third_party/WebKit/public/blink.gyp:blink',
        '../third_party/WebKit/public/blink_resources.gyp:blink_image_resources',
        '../third_party/WebKit/public/blink_resources.gyp:blink_resources',
        '../third_party/npapi/npapi.gyp:npapi',
      ],
    }],
    ['use_aura==1', {
      'sources!': [
        'child/npapi/webplugin_delegate_impl_mac.mm',
      ],
    }],
    ['OS=="win"', {
      'sources!': [
        'child/npapi/webplugin_delegate_impl_aura.cc',
      ],
    }],
  ],
}
