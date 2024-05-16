#include <win.h>
win::win(int argc, char*argv[]):QCoreApplication(argc,argv)
{
    connect(&thread,&QThread::started,&myfile.read,&reader::readcommand);
    connect(&thread,&QThread::finished,&myfile.read,&reader::deleteLater);

    connect(&loger,&logger::createS,&myfile,&File::create);
    connect(&loger,&logger::deleteS,&myfile,&File::del);
    connect(&loger,&logger::starttimerS,this,&win::starttimer);
    connect(&loger,&logger::stoptimerS,this,&win::stoptimer);
    connect(&loger,&logger::exitS,this,&win::execute);
    connect(&loger,&logger::readS,&myfile.read,&reader::readcommand);
    connect(&loger,&logger::listS,&myfile,&File::listfiles);
    connect(&loger,&logger::addfileS,&myfile,&File::addfile);
    connect(&loger,&logger::removefileS,&myfile,&File::removefile);
    connect(&loger,&logger::changefileS,&myfile,&File::change);

    connect(&myfile,&File::updateS,&myfile.read,&reader::readcommand);
    connect(&myfile,&File::changedS,&loger,&logger::fileinfo);
    connect(&myfile,&File::listfilesS,&loger,&logger::list);
    connect(&myfile,&File::infoS,&loger,&logger::info);

    connect(&myfile.read,&reader::input,&loger,&logger::runcommand);
    connect(this,&win::updateSW,&myfile,&File::checkSL);
    connect(this,&win::runS,&myfile.read,&reader::readcommand);

    connect(&myfile.read,&reader::comS,&loger,&logger::info);

    connect(newtimer,&QTimer::timeout,&myfile,&File::checkSL);

    cout << "~Консольное приложение для отслеживания изменений файлов~" << endl
         << "| Вывести список доступных комманд - /help |" << endl;
    myfile.read.moveToThread(&thread);
    thread.start();
}
void win::execute()
{
    thread.quit();
    this->exit();
}
void win::starttimer()
{
    newtimer->start(3000);
    emit runS();
}
void win::stoptimer()
{
    newtimer->stop();
    emit runS();
}

