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
    int exit();
    QString getstring();
protected:

private:
    QString command;
    std::map<QString, void(logger::*)()> commands;
    File file;
signals:
    void createS();
    void deleteS();
    void changeS();
    void getpathS();
    void getexistS();
    void getsizeS();
public slots:
    void createSL();
    void delSL();
    void changeSL();
    void getpathSL();
    void getexistSL();
    void getsizeSL();
};

#endif // LOGGER_H
