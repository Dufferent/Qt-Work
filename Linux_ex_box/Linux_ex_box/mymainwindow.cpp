#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QDebug>


MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    Camera = new QPushButton(this);
    avideo = new QPushButton(this);
    chat = new QPushButton(this);
    Exit_Key = new QPushButton(this);
    cam_stop = new QPushButton(this);
    chat_ui  = new QLabel();
    chat_rows = new QTextEdit(chat_ui);
    chat_send = new QTextEdit(chat_ui);
    send = new QPushButton(chat_ui);

    capimg = new QLabel(this);
    /* configure */
    Camera->move(800,100);
    Camera->resize(80,30);
    Camera->setText(QString("CAM"));
    cam_stop->move(700,100);
    cam_stop->resize(80,30);
    cam_stop->setText(QString("CAM_STOP"));
    cam_stop->setDisabled(true);
    capimg->move(20,60);
    capimg->resize(640,480);
    Mat cvimg(640,480,CV_8UC3,Scalar(0,0,0));
    QImage img(cvimg.data,cvimg.cols,cvimg.rows,cvimg.step,QImage::Format_RGB888);
    capimg->setPixmap(QPixmap::fromImage(img));
    capimg->setScaledContents(true);
    capimg->show();
    cap_time = new QTimer(this);

    chat->move(800,140);
    chat->resize(80,30);
    chat->setText(QString("CHAT"));
    chat_ui->move(100,60);
    chat_ui->resize(600,500);
    chat_rows->move(10,10);
    chat_rows->resize(572,380);
    chat_rows->setReadOnly(true);
    chat_send->move(10,390);
    chat_send->resize(500,100);
    send->move(520,390);
    send->resize(80,30);
    send->setText(QString("&send"));

    Exit_Key->move(800,180);
    Exit_Key->resize(80,30);
    Exit_Key->setText(QString("Exit"));

    QToolBar *mytoolbar = new QToolBar(this);
    mytoolbar->move(0,0);
    mytoolbar->resize(1024,20);
    QAction *Action_1 = new QAction(mytoolbar);
    Action_1->setText(QString("check"));
    mytoolbar->addAction(Action_1);
    QAction *Action_2 = new QAction(mytoolbar);
    Action_2->setText(QString("collect"));
    mytoolbar->addAction(Action_2);
    QAction *Action_3 = new QAction(mytoolbar);
    Action_3->setText(QString("handsup"));
    mytoolbar->addAction(Action_3);

    /* Tcp server */
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,10860);
    cct = 0;
    udp_socket = new QUdpSocket(this);
    udp_socket->bind(QHostAddress::Any,10861);

    chklabel = new QLabel();
    chklabel->move(200,100);
    chklabel->resize(600,300);
    chkedit = new QTextEdit(chklabel);
    chkedit->move(10,10);
    chkedit->resize(580,260);
    chkedit->setReadOnly(true);
    online = new QLabel(chklabel);
    online->move(10,280);
    online->resize(100,10);
    online->setText(QString("online:%1").arg(cct));
    /* connect */
    connect(Camera,&QPushButton::clicked,this,&MyMainWindow::cap_init);
    connect(Exit_Key,&QPushButton::clicked,this,&MyMainWindow::Exit);
    connect(cam_stop,&QPushButton::clicked,this,&MyMainWindow::cap_stop);
    connect(chat,&QPushButton::clicked,
            [=](){
                    chat_ui->show();
                });
    connect(Action_1,&QAction::triggered,
            [=](){
                    chklabel->show();
                });

    connect(server,&QTcpServer::newConnection,
            [=](){
                    cnode[cct].cfd = new QTcpSocket(this);
                    cnode[cct].cfd = server->nextPendingConnection();
                    chkedit->append(QString("Ip:%1 Port:%2 State:on").arg(cnode[cct].cfd->peerAddress().toString()).arg(cnode[cct].cfd->peerPort()));
                    //chkedit->append(QString(" \n"));
                    netcnt_del(cnode[cct]);
                    cct++;
                    online->setText(QString("online:%1").arg(cct));
                });
    connect(send,&QPushButton::clicked,
            [=](){
                    chat_rows->append(QString("[local:10860]:%1").arg(chat_send->toPlainText()));
                    QByteArray tmp;
                    tmp.append(QString("chat##"));
                    tmp.append(chat_send->toPlainText().toUtf8());
                    udp_socket->writeDatagram(tmp,QHostAddress::Broadcast,8801);
                    chat_send->clear();
                });
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::cap_init()
{
    //system("ffmpeg -f video4linux2 -i /dev/video0 -f flv rtmp://0.0.0.0:1935/live/xny");
    p = new QProcess(this);
    p->start(QString("/home/ts/Git-Hub/Shell/grabx11.sh"));
    QThread::msleep(2000);
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
    connect(cap_time,&QTimer::timeout,this,&MyMainWindow::cap_update);
    cap_time->start(30);//5ms
    cam_stop->setEnabled(true);
}

void MyMainWindow::cap_update()
{
    cap.read(capture);
    cvtColor(capture,capture,CV_RGB2BGR);
    cv::resize(capture,capture,Size(640,480),0,0,INTER_LINEAR);
    if(!capture.empty())
    {
        QImage tmp(capture.data,capture.cols,capture.rows,capture.step,QImage::Format_RGB888);
        capimg->setPixmap(QPixmap::fromImage(tmp));
        capimg->setScaledContents(true);
        capimg->show();
    }
    cap_time->start(30);//5ms
}

void MyMainWindow::cap_stop()
{
    cap_time->stop();
    cam_stop->setDisabled(true);
    capture.release();
    cap.release();
    p->kill();
    p->close();
    p->destroyed(NULL);
}

void MyMainWindow::Exit()
{
    if(cap.isOpened())
    {
        cap_time->stop();
        cap.release();
    }
    exit(0);
}

void MyMainWindow::netcnt_del(CNode obj)
{
    connect(obj.cfd,&QTcpSocket::disconnected,
            [=](){
                    chkedit->append(QString("Ip:%1 Port:%2 State:off").arg(obj.cfd->peerAddress().toString()).arg(obj.cfd->peerPort()));
                    cct--;
                    online->setText(QString("online:%1").arg(cct));
                });
    connect(obj.cfd,&QTcpSocket::readyRead,
            [=](){
                    QByteArray rec = obj.cfd->readAll();
                    chat_rows->append(QString("[%1]:%2").arg(obj.cfd->peerAddress().toString()).arg(QString(rec)));
                    //chat_rows->append(QString(" \n"));
                });
    /*
    connect(send,&QPushButton::clicked,
            [=]()
                {
                    chat_rows->append(QString("[local:10860]:%1").arg(chat_send->toPlainText()));
                    obj.cfd->write(chat_send->toPlainText().toUtf8());
                });
    */
}
