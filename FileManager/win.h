#ifndef WIN_H
#define WIN_H
#include <QCoreApplication>
#include <logger.h>
#include <QObject>
#include <file.h>
#include <qthread.h>
#include <QTimer>
#include <QString>
using namespace std;

class win:public QCoreApplication
{
    Q_OBJECT
public:
    win(int argc, char*argv[]);
protected:
    void starttimer();
    void stoptimer();
    void execute();
private:
    File &myfile = File::Instance();
    logger &loger = logger::Instance();
    QThread thread;
    QTimer *newtimer = new QTimer(this);
signals:
    void updateSW();
    void runS();
    void userinputS(QString input);
};



#endif
