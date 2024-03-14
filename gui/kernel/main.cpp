#include <QtWidgets/QApplication>

#include "app_main.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    CAppMain w;
    w.show();
    return a.exec();
}