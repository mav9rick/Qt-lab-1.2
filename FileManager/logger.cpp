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
    commands["/list"] = &logger::listS;
}
void logger::displayhelp()
{
    cout << "Commands:" <<  endl
         << "~ Every command starts with / ~" << endl
         << "/help - list of all commands" <<  endl
         << "/list - list of files" <<  endl
         << "/createfile - create file" <<  endl
         << "/deletefile - delete file" <<  endl
         << "/changefile - change file" <<  endl
         << "/addfile - add file to watchlist" <<  endl
         << "/removefile - remove file from watchlist" <<  endl
         << "/start - start file monitoring process" <<  endl
         << "/stop - stop file monitoring process" <<  endl
         << "/exit - exit the program" <<  endl
         << "(File path should be specified as: C:/Directory/Your_File.txt)" << endl;
    emit readS();
}
void logger::fileinfo(int size, QString name , QString lastmod, bool exist)
{
    QTextStream out(stdout);
    out << "\n";
    out << "+----------------------------------------------------+" << "\n"
        << "|Name|Size|Exists|Last Modified Date|" << "\n"
        << "+----------------------------------------------------+" << "\n"
        << "| " << name << " | " << QString::number(size) << " | "<< (exist ? QString("Yes") : QString("No")) << " | " << lastmod << " |" << "\n"
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
        cout << "Unknown command." << endl;
        emit readS();
    }
}
void logger::list(int n, QVector<QString> pathlist)
{
    QTextStream out(stdout);
    out << "+----------------------------------------------------+" << "\n"
        << "|Name|Size|Exists|Last Modified Date|" << "\n"
        << "+----------------------------------------------------+" << "\n";
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            QString path = pathlist[i];
            QFileInfo fileinfo(path);
            QDateTime lasttimemod = fileinfo.lastModified();
            QString name = fileinfo.fileName(), lastmod = lasttimemod.toString();
            bool exist = fileinfo.exists();
            int size = fileinfo.size();
            out << "|" << name << "|" << QString::number(size) << "|"<< (exist ? QString("Yes") : QString("No")) << "|" << lastmod << "|" << "\n"
                << "+----------------------------------------------------+" << "\n";
        }
        emit readS();
    }
    else
    {
        out << " ~File list is empty~ " << "\n"
            << "+----------------------------------------------------+" << "\n";
        emit readS();
    }
}
void logger::info(int c)
{
    QTextStream out(stdout);
    switch(c)
    {
    case -1:
        out << "ERROR" << "\n";
        out.flush();
        break;
    case 0:
        out << "Enter the file path: ";
        out.flush();
        break;
    case 1:
        out << "Operation completed successfully" << "\n";
        out.flush();
        break;
    case 2:
        out << "Enter the file name: ";
        out.flush();
        break;
    case 3:
        out << "Enter the file content: ";
        out.flush();
        break;
    case 4:
        out << "Enter the directory to create the file: ";
        out.flush();
        break;
    case 5:
        out << "Enter a command: ";
        out.flush();
        break;
    }
}
