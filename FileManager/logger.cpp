#include "logger.h"

using namespace std;
logger::logger()
{
    commands["/help"] = &logger::displayhelp;
    commands["/createfile"] = &logger::createS;
    commands["/deletefile"] = &logger::deleteS;
    commands["/changefile"] = &logger::changefileS;
    commands["/start"] = &logger::starttimerS;
    commands["/stop"] = &logger::stoptimerS;
    commands["/exit"] = &logger::exitS;
    commands["/addfile"] = &logger::addfileS;
    commands["/removefile"] = &logger::removefileS;
    commands["/list"]=&logger::listS;
}
void logger::displayhelp()
{
    cout << "Доступные команды:" <<  endl
         << "~ Каждая команда начинается с / ~" << endl
         << "/help - отобразить список доступных команд" <<  endl
         << "/list - список файлов" <<  endl
         << "/createfile - создать файл" <<  endl
         << "/deletefile - удалить файл" <<  endl
         << "/changefile - изменить файл" <<  endl
         << "/addfile - добавить файл в список контроля" <<  endl
         << "/removefile - удалить файл из списка контроля" <<  endl
         << "/start - запуск процесса проверки файла" <<  endl
         << "/stop - остановка процесса проверки файла" <<  endl
         << "/exit - завершить программу" <<  endl
         << "(Путь к файлу указывается по типу : C:/Директория/Ваш_Файл.txt)" << endl;
    emit readS();
}
void logger::fileinfo(int size, QString name , QString lastmod, bool exist)
{
    QTextStream out(stdout);
    cout << "\n";
    out << "+----------------------------------------------------+" << "\n"
        << "|Название|Размер|Существует|Дата последнего изменения|" << "\n"
        << "+----------------------------------------------------+" << "\n"
        << "| " << name << " | " << QString::number(size) << " | "<< (exist ? QString("Да") : QString("Нет")) << " | " << lastmod << " |" << "\n"
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
void logger::list(int n,QVector<QString> pathlist)
{
    QTextStream out(stdout);
    cout << "\n";
    cout << "+----------------------------------------------------+" << "\n"
         << "|Название|Размер|Существует|Дата последнего изменения|" << "\n"
         << "+----------------------------------------------------+" << "\n";
    if (n != 0)
    {
        for (int i = 0; i < n ;i++)
        {
            QString path = pathlist[i];
            QFileInfo fileinfo(path);
            QDateTime lasttimemod = fileinfo.lastModified();
            QString name = fileinfo.fileName(),lastmod = lasttimemod.toString();
            bool exist = fileinfo.exists();
            int size = fileinfo.size();
            out << "|" << name << "|" << QString::number(size) << "|"<< (exist ? QString("Да") : QString("Нет")) << "|" << lastmod << "|" << "\n"
                << "+----------------------------------------------------+" << "\n";
            out.flush();
        }
        emit readS();
    }
    else
    {
        cout << " ~Список файлов пуст~ " << endl
             << "+----------------------------------------------------+" << endl;
        emit readS();
    }
}









