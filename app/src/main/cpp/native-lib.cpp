#include <jni.h>
#include <string>

#include "FFmpegPlayer.h"
#include "MyLog.h"

extern "C" {
#include <libavutil/avutil.h>
#include <libavformat/avformat.h>
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_chris_ffmpeg_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from ffmpeg version: ";
    hello.append(av_version_info());
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT void JNICALL
Java_com_chris_ffmpeg_FFmpegPlayer_parpareNative(JNIEnv *env, jobject thiz, jstring data) {


    const char *path_data = env->GetStringUTFChars(data, NULL);
    LOGD("准备  path： %s\n", data);
    FFmpegPlayer *pFFmpegPlayer = new FFmpegPlayer(path_data);
    pFFmpegPlayer->prepare();
    env->ReleaseStringUTFChars(data, path_data);

}extern "C"
JNIEXPORT void JNICALL
Java_com_chris_ffmpeg_FFmpegPlayer_startNative(JNIEnv *env, jobject thiz) {
    // TODO: implement startNative()
}extern "C"
JNIEXPORT void JNICALL
Java_com_chris_ffmpeg_FFmpegPlayer_stopNative(JNIEnv *env, jobject thiz) {
    // TODO: implement stopNative()
}extern "C"
JNIEXPORT void JNICALL
Java_com_chris_ffmpeg_FFmpegPlayer_releaseNative(JNIEnv *env, jobject thiz) {
    // TODO: implement releaseNative()
}extern "C"
JNIEXPORT void JNICALL
Java_com_chris_ffmpeg_FFmpegPlayer_setSurfaceViewNative(JNIEnv *env, jobject thiz,
                                                        jobject surface) {
    // TODO: implement setSurfaceViewNative()
}