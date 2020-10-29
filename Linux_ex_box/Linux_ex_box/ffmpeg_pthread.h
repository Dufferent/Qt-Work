#ifndef FFMPEG_PTHREAD_H
#define FFMPEG_PTHREAD_H

#include <QThread>

class ffmpeg_pthread : public QThread
{
    Q_OBJECT

public:
    ffmpeg_pthread();

private:
    virtual void run();

public:

    signals:


public slots:

};

#endif // FFMPEG_PTHREAD_H
