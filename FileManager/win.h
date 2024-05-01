#ifndef WIN_H
#define WIN_H
#include <QCoreApplication>
#include <logger.h>
#include <QObject>
#include <file.h>
#include <qthread.h>
using namespace std;

class win:public QCoreApplication
{
    Q_OBJECT
public:
    win(int argc, char*argv[]);
protected:
    void starttimer();
    void stoptimer();
    int execute();
    void timerEvent(QTimerEvent *event);
private:
    int timer;
    File myfile;
    logger loger;
    QThread thread;
signals:
    void updateS();
    void runS();
};



#endif
