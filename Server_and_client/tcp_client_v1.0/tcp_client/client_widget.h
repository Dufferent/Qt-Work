#ifndef CLIENT_WIDGET_H
#define CLIENT_WIDGET_H

#include <QWidget>
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
#include <QLineEdit>

namespace Ui {
class Client_Widget;
}

class Client_Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Client_Widget(QWidget *parent = 0);
    ~Client_Widget();
    
private:
    Ui::Client_Widget *ui;

public:
    QLabel       *backbg;
    QLabel       *cnt_stat;
    QLabel       *host_text;
    QLabel       *port_text;
    QLineEdit    *host;
    QLineEdit    *port;
    QImage       img;
    QPushButton  *open;
    QPushButton  *send;
    QPushButton  *cnt;
    QPushButton  *exti;
    qint8        cntbuf;
    QTcpSocket   *socket;
    QFile        file;
    QString      filename;
    qint64       filesize;
    qint64       sendsize;
    QTimer       *tim;

private slots:
    void Win_Init();
    void send_date();

};

#endif // CLIENT_WIDGET_H
