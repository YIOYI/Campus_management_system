#ifndef _CURRICULUM_H_
#define _CURRICULUM_H_

#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include<fstream>
#include "Time.h"
//#include "Building.h"
//#include "Person.h"
using namespace std;

class Event
{
public:
	Event() { ; };
	~Event() { ; };
	friend class Curriculum;
	void init(Event& a);
private:
	Time start;
	Time end;
	string name;
	/*Building& building;*/
	vector<int> weeks;      //事件发生周次
	unsigned Tag;           //区分不同种类事件
	vector<int> ID;         //学生学号(2021xxx)
	vector<Event> event;
	vector<vector<int>> time_sort_;
};

class Curriculum
{
public:
	Curriculum() { ; };
	~Curriculum() { ; };
	void createcurriculum();
	void show();
	void search_one_day(int);
	void search_one_class(string);
	void sort_time();
private:
	vector<Event> events;
	vector<vector<int>> time_sort_;
	array<vector<int>, 7> time;
	array<vector<int>, 5> weight;
};


#endif // !_CURRICULUM_H_