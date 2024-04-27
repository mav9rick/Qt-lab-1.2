#ifndef LOGGER_H
#define LOGGER_H
#include <map>
#include <iostream>
#include <QString>
#include <QFileInfo>
#include <file.h>
using namespace std;

class logger:public QObject
{
    Q_OBJECT
public:
    logger();
    void displayhelp();
    void createfile();
    void deletefile();
    void changefile();
    void getfilepath();
    void existfile();
    void sizefile();
    void runcommand(const QString &command);
    QString getstring();
private:
    QString command;
    std::map<QString, void(logger::*)()> commands;
    File file;
signals:
    void createS();
    void deleteS();
    void getpathS();
public slots:
    void createSL();
    void delSL();
    void getpathSL();
};
class Timer:public QCoreApplication
{
public:
    Timer(int &argc, char **argv) : QCoreApplication(argc, argv), tick(0) {}
protected:
    void start();
    void stop();
    void timerEvent(QTimerEvent*);
private:
    int tick;
signals:
    void check();
};











#endif // LOGGER_H
