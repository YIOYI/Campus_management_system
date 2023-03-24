#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <vector>
#include "Event.h"
#include "Building.h"
using namespace std;

class Person
{
public:
	Person();
	~Person();

private:
	string ID;
	string password;
	vector<Event&> DayCurriculum;	//每天晚上读取学生第二天的课表
	Building position;				//学生当前位置
	unsigned Tag;
};

Person::Person()
{
}

Person::~Person()
{
}

#endif // !_PERSON_H_