
#include "timepause.h"


TimePause::TimePause(QObject *parent) : QObject(parent)
{

}
void TimePause::to_time_pause()
{
    emit t_pause();
}
