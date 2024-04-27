#include "logger.h"
#include <iostream>
#include <map>
#include <QTextStream>

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
    QObject::connect(this, &logger::createS,this, &logger::createSL);
    QObject::connect(this, &logger::deleteS,this, &logger::delSL);
    QObject::connect(this, &logger::getpathS,this, &logger::getpathSL);
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
void logger::createfile()
{
    cout << "createfile" << endl;
    emit createS();
}
void logger::deletefile()
{
    cout << "deletefile" << endl;
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
    QTextStream in(stdin);
    QString input;
    in >> input;
    return input;
}
void logger::createSL()
{
    cout << "~Метод создания файла~" << endl;
    file.create();
}
void logger::delSL()
{
    cout << "~Метод удаления файла~" << endl;
    file.del();
}
void logger::getpathSL()
{
    cout << "~Метод возвращения пути файла~" << endl;
    QTextStream out(stdout);
    QString path;
    path = file.getpath();
    out << "Путь к файлу : " << path << "\n";
}
void Timer::start()
{
    tick = startTimer(500);
}
void Timer::stop()
{
    killTimer(tick);
}
void Timer::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == tick)
    {
        emit check();
    }
    else
        QCoreApplication::timerEvent(event);
}










