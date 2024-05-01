#include <win.h>

win::win(int argc, char*argv[]):QCoreApplication(argc,argv)
{
    connect(&loger,&logger::createS,&myfile,&File::create);
    connect(&loger,&logger::deleteS,&myfile,&File::del);
    connect(&loger,&logger::getpathS,&myfile,&File::getpath);
    connect(&loger,&logger::starttimerS,this,&win::starttimer);
    connect(&loger,&logger::stoptimerS,this,&win::stoptimer);
    connect(this,&win::updateS,&myfile,&File::checkSL);
    connect(&thread,&QThread::started,&loger,&logger::runcommand);
    connect(&thread,&QThread::finished,&loger,&logger::exit);
    connect(&loger,&logger::exitS,this,&win::execute);
    connect(&myfile,&File::updateS,&loger,&logger::runcommand);
    connect(&myfile,&File::changedS,&loger,&logger::deleted);
    connect(&loger,&logger::setfileS,&myfile,&File::setfile);
    connect(&loger,&logger::updateS,&loger,&logger::runcommand);
    connect(this,&win::runS,&loger,&logger::runcommand);
    loger.moveToThread(&thread);
    thread.start();
}
int win::execute()
{
    thread.quit();
    this->exit();
    cout << "Остановка программы...." << endl;
    return 0;
}
void win::starttimer()
{
    timer = startTimer(500);
    emit runS();
}
void win::stoptimer()
{
    killTimer(timer);
    emit runS();
}
void win::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer)
    {
        //qDebug() << "tick" << "\n";
        emit updateS();
    }
    else
        QObject::timerEvent(event);
}
