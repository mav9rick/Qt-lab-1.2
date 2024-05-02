#ifndef LOGGER_H
#define LOGGER_H
#include <map>
#include <QObject>
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
    void runcommand(QString input);
    void fileinfo(int size, QString name , QString lastmod, bool exist);
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
    void readS();
    void userinput(QString input);
public slots:
    void getpathSL();
};












#endif // LOGGER_H
