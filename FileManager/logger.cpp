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
    emit updateS();
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
    emit getpathS();
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
    cout << "existfile" << endl;
    //emit sizeS();
}
void logger::deleted()
{
    QTextStream out(stdout);
    QFileInfo file(getpath());
    QString name = file.fileName();
    int size = file.size();
    QString exist = "false";
    if (file.exists() == 1)
    {
        exist = "true";
    }
    out << "\n";
    out << "---------------------------------------------------" << "\n"
        << "| Имя файла | Существование | Размер | LastChange |" << "\n"
        << "| " << name << " | " << exist << " | " << size << " | " << "--" << " |" << "\n"
        << "---------------------------------------------------" << "\n";
    out << "Файл был удалён." << "\n";
    emit updateS();
}
void logger::runcommand()
{
    cout << "Введите команду : " ;
    QTextStream in(stdin);
    QString input;
    in >> input;
    auto it = commands.find(input);
    if (it != commands.end())
    {
        (this->*(it->second))();
    }
    else
    {
        cout << "Неизвестная команда." << endl;
        emit updateS();
    }
}
QString logger::getstring()
{
    cout << "Введите команду : " ;
    QTextStream in(stdin);
    QString input;
    in >> input;
    return input;
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







