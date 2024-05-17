#include <win.h>
win::win(int argc, char*argv[]):QCoreApplication(argc,argv)
{
    connect(&thread,&QThread::started,&myfile.r,&reader::readcommand);
    connect(&thread,&QThread::finished,&myfile.r,&reader::deleteLater);

    connect(&loger,&logger::createS,&myfile,&File::create);
    connect(&loger,&logger::deleteS,&myfile,&File::del);
    connect(&loger,&logger::starttimerS,this,&win::starttimer);
    connect(&loger,&logger::stoptimerS,this,&win::stoptimer);
    connect(&loger,&logger::exitS,this,&win::execute);
    connect(&loger,&logger::readS,&myfile.r,&reader::readcommand);
    connect(&loger,&logger::listS,&myfile,&File::listfiles);
    connect(&loger,&logger::addfileS,&myfile,&File::addfile);
    connect(&loger,&logger::removefileS,&myfile,&File::removefile);
    connect(&loger,&logger::changefileS,&myfile,&File::change);

    connect(&myfile,&File::updateS,&myfile.r,&reader::readcommand);
    connect(&myfile,&File::changedS,&loger,&logger::fileinfo);
    connect(&myfile,&File::listfilesS,&loger,&logger::list);
    connect(&myfile,&File::infoS,&loger,&logger::info);

    connect(&myfile.r,&reader::input,&loger,&logger::runcommand);
    connect(this,&win::updateSW,&myfile,&File::checkSL);
    connect(this,&win::runS,&myfile.r,&reader::readcommand);
    connect(this,&win::infS,&loger,&logger::info);

    connect(&myfile.r,&reader::comS,&loger,&logger::info);

    connect(newtimer,&QTimer::timeout,&myfile,&File::checkSL);

    cout << "~Консольное приложение для отслеживания изменений файлов~" << endl
         << "| Вывести список доступных комманд - /help |" << endl;
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
    newtimer->start(3000);
    emit infS(1);
    emit runS();
}
void win::stoptimer()
{
    newtimer->stop();
    emit infS(1);
    emit runS();
}


