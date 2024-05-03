#include <win.h>
reader::reader()
{}
void reader::readcommand()
{
    cout << "Введите команду : " ;
    string s;
    getline(cin,s);
    QString df(s.c_str());
    emit input(df);
}
win::win(int argc, char*argv[]):QCoreApplication(argc,argv)
{
    connect(&thread,&QThread::started,&read,&reader::readcommand);
    connect(&thread,&QThread::finished,&read,&reader::deleteLater);

    connect(&loger,&logger::createS,&myfile,&File::create);
    connect(&loger,&logger::deleteS,&myfile,&File::del);
    connect(&loger,&logger::getpathS,&myfile,&File::getpath);
    connect(&loger,&logger::starttimerS,this,&win::starttimer);
    connect(&loger,&logger::stoptimerS,this,&win::stoptimer);
    connect(&loger,&logger::exitS,this,&win::execute);
    connect(&loger,&logger::setfileS,&myfile,&File::setfile);
    connect(&loger,&logger::readS,&read,&reader::readcommand);
    connect(&loger,&logger::testS,&myfile,&File::testmethod);

    connect(&myfile,&File::updateS,&read,&reader::readcommand);
    connect(&myfile,&File::changedS,&loger,&logger::fileinfo);

    connect(&read,&reader::input,&loger,&logger::runcommand);
    connect(this,&win::updateSW,&myfile,&File::checkSL);
    connect(this,&win::runS,&read,&reader::readcommand);

    connect(newtimer,&QTimer::timeout,&myfile,&File::checkSL);

    read.moveToThread(&thread);
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
