#ifndef __TIME_H_
#define __TIME_H_
#include <QObject>
#include <QString>
#include <iostream>
#include <timepause.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
class _Time
{
public:
    TimePause *tp;
    _Time(int m = 1, int d = 1, int h = 0) :
        week_(m), day_(d), hour_(h) { tp=new TimePause; };
    ~_Time() { ; };
    int& week() { return week_; };
    int& day() { return day_; };
    int& hour() { return hour_; };
    void time_now();
    void time_set(int w,int d,int h);
	void time_suspend();
	void time_continue();
    int  is_continue();  //返回0表示正在时停
    int  is_init();  //返回0表示未初始化
    void get_last_time();
    void save_this_time();
    void set_init();  //置1
private:
	int week_ = 1;  // 周数 从1开始
	int day_ = 1;   //day_ 1-7代表周一到周日
	int hour_ = 0;  //hour_ 24小时制,0-23
};

 
#endif 
