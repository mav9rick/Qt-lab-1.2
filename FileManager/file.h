#ifndef FILE_H
#define FILE_H
#include "qwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>

class File:public QObject
{
    //Q_OBJECT
public:
    File();
    File(QString path);
    int create();
    int del();
    int change();
    void testmethod();
    QString setfile();
protected:
    bool exist;
    int size;
    QString path;
    int mytimer;
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    QString getpath();
    QString setpath(QString newpath);
    int getsize();
    int setsize(int newsize);
    bool getexist();
    bool setexist(bool newexist);
private:
};
#endif // FILE_H
