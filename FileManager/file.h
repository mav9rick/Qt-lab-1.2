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
    int create();
    int del();
    int change();
    int addfile();
    void removefile();
    void check();
    void listfiles();
private:
    QVector<QString> pathlist;
    QVector<filestats> fileinfo;
signals:
    void deletedS();
    void changedS(int size, QString name , QString lastmod, bool exist);
    void createdS();
    void updateS();
    void testS();
    void fileinfoS(QString pathlist);
    void listfilesS(int n , QVector<QString> pathlist);
public slots:
    void checkSL();
};
#endif // FILE_H
