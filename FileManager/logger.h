#ifndef LOGGER_H
#define LOGGER_H
#include <map>
#include <iostream>
#include <QString>
using namespace std;

class logger
{
public:
    logger();
    void displayhelp();
    void createfile();
    void deletefile();
    void changefile();
    void getpath();
    void existfile();
    void sizefile();
    void runcommand(const QString &command);
    int exit();
    QString getstring();
    void setstring();
protected:

private:
    QString command;
    std::map<QString, void(logger::*)()> commands;

};

#endif // LOGGER_H
