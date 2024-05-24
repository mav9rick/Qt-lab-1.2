#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QCoreApplication>
#include <QString>
#include <QDir>
#include <iostream>
#include <QDateTime>
class reader: public QObject
{
    Q_OBJECT
public:
    reader();
signals:
    void input(QString);
    void comS(int n);
public slots:
    void readcommand();
    QString read();
};
class filestats:public QFileInfo
{
private:
    bool exist;
    int size;
    QDateTime timemod;
public:
    filestats(QString path);
    int check(QString newpath);
};
class File:public QObject
{
    Q_OBJECT
public:
    File(){};
    int create(QString path , QString name);
    int content(QString path , QString userInput);
    int del(QString filepath);
    int addfile(QString filepath);
    int removefile(QString filepath);
    void listfiles();
    static File& Instance()
    {
        static File i;
        return i;
    }
    reader r;
private:
    QVector<QString> pathlist;
    QVector<filestats> fileinfo;
signals:
    void deletedS();
    void changedS(int size, QString name , QString lastmod, bool exist);
    void createdS();
    void updateS();
    void fileinfoS(QString pathlist);
    void listfilesS(int n , QVector<QString> pathlist);
    void infoS(int i);
public slots:
    void checkSL();
};

#endif // FILE_H
