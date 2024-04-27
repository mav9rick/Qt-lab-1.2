#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QCoreApplication>

class File:public QObject
{
public:
    File();
    File(QString path);
    int create();
    int del();
    int change();
    bool getexist();
    int getsize();
    QString getpath();
    QString setfile();
protected:
    QString setpath(QString newpath);
    int setsize(int newsize);
    bool setexist(bool newexist);
private:
    bool exist;
    int size;
    QString path;
};
#endif // FILE_H
