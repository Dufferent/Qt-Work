#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.resize(1024,600);/* 窗口大小 */
    w.show();

    return a.exec();
}
