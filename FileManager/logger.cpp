#include "logger.h"
#include <iostream>
#include <map>

using namespace std;
logger::logger() {}
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
int logger::exit()
{
    cout << "Завершение программы" << endl;
    return -1;
}
void logger::createfile()
{

}
void logger::deletefile()
{

}
void logger::getpath()
{

}
void logger::changefile()
{

}
void logger::existfile()
{

}
void logger::sizefile()
{

}
