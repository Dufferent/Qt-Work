#include "ffmpthread.h"

ffmpthread::ffmpthread(QThread *parent) :
    QThread(parent)
{
}

void ffmpthread::run()
{
    while(1)
    {
        static int flag = 1;
        if(flag)
        {
            system("ffmpeg -f video4linux2 -i /dev/video0 -f flv rtmp://0.0.0.0:1935/live/xny");
            flag = 0;
        }
        QThread::msleep(30);
    }
}
