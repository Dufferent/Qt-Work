#include "ffmpeg_pthread.h"

ffmpeg_pthread::ffmpeg_pthread()
{
    /* do nothing */
}

void run()
{
    system("ffmpeg -f video4linux2 -i /dev/video0 -f flv rtmp://0.0.0.0:1935/live/xny");
}
