#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTextEdit>
#include <QImage>
#include <QPixmap>
#include <QCheckBox>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Server_Widget;
}

class Server_Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Server_Widget(QWidget *parent = 0);
    ~Server_Widget();
    
private:
    Ui::Server_Widget *ui;

public:
    QTcpServer *server;
    QTcpSocket *socket;
    QLabel     *backgd;
    QTextEdit  *online;
    QTextEdit  *exfile;
    QLabel     *online_text;
    QLabel     *exfile_text;
    QPushButton *start;
    QPushButton  *stop;
    QPushButton *reject;
    QLabel      *start_stat;
    QLabel      *stop_stat;
    QImage      img;
    //QPixmap     pixmap;
    QCheckBox   *classroom;
    QCheckBox   *Teacher;
    qint8        socket_stat;
    qint8        server_stat;
    QString      ip;
    qint16       port;
    QFile        file;
    QString      filename;
    qint64       filesize;
    qint64       recsize;

private slots:
    void Value_Init();
    void Server_start();
    void netconfig();
    void exit();
    void offline();
    void process();
};

#endif // SERVER_WIDGET_H
