#include "file.h"

using namespace std;
const QString defpath = QDir::currentPath();
int filestats::check(QString newpath)
{
    QFileInfo fileinfo(newpath);
    int currsize = fileinfo.size();
    bool currexist = fileinfo.exists();
    if (currexist != exist || currsize != size)
    {
        exist = currexist;
        size = currsize;
        timemod = fileinfo.lastModified();
        return 1;
    }
    return 0;
}
filestats::filestats(QString path)
{
    QFileInfo file(path);
    exist = file.exists();
    size = file.size();
    timemod = file.lastModified();
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
    }
    else
    {
        QDir::setCurrent(defpath);
    }
    cout << "Введите название файла : ";
    QString userInput,name;
    QTextStream in(stdin),in2(stdin);
    in2 >> name;
    QFile file(name + ".txt");
    QTextStream out2(&file);
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
    cout << "\n";
    cout << "Файл создан успешно." << endl;
    emit updateS();
    return 1;
}
int File::del() // Метод для удаления файла
{
    QTextStream in(stdin);
    cout << "Введите путь к файлу : " ;
    QString filepath;
    in >> filepath;
    if (!QFileInfo::exists(filepath))
    {
        cout << "Файл не найден." << endl;
        return 0;
    }
    QFile file(filepath);
    if (file.remove())
    {
        cout << "Файл успешно удален." << endl;
        emit updateS();
        return 1;
    }
    else
    {
        cout << "Не удалось удалить файл." << endl;
        emit updateS();
        return 0;
    }
}
int File::change()
{
    QTextStream in(stdin),in1(stdin);
    cout << "Введите путь к файлу : " ;
    QString filePath;
    in >> filePath;
    if (!QFileInfo::exists(filePath))
    {
        cout << "Файл не найден." << endl;
        return 0;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "Ошибка открытия файла для чтения и записи." << endl;
        return 0;
    }
    cout << "Введите содержимое файла : ";
    QString userInput = in.readLine();
    QTextStream out(&file);
    out << userInput << "\n";
    file.close();
    cout << "Файл был успешно изменён." << endl;
    emit updateS();
    return 1;
}
int File::addfile()
{
    cout << endl;
    cout << "Введите путь к файлу , который необходимо добавить в список : " ;
    QTextStream in(stdin);
    QString filepath;
    in >> filepath;
    filestats file(filepath);
    int n = pathlist.size();
    for (int i = 0; i < n;i++)
    {
        if (filepath == pathlist[i])
        {
            cout << "Файл уже есть в списке" << endl;
            emit updateS();
            return 0;
        }
    }
    fileinfo.append(file);
    pathlist.append(filepath);
    cout << "Файл добавлен в список" << endl;
    emit updateS();
    return 1;
}
void File::removefile()
{
    cout << endl;
    cout << "Введите путь к файлу , который необходимо убрать из списка : " ;
    QTextStream in(stdin);
    QString filepath;
    in >> filepath;
    filestats file(filepath);
    fileinfo.removeOne(file);
    pathlist.removeOne(filepath);
    cout << "Файл удалён из списка" << endl;
    emit updateS();
}
void File::checkSL()
{
    int n = pathlist.size();
    for (int i = 0; i < n ;i++)
    {
        int c = fileinfo[i].check(pathlist[i]);
        if (c == 1)
        {
            QFileInfo file(pathlist[i]);
            QDateTime lasttimemod = file.lastModified();
            QString lastmod = lasttimemod.toString();
            emit changedS(file.size(),file.fileName(),lastmod,file.exists());
        }
    }
}
void File::listfiles()
{
    int n = pathlist.size();
    emit listfilesS(n,pathlist);
}












