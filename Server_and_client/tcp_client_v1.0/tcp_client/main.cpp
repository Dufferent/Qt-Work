#include "client_widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client_Widget w;
    w.resize(1024,600);
    w.setWindowTitle("Tcp_Client");
    w.show();
    
    return a.exec();
}
