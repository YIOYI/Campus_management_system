
#include "mainwindow.h"
#include "Person.h"
#include <QApplication>
#include <QScreen>


int main(int argc, char *argv[])
{
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);

//    QScreen *screen = QGuiApplication::primaryScreen();
//    qreal screenDpi = screen->logicalDotsPerInch() / 96.0;
//    qDebug()<< "屏幕缩放" <<screenDpi;

    QApplication a(argc, argv);
    MainWindow w;
    w.ready();
    return a.exec();
}
