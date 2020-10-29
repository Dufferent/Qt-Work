#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.resize(1024,600);
    w.show();

    
    return a.exec();
}
