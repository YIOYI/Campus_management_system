
#ifndef ALARM_H
#define ALARM_H

#include <QString>
#include "_Time.h"
#include "Event.h"

//ONCE-单次 DAYLY-每日 WEEKLY-每周 SELFLY-自定义
enum {ONCE, DAYLY, WEEKLY};
//CLASS-课程类 AFTERCLASS-课后活动 TEMPORARY-临时活动 NONE-啥都不是
enum {AFTERCLASS, TEMPORARY, NONE, CLASS};


class Alarm
{
public:
    Alarm();

    bool operator==(const Alarm &rhs)
    {
        if (this->index != rhs.index)
            return false;
        else
            return true;
    }

    bool operator!= (const Alarm &rhs)
    {
        return !((*this) == rhs);
    }

    int index = 0;
    bool IsUsed = true;
    int alarm_hour = 0;
    int alarm_week = 0;
    int alarm_tag = ONCE;
    int event_tag = AFTERCLASS;
    Event alarm_event;
    bool IsRung = false;
    QString tip;
};

#endif // ALARM_H
