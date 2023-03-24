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
	vector<Event&> DayCurriculum;	//ÿ�����϶�ȡѧ���ڶ���Ŀα�
	Building position;				//ѧ����ǰλ��
	unsigned Tag;
};

Person::Person()
{
}

Person::~Person()
{
}

#endif // !_PERSON_H_