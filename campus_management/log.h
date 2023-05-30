
#ifndef LOG_H
#define LOG_H

#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QMutex>
#include <QString>
#include <qapplication.h>
#include <QMessageBox>

#include <_Time.h>

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();

    _Time ti;
    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;
    case QtWarningMsg:
        text = QString("Warning:");
        break;
    case QtCriticalMsg:
        text = QString("Critical:");
        break;
    case QtFatalMsg:
        text = QString("Fatal:");
        break;
    default:break;
    }

    ti.time_now();
    // 设置输出信息格式
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);

    QString day;
    ti.time_now();
    switch (ti.day())
    {
    case 1: day="周一"; break;
        case 2: day="周二"; break;
        case 3: day="周三"; break;
        case 4: day="周四"; break;
        case 5: day="周五"; break;
        case 6: day="周六"; break;
        case 7: day="周日"; break;
    }
    QString current_date=QString("第%1周\t").arg(ti.week())+day+QString("\t%1点\t").arg(ti.hour());

    QString message = QString("%1 %2").arg(current_date).arg(msg);

    // 输出信息至文件中（读写、追加形式）
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
    // 解锁
    mutex.unlock();
}


#endif // LOG_H
