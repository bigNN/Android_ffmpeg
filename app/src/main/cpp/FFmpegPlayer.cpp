//
// Created by sniper on 2020/11/19.
//

#pragma once

#include "FFmpegPlayer.h"


void *threadTaskPrepare(void *pVoid) {
    FFmpegPlayer *fmpegPlayer = static_cast<FFmpegPlayer *>(pVoid);
    fmpegPlayer->prepare_();
    return 0;
}


FFmpegPlayer::FFmpegPlayer() {

}

FFmpegPlayer::~FFmpegPlayer() {


}

void FFmpegPlayer::prepare() {
    pthread_create(&this->pit_prepare, 0, threadTaskPrepare, this);
    LOGE("prepare");


}

void FFmpegPlayer::prepare_() {
    LOGE("prepare_ -------");
    this->avFormatContext = avformat_alloc_context();
    AVDictionary *dictionary = 0;
    av_dict_set(&dictionary, "timeout", "5000000", 0);

    av_dict_free(&dictionary);
    int ret = avformat_open_input(&this->avFormatContext, this->data_path, 0, &dictionary);
    if (ret) {
        LOGE("写JNI回调，告诉Java层，通知用户，你的播放流损坏的");
        return;
    }

    ret = avformat_find_stream_info(this->avFormatContext, 0);
    if (ret < 0) {
        LOGE("写JNI回调，告诉Java层，通知用户");
        return;
    }
    for (int i = 0; i < this->avFormatContext->nb_streams; i++) {

    }


}

FFmpegPlayer::FFmpegPlayer(const char *path_data) {
    this->data_path = new char[strlen(path_data) + 1];
    strcpy(this->data_path, path_data);
    LOGE("FFmpegPlayer");

}


