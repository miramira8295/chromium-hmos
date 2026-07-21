/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ohos_adapter/ctocpp/ark_ohos_adapter_helper_ctocpp.h"

#include "base/ctocpp/ark_web_ctocpp_macros.h"
#include "ohos_adapter/bridge/ark_web_adapter_webcore_bridge_helper.h"
#include "ohos_adapter/ctocpp/ark_aafwk_app_mgr_client_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_access_token_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_audio_capturer_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_audio_codec_decoder_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_audio_renderer_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_audio_system_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_battery_mgr_client_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_camera_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_cert_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_datashare_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_date_time_format_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_display_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_drm_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_enterprise_device_management_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_event_handler_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_flowbuffer_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_hi_sys_event_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_hi_trace_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_iconsumer_surface_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_imfadapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_keystore_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_media_avsession_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_media_codec_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_media_codec_decoder_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_media_codec_list_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_migration_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_mmiadapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_native_image_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_net_connect_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_net_proxy_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_drawing_text_font_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_drawing_text_typography_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_image_decoder_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_init_web_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_native_buffer_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_resource_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_web_data_base_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_ohos_web_permission_data_base_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_paste_board_client_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_player_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_power_mgr_client_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_print_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_screen_capture_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_screenlock_manager_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_sensor_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_soc_perf_client_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_system_properties_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_vsync_adapter_ctocpp.h"
#include "ohos_adapter/ctocpp/ark_window_adapter_ctocpp.h"

namespace OHOS::ArkWeb {

using ArkOhosAdapterHelperGetInstanceFunc =
    ark_ohos_adapter_helper_t* (*)(void);
static ArkOhosAdapterHelperGetInstanceFunc
    ark_ohos_adapter_helper_get_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateAafwkAdapterFunc =
    ark_aafwk_app_mgr_client_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                                self);
static ArkOhosAdapterHelperCreateAafwkAdapterFunc
    ark_ohos_adapter_helper_create_aafwk_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateAafwkAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreatePowerMgrClientAdapterFunc =
    ark_power_mgr_client_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                            self);
static ArkOhosAdapterHelperCreatePowerMgrClientAdapterFunc
    ark_ohos_adapter_helper_create_power_mgr_client_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreatePowerMgrClientAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateDisplayMgrAdapterFunc =
    ark_display_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateDisplayMgrAdapterFunc
    ark_ohos_adapter_helper_create_display_mgr_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateDisplayMgrAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateBatteryClientAdapterFunc =
    ark_battery_mgr_client_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                              self);
static ArkOhosAdapterHelperCreateBatteryClientAdapterFunc
    ark_ohos_adapter_helper_create_battery_client_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateBatteryClientAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateNetConnectAdapterFunc =
    ark_net_connect_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateNetConnectAdapterFunc
    ark_ohos_adapter_helper_create_net_connect_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateNetConnectAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetOhosWebDataBaseAdapterInstanceFunc =
    ark_ohos_web_data_base_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                              self);
static ArkOhosAdapterHelperGetOhosWebDataBaseAdapterInstanceFunc
    ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance =
        reinterpret_cast<
            ArkOhosAdapterHelperGetOhosWebDataBaseAdapterInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetPasteBoardFunc =
    ark_paste_board_client_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                              self);
static ArkOhosAdapterHelperGetPasteBoardFunc
    ark_ohos_adapter_helper_get_paste_board =
        reinterpret_cast<ArkOhosAdapterHelperGetPasteBoardFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateAudioRendererAdapterFunc =
    ark_audio_renderer_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateAudioRendererAdapterFunc
    ark_ohos_adapter_helper_create_audio_renderer_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateAudioRendererAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateAudioCapturerAdapterFunc =
    ark_audio_capturer_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateAudioCapturerAdapterFunc
    ark_ohos_adapter_helper_create_audio_capturer_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateAudioCapturerAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetAudioSystemManagerFunc =
    ark_audio_system_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                                self);
static ArkOhosAdapterHelperGetAudioSystemManagerFunc
    ark_ohos_adapter_helper_get_audio_system_manager =
        reinterpret_cast<ArkOhosAdapterHelperGetAudioSystemManagerFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetWebPermissionDataBaseInstanceFunc =
    ark_ohos_web_permission_data_base_adapter_t* (*)(struct
                                                     _ark_ohos_adapter_helper_t*
                                                         self);
static ArkOhosAdapterHelperGetWebPermissionDataBaseInstanceFunc
    ark_ohos_adapter_helper_get_web_permission_data_base_instance =
        reinterpret_cast<
            ArkOhosAdapterHelperGetWebPermissionDataBaseInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateMMIAdapterFunc =
    ark_mmiadapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateMMIAdapterFunc
    ark_ohos_adapter_helper_create_mmiadapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateMMIAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateSocPerfClientAdapterFunc =
    ark_soc_perf_client_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateSocPerfClientAdapterFunc
    ark_ohos_adapter_helper_create_soc_perf_client_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateSocPerfClientAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetResourceAdapterFunc =
    ark_ohos_resource_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self,
                                     const ArkWebString* hapPath);
static ArkOhosAdapterHelperGetResourceAdapterFunc
    ark_ohos_adapter_helper_get_resource_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetResourceAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetSystemPropertiesInstanceFunc =
    ark_system_properties_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                             self);
static ArkOhosAdapterHelperGetSystemPropertiesInstanceFunc
    ark_ohos_adapter_helper_get_system_properties_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetSystemPropertiesInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetVSyncAdapterFunc =
    ark_vsync_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetVSyncAdapterFunc
    ark_ohos_adapter_helper_get_vsync_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetVSyncAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetInitWebAdapterFunc =
    ark_ohos_init_web_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetInitWebAdapterFunc
    ark_ohos_adapter_helper_get_init_web_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetInitWebAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetKeystoreAdapterInstanceFunc =
    ark_keystore_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetKeystoreAdapterInstanceFunc
    ark_ohos_adapter_helper_get_keystore_adapter_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetKeystoreAdapterInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetEnterpriseDeviceManagementInstanceFunc =
    ark_enterprise_device_management_adapter_t* (*)(struct
                                                    _ark_ohos_adapter_helper_t*
                                                        self);
static ArkOhosAdapterHelperGetEnterpriseDeviceManagementInstanceFunc
    ark_ohos_adapter_helper_get_enterprise_device_management_instance =
        reinterpret_cast<
            ArkOhosAdapterHelperGetEnterpriseDeviceManagementInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetDatashareInstanceFunc =
    ark_datashare_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetDatashareInstanceFunc
    ark_ohos_adapter_helper_get_datashare_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetDatashareInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateIMFAdapterFunc =
    ark_imfadapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateIMFAdapterFunc
    ark_ohos_adapter_helper_create_imfadapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateIMFAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetRootCertDataAdapterFunc =
    ark_cert_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetRootCertDataAdapterFunc
    ark_ohos_adapter_helper_get_root_cert_data_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetRootCertDataAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetAccessTokenAdapterInstanceFunc =
    ark_access_token_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetAccessTokenAdapterInstanceFunc
    ark_ohos_adapter_helper_get_access_token_adapter_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetAccessTokenAdapterInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetEventHandlerAdapterFunc =
    ark_event_handler_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetEventHandlerAdapterFunc
    ark_ohos_adapter_helper_get_event_handler_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetEventHandlerAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetPrintManagerInstanceFunc =
    ark_print_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetPrintManagerInstanceFunc
    ark_ohos_adapter_helper_get_print_manager_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetPrintManagerInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateConsumerSurfaceAdapterFunc =
    ark_iconsumer_surface_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                             self);
static ArkOhosAdapterHelperCreateConsumerSurfaceAdapterFunc
    ark_ohos_adapter_helper_create_consumer_surface_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateConsumerSurfaceAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreatePlayerAdapterFunc =
    ark_player_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreatePlayerAdapterFunc
    ark_ohos_adapter_helper_create_player_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreatePlayerAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetWindowAdapterInstanceFunc =
    ark_window_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetWindowAdapterInstanceFunc
    ark_ohos_adapter_helper_get_window_adapter_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetWindowAdapterInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetHiSysEventAdapterInstanceFunc =
    ark_hi_sys_event_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetHiSysEventAdapterInstanceFunc
    ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetHiSysEventAdapterInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetHiTraceAdapterInstanceFunc =
    ark_hi_trace_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetHiTraceAdapterInstanceFunc
    ark_ohos_adapter_helper_get_hi_trace_adapter_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetHiTraceAdapterInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetNetProxyInstanceFunc =
    ark_net_proxy_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetNetProxyInstanceFunc
    ark_ohos_adapter_helper_get_net_proxy_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetNetProxyInstanceFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetCameraManagerAdapterFunc =
    ark_camera_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetCameraManagerAdapterFunc
    ark_ohos_adapter_helper_get_camera_manager_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetCameraManagerAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateScreenCaptureAdapterFunc =
    ark_screen_capture_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateScreenCaptureAdapterFunc
    ark_ohos_adapter_helper_create_screen_capture_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateScreenCaptureAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateDateTimeFormatAdapterFunc =
    ark_date_time_format_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                            self);
static ArkOhosAdapterHelperCreateDateTimeFormatAdapterFunc
    ark_ohos_adapter_helper_create_date_time_format_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateDateTimeFormatAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateMediaCodecDecoderAdapterFunc =
    ark_media_codec_decoder_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                               self);
static ArkOhosAdapterHelperCreateMediaCodecDecoderAdapterFunc
    ark_ohos_adapter_helper_create_media_codec_decoder_adapter =
        reinterpret_cast<
            ArkOhosAdapterHelperCreateMediaCodecDecoderAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateNativeImageAdapterFunc =
    ark_native_image_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateNativeImageAdapterFunc
    ark_ohos_adapter_helper_create_native_image_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateNativeImageAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateMediaCodecEncoderAdapterFunc =
    ark_media_codec_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateMediaCodecEncoderAdapterFunc
    ark_ohos_adapter_helper_create_media_codec_encoder_adapter =
        reinterpret_cast<
            ArkOhosAdapterHelperCreateMediaCodecEncoderAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetMediaCodecListAdapterFunc =
    ark_media_codec_list_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                            self);
static ArkOhosAdapterHelperGetMediaCodecListAdapterFunc
    ark_ohos_adapter_helper_get_media_codec_list_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetMediaCodecListAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateFlowbufferAdapterFunc =
    ark_flowbuffer_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateFlowbufferAdapterFunc
    ark_ohos_adapter_helper_create_flowbuffer_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateFlowbufferAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateMediaAVSessionAdapterFunc =
    ark_media_avsession_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateMediaAVSessionAdapterFunc
    ark_ohos_adapter_helper_create_media_avsession_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateMediaAVSessionAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateOhosImageDecoderAdapterFunc =
    ark_ohos_image_decoder_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                              self);
static ArkOhosAdapterHelperCreateOhosImageDecoderAdapterFunc
    ark_ohos_adapter_helper_create_ohos_image_decoder_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateOhosImageDecoderAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateSensorAdapterFunc =
    ark_sensor_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateSensorAdapterFunc
    ark_ohos_adapter_helper_create_sensor_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateSensorAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperSetArkWebCoreHapPathOverrideFunc =
    void (*)(struct _ark_ohos_adapter_helper_t* self,
             const ArkWebString* hapPath);
static ArkOhosAdapterHelperSetArkWebCoreHapPathOverrideFunc
    ark_ohos_adapter_helper_set_ark_web_core_hap_path_override =
        reinterpret_cast<ArkOhosAdapterHelperSetArkWebCoreHapPathOverrideFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetOhosNativeBufferAdapterFunc =
    ark_ohos_native_buffer_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                              self);
static ArkOhosAdapterHelperGetOhosNativeBufferAdapterFunc
    ark_ohos_adapter_helper_get_ohos_native_buffer_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetOhosNativeBufferAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateMigrationMgrAdapterFunc =
    ark_migration_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                             self);
static ArkOhosAdapterHelperCreateMigrationMgrAdapterFunc
    ark_ohos_adapter_helper_create_migration_mgr_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateMigrationMgrAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateAudioCodecDecoderAdapterFunc =
    ark_audio_codec_decoder_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                               self);
static ArkOhosAdapterHelperCreateAudioCodecDecoderAdapterFunc
    ark_ohos_adapter_helper_create_audio_codec_decoder_adapter =
        reinterpret_cast<
            ArkOhosAdapterHelperCreateAudioCodecDecoderAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateDrmAdapterFunc =
    ark_drm_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperCreateDrmAdapterFunc
    ark_ohos_adapter_helper_create_drm_adapter =
        reinterpret_cast<ArkOhosAdapterHelperCreateDrmAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetOhosDrawingTextFontAdapterFunc =
    ark_ohos_drawing_text_font_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                                  self);
static ArkOhosAdapterHelperGetOhosDrawingTextFontAdapterFunc
    ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetOhosDrawingTextFontAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetOhosDrawingTextTypographyAdapterFunc =
    ark_ohos_drawing_text_typography_adapter_t* (*)(struct
                                                    _ark_ohos_adapter_helper_t*
                                                        self);
static ArkOhosAdapterHelperGetOhosDrawingTextTypographyAdapterFunc
    ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter =
        reinterpret_cast<
            ArkOhosAdapterHelperGetOhosDrawingTextTypographyAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperCreateScreenlockManagerAdapterFunc =
    ark_screenlock_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t*
                                              self);
static ArkOhosAdapterHelperCreateScreenlockManagerAdapterFunc
    ark_ohos_adapter_helper_create_screenlock_manager_adapter =
        reinterpret_cast<
            ArkOhosAdapterHelperCreateScreenlockManagerAdapterFunc>(
            ARK_WEB_INIT_ADDR);

using ArkOhosAdapterHelperGetCertManagerAdapterFunc =
    ark_cert_manager_adapter_t* (*)(struct _ark_ohos_adapter_helper_t* self);
static ArkOhosAdapterHelperGetCertManagerAdapterFunc
    ark_ohos_adapter_helper_get_cert_manager_adapter =
        reinterpret_cast<ArkOhosAdapterHelperGetCertManagerAdapterFunc>(
            ARK_WEB_INIT_ADDR);

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosAdapterHelper> ArkOhosAdapterHelper::GetInstance() {
  ARK_WEB_CTOCPP_DV_LOG();

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const char* funcName = "ark_ohos_adapter_helper_get_instance_static";
    ark_ohos_adapter_helper_get_instance =
        reinterpret_cast<ArkOhosAdapterHelperGetInstanceFunc>(
            ArkWebAdapterWebcoreBridgeHelper::GetInstance().LoadFuncSymbol(
                funcName));
  }

  if (!ark_ohos_adapter_helper_get_instance) {
    ARK_WEB_CTOCPP_WARN_LOG(
        "failed to load func ark_ohos_adapter_helper_get_instance_static");
    return nullptr;
  }

  // Execute
  ark_ohos_adapter_helper_t* _retval = ark_ohos_adapter_helper_get_instance();

  // Return type: refptr_same
  return ArkOhosAdapterHelperCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAafwkAppMgrClientAdapter>
ArkOhosAdapterHelperCToCpp::CreateAafwkAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_create_aafwk_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "E97aJC1bNGBDJFgMRkxv$w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_aafwk_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_aafwk_adapter)) {
        ark_ohos_adapter_helper_create_aafwk_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_aafwk_adapter =
            _struct->create_aafwk_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_aafwk_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateAafwkAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_aafwk_adapter, nullptr);

  // Execute
  ark_aafwk_app_mgr_client_adapter_t* _retval =
      ark_ohos_adapter_helper_create_aafwk_adapter(_struct);

  // Return type: refptr_same
  return ArkAafwkAppMgrClientAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPowerMgrClientAdapter>
ArkOhosAdapterHelperCToCpp::CreatePowerMgrClientAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_power_mgr_client_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "R3FwhGfupE8ZZxIYE1ZpgA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_power_mgr_client_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_power_mgr_client_adapter)) {
        ark_ohos_adapter_helper_create_power_mgr_client_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_power_mgr_client_adapter =
            _struct->create_power_mgr_client_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_power_mgr_client_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreatePowerMgrClientAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_power_mgr_client_adapter, nullptr);

  // Execute
  ark_power_mgr_client_adapter_t* _retval =
      ark_ohos_adapter_helper_create_power_mgr_client_adapter(_struct);

  // Return type: refptr_same
  return ArkPowerMgrClientAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkDisplayManagerAdapter>
ArkOhosAdapterHelperCToCpp::CreateDisplayMgrAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_display_mgr_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GyO5EK1iNuVy7vB$YBQN_Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_display_mgr_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_display_mgr_adapter)) {
        ark_ohos_adapter_helper_create_display_mgr_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_display_mgr_adapter =
            _struct->create_display_mgr_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_display_mgr_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateDisplayMgrAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_display_mgr_adapter, nullptr);

  // Execute
  ark_display_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_create_display_mgr_adapter(_struct);

  // Return type: refptr_same
  return ArkDisplayManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkBatteryMgrClientAdapter>
ArkOhosAdapterHelperCToCpp::CreateBatteryClientAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_battery_client_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "aoE8BbFouVkGt7ETFKurFA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_battery_client_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_battery_client_adapter)) {
        ark_ohos_adapter_helper_create_battery_client_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_battery_client_adapter =
            _struct->create_battery_client_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_battery_client_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateBatteryClientAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_battery_client_adapter, nullptr);

  // Execute
  ark_battery_mgr_client_adapter_t* _retval =
      ark_ohos_adapter_helper_create_battery_client_adapter(_struct);

  // Return type: refptr_same
  return ArkBatteryMgrClientAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkNetConnectAdapter>
ArkOhosAdapterHelperCToCpp::CreateNetConnectAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_net_connect_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wQOgdiSKSQBqLjXvbRIWGA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_net_connect_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_net_connect_adapter)) {
        ark_ohos_adapter_helper_create_net_connect_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_net_connect_adapter =
            _struct->create_net_connect_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_net_connect_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateNetConnectAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_net_connect_adapter, nullptr);

  // Execute
  ark_net_connect_adapter_t* _retval =
      ark_ohos_adapter_helper_create_net_connect_adapter(_struct);

  // Return type: refptr_same
  return ArkNetConnectAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosWebDataBaseAdapter>
ArkOhosAdapterHelperCToCpp::GetOhosWebDataBaseAdapterInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "BEGxUE05Frz9qETH0AWJRw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, get_ohos_web_data_base_adapter_instance)) {
        ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance =
            nullptr;
      } else {
        ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance =
            _struct->get_ohos_web_data_base_adapter_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance =
          reinterpret_cast<
              ArkOhosAdapterHelperGetOhosWebDataBaseAdapterInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance, nullptr);

  // Execute
  ark_ohos_web_data_base_adapter_t* _retval =
      ark_ohos_adapter_helper_get_ohos_web_data_base_adapter_instance(_struct);

  // Return type: refptr_same
  return ArkOhosWebDataBaseAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPasteBoardClientAdapter>
ArkOhosAdapterHelperCToCpp::GetPasteBoard() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_paste_board);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "N$R29S1IWfglydWp5rvUyw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member ark_ohos_adapter_helper_get_paste_board");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_paste_board)) {
        ark_ohos_adapter_helper_get_paste_board = nullptr;
      } else {
        ark_ohos_adapter_helper_get_paste_board = _struct->get_paste_board;
      }
    } else {
      ark_ohos_adapter_helper_get_paste_board =
          reinterpret_cast<ArkOhosAdapterHelperGetPasteBoardFunc>(func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_adapter_helper_get_paste_board,
                                    nullptr);

  // Execute
  ark_paste_board_client_adapter_t* _retval =
      ark_ohos_adapter_helper_get_paste_board(_struct);

  // Return type: refptr_same
  return ArkPasteBoardClientAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAudioRendererAdapter>
ArkOhosAdapterHelperCToCpp::CreateAudioRendererAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_audio_renderer_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "yqlgoxX5640sJgAm9$CsXg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_audio_renderer_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_audio_renderer_adapter)) {
        ark_ohos_adapter_helper_create_audio_renderer_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_audio_renderer_adapter =
            _struct->create_audio_renderer_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_audio_renderer_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateAudioRendererAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_audio_renderer_adapter, nullptr);

  // Execute
  ark_audio_renderer_adapter_t* _retval =
      ark_ohos_adapter_helper_create_audio_renderer_adapter(_struct);

  // Return type: refptr_same
  return ArkAudioRendererAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAudioCapturerAdapter>
ArkOhosAdapterHelperCToCpp::CreateAudioCapturerAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_audio_capturer_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GBxoOysbjcjE0_pVjcF1DA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_audio_capturer_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_audio_capturer_adapter)) {
        ark_ohos_adapter_helper_create_audio_capturer_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_audio_capturer_adapter =
            _struct->create_audio_capturer_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_audio_capturer_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateAudioCapturerAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_audio_capturer_adapter, nullptr);

  // Execute
  ark_audio_capturer_adapter_t* _retval =
      ark_ohos_adapter_helper_create_audio_capturer_adapter(_struct);

  // Return type: refptr_same
  return ArkAudioCapturerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAudioSystemManagerAdapter>
ArkOhosAdapterHelperCToCpp::GetAudioSystemManager() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_audio_system_manager);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "6fRDpdB1KLnlrUqbUfdJUQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_audio_system_manager");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_audio_system_manager)) {
        ark_ohos_adapter_helper_get_audio_system_manager = nullptr;
      } else {
        ark_ohos_adapter_helper_get_audio_system_manager =
            _struct->get_audio_system_manager;
      }
    } else {
      ark_ohos_adapter_helper_get_audio_system_manager =
          reinterpret_cast<ArkOhosAdapterHelperGetAudioSystemManagerFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_audio_system_manager, nullptr);

  // Execute
  ark_audio_system_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_get_audio_system_manager(_struct);

  // Return type: refptr_same
  return ArkAudioSystemManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosWebPermissionDataBaseAdapter>
ArkOhosAdapterHelperCToCpp::GetWebPermissionDataBaseInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_web_permission_data_base_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "1ZYXJEwD0CDWXs86Otok1g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_web_permission_data_base_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_web_permission_data_base_instance)) {
        ark_ohos_adapter_helper_get_web_permission_data_base_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_web_permission_data_base_instance =
            _struct->get_web_permission_data_base_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_web_permission_data_base_instance =
          reinterpret_cast<
              ArkOhosAdapterHelperGetWebPermissionDataBaseInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_web_permission_data_base_instance, nullptr);

  // Execute
  ark_ohos_web_permission_data_base_adapter_t* _retval =
      ark_ohos_adapter_helper_get_web_permission_data_base_instance(_struct);

  // Return type: refptr_same
  return ArkOhosWebPermissionDataBaseAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkMMIAdapter> ArkOhosAdapterHelperCToCpp::CreateMMIAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_create_mmiadapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Hrq7BzJ3YNMuEMrTte8k2w";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_mmiadapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_mmiadapter)) {
        ark_ohos_adapter_helper_create_mmiadapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_mmiadapter = _struct->create_mmiadapter;
      }
    } else {
      ark_ohos_adapter_helper_create_mmiadapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateMMIAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_adapter_helper_create_mmiadapter,
                                    nullptr);

  // Execute
  ark_mmiadapter_t* _retval =
      ark_ohos_adapter_helper_create_mmiadapter(_struct);

  // Return type: refptr_same
  return ArkMMIAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkSocPerfClientAdapter>
ArkOhosAdapterHelperCToCpp::CreateSocPerfClientAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_soc_perf_client_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "dANm50vVJogPZuciPsFk3Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_soc_perf_client_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_soc_perf_client_adapter)) {
        ark_ohos_adapter_helper_create_soc_perf_client_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_soc_perf_client_adapter =
            _struct->create_soc_perf_client_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_soc_perf_client_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateSocPerfClientAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_soc_perf_client_adapter, nullptr);

  // Execute
  ark_soc_perf_client_adapter_t* _retval =
      ark_ohos_adapter_helper_create_soc_perf_client_adapter(_struct);

  // Return type: refptr_same
  return ArkSocPerfClientAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosResourceAdapter>
ArkOhosAdapterHelperCToCpp::GetResourceAdapter(const ArkWebString& hapPath) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_resource_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Ngx64FZKKMAzYAabQTAbxA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_resource_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_resource_adapter)) {
        ark_ohos_adapter_helper_get_resource_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_resource_adapter =
            _struct->get_resource_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_resource_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetResourceAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_resource_adapter, nullptr);

  // Execute
  ark_ohos_resource_adapter_t* _retval =
      ark_ohos_adapter_helper_get_resource_adapter(_struct, &hapPath);

  // Return type: refptr_same
  return ArkOhosResourceAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkSystemPropertiesAdapter>
ArkOhosAdapterHelperCToCpp::GetSystemPropertiesInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_system_properties_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "wVcEHnlR0idUQ$lJjl1sXg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_system_properties_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_system_properties_instance)) {
        ark_ohos_adapter_helper_get_system_properties_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_system_properties_instance =
            _struct->get_system_properties_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_system_properties_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetSystemPropertiesInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_system_properties_instance, nullptr);

  // Execute
  ark_system_properties_adapter_t* _retval =
      ark_ohos_adapter_helper_get_system_properties_instance(_struct);

  // Return type: refptr_same
  return ArkSystemPropertiesAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkVSyncAdapter> ArkOhosAdapterHelperCToCpp::GetVSyncAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_vsync_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "K1wcLJQucsaWBwZ_L79oWg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_vsync_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_vsync_adapter)) {
        ark_ohos_adapter_helper_get_vsync_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_vsync_adapter = _struct->get_vsync_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_vsync_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetVSyncAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_adapter_helper_get_vsync_adapter,
                                    nullptr);

  // Execute
  ark_vsync_adapter_t* _retval =
      ark_ohos_adapter_helper_get_vsync_adapter(_struct);

  // Return type: refptr_same
  return ArkVSyncAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosInitWebAdapter>
ArkOhosAdapterHelperCToCpp::GetInitWebAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_init_web_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "IpIva$KWIJczRRz2fv7zCg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_init_web_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_init_web_adapter)) {
        ark_ohos_adapter_helper_get_init_web_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_init_web_adapter =
            _struct->get_init_web_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_init_web_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetInitWebAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_init_web_adapter, nullptr);

  // Execute
  ark_ohos_init_web_adapter_t* _retval =
      ark_ohos_adapter_helper_get_init_web_adapter(_struct);

  // Return type: refptr_same
  return ArkOhosInitWebAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkKeystoreAdapter>
ArkOhosAdapterHelperCToCpp::GetKeystoreAdapterInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_keystore_adapter_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "nlAo2PKj$ZVUFrTpXub82g";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_keystore_adapter_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_keystore_adapter_instance)) {
        ark_ohos_adapter_helper_get_keystore_adapter_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_keystore_adapter_instance =
            _struct->get_keystore_adapter_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_keystore_adapter_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetKeystoreAdapterInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_keystore_adapter_instance, nullptr);

  // Execute
  ark_keystore_adapter_t* _retval =
      ark_ohos_adapter_helper_get_keystore_adapter_instance(_struct);

  // Return type: refptr_same
  return ArkKeystoreAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkEnterpriseDeviceManagementAdapter>
ArkOhosAdapterHelperCToCpp::GetEnterpriseDeviceManagementInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_enterprise_device_management_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "ECPPabnbd_HqWo96LPTijw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_enterprise_device_management_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, get_enterprise_device_management_instance)) {
        ark_ohos_adapter_helper_get_enterprise_device_management_instance =
            nullptr;
      } else {
        ark_ohos_adapter_helper_get_enterprise_device_management_instance =
            _struct->get_enterprise_device_management_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_enterprise_device_management_instance =
          reinterpret_cast<
              ArkOhosAdapterHelperGetEnterpriseDeviceManagementInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_enterprise_device_management_instance,
      nullptr);

  // Execute
  ark_enterprise_device_management_adapter_t* _retval =
      ark_ohos_adapter_helper_get_enterprise_device_management_instance(
          _struct);

  // Return type: refptr_same
  return ArkEnterpriseDeviceManagementAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkDatashareAdapter>
ArkOhosAdapterHelperCToCpp::GetDatashareInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_datashare_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "s9GBPa_foScHGqWk$qr_Eg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_datashare_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_datashare_instance)) {
        ark_ohos_adapter_helper_get_datashare_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_datashare_instance =
            _struct->get_datashare_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_datashare_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetDatashareInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_datashare_instance, nullptr);

  // Execute
  ark_datashare_adapter_t* _retval =
      ark_ohos_adapter_helper_get_datashare_instance(_struct);

  // Return type: refptr_same
  return ArkDatashareAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkIMFAdapter> ArkOhosAdapterHelperCToCpp::CreateIMFAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_create_imfadapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "UnmSezpnmSiH2N7nULZaYQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_imfadapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_imfadapter)) {
        ark_ohos_adapter_helper_create_imfadapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_imfadapter = _struct->create_imfadapter;
      }
    } else {
      ark_ohos_adapter_helper_create_imfadapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateIMFAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_adapter_helper_create_imfadapter,
                                    nullptr);

  // Execute
  ark_imfadapter_t* _retval =
      ark_ohos_adapter_helper_create_imfadapter(_struct);

  // Return type: refptr_same
  return ArkIMFAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkCertManagerAdapter>
ArkOhosAdapterHelperCToCpp::GetRootCertDataAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_root_cert_data_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "QcJrYxO2Tvr7qsBiErMxjg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_root_cert_data_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_root_cert_data_adapter)) {
        ark_ohos_adapter_helper_get_root_cert_data_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_root_cert_data_adapter =
            _struct->get_root_cert_data_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_root_cert_data_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetRootCertDataAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_root_cert_data_adapter, nullptr);

  // Execute
  ark_cert_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_get_root_cert_data_adapter(_struct);

  // Return type: refptr_same
  return ArkCertManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAccessTokenAdapter>
ArkOhosAdapterHelperCToCpp::GetAccessTokenAdapterInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_access_token_adapter_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "S2iVo0NjhQZtdPqHBucpIw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_access_token_adapter_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_access_token_adapter_instance)) {
        ark_ohos_adapter_helper_get_access_token_adapter_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_access_token_adapter_instance =
            _struct->get_access_token_adapter_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_access_token_adapter_instance =
          reinterpret_cast<
              ArkOhosAdapterHelperGetAccessTokenAdapterInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_access_token_adapter_instance, nullptr);

  // Execute
  ark_access_token_adapter_t* _retval =
      ark_ohos_adapter_helper_get_access_token_adapter_instance(_struct);

  // Return type: refptr_same
  return ArkAccessTokenAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkEventHandlerAdapter>
ArkOhosAdapterHelperCToCpp::GetEventHandlerAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_event_handler_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "GSFYMnGpPHAGDo$0Jgx37Q";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_event_handler_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_event_handler_adapter)) {
        ark_ohos_adapter_helper_get_event_handler_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_event_handler_adapter =
            _struct->get_event_handler_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_event_handler_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetEventHandlerAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_event_handler_adapter, nullptr);

  // Execute
  ark_event_handler_adapter_t* _retval =
      ark_ohos_adapter_helper_get_event_handler_adapter(_struct);

  // Return type: refptr_same
  return ArkEventHandlerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPrintManagerAdapter>
ArkOhosAdapterHelperCToCpp::GetPrintManagerInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_print_manager_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EkPUScnoiEC2cC8dcu_VPA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_print_manager_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_print_manager_instance)) {
        ark_ohos_adapter_helper_get_print_manager_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_print_manager_instance =
            _struct->get_print_manager_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_print_manager_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetPrintManagerInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_print_manager_instance, nullptr);

  // Execute
  ark_print_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_get_print_manager_instance(_struct);

  // Return type: refptr_same
  return ArkPrintManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkIConsumerSurfaceAdapter>
ArkOhosAdapterHelperCToCpp::CreateConsumerSurfaceAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_consumer_surface_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "EOvyoLsZW0yRK6kCHC0w4A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_consumer_surface_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_consumer_surface_adapter)) {
        ark_ohos_adapter_helper_create_consumer_surface_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_consumer_surface_adapter =
            _struct->create_consumer_surface_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_consumer_surface_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperCreateConsumerSurfaceAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_consumer_surface_adapter, nullptr);

  // Execute
  ark_iconsumer_surface_adapter_t* _retval =
      ark_ohos_adapter_helper_create_consumer_surface_adapter(_struct);

  // Return type: refptr_same
  return ArkIConsumerSurfaceAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkPlayerAdapter>
ArkOhosAdapterHelperCToCpp::CreatePlayerAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_create_player_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "5oYPatVHHV_qW8cU4YLYrQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_player_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_player_adapter)) {
        ark_ohos_adapter_helper_create_player_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_player_adapter =
            _struct->create_player_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_player_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreatePlayerAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_player_adapter, nullptr);

  // Execute
  ark_player_adapter_t* _retval =
      ark_ohos_adapter_helper_create_player_adapter(_struct);

  // Return type: refptr_same
  return ArkPlayerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkWindowAdapter>
ArkOhosAdapterHelperCToCpp::GetWindowAdapterInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_window_adapter_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "KMn11B0xOToRU2CvKzYLZg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_window_adapter_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_window_adapter_instance)) {
        ark_ohos_adapter_helper_get_window_adapter_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_window_adapter_instance =
            _struct->get_window_adapter_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_window_adapter_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetWindowAdapterInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_window_adapter_instance, nullptr);

  // Execute
  ark_window_adapter_t* _retval =
      ark_ohos_adapter_helper_get_window_adapter_instance(_struct);

  // Return type: refptr_same
  return ArkWindowAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkHiSysEventAdapter>
ArkOhosAdapterHelperCToCpp::GetHiSysEventAdapterInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XRhcgX1C5XBFjp4btORdOQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_hi_sys_event_adapter_instance)) {
        ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance =
            _struct->get_hi_sys_event_adapter_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance =
          reinterpret_cast<
              ArkOhosAdapterHelperGetHiSysEventAdapterInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance, nullptr);

  // Execute
  ark_hi_sys_event_adapter_t* _retval =
      ark_ohos_adapter_helper_get_hi_sys_event_adapter_instance(_struct);

  // Return type: refptr_same
  return ArkHiSysEventAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkHiTraceAdapter>
ArkOhosAdapterHelperCToCpp::GetHiTraceAdapterInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_hi_trace_adapter_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "2tEg06Vv_9aIOZmhkVL8pQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_hi_trace_adapter_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_hi_trace_adapter_instance)) {
        ark_ohos_adapter_helper_get_hi_trace_adapter_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_hi_trace_adapter_instance =
            _struct->get_hi_trace_adapter_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_hi_trace_adapter_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetHiTraceAdapterInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_hi_trace_adapter_instance, nullptr);

  // Execute
  ark_hi_trace_adapter_t* _retval =
      ark_ohos_adapter_helper_get_hi_trace_adapter_instance(_struct);

  // Return type: refptr_same
  return ArkHiTraceAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkNetProxyAdapter>
ArkOhosAdapterHelperCToCpp::GetNetProxyInstance() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_net_proxy_instance);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Hs8HlZRIjkgLAc$MuHWYQg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_net_proxy_instance");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_net_proxy_instance)) {
        ark_ohos_adapter_helper_get_net_proxy_instance = nullptr;
      } else {
        ark_ohos_adapter_helper_get_net_proxy_instance =
            _struct->get_net_proxy_instance;
      }
    } else {
      ark_ohos_adapter_helper_get_net_proxy_instance =
          reinterpret_cast<ArkOhosAdapterHelperGetNetProxyInstanceFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_net_proxy_instance, nullptr);

  // Execute
  ark_net_proxy_adapter_t* _retval =
      ark_ohos_adapter_helper_get_net_proxy_instance(_struct);

  // Return type: refptr_same
  return ArkNetProxyAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkCameraManagerAdapter>
ArkOhosAdapterHelperCToCpp::GetCameraManagerAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_camera_manager_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "XrancXaJvvkE$vfEtpqgNA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_camera_manager_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_camera_manager_adapter)) {
        ark_ohos_adapter_helper_get_camera_manager_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_camera_manager_adapter =
            _struct->get_camera_manager_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_camera_manager_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetCameraManagerAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_camera_manager_adapter, nullptr);

  // Execute
  ark_camera_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_get_camera_manager_adapter(_struct);

  // Return type: refptr_same
  return ArkCameraManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkScreenCaptureAdapter>
ArkOhosAdapterHelperCToCpp::CreateScreenCaptureAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_screen_capture_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "u2NcxuIrrgSBVmc2xhOuFQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_screen_capture_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_screen_capture_adapter)) {
        ark_ohos_adapter_helper_create_screen_capture_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_screen_capture_adapter =
            _struct->create_screen_capture_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_screen_capture_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateScreenCaptureAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_screen_capture_adapter, nullptr);

  // Execute
  ark_screen_capture_adapter_t* _retval =
      ark_ohos_adapter_helper_create_screen_capture_adapter(_struct);

  // Return type: refptr_same
  return ArkScreenCaptureAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkDateTimeFormatAdapter>
ArkOhosAdapterHelperCToCpp::CreateDateTimeFormatAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_date_time_format_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "d7XmNeRSKjANj1WoEwpvXQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_date_time_format_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_date_time_format_adapter)) {
        ark_ohos_adapter_helper_create_date_time_format_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_date_time_format_adapter =
            _struct->create_date_time_format_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_date_time_format_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateDateTimeFormatAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_date_time_format_adapter, nullptr);

  // Execute
  ark_date_time_format_adapter_t* _retval =
      ark_ohos_adapter_helper_create_date_time_format_adapter(_struct);

  // Return type: refptr_same
  return ArkDateTimeFormatAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkMediaCodecDecoderAdapter>
ArkOhosAdapterHelperCToCpp::CreateMediaCodecDecoderAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_media_codec_decoder_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "Lt7mfGPt_tGdWX$PweZZIw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_media_codec_decoder_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_media_codec_decoder_adapter)) {
        ark_ohos_adapter_helper_create_media_codec_decoder_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_media_codec_decoder_adapter =
            _struct->create_media_codec_decoder_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_media_codec_decoder_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperCreateMediaCodecDecoderAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_media_codec_decoder_adapter, nullptr);

  // Execute
  ark_media_codec_decoder_adapter_t* _retval =
      ark_ohos_adapter_helper_create_media_codec_decoder_adapter(_struct);

  // Return type: refptr_same
  return ArkMediaCodecDecoderAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkNativeImageAdapter>
ArkOhosAdapterHelperCToCpp::CreateNativeImageAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_native_image_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "kNsXNvkX0rPdgSj8YwRReg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_native_image_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_native_image_adapter)) {
        ark_ohos_adapter_helper_create_native_image_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_native_image_adapter =
            _struct->create_native_image_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_native_image_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateNativeImageAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_native_image_adapter, nullptr);

  // Execute
  ark_native_image_adapter_t* _retval =
      ark_ohos_adapter_helper_create_native_image_adapter(_struct);

  // Return type: refptr_same
  return ArkNativeImageAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkMediaCodecAdapter>
ArkOhosAdapterHelperCToCpp::CreateMediaCodecEncoderAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_media_codec_encoder_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "PI1OxrTtld49NJ7xXuFQcQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_media_codec_encoder_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_media_codec_encoder_adapter)) {
        ark_ohos_adapter_helper_create_media_codec_encoder_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_media_codec_encoder_adapter =
            _struct->create_media_codec_encoder_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_media_codec_encoder_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperCreateMediaCodecEncoderAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_media_codec_encoder_adapter, nullptr);

  // Execute
  ark_media_codec_adapter_t* _retval =
      ark_ohos_adapter_helper_create_media_codec_encoder_adapter(_struct);

  // Return type: refptr_same
  return ArkMediaCodecAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkMediaCodecListAdapter>
ArkOhosAdapterHelperCToCpp::GetMediaCodecListAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_media_codec_list_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "oIuqa39Jcg8S4NFZ03ak4A";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_media_codec_list_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_media_codec_list_adapter)) {
        ark_ohos_adapter_helper_get_media_codec_list_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_media_codec_list_adapter =
            _struct->get_media_codec_list_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_media_codec_list_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetMediaCodecListAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_media_codec_list_adapter, nullptr);

  // Execute
  ark_media_codec_list_adapter_t* _retval =
      ark_ohos_adapter_helper_get_media_codec_list_adapter(_struct);

  // Return type: refptr_same
  return ArkMediaCodecListAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkFlowbufferAdapter>
ArkOhosAdapterHelperCToCpp::CreateFlowbufferAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_flowbuffer_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "gnpqGhl_TLaYpP5c6C_swA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_flowbuffer_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_flowbuffer_adapter)) {
        ark_ohos_adapter_helper_create_flowbuffer_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_flowbuffer_adapter =
            _struct->create_flowbuffer_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_flowbuffer_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateFlowbufferAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_flowbuffer_adapter, nullptr);

  // Execute
  ark_flowbuffer_adapter_t* _retval =
      ark_ohos_adapter_helper_create_flowbuffer_adapter(_struct);

  // Return type: refptr_same
  return ArkFlowbufferAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkMediaAVSessionAdapter>
ArkOhosAdapterHelperCToCpp::CreateMediaAVSessionAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_media_avsession_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "A6hqNqkOVd57uQRfTcYCxg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_media_avsession_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_media_avsession_adapter)) {
        ark_ohos_adapter_helper_create_media_avsession_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_media_avsession_adapter =
            _struct->create_media_avsession_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_media_avsession_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateMediaAVSessionAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_media_avsession_adapter, nullptr);

  // Execute
  ark_media_avsession_adapter_t* _retval =
      ark_ohos_adapter_helper_create_media_avsession_adapter(_struct);

  // Return type: refptr_same
  return ArkMediaAVSessionAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosImageDecoderAdapter>
ArkOhosAdapterHelperCToCpp::CreateOhosImageDecoderAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_ohos_image_decoder_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "9RkhXgsyaLiCbTPjR172zQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_ohos_image_decoder_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_ohos_image_decoder_adapter)) {
        ark_ohos_adapter_helper_create_ohos_image_decoder_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_ohos_image_decoder_adapter =
            _struct->create_ohos_image_decoder_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_ohos_image_decoder_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperCreateOhosImageDecoderAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_ohos_image_decoder_adapter, nullptr);

  // Execute
  ark_ohos_image_decoder_adapter_t* _retval =
      ark_ohos_adapter_helper_create_ohos_image_decoder_adapter(_struct);

  // Return type: refptr_same
  return ArkOhosImageDecoderAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkSensorAdapter>
ArkOhosAdapterHelperCToCpp::CreateSensorAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_create_sensor_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "u4xixVRfYYnEidq9joVfnA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_sensor_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_sensor_adapter)) {
        ark_ohos_adapter_helper_create_sensor_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_sensor_adapter =
            _struct->create_sensor_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_sensor_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateSensorAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_sensor_adapter, nullptr);

  // Execute
  ark_sensor_adapter_t* _retval =
      ark_ohos_adapter_helper_create_sensor_adapter(_struct);

  // Return type: refptr_same
  return ArkSensorAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
void ArkOhosAdapterHelperCToCpp::SetArkWebCoreHapPathOverride(
    const ArkWebString& hapPath) {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, ARK_WEB_RETURN_VOID);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_set_ark_web_core_hap_path_override);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "pu4PimdMHQE_9Al_H2_siw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_set_ark_web_core_hap_path_override");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      set_ark_web_core_hap_path_override)) {
        ark_ohos_adapter_helper_set_ark_web_core_hap_path_override = nullptr;
      } else {
        ark_ohos_adapter_helper_set_ark_web_core_hap_path_override =
            _struct->set_ark_web_core_hap_path_override;
      }
    } else {
      ark_ohos_adapter_helper_set_ark_web_core_hap_path_override =
          reinterpret_cast<
              ArkOhosAdapterHelperSetArkWebCoreHapPathOverrideFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_set_ark_web_core_hap_path_override,
      ARK_WEB_RETURN_VOID);

  // Execute
  ark_ohos_adapter_helper_set_ark_web_core_hap_path_override(_struct, &hapPath);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosNativeBufferAdapter>
ArkOhosAdapterHelperCToCpp::GetOhosNativeBufferAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_ohos_native_buffer_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "8GKPO0DF3Apu6YM$8j_TEA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_ohos_native_buffer_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_ohos_native_buffer_adapter)) {
        ark_ohos_adapter_helper_get_ohos_native_buffer_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_ohos_native_buffer_adapter =
            _struct->get_ohos_native_buffer_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_ohos_native_buffer_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetOhosNativeBufferAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_ohos_native_buffer_adapter, nullptr);

  // Execute
  ark_ohos_native_buffer_adapter_t* _retval =
      ark_ohos_adapter_helper_get_ohos_native_buffer_adapter(_struct);

  // Return type: refptr_same
  return ArkOhosNativeBufferAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkMigrationManagerAdapter>
ArkOhosAdapterHelperCToCpp::CreateMigrationMgrAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_migration_mgr_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "i2ItsD8DUnfN4luJxLvbaw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_migration_mgr_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_migration_mgr_adapter)) {
        ark_ohos_adapter_helper_create_migration_mgr_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_migration_mgr_adapter =
            _struct->create_migration_mgr_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_migration_mgr_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateMigrationMgrAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_migration_mgr_adapter, nullptr);

  // Execute
  ark_migration_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_create_migration_mgr_adapter(_struct);

  // Return type: refptr_same
  return ArkMigrationManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkAudioCodecDecoderAdapter>
ArkOhosAdapterHelperCToCpp::CreateAudioCodecDecoderAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_audio_codec_decoder_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "VOqM7Pes22T9dtce0Tv3bg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_audio_codec_decoder_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_audio_codec_decoder_adapter)) {
        ark_ohos_adapter_helper_create_audio_codec_decoder_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_audio_codec_decoder_adapter =
            _struct->create_audio_codec_decoder_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_audio_codec_decoder_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperCreateAudioCodecDecoderAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_audio_codec_decoder_adapter, nullptr);

  // Execute
  ark_audio_codec_decoder_adapter_t* _retval =
      ark_ohos_adapter_helper_create_audio_codec_decoder_adapter(_struct);

  // Return type: refptr_same
  return ArkAudioCodecDecoderAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkDrmAdapter> ArkOhosAdapterHelperCToCpp::CreateDrmAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_create_drm_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "h$Zj67JKbfiZpIBLqVhhPQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_drm_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, create_drm_adapter)) {
        ark_ohos_adapter_helper_create_drm_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_drm_adapter =
            _struct->create_drm_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_drm_adapter =
          reinterpret_cast<ArkOhosAdapterHelperCreateDrmAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(ark_ohos_adapter_helper_create_drm_adapter,
                                    nullptr);

  // Execute
  ark_drm_adapter_t* _retval =
      ark_ohos_adapter_helper_create_drm_adapter(_struct);

  // Return type: refptr_same
  return ArkDrmAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosDrawingTextFontAdapter>
ArkOhosAdapterHelperCToCpp::GetOhosDrawingTextFontAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "HpmB00mFhpuZjlopR6XnIA";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      get_ohos_drawing_text_font_adapter)) {
        ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter =
            _struct->get_ohos_drawing_text_font_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperGetOhosDrawingTextFontAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter, nullptr);

  // Execute
  ark_ohos_drawing_text_font_adapter_t* _retval =
      ark_ohos_adapter_helper_get_ohos_drawing_text_font_adapter(_struct);

  // Return type: refptr_same
  return ArkOhosDrawingTextFontAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkOhosDrawingTextTypographyAdapter>
ArkOhosAdapterHelperCToCpp::GetOhosDrawingTextTypographyAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "DsSnRkpd1nyvYX4pgRdiFg";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(
              _struct, get_ohos_drawing_text_typography_adapter)) {
        ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter =
            nullptr;
      } else {
        ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter =
            _struct->get_ohos_drawing_text_typography_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperGetOhosDrawingTextTypographyAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter,
      nullptr);

  // Execute
  ark_ohos_drawing_text_typography_adapter_t* _retval =
      ark_ohos_adapter_helper_get_ohos_drawing_text_typography_adapter(_struct);

  // Return type: refptr_same
  return ArkOhosDrawingTextTypographyAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkScreenlockManagerAdapter>
ArkOhosAdapterHelperCToCpp::CreateScreenlockManagerAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer = reinterpret_cast<void*>(
      ark_ohos_adapter_helper_create_screenlock_manager_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "NEH$kEVWkO7cvSnFFxLYLw";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_create_screenlock_manager_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct,
                                      create_screenlock_manager_adapter)) {
        ark_ohos_adapter_helper_create_screenlock_manager_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_create_screenlock_manager_adapter =
            _struct->create_screenlock_manager_adapter;
      }
    } else {
      ark_ohos_adapter_helper_create_screenlock_manager_adapter =
          reinterpret_cast<
              ArkOhosAdapterHelperCreateScreenlockManagerAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_create_screenlock_manager_adapter, nullptr);

  // Execute
  ark_screenlock_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_create_screenlock_manager_adapter(_struct);

  // Return type: refptr_same
  return ArkScreenlockManagerAdapterCToCpp::Invert(_retval);
}

ARK_WEB_NO_SANITIZE
ArkWebRefPtr<ArkCertManagerAdapter>
ArkOhosAdapterHelperCToCpp::GetCertManagerAdapter() {
  ARK_WEB_CTOCPP_DV_LOG("capi struct is %{public}ld", (long)this);

  ark_ohos_adapter_helper_t* _struct = GetStruct();
  ARK_WEB_CTOCPP_CHECK_PARAM(_struct, nullptr);

  void* func_pointer =
      reinterpret_cast<void*>(ark_ohos_adapter_helper_get_cert_manager_adapter);
  if (func_pointer == ARK_WEB_INIT_ADDR) {
    static const std::string funcName = "qpW3q2vhBXxZOYZKs2GUsQ";
    func_pointer =
        ArkWebAdapterWebcoreBridgeHelper::GetInstance()
            .CheckFuncMemberForCaller(ARK_OHOS_ADAPTER_HELPER, funcName);
    if (func_pointer == ARK_WEB_INIT_ADDR) {
      ARK_WEB_CTOCPP_DV_LOG(
          "failed to find func member "
          "ark_ohos_adapter_helper_get_cert_manager_adapter");
      if (ARK_WEB_FUNC_MEMBER_MISSING(_struct, get_cert_manager_adapter)) {
        ark_ohos_adapter_helper_get_cert_manager_adapter = nullptr;
      } else {
        ark_ohos_adapter_helper_get_cert_manager_adapter =
            _struct->get_cert_manager_adapter;
      }
    } else {
      ark_ohos_adapter_helper_get_cert_manager_adapter =
          reinterpret_cast<ArkOhosAdapterHelperGetCertManagerAdapterFunc>(
              func_pointer);
    }
  }

  ARK_WEB_CTOCPP_CHECK_FUNC_POINTER(
      ark_ohos_adapter_helper_get_cert_manager_adapter, nullptr);

  // Execute
  ark_cert_manager_adapter_t* _retval =
      ark_ohos_adapter_helper_get_cert_manager_adapter(_struct);

  // Return type: refptr_same
  return ArkCertManagerAdapterCToCpp::Invert(_retval);
}

ArkOhosAdapterHelperCToCpp::ArkOhosAdapterHelperCToCpp() {}

ArkOhosAdapterHelperCToCpp::~ArkOhosAdapterHelperCToCpp() {}

template <>
ArkWebBridgeType
    ArkWebCToCppRefCounted<ArkOhosAdapterHelperCToCpp,
                           ArkOhosAdapterHelper,
                           ark_ohos_adapter_helper_t>::kBridgeType =
        ARK_OHOS_ADAPTER_HELPER;

}  // namespace OHOS::ArkWeb
