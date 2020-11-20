//
// Created by sniper on 2020/11/19.
//

#ifndef FFMPEG_FFMPEGPLAYER_H
#define FFMPEG_FFMPEGPLAYER_H

#include <cstring>
#include <pthread.h>
#include <libavformat/avformat.h>
#include "MyLog.h"


class FFmpegPlayer {
public:
    FFmpegPlayer();

    FFmpegPlayer(const char *string);

    virtual ~FFmpegPlayer();

    void prepare();

    //一部准备资源
    void prepare_();

private:
    char *data_path = 0;
    pthread_t pit_prepare = 0;
    //媒体上下文
    AVFormatContext *avFormatContext = 0;


};


#endif //FFMPEG_FFMPEGPLAYER_H
