#ifndef _TIME_H_
#define _TIME_H_
//#include<fstream>
#include<iostream>
using namespace std;
class Time
{
public:
	Time(int m=0, int d=0, int h=0) :
		week(m), day(d), hour(h) {}
	~Time() { ; };
	friend class Event;         //Event��Time����Ԫ��  
	friend class Curriculum;
	//friend void operator>>(ifstream&, Time&);
private:
	int week = 0;
	int day = 0;
	int hour = 0;
};
 
//void operator>>(ifstream& a,Time& b)   //���������">>"
//{
//	a >> b.day;
//	a >> b.hour;
//}
#endif 
