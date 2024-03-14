#include <QtWidgets/QApplication>

#include "app_main.h"
#include <QDir>
#include <qresource.h>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);


    QString path = QCoreApplication::applicationDirPath();
    path = QDir::toNativeSeparators(path);
    path = path.mid(0, path.lastIndexOf("\\"));
    path += "\\skin\\default.rcc";

    QResource::registerResource(path);

    QFile qss(":/qss/default.qss");
    if (qss.open(QFile::ReadOnly))
    {
        a.setStyleSheet(qss.readAll().toStdString().c_str());
        qss.close();
    }

  
    CAppMain w;
    w.show();
    return a.exec();
}