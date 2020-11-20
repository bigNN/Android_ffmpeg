
//
// Created by sniper on 2020/11/20.
//

#ifndef FFMPEG_MYLOG_H
#define FFMPEG_MYLOG_H
#define LOG_TAG "bigNN"

#include <jni.h>
#include <error.h>
#include <android/log.h>
#include <string.h>

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGD(...)    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

#endif //FFMPEG_MYLOG_H
