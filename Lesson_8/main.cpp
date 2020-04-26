#include "justforfun.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JustForFun w;
    w.show();
    return a.exec();
}
