
#ifndef TIMEPAUSE_H
#define TIMEPAUSE_H


#include <QObject>


class TimePause :public QObject
{
    Q_OBJECT
signals:
    void t_pause();
public:
    void to_time_pause();
    explicit TimePause(QObject *parent = 0);
};

#endif // TIMEPAUSE_H
