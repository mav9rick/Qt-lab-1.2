#include "win.h"
#include <locale>
#include <logger.h>
#include <file.h>
#include <QTextStream>
#include <QDir>
using namespace std;
int main(int argc, char *argv[])
{
    locale::global(locale("ru_RU.UTF-8"));
    win a(argc, argv);
    return a.exec();
}

