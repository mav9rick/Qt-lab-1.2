#include "file.h"

using namespace std;
reader::reader()
{}
void reader::readcommand()
{
    emit comS(5);
    string s;
    getline(cin,s);
    QString df(s.c_str());
    emit input(df);
}
QString reader::read()
{
    string s;
    getline(cin,s);
    QString df(s.c_str());
    return df;
}
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
int File::create()
{
    emit infoS(4);
    QString path = r.read();
    QDir::setCurrent(path);
    emit infoS(2);
    QString userInput,name = r.read();
    QFile file(name + ".txt");
    if (!QFileInfo::exists(path))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    QTextStream out2(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    emit infoS(3);
    userInput = r.read();
    out2 << userInput << "\n";
    file.close();
    emit infoS(1);
    emit updateS();
    return 1;
}
int File::del()
{
    emit infoS(0);
    QString filepath;
    filepath = r.read();
    if (!QFileInfo::exists(filepath))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    QFile file(filepath);
    if (file.remove())
    {
        emit infoS(1);
        emit updateS();
        return 1;
    }
    else
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
}
int File::change()
{
    emit infoS(0);
    QString filePath;
    filePath = r.read();
    if (!QFileInfo::exists(filePath))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    QFile file(filePath);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    emit infoS(3);
    QString userInput;
    userInput = r.read();
    out << userInput << "\n";
    file.close();
    emit infoS(1);
    emit updateS();
    return 1;
}
int File::addfile()
{
    emit infoS(0);
    QString filepath = r.read();
    filestats file(filepath);
    int n = pathlist.size();
    if (!QFileInfo::exists(filepath))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    for (int i = 0; i < n;i++)
    {
        if (filepath == pathlist[i])
        {
            emit infoS(-1);
            emit updateS();
            return 0;
        }
    }
    fileinfo.append(file);
    pathlist.append(filepath);
    emit infoS(1);
    emit updateS();
    return 1;
}
int File::removefile()
{
    emit infoS(0);
    QString filepath = r.read();
    filestats file(filepath);
    if (!QFileInfo::exists(filepath))
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    int n = pathlist.size();
    if (pathlist.isEmpty())
    {
        emit infoS(-1);
        emit updateS();
        return 0;
    }
    for (int i = 0; i < n;i++)
    {
        if (filepath != pathlist[i])
        {
            emit infoS(-1);
            emit updateS();
            return 0;
        }
    }
    fileinfo.removeOne(file);
    pathlist.removeOne(filepath);
    emit infoS(1);
    emit updateS();
    return 1;
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

