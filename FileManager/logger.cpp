#include "logger.h"
#include <iostream>
#include <map>
#include <QTextStream>
#include <QThread>

using namespace std;
logger::logger()
{
    commands["/help"] = &logger::displayhelp;
    commands["/createfile"] = &logger::createfile;
    commands["/deletefile"] = &logger::deletefile;
    commands["/changefile"] = &logger::changefile;
    commands["/getpath"] = &logger::getfilepath;
    commands["/existfile"] = &logger::existfile;
    commands["/sizefile"] = &logger::sizefile;
    commands["/starttimer"] = &logger::starttimer;
    commands["/stoptimer"] = &logger::stoptimer;
    commands["/exit"] = &logger::exit;
    commands["/setfile"] = &logger::setfile;
    //QObject::connect(&timer,&Timer::checkS,&file,&File::checkSL);
    //QObject::connect(&file, &File::deletedS,this, &logger::deleted);
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
void logger::setfile()
{
    emit setfileS();
}
void logger::exit()
{
    emit exitS();
}
void logger::createfile()
{
    cout << "~Метод создания файла~" << endl;
    emit createS();
}
void logger::deletefile()
{
    cout << "~Метод удаления файла~" << endl;
    emit deleteS();
}
void logger::getfilepath()
{
    cout << "getpath" << endl;
    emit readS();
}
void logger::changefile()
{
    cout << "changefile" << endl;
    //emit changeS();
}
void logger::existfile()
{
    cout << "existfile" << endl;
    //emit existS();
}
void logger::sizefile()
{
    cout << "sizefile" << endl;
    //emit sizeS();
}
void logger::fileinfo(int size, QString name , QString lastmod, bool exist)
{
    QTextStream out(stdout);
    //qDebug() << "logger::fileinfo" << "\n";
    cout << "\n";
    out << "+----------------------------------------------------+" << "\n"
        << "|Название|Размер|Существует|Дата последнего изменения|" << "\n"
        << "+----------------------------------------------------+" << "\n"
        << "|" << name << "|" << QString::number(size) << "|"<< (exist ? QString("Да") : QString("Нет")) << "|" << lastmod << "|" << "\n"
        << "+----------------------------------------------------+" << "\n";
    out.flush();
    //emit readS();
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
void logger::getpathSL()
{
    cout << "~Метод возвращения пути файла~" << endl;
    QTextStream out(stdout);
    QString path;
    path = "&File::getpath();";
    out << "Путь к файлу : " << path << "\n";
}
void logger::starttimer()
{
    emit starttimerS();
}
void logger::stoptimer()
{
    emit stoptimerS();
}







