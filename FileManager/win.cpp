#include <win.h>
reader::reader()
{}
void reader::listenCommand()
{
    cout << "Введите команду : " ;
    string s;
    getline(cin,s);
    QString df(s.c_str());
    emit commandInput(df);
}
win::win(int argc, char*argv[]):QCoreApplication(argc,argv)
{
    connect(&thread,&QThread::started,&read,&reader::listenCommand);
    connect(&thread,&QThread::finished,&read,&reader::deleteLater);

    connect(&loger,&logger::createS,&myfile,&File::create);
    connect(&loger,&logger::deleteS,&myfile,&File::del);
    connect(&loger,&logger::getpathS,&myfile,&File::getpath);
    connect(&loger,&logger::starttimerS,this,&win::starttimer);
    connect(&loger,&logger::stoptimerS,this,&win::stoptimer);
    connect(&loger,&logger::exitS,this,&win::execute);
    connect(&loger,&logger::setfileS,&myfile,&File::setfile);
    connect(&loger,&logger::readS,&read,&reader::listenCommand);

    connect(&myfile,&File::updateS,&read,&reader::listenCommand);
    connect(&myfile,&File::changedS,&loger,&logger::fileinfo);
    connect(&myfile,&File::testS,&loger,&logger::getfilepath);

    connect(&read,&reader::commandInput,&loger,&logger::runcommand);
    connect(this,&win::updateSW,&myfile,&File::checkSL);
    connect(this,&win::runS,&read,&reader::listenCommand);

    connect(newtimer,&QTimer::timeout,&myfile,&File::checkSL);

    read.moveToThread(&thread);
    thread.start();
}
void win::execute()
{
    //cout << "Остановка программы...." << endl;
    thread.quit();
    this->exit();
}
void win::starttimer()
{
    newtimer->start(3000);
    //cout << "Таймер запущен" << "\n";
    emit runS();
    /*timer = startTimer(3000);
    qDebug() << "starting timer" << "\n";
    emit runS();*/
}
void win::stoptimer()
{
    newtimer->stop();
    //cout << "Таймер остановлен" << "\n";
    //killTimer(timer);
    emit runS();
}
void win::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer)
    {
        //qDebug() << "emit updateS" << "\n";
        emit updateSW();
        //QCoreApplication::processEvents();
    }
    else
        QObject::timerEvent(event);
}
QString win::getstring()
{
    //cout << endl;
    //cout << "Введите команду : " ;
    QTextStream in(stdin);
    QString input;
    in >> input;
    emit userinputS(input);
    return input;
}
