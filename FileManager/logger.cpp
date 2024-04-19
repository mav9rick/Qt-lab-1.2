#include "logger.h"
#include <iostream>
#include <map>
#include <QTextStream>

using namespace std;
logger::logger()
{
    commands["/help"] = &logger::displayhelp;
    //commands["/exit"] = &logger::exit;
    commands["/createfile"] = &logger::createfile;
    commands["/deletefile"] = &logger::deletefile;
    commands["/changefile"] = &logger::changefile;
    commands["/getpath"] = &logger::getpath;
    commands["/existfile"] = &logger::existfile;
    commands["/sizefile"] = &logger::sizefile;
}
void logger::displayhelp()
{
    cout << "Доступные команды:" <<  endl;
    cout << "/help - отобразить список доступных команд" <<  endl;
    cout << "/exit - завершить программу" <<  endl;
    cout << "/createfile - создать файл" <<  endl;
    cout << "/deletefile - удалить файл" <<  endl;
    cout << "/changefile - изменить файл" <<  endl;
    cout << "/getpath- вернуть путь к файлу" <<  endl;
    cout << "/existfile - проверить существование файла" <<  endl;
    cout << "/sizefile - узнать размер файла" <<  endl;
}
//int logger::exit()
//{
//cout << "Завершение программы" << endl;
//return -1;
//}
void logger::createfile()
{
    cout << "createfile" << endl;
}
void logger::deletefile()
{
    cout << "deletefile" << endl;
}
void logger::getpath()
{
    cout << "getpath" << endl;
}
void logger::changefile()
{
    cout << "changefile" << endl;
}
void logger::existfile()
{
    cout << "existfile" << endl;
}
void logger::sizefile()
{
    cout << "existfile" << endl;
}
void logger::runcommand(const QString &command)
{
    auto it = commands.find(command);
    if (it != commands.end())
    {
        (this->*(it->second))();
    }
    else
    {
        cout << "Неизвестная команда." << endl;
    }
}
QString logger::getstring()
{
    cout << "Введите команду : " ;
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QString input;
    qin >> input;
    return input;
}
