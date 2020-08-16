#include "client_widget.h"
#include "ui_client_widget.h"
#include <QHostAddress>
#include <QFileDialog>
#include <QDebug>

Client_Widget::Client_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client_Widget)
{
    ui->setupUi(this);
    Win_Init();
}

Client_Widget::~Client_Widget()
{
    delete ui;
}

void Client_Widget::Win_Init()
{
    backbg = new QLabel(this);
    backbg->move(0,0);
    backbg->resize(1024,600);
    img.load("/home/graphes/backgd.jpg");
    backbg->setPixmap(QPixmap::fromImage(img));
    backbg->setScaledContents(true);

    host = new QLineEdit(this);
    port = new QLineEdit(this);
    host->move(100,50);
    host->resize(650,50);
    port->move(100,150);
    port->resize(650,50);
    host_text = new QLabel(this);
    port_text = new QLabel(this);
    host_text->move(20,50);
    port_text->move(20,150);
    host_text->resize(70,50);
    port_text->resize(70,50);
    host_text->setText("host");
    port_text->setText("port");

    cnt = new QPushButton(this);
    cnt->move(800,50);
    cnt->resize(150,50);
    cnt->setText("connect");

    send = new QPushButton(this);
    send->move(100,300);
    send->resize(150,50);
    send->setText("send");

    open = new QPushButton(this);
    open->move(300,300);
    open->resize(150,50);
    open->setText("open");

    exti = new QPushButton(this);
    exti->move(300,400);
    exti->resize(150,50);
    exti->setText("exti");

    cnt_stat = new QLabel(this);
    cnt_stat->move(500,300);
    cnt_stat->resize(100,50);
    cnt_stat->setText("disconnected");

    tim = new QTimer(this);

    cntbuf = 0;

    send->setEnabled(false);
    /* SIGNAL && SLOTS */
    connect(tim,&QTimer::timeout,this,&Client_Widget::send_date);

    connect(cnt,&QPushButton::clicked,
            [=]()
            {
                socket = new QTcpSocket(this);
                QString ip = host->text();
                qint64 pot = port->text().toInt();
                socket->connectToHost(QHostAddress(ip),pot);
                connect(socket,&QTcpSocket::connected,
                        [=]()
                        {
                             cnt_stat->setText("connected");
                             cntbuf = 1;
                        }
                        );
                connect(socket,&QTcpSocket::disconnected,
                        [=]()
                        {
                             cnt_stat->setText("disconnected");
                             cntbuf = 0;
                        }
                        );
            }
            );
    connect(exti,&QPushButton::clicked,
            [=]()
            {
                 if(cntbuf)
                 {
                     socket->disconnectFromHost();
                     socket->close();
                 }
                 this->close();
            }
            );

    connect(open,&QPushButton::clicked,
            [=]()
            {
                QString filepath = QFileDialog::getOpenFileName(this,"open","../s");
                if(false == filepath.isEmpty())
                {
                    //acquire file info
                    //readony
                    filename.clear();
                    filesize = 0;
                    QFileInfo info(filepath);
                    filename = info.fileName();
                    filesize = info.size();
                    sendsize = 0;
                    file.setFileName(filepath);

                    bool isOK = file.open(QIODevice::ReadOnly);
                    if( isOK == true )
                    {
                        send->setEnabled(true);
                        open->setEnabled(false);
                    }
                    else
                    {
                         printf("readonly openfile failed! 129");
                    }
                }
            }
            );

    connect(send,&QPushButton::clicked,
            [=]()
            {
                QString head = QString("%1##%2").arg(filename).arg(filesize);
                qint64 len   = socket->write(head.toUtf8());
                if(len > 0)
                {
                    tim->start(20);//20ms
                }
                else
                {
                    printf("info send failed! 149");
                    file.close();
                    open->setEnabled(true);
                    send->setEnabled(false);
                }

            }
            );
}

void Client_Widget::send_date()
{
    qint64 len;
    do{
        char buf[1024*4] = {0};
        len = 0;
        len = file.read(buf,sizeof(buf));
        socket->write(buf,len);
        sendsize += len;

    }while(len > 0);

    if(sendsize == filesize)
    {
        send->setText("finished");
        file.close();
    }
}








