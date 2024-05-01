#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QCoreApplication>

class File:public QObject
{
    Q_OBJECT
public:
    File();
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
    bool exist = false;
    int size = 0;
    QString path = "None";
signals:
    void deletedS();
    void changedS();
    void createdS();
    void updateS();
public slots:
    void checkSL();
};
#endif // FILE_H
