#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include "log.h"

int main(int argc, char *argv[])
{
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);

    QApplication a(argc, argv);
    qInstallMessageHandler(outputMessage);
    MainWindow w;
    w.ready();
    return a.exec();
}
