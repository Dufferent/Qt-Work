#include "mymainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.resize(1024,600);//TFT LCD 1024*600
    w.show();

    return a.exec();
}
