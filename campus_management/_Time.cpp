#include <emmintrin.h>
#include<iostream>
#include"_Time.h"
#include<ctime>
using std::cin;
using std::cout;

static time_t start_time = time(NULL);  //可以通过调整start_time来调整时间
static time_t now_time;
static int time_tag = 1;  //tag为0时间暂停，tag为1时间继续流动
void _Time::time_now()  //时间自然流动
{
    if (time_tag != 0)
        now_time = time(NULL);	//未暂停时间，时间更新
    hour_ = (now_time - start_time) / 5 % 24;
    day_ = (now_time - start_time) / 5 / 24 % 7 + 1;
    week_ = (now_time - start_time) / 5 / 24 / 7 + 1;
}
void _Time::time_set(int w,int d,int h)  //用户设定时间
{
    time_suspend();  //暂停时间
    week_ =w;
    day_ =d;
    hour_=h;
	start_time = now_time - (((long)week_ * 7 - 7 + day_ - 1) * 24 + hour_) * 5;
	time_continue();  //时间继续流动
}
void _Time::time_suspend()  //暂停时间
{
    if(time_tag==1)
    {
        tp->to_time_pause();
        time_tag = 0;
        now_time = time(NULL);  //记录暂停时的时间
    }
}
void _Time::time_continue()  //时间继续流动
{
    if(time_tag==0)
    {
        time_tag = 1;
        int dis = now_time - start_time;
        now_time = time(0);
        start_time = now_time - dis;
    }
}
int _Time::is_continue()
{
    return time_tag;
}
