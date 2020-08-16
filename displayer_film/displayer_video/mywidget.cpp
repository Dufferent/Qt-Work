#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QTimer>
#include <QPixmap>
/* world values */
QTimer *tim;
QLabel *label;


myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    tim = new QTimer(label);     /* 指针空间分配 */
    label = new QLabel(this);   /* 指针空间分配 */

    connect(tim,SIGNAL(timeout()),this,SLOT(update_evt()));
    tim->start();
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::update_evt()
{
    static int head_num = 0;
    char* file;
    file = (char*)malloc(sizeof(char)*50);
    sprintf(file,"%s%d%s","../frames/",head_num,".jpg");
    label->move(0,0);                        //label set
    label->setFixedWidth(1024);
    label->setFixedHeight(600);

    QPixmap pixmap;
    QPixmap pixshow;

    pixmap.load(QString(file));
    pixshow = pixmap.scaled(1024,600,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    /* 填充图片 */
    label->setPixmap(pixshow);
    head_num++;
    if(head_num == 86)
        head_num = 0;
    tim->start(15);   //fps = 1/0.015 ~= 66帧
}
