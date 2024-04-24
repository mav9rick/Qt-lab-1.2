#include "file.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <iostream>
using namespace std;
const QString defpath = QDir::currentPath();
QString File::getpath()
{
    return path;
}
QString File::setpath(QString newpath)
{
    path = newpath;
    return path;
}
File::File()// Конструктор по умолчанию
{
    QTextStream cout(stdout);
    QFile file("test.txt");
    QString directoryPath = QDir::currentPath();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Failed to open file for writing." << "\n";
        exist = false;
        size = 0;
        path = nullptr;
        abort();
    }
    QTextStream out(&file);
    out << "This is a test file created by constructor." << "\n";
    file.close();
    exist = true;
    size = file.size();
    path = directoryPath;
    //cout << "File created successfully." << "\n";
    //cout << "Size of file = " << size << "\n";
    //cout << "Path to file = " << path << "\n";
}
File::File(QString path1) // Конструктор принимающий адрес где создать файл
{
    QTextStream cout(stdout);
    QFile file(path1 + "/test.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Failed to open file for writing." << "\n";
        exist = false;
        size = 0;
        path = nullptr;
        abort();
    }
    QTextStream out(&file);
    out << "This is a test file created by constructor." << "\n";
    file.close();
    exist = true;
    size = file.size();
    path = path1;
    //cout << "File created successfully." << "\n";
    //cout << "Size of file = " << size << "\n";
    //cout << "Path to file = " << path1 << "\n";
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
    QString userInput;
    QTextStream in(stdin);
    in >> userInput;
    QFile file(userInput + ".txt");
    QTextStream out2(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Ошибка при открытии файла на чтение." << endl;
        return 0;
    }
    cout << "Введите содержание файла : ";
    userInput = in.readLine();
    out2 << userInput;
    out2 << "\n";
    out2 << "This is a test file created using Qt.";
    file.close();
    cout << "\n";
    cout << "Файл создан успешно." << endl;
    //emit created();
    return 1;
}
int File::del() // Метод для удаления файла
{
    QTextStream out(stdout),in(stdin);
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
        return 1;
    }
    else
    {
        cout << "Не удалось удалить файл." << endl;
        return 0;
    }
}

int File::getsize()
{
    return size;
}
bool File::getexist()
{
    return exist;
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
    return 0;
}
void File::testmethod()
{
    cout << "Testmethod classa File" << endl;
}

