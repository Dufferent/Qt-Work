#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTextEdit>
#include <QTime>
#include <QTimer>


#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

using namespace cv;

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();
    /* @parm */
    QLabel *bg;
    QTextEdit *recblock;
    QTextEdit *sendblock;
    QPushButton *send;
    QPushButton *link;
    QPushButton *screen;
    QTcpSocket  *Tsocket;
    QUdpSocket  *Usocket;

    QTimer      *cap_time;
    Mat          capture;
    VideoCapture cap;
private:
    Ui::myWidget *ui;
};

#endif // MYWIDGET_H
