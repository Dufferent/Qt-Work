#include "server_widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server_Widget w;
    w.resize(1024,600); //lcd size::1024x600
    w.setWindowTitle("Tcp_File_Server");
    w.show();
    
    return a.exec();
}
