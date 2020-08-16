#include "server_widget.h"
#include "ui_server_widget.h"
#include "stdio.h"
#include "stdlib.h"

#define Listen_Port 8086

Server_Widget::Server_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server_Widget)
{
    ui->setupUi(this);
    Value_Init();
}

Server_Widget::~Server_Widget()
{
    delete ui;
}

void Server_Widget::Value_Init()
{
    /* background initure */
    backgd = new QLabel(this);
    backgd->move(0,0);
    backgd->resize(1024,600); //full lcd
    img.load("/home/graphes/backgd.jpg");
    backgd->setPixmap(QPixmap::fromImage(img));
    backgd->setScaledContents(true);//full Scaled
    \
    /* server win initure */
    online = new QTextEdit(this);
    exfile = new QTextEdit(this);
    online->move(80,80);
    online->resize(500,220);
    exfile->move(80,340);
    exfile->resize(500,220);
    online->setReadOnly(true);
    exfile->setReadOnly(true);
    online_text = new QLabel(this);
    exfile_text = new QLabel(this);
    online_text->move(80,50);
    online_text->resize(200,20);
    exfile_text->move(80,310);
    exfile_text->resize(200,20);
    online_text->setText("online members");
    exfile_text->setText("existed files");

    /* press ker initure */
    start = new QPushButton(this);
    stop  = new QPushButton(this);
    reject = new QPushButton(this);
    start->move(650,80);
    //each key distanse is 10mil
    stop->move(650,120);
    //each key distanse is 10mil
    reject->move(650,160);
    //each key distanse is 10mil
    start->resize(80,30);
    stop->resize(80,30);
    reject->resize(80,30);
    start->setText("start");
    stop->setText("stop");
    reject->setText("reject");

    /* chose mod initure */
    classroom = new QCheckBox(this);
    classroom->move(650,200);
    classroom->resize(150,30);
    classroom->setText("class mod");
    Teacher = new QCheckBox(this);
    Teacher->move(650,240);
    Teacher->resize(150,30);
    Teacher->setText("teacher mod");

    /* signal && slot */
    server_stat = 0;
    socket_stat = 0;
    start_stat = new QLabel(this);
    stop_stat = new QLabel(this);
    start_stat->move(750,80);
    stop_stat->move(750,120);
    start_stat->resize(100,30);
    stop_stat->resize(100,30);
    start_stat->setText("LISTEN OFF");
    stop_stat->setText("CONNECT OFF");

    connect(start,&QPushButton::clicked,this,&Server_Widget::Server_start);
    connect(reject,&QPushButton::clicked,this,&Server_Widget::exit);
    connect(stop,&QPushButton::clicked,this,&Server_Widget::offline);
}

void Server_Widget::Server_start()
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,Listen_Port);
    server_stat = 1;
    start_stat->setText("LISTEN ON");
    connect(server,&QTcpServer::newConnection,this,&Server_Widget::netconfig);
}

void Server_Widget::netconfig()
{
    server_stat = 1;
    stop_stat->setText("CONNECT ON");
    socket = new QTcpSocket(this);
    socket = server->nextPendingConnection();

    connect(socket,&QTcpSocket::disconnected,this,&Server_Widget::process);
    connect(socket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray recbuf = socket->readAll();
                //acquire recieve data
                static bool isStart = true;
                if(isStart == true)
                {
                    isStart = false;
                    //solove imformation
                    filename = QString(recbuf).section("##",0,0);
                    filesize = QString(recbuf).section("##",1,1).toInt();
                    recsize = 0;


                    //openfile
                    QString path = QString("/root/");
                    QString filepath = QString("%1%2").arg(path).arg(filename);
                    file.setFileName(filepath);

                    bool isOK = file.open(QIODevice::WriteOnly);
                    if(false == isOK)
                    {
                        qDebug() << "writingOnly error 130";
                    }
                }
                else //file info
                {
                    qint64 len = file.write(recbuf);
                    recsize += len;
                    if(recsize >= filesize)
                    {
                        file.close();
                        QMessageBox::information(this,"ok","recieve successful");
                    }

                }


            }
            );

    ip = socket->peerAddress().toString();
    port = socket->peerPort();
    online->setText(QString("IP:%1::PORT:%2::STAT:ONLINE\r\n").arg(ip).arg(port));
    socket_stat = 1;
    /* judge ip addr */
    char ipnum[20] = {0};
    sprintf(ipnum,"%s",ip.toUtf8().data());
    /* child ip number < 120 refused */
    if(((ipnum[10]-48)*100+(ipnum[11]-48)*10+(ipnum[12]-48)<120)&&Teacher->checkState())//teacher mod
    {
        socket->disconnectFromHost();//disconnect
        socket->close();//close socket
        socket_stat = 0;
        stop_stat->setText("CONNECT OFF");
        //server->close();//close server
        //server_stat = 0;

    }
    /* free mod */
    if(classroom->checkState())
    {
        /* do nothings */

    }
}

void Server_Widget::exit()
{
    static int exit_ct = 0;
    if(socket_stat)
    {
        socket->disconnectFromHost();
        socket->close();
        stop_stat->setText("CONNECT OFF");
    }
    if(server_stat)
    {
        server->close();
        start_stat->setText("LISTEN OFF");
    }
    if(exit_ct)
    {
        this->close();
        exit_ct = 0;
    }
    exit_ct = 1;
}

void Server_Widget::offline()
{
    if(socket_stat)
    {
        socket->disconnectFromHost();
        socket->close();
        stop_stat->setText("CONNECT OFF");
    }
    else
    {
        /* do nothings */
    }
}

void Server_Widget::process()
{
    online->setText(QString("IP:%1::PORT:%2::STAT:OFFLINE").arg(ip).arg(port));
    socket->close();//close socket
    socket_stat = 0;
    stop_stat->setText("CONNECT OFF");
}


