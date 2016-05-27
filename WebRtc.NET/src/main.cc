
// GYP_DEFINES=component=shared_library

#pragma comment(lib,"crypt32.lib")
#pragma comment(lib,"iphlpapi.lib")
#pragma comment(lib,"secur32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dmoguids.lib")
#pragma comment(lib,"wmcodecdspuuid.lib")
#pragma comment(lib,"amstrmid.lib")
#pragma comment(lib,"msdmo.lib")
#pragma comment(lib,"Strmiids.lib")

#pragma comment(lib,"wininet.lib")
#pragma comment(lib,"dnsapi.lib")
#pragma comment(lib,"version.lib")
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"usp10.lib")
#pragma comment(lib,"psapi.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"shlwapi.lib")
#pragma comment(lib,"kernel32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"winspool.lib")
#pragma comment(lib,"comdlg32.lib")
#pragma comment(lib,"advapi32.lib")
#pragma comment(lib,"shell32.lib")
#pragma comment(lib,"ole32.lib")
#pragma comment(lib,"oleaut32.lib")
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"uuid.lib")
#pragma comment(lib,"odbc32.lib")
#pragma comment(lib,"odbccp32.lib")
#pragma comment(lib,"delayimp.lib")
#pragma comment(lib,"credui.lib")
#pragma comment(lib,"netapi32.lib")

#pragma comment(lib,"turbojpeg-static.lib")

#pragma comment(lib,"audioproc_debug_proto.lib")
#pragma comment(lib,"audio_coding_module.lib")
#pragma comment(lib,"audio_conference_mixer.lib")
#pragma comment(lib,"audio_decoder_factory_interface.lib")
#pragma comment(lib,"audio_decoder_interface.lib")
#pragma comment(lib,"audio_device.lib")
#pragma comment(lib,"audio_encoder_interface.lib")
#pragma comment(lib,"audio_processing.lib")
#pragma comment(lib,"audio_processing_sse2.lib")
#pragma comment(lib,"bitrate_controller.lib")
#pragma comment(lib,"boringssl.lib")
#pragma comment(lib,"boringssl_asm.lib")
#pragma comment(lib,"builtin_audio_decoder_factory.lib")
#pragma comment(lib,"cng.lib")
#pragma comment(lib,"common_audio.lib")
#pragma comment(lib,"common_audio_sse2.lib")
#pragma comment(lib,"common_video.lib")
#pragma comment(lib,"congestion_controller.lib")
#pragma comment(lib,"directshow_baseclasses.lib")
#pragma comment(lib,"expat.lib")
#pragma comment(lib,"field_trial_default.lib")
#pragma comment(lib,"g711.lib")
#pragma comment(lib,"g722.lib")
#pragma comment(lib,"genperf_libs.lib")
#pragma comment(lib,"ilbc.lib")
#pragma comment(lib,"isac.lib")
#pragma comment(lib,"isac_common.lib")
#pragma comment(lib,"jsoncpp.lib")
#pragma comment(lib,"libjingle_peerconnection.lib")
#pragma comment(lib,"libjpeg.lib")
#pragma comment(lib,"libsrtp.lib")
#pragma comment(lib,"libvpx.lib")
#pragma comment(lib,"libvpx_intrinsics_avx.lib")
#pragma comment(lib,"libvpx_intrinsics_avx2.lib")
#pragma comment(lib,"libvpx_intrinsics_mmx.lib")
#pragma comment(lib,"libvpx_intrinsics_sse2.lib")
#pragma comment(lib,"libvpx_intrinsics_sse4_1.lib")
#pragma comment(lib,"libvpx_intrinsics_ssse3.lib")
#pragma comment(lib,"libyuv.lib")
#pragma comment(lib,"media_file.lib")
#pragma comment(lib,"metrics_default.lib")
#pragma comment(lib,"neteq.lib")
#pragma comment(lib,"openmax_dl.lib")
#pragma comment(lib,"opus.lib")
#pragma comment(lib,"paced_sender.lib")
#pragma comment(lib,"pcm16b.lib")
#pragma comment(lib,"protobuf_lite.lib")
#pragma comment(lib,"red.lib")
#pragma comment(lib,"remote_bitrate_estimator.lib")
#pragma comment(lib,"rent_a_codec.lib")
#pragma comment(lib,"rtc_base.lib")
#pragma comment(lib,"rtc_base_approved.lib")
#pragma comment(lib,"rtc_event_log.lib")
#pragma comment(lib,"rtc_event_log_proto.lib")
#pragma comment(lib,"rtc_media.lib")
#pragma comment(lib,"rtc_p2p.lib")
#pragma comment(lib,"rtc_pc.lib")
#pragma comment(lib,"rtc_xmllite.lib")
#pragma comment(lib,"rtc_xmpp.lib")
#pragma comment(lib,"rtp_rtcp.lib")
#pragma comment(lib,"system_wrappers.lib")
#pragma comment(lib,"usrsctplib.lib")
#pragma comment(lib,"video_capture_module.lib")
#pragma comment(lib,"video_capture_module_internal_impl.lib")
#pragma comment(lib,"video_coding_utility.lib")
#pragma comment(lib,"video_processing.lib")
#pragma comment(lib,"video_processing_sse2.lib")
#pragma comment(lib,"voice_engine.lib")
#pragma comment(lib,"webrtc.lib")
#pragma comment(lib,"webrtc_common.lib")
#pragma comment(lib,"webrtc_h264.lib")
#pragma comment(lib,"webrtc_i420.lib")
#pragma comment(lib,"webrtc_opus.lib")
#pragma comment(lib,"webrtc_utility.lib")
#pragma comment(lib,"webrtc_video_coding.lib")
#pragma comment(lib,"webrtc_vp9.lib")

//#pragma comment(lib,"webrtc_vp8.lib")       // original
#pragma comment(lib,"webrtc_vp8_no_impl.lib") // for hacking vp8_impl.cc

#include "stdafx.h"

#include "webrtc/base/ssladapter.h"
#include "webrtc/base/win32socketinit.h"
#include "webrtc/base/win32socketserver.h"

void _InitializeSSL()
{
	rtc::EnsureWinsockInit();
	rtc::InitializeSSL(NULL);
}

void _CleanupSSL()
{
	rtc::CleanupSSL();
}

FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}