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
    void runcommand(QString input);
    void fileinfo(int size, QString name , QString lastmod, bool exist);
    void list(int n,QVector<QString> pathlist);
    static logger& Instance()
    {
        static logger i;
        return i;
    }
    void info(int c);
private:
    QString command;
    map<QString, void(logger::*)()> commands;
signals:
    void createS();
    void deleteS();
    void starttimerS();
    void stoptimerS();
    void exitS();
    void addfileS();
    void removefileS();
    void readS();
    void userinput(QString input);
    void changefileS();
    void listS();
};












#endif // LOGGER_H
