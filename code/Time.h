#ifndef _TIME_H_
#define _TIME_H_

class Time
{
public:
	Time() : Time(0, 0, 0) {}
	Time(int m, int d, int h) :
		week(m), day(d), hour(h) {}
	~Time();

private:
	int week = 0;
	int day = 0;
	int hour = 0;
};

Time::Time()
{
}

Time::~Time()
{
}

#endif // !_TIME_H_
