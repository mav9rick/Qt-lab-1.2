#ifndef LOGGER_H
#define LOGGER_H
#include <map>
#include <iostream>
#include <QObject>
#include <QString>
#include <QFileInfo>
#include <file.h>
#include <timer.h>
using namespace std;

class logger:public File
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
    void runcommand();
    QString getstring();
    void deleted();
    void starttimer();
    void stoptimer();
    void exit();
    void setfile();
private:
    QString command;
    std::map<QString, void(logger::*)()> commands;
signals:
    void createS();
    void deleteS();
    void getpathS();
    void starttimerS();
    void stoptimerS();
    void exitS();
    void setfileS();
    void updateS();
public slots:
    void getpathSL();
};












#endif // LOGGER_H
