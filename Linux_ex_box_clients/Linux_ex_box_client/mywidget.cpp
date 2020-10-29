#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    bg = new QLabel(this);
    recblock = new QTextEdit(bg);
    sendblock = new QTextEdit(bg);
    send = new QPushButton(bg);
    link = new QPushButton(bg);
    screen = new QPushButton(bg);
    screen->move(920,500);
    screen->resize(80,30);
    screen->setText("screen");

    cap_time = new QTimer(this);

    Tsocket = new QTcpSocket(this);
    Usocket = new QUdpSocket(this);
    Tsocket->bind(QHostAddress::Any,8800);
    Usocket->bind(QHostAddress::Any,8801);

    bg->move(0,0);
    bg->resize(1024,600);

    recblock->move(10,10);
    recblock->resize(1000,380);
    recblock->setReadOnly(true);
    sendblock->move(10,400);
    sendblock->resize(900,190);
    send->move(920,400);
    send->resize(80,30);
    send->setText(QString("&send"));
    send->setDisabled(true);
    link->move(920,450);
    link->resize(80,30);
    link->setText(QString("&link"));

    connect(link,&QPushButton::clicked,
            [=](){
                    Tsocket->connectToHost(QHostAddress(QString("192.168.0.105")),10860);
                    QThread::msleep(30);
                    if(Tsocket->ConnectedState != 3)
                    {
                        QLabel *err = new QLabel();
                        err->move(452,260);
                        err->resize(120,80);
                        err->setText(QString("can't connect to host!"));
                    }
                    else
                    {
                        recblock->append(QString("Connect successful!"));
                        send->setEnabled(true);
                        connect(send,&QPushButton::clicked,
                                [=](){

                                        Tsocket->write(sendblock->toPlainText().toUtf8());
                                        recblock->append(QString("[local]:%1").arg(sendblock->toPlainText()));
                                        sendblock->clear();
                                    });
                    }
                });
    connect(Usocket,&QUdpSocket::readyRead,
            [=](){
                    QByteArray recieve;
                    while(Usocket->hasPendingDatagrams())
                    {
                        recieve.resize(Usocket->pendingDatagramSize());
                        Usocket->readDatagram(recieve.data(),recieve.size());
                    }
                    QString cmd_type = QString(recieve).section("##",0,0);
                    if(!QString::compare(QString("chat"),cmd_type))
                        recblock->append(QString("[server]:%1").arg(QString(recieve).section("##",1,1)));
                });

    connect(screen,&QPushButton::clicked,
            [=]()
                {
                    QLabel *src = new QLabel();
                    src->move(200,200);
                    src->resize(640,480);
                    cap.open("rtmp://192.168.0.105:1935/live/xny");
                    if(!cap.isOpened())
                    {
                        QLabel *error_msg;
                        error_msg = new QLabel();
                        error_msg->move(512-60,300-30);
                        error_msg->resize(160,100);
                        error_msg->setText(QString("cap open failed!"));
                        QPushButton *ok;
                        ok = new QPushButton(error_msg);
                        ok->move(60,60);
                        ok->resize(60,30);
                        ok->setText(QString("ok"));
                        error_msg->show();
                        connect(ok,&QPushButton::clicked,error_msg,&QLabel::hide);
                    }
                    connect(cap_time,&QTimer::timeout,[=](){
                        cap.read(capture);
                        cvtColor(capture,capture,CV_RGB2BGR);
                        cv::resize(capture,capture,Size(640,480),0,0,INTER_LINEAR);
                        if(!capture.empty())
                        {
                            QImage tmp(capture.data,capture.cols,capture.rows,capture.step,QImage::Format_RGB888);
                            src->setPixmap(QPixmap::fromImage(tmp));
                            src->setScaledContents(true);
                            src->show();
                        }
                        cap_time->start(30);//5ms
                    });
                    cap_time->start(30);//5ms
                });
}

myWidget::~myWidget()
{
    delete ui;
}
