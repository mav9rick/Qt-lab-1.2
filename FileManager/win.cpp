#include <win.h>
win::win(int argc, char*argv[]):QCoreApplication(argc,argv)
{
    connect(&thread,&QThread::started,&myfile.r,&reader::readcommand);
    connect(&thread,&QThread::finished,&myfile.r,&reader::deleteLater);

    connect(&loger,&logger::createS,this,&win::createFile);
    connect(&loger,&logger::deleteS,this,&win::delFile);
    connect(&loger,&logger::starttimerS,this,&win::starttimer);
    connect(&loger,&logger::stoptimerS,this,&win::stoptimer);
    connect(&loger,&logger::exitS,this,&win::execute);
    connect(&loger,&logger::readS,&myfile.r,&reader::readcommand);
    connect(&loger,&logger::listS,&myfile,&File::listfiles);
    connect(&loger,&logger::addfileS,this,&win::addFile);
    connect(&loger,&logger::removefileS,this,&win::removeFile);
    connect(&loger,&logger::changefileS,this,&win::changeFile);

    connect(&myfile,&File::updateS,&myfile.r,&reader::readcommand);
    connect(&myfile,&File::changedS,&loger,&logger::fileinfo);
    connect(&myfile,&File::listfilesS,&loger,&logger::list);
    connect(&myfile,&File::infoS,&loger,&logger::info);

    connect(&myfile.r,&reader::input,&loger,&logger::runcommand);
    connect(this,&win::updateSW,&myfile,&File::checkSL);
    connect(this,&win::runS,&myfile.r,&reader::readcommand);
    connect(this,&win::infS,&loger,&logger::info);

    connect(&myfile.r,&reader::comS,&loger,&logger::info);

    connect(&newtimer,&QTimer::timeout,&myfile,&File::checkSL);

    cout << "~Console application for monitoring file changes~" << endl
         << "| Display list of available commands - /help |" << endl;
    myfile.r.moveToThread(&thread);
    thread.start();
}
void win::execute()
{
    thread.quit();
    this->exit();
}
void win::starttimer()
{
    newtimer.start(3000);
    emit infS(1);
    emit runS();
}
void win::stoptimer()
{
    newtimer.stop();
    emit infS(1);
    emit runS();
}
void win::FileContent(QString path)
{
    loger.info(3);
    QString input = myfile.r.read();
    int c = myfile.content(path,input);
    if (c == -1)
    {
        loger.info(-1);
    }
    else
    {
        loger.info(1);
    }
}
void win::createFile()
{
    loger.info(4);
    QString path = myfile.r.read();
    loger.info(2);
    QString name = myfile.r.read();
    int c = myfile.create(path,name);
    if (c == -1)
    {
        loger.info(-1);
    }
    else
    {
        loger.info(1);
    }
    QString fullpath = path + "/" + name;
    FileContent(fullpath);
    emit runS();
}
void win::delFile()
{
    loger.info(0);
    QString path = myfile.r.read();
    int c = myfile.del(path);
    if (c == -1)
    {
        loger.info(-1);
    }
    else
    {
        loger.info(1);
    }
    emit runS();
}
void win::addFile()
{
    loger.info(0);
    QString path = myfile.r.read();
    int c = myfile.addfile(path);
    if (c == -1)
    {
        loger.info(-1);
    }
    else
    {
        loger.info(1);
    }
    emit runS();
}
void win::removeFile()
{
    loger.info(0);
    QString path = myfile.r.read();
    int c = myfile.removefile(path);
    if (c == -1)
    {
        loger.info(-1);
    }
    else
    {
        loger.info(1);
    }
    emit runS();
}
void win::changeFile()
{
    loger.info(0);
    QString path = myfile.r.read();
    FileContent(path);
    emit runS();
}
