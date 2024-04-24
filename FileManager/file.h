#ifndef FILE_H
#define FILE_H
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
    QString getpath();
    QString setpath();
    int getsize();
    bool getexist();
    void testmethod();
protected:
    bool exist;
    int size;
    QString path;
private:
};
#endif // FILE_H
