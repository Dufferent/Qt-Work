#ifndef FFMPEG_H
#define FFMPEG_H

extern "C"{
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavdevice/avdevice.h"
#include "libavutil/imgutils.h"
#include "libswscale/swscale.h"
#include "libavutil/timestamp.h"
#include "libavutil/rational.h"

    //引入时间
#include "libavutil/time.h"
}


#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

/* extern */
int Rtmp_Start(cv::VideoCapture cam);


#endif // FFMPEG_H
