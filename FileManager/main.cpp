#include <iostream>
#include <string>
#include <map>
#include <locale>
#include <logger.h>
#include <file.h>
#include <QTextStream>
#include <QDir>
using namespace std;

int main()
{
    locale::global( locale("ru_RU.UTF-8"));
    logger a;
    while (true)
    {
        QString b = a.getstring();
        if (b != "/exit")
        {
            a.runcommand(b);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}
