#include "file.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <iostream>
#include <QCoreApplication>
using namespace std;
const QString defpath = QDir::currentPath();
QString prevpath;
QDateTime prevlastmod;
int prevsize;
bool prevexist;
File::File()
{
    prevsize = 0;
    prevexist = 0;
    prevpath = "None";
}
QString File::getpath()
{
    QFileInfo fileinfo(path);
    path = fileinfo.absoluteFilePath();
    return path;
}
QString File::setpath(QString newpath)
{
    path = newpath;
    prevpath = path;
    return path;
}
int File::setsize(int newsize)
{
    size = newsize;
    prevsize = size;
    return size;
}
int File::getsize()
{
    QFileInfo fileinfo(path);
    size = fileinfo.size();
    return size;
}
bool File::setexist(bool newexist)
{
    exist = newexist;
    prevexist = exist;
    return exist;
}
bool File::getexist()
{
    QFileInfo fileinfo(path);
    exist = fileinfo.exists();
    return exist;
}
int File::create() // Метод создания файла
{
    cout << "Выберите где создать файл : " << endl
         << "1 - Создать в стандартной директории." << endl
         << "2 - Задать директорию" << endl;
    int c = 0;
    cin >> c;
    if (c == 2)
    {
        cout << "Введите директорию в которой создать файл : " ;
        QTextStream in1(stdin);
        QString newpath;
        in1 >> newpath;
        QDir::setCurrent(newpath);
        setpath(newpath);
    }
    else
    {
        QDir::setCurrent(defpath);
        setpath(defpath);
    }
    cout << "Введите название файла : ";
    QString userInput,name;
    QTextStream in(stdin),in2(stdin);
    in2 >> name;
    QFile file(name + ".txt");
    QTextStream out2(&file),out(stdout);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Ошибка при открытии файла на чтение." << endl;
        return 0;
    }
    cout << "Введите содержание файла : ";
    userInput = in.readLine();
    out2 << userInput << "\n";
    out2 << "This is a test file created using Qt.";
    file.close();
    out << "Данные до создания файла : " << exist << " " << path << " "  << size << "\n";
    cout << "\n";
    cout << "Файл создан успешно." << endl;
    QFileInfo fileinfo(path + "/" + name + ".txt");
    int newsize = fileinfo.size();
    bool newexist = fileinfo.exists();
    setsize(newsize);
    setexist(newexist);
    out << "Данные только что созданного файла : " << exist << " " << path << " "  << size << "\n";
    emit updateS();
    return 1;
}
int File::del() // Метод для удаления файла
{
    QTextStream out(stdout),in(stdin);
    out << "Данные до удаления : " << exist << " " << path << " "  << size << "\n";
    cout << "Введите путь к файлу : " ;
    QString filepath;
    in >> filepath;
    cout << "Введите название файла : " ;
    QString filename;
    in >> filename;
    QFile file(filepath + "/" + filename);
    if (file.remove())
    {
        cout << "Файл успешно удален." << endl;
        setsize(0);
        setexist(false);
        emit updateS();
        out << "Данные после удаления : " << exist << " " << path << " "  << size << "\n";
        return 1;
    }
    else
    {
        cout << "Не удалось удалить файл." << endl;
        out << "Данные при неудачном удалении : " << exist << " " << path << " "  << size << "\n";
        emit updateS();
        return 0;
    }
}
int File::change()
{
    QTextStream in(stdin);
    QString filePath = getpath();
    if (!QFileInfo::exists(filePath))
    {
        cout << "Файл не найден." << endl;
        return 1;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "Ошибка открытия файла для чтения и записи." << endl;
        return 1;
    }
    cout << "Введите содержимое файла : ";
    QString userInput = in.readLine();
    QTextStream out(&file);
    out << userInput << "\n";
    file.close();
    cout << "Файл был успешно изменён." << endl;
    QFileInfo fileinfo(filePath);
    int newsize = fileinfo.size();
    setsize(newsize);
    emit updateS();
    return 0;
}
QString File::setfile() // Метод для выбора файла за которым необходимо установить контроль
{
    cout << "Введите путь к файлу за которым необходимо установить контроль : " ;
    QTextStream in(stdin);
    QString filepath;
    in >> filepath;
    QFileInfo fileinfo;
    fileinfo.setFile(filepath);
    setpath(filepath);
    setexist(fileinfo.exists());
    setsize(fileinfo.size());
    emit updateS();
    return filepath;
}
void File::checkSL()
{
    QFileInfo fileinfo(path);
    int currsize = fileinfo.size();
    bool currexist = fileinfo.exists();
    //cout << "curex : " << currexist << "prevex : " << prevexist << endl;
    if (currexist != prevexist)
    {
        //cout << "Файл был удалён. File" << endl;
        setexist(false);
        setsize(0);
        setpath("None");
        emit changedS();
    }
    else
    {
        prevexist = fileinfo.exists();
        emit updateS();
    }
    if(currsize != prevsize)
    {
        setsize(fileinfo.size());
        emit changedS();
    }
    else
    {
        prevsize = fileinfo.size();
        emit updateS();
    }
}













