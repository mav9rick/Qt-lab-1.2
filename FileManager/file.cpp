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
int File::create(QString path, QString name)
{
    QDir::setCurrent(path);
    QString userInput;
    QFile file(name + ".txt");
    if (!QFileInfo::exists(path))
    {
        return -1;
    }
    QTextStream out2(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return -1;
    }
    return 1;
}
int File::content(QString path, QString userInput)
{
    QFile file(path);
    QTextStream out2(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return -1;
    }
    out2 << userInput << "\n";
    file.close();
    return 1;
}
int File::del(QString filepath)
{
    if (!QFileInfo::exists(filepath))
    {
        return -1;
    }
    QFile file(filepath);
    if (file.remove())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int File::addfile(QString filepath)
{
    filestats file(filepath);
    int n = pathlist.size();
    if (!QFileInfo::exists(filepath))
    {
        return -1;
    }
    for (int i = 0; i < n;i++)
    {
        if (filepath == pathlist[i])
        {
            return -1;
        }
    }
    fileinfo.append(file);
    pathlist.append(filepath);
    return 1;
}
int File::removefile(QString filepath)
{
    filestats file(filepath);
    if (!QFileInfo::exists(filepath))
    {
        return -1;
    }
    int n = pathlist.size();
    if (pathlist.isEmpty())
    {
        return -1;
    }
    for (int i = 0; i < n;i++)
    {
        if (filepath != pathlist[i])
        {
            return -1;
        }
    }
    fileinfo.removeOne(file);
    pathlist.removeOne(filepath);
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

