#include "file.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QDir>

File::File()// Конструктор по умолчанию
{
    QTextStream cout(stdout);
    QFile file("test.txt");
    QString directoryPath = QDir::currentPath();
    cout << "Dir path == " << directoryPath << "\n";
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        cout << "Failed to open file for writing." << "\n";
        exist = false;
        size = 0;
        path = nullptr;
    }
    else
    {
    QTextStream out(&file);
    out << "This is a test file created by constructor." << "\n";
    file.close();
    exist = true;
    size = file.size();
    path = directoryPath + "/test.txt";
    cout << "File created successfully. (const())" << "\n";
    //cout << "Size of file = " << size << "\n";
    //cout << "Path to file = " << path << "\n";
    }
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
    }
    else
    {
    QTextStream out(&file);
    out << "This is a test file created by constructor." << "\n";
    file.close();
    exist = true;
    size = file.size();
    path = path1 + "/test.txt";
    cout << "File created successfully.(const(path))" << "\n";
    //cout << "Size of file = " << size << "\n";
    //cout << "Path to file = " << path1 << "\n";
    }
}
int File::create() // Метод создания файла
{
    QTextStream out(stdout);
    out << "Enter name of file:";
    out.flush();
    QString userInput;
    QTextStream in(stdin);
    in >> userInput;
    QFile file(userInput + ".txt");
    QTextStream out2(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        out << "Failed to open file for writing.";
        out.flush();
        return 1;
    }
    out << "Enter content of file:";
    out.flush();
    in >> userInput;
    out2 << userInput;
    out2 << "\n";
    out2 << "This is a test file created using Qt.";
    file.close();
    out << "\n";
    out << "File created successfully.";
    return 0;
}
void File::del(QFileInfo filepath) // Метод для удаления файла
{
    QTextStream out(stdout);
    QString Path = filepath.absolutePath();
    if (QFile(Path).exists())
    {
        if (QFile::remove(Path))
        {
            out << "File successfully deleted";
        }
        else
        {
            out << "Failed to delete file";
        }
    }
    else
    {
        out << "File does not exist";
    }
}
QString File::getpath()
{
    return path;
}
int File::getsize()
{
    return size;
}
bool File::getexist()
{
    return exist;
}
void File::change()
{
    QTextStream cout(stdout);
    QTextStream in(stdin);
    QString filePath = getpath();
    QString userInput;
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        cout << "Failed to open file for reading and writing.";
    }
    else
    {
    QTextStream out2(&file);
    cout << "Enter content of file:";
    cout.flush();
    in >> userInput;
    out2 << userInput;
    out2 << "\n";
    cout << "~New content added to the file.~" << "\n";
    cout << "\n";
    file.close();
    cout << "File has been changed successfully." << "\n";
    cout << "\n";
    }
}
