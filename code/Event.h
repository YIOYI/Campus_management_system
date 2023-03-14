#ifndef _EVENT_H_
#define _EVENT_H_

#include <string>
#include <vector>
#include "Time.h"
#include "Building.h"
using namespace std;

class Event
{
public:
	Event();
	~Event();

private:
	Time time;
	string name;
	Building& building;
	vector<string> member;
	vector<int> weeks;
	unsigned Tag;
};

Event::Event()
{
}

Event::~Event()
{
}

#endif // !_EVENT_H_

