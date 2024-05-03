#include "logger.h"
#include <iostream>
#include <map>
#include <QTextStream>
#include <QThread>

using namespace std;
logger::logger()
{
    commands["/help"] = &logger::displayhelp;
    commands["/createfile"] = &logger::createS;
    commands["/deletefile"] = &logger::deleteS;
    commands["/changefile"] = &logger::changefileS;
    commands["/getpath"] = &logger::getfilepathS;
    commands["/existfile"] = &logger::existS;
    commands["/sizefile"] = &logger::sizeS;
    commands["/starttimer"] = &logger::starttimerS;
    commands["/stoptimer"] = &logger::stoptimerS;
    commands["/exit"] = &logger::exitS;
    commands["/setfile"] = &logger::setfileS;
    commands["/test"]=&logger::testS;
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
    cout << "/starttimer - запуск таймера" <<  endl;
    cout << "/stoptimer - отключение таймера" <<  endl;
    emit readS();
}
void logger::fileinfo(int size, QString name , QString lastmod, bool exist)
{
    QTextStream out(stdout);
    cout << "\n";
    out << "+----------------------------------------------------+" << "\n"
        << "|Название|Размер|Существует|Дата последнего изменения|" << "\n"
        << "+----------------------------------------------------+" << "\n"
        << "|" << name << "|" << QString::number(size) << "|"<< (exist ? QString("Да") : QString("Нет")) << "|" << lastmod << "|" << "\n"
        << "+----------------------------------------------------+" << "\n";
    out.flush();
}
void logger::runcommand(QString input)
{
    auto it = commands.find(input);
    if (it != commands.end())
    {
        (this->*(it->second))();
    }
    else
    {
        cout << "Неизвестная команда." << endl;
        emit readS();
    }
}









