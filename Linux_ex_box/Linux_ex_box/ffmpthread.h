#ifndef FFMPTHREAD_H
#define FFMPTHREAD_H

#include <QThread>

class ffmpthread : public QThread
{
    Q_OBJECT
public:
    explicit ffmpthread(QThread *parent = 0);
    
private:
    virtual void run();

signals:
    
public slots:
    
};

#endif // FFMPTHREAD_H
