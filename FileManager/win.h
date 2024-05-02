#ifndef WIN_H
#define WIN_H
#include <QCoreApplication>
#include <logger.h>
#include <QObject>
#include <file.h>
#include <qthread.h>
#include <QTimer>
#include <iostream>
#include <QString>
using namespace std;
class reader: public QObject
{
    Q_OBJECT
public:
    reader();
protected:
signals:
    void commandInput(QString);
public slots:
    void listenCommand();
};
class win:public QCoreApplication
{
    Q_OBJECT
public:
    win(int argc, char*argv[]);
protected:
    void starttimer();
    void stoptimer();
    void execute();
    void timerEvent(QTimerEvent *event);
    QString getstring();
private:
    int timer;
    File myfile;
    logger loger;
    QThread thread;
    QTimer *newtimer = new QTimer(this);
    reader read;
signals:
    void updateSW();
    void runS();
    void userinputS(QString input);
};



#endif
