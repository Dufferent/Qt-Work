#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QTimer>
#include <QTextEdit>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QToolBar>
#include <QProcess>
#include <QThread>

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

extern "C"{
#include "libavcodec/avcodec.h"
#include "libavdevice/avdevice.h"
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavformat/avio.h"
#include "libavutil/attributes.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avconfig.h"
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/buffer.h"
#include "libswresample/swresample.h"
#include "libswscale/swscale.h"
}

using namespace cv;

typedef struct cfd{
    QTcpSocket *cfd;
}CNode;

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    /* parameters */
    QPushButton *Camera;
    QPushButton *cam_stop;
    QPushButton *avideo;
    QPushButton *chat;
    QPushButton *Exit_Key;
    QLabel      *capimg;
    QLabel      *chat_ui;
    QTextEdit   *chat_rows;
    QTextEdit   *chat_send;
    QPushButton *send;

    QTimer      *cap_time;
    Mat          capture;
    VideoCapture cap;

    /* Tcp configure */
    QTcpServer *server;
    CNode       cnode[60];
    uint8_t     cct;
    QUdpSocket  *udp_socket;

    QLabel      *chklabel;
    QTextEdit   *chkedit;
    QLabel      *online;

    QProcess    *p;
private:
    Ui::MyMainWindow *ui;

public:
    void netcnt_del(CNode obj);

private slots:
    void cap_update();
    void cap_init();
    void Exit();
    void cap_stop();
};

#endif // MYMAINWINDOW_H
