
#include "mainwindow.h"
#include"process.h"
#include "Person.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);
    QApplication a(argc, argv);
    MainWindow w;
    w.ready();
    return a.exec();
}
