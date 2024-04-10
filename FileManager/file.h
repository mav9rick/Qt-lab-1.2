#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>

class File:public QFile
{
public:
    File();
    File(QString path);
    int create();
    void del(QFileInfo filepath);
    int change();
    QString getpath();
    int getsize();
    bool getexist();
protected:
    bool exist;
    int size;
    QString path;
private:

};
#endif // FILE_H
