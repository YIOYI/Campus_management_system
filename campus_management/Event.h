#ifndef _CURRICULUM_H_
#define _CURRICULUM_H_

#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include<fstream>
#include "_Time.h"
#include<unordered_set>
#include<unordered_map>
#include <QFile.h>
#include <QTextStream>
#include "Building.h"
//#include "Person.h"
using namespace std;

/**
 * @brief 储存事件开始和结束时间的结构体
 * @param start: 开始时间，time类
 * @param end :  结束时间，time类
*/
struct duration {
    _Time start;
    _Time end;
};


class Event               // 储存单个事件单次的信息,可以是课程也可以是其他事件
{
public:
    Event():Tag(0){ ; };
	~Event() { ; };
	friend class Curriculum;
	friend class Person;
    friend class Form1;
    friend class Form2;
    friend class Form3;
    friend class adminwdt;

	friend bool cmp(Event,Event);
    void init();

private:

    int periodicity;   //判断该事件是否是周期性事件
    _Time start;
    _Time end;
	vector<duration> time;  //Event类私有变量，储存这个事件所有的开始结束时间
    QString name;
    Building building;
	vector<int> weeks;      // 事件发生周次
    int Tag;           /*区分不同种类事件,1--必修;2--选修;3--集体事务;4--个人事务;5--临时事务*/

	vector<int> ID;         // 学生学号(2021xxx)
};


class Curriculum             //整个课表,储存所有的选修必修以及集体事务信息
{
public:
	Curriculum() { ; };
	~Curriculum() { ; };

	/**
	 * @brief 从文件中读入整个课表，储存在类curriculum中的vector<Event> events
	*/
	void createcurriculum();

    
	/**
	 * @brief 学生更新集体事务、管理员更新课表信息以及集体事务时用这个刷新文件中的数据
	*/
	void updatecurriculum();

	friend class Person;

    int type_num; //事件种类的数量

private:

	unordered_set<int> time;                  //用于检测某时间段是否已经有事件
	vector<Event> events;                     //储存所有的选修必修以及集体事务信息，学生每次登录时在这里获取个人的课表以及集体事务信息，个人事务和临时事务在另一个学生文件中获取

};



#endif // !_CURRICULUM_H_
