#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QImage>


/* world value */
QLabel *label;
QTimer *tim;



MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    label = new QLabel(this);//label的对象是MyWidget

    tim   = new QTimer(label);  /* 定时器设置*/
    connect(tim,SIGNAL(timeout()),this,SLOT(UpdateIm())); /* 链接信号槽 */
    tim->start();

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::UpdateIm()
{

       static int ct = 1;
       char* name;
       name = (char*)malloc(sizeof(char)*20);
       sprintf(name,"%s%d%s","/home/graphes/",ct,".jpg");

       label->move(0,0);                        //label set
       label->setFixedWidth(1024);
       label->setFixedHeight(600);

       /* 每次都要设置label大小 */
       QPixmap pixmap;
       QPixmap pixshow;
       pixmap.load(QString(name));
       pixshow = pixmap.scaled(1024, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       /* 填充图片 */
       label->setPixmap(pixshow);
       ct++;
       free(name);
       if(4 == ct)
           ct=1;
       tim->start(1000);
}

