#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<fstream>
#include <string>
#include <QFile.h>
#include <QTextStream>
#include "Event.h"
#define MAX_ONE_DAY 100
#define MAX_ONE_WEEK 800
#define DAY 7
#define HOURS 16
//#include "Building.h"

using namespace std;

/**
 * @brief  sort函数的cmp
 * @param  a 要比较的第一个事件
 * @param  b 要比较的第二个事件
 * @return 从小到大排序
*/
bool cmp(Event, Event);

struct arrayindex  //储存perevent下标，用于map第二个参数
{
	int first_index;
	int second_index;
	int count; //自动计数器,分每个value
};

struct seektime //储存时间,用于iscollision函数返回值
{
	int week;
	int day;
	int hour;
    int tag;   //判断该时间点是否空闲
};


class Person                 // 一个储存单个学生信息的类，储存学生姓名、id、密码、课表
{
public:
    Person(QString name_="\0", int i = 0, int pass = 0, int TAG = 0) :name(name_), ID(i), password(pass), Tag(TAG) { ; };
	~Person() { ; };

	/**
     * @brief 从大课表中和该学生私人的文件中读出该学生的所有事件,储存在vector<Event> perEvents[DAY][HOURS]
    */
    void get_perevents();

	/**
	 * @brief 更新个人事务、临时事务表和集体活动的文件，选修必修课不能被学生增加修改
	*/
    void update_perevents();

	/**
	 * @brief 用于检测时间段是否发生冲突
     * @return 返回一个时间类表示冲突的时间
	*/
    seektime iscollision(Event &);

	/**
	* @brief 如果学生输入事件与已有事件时间发生冲突，则调用该函数寻找当天空闲的三个时间段
	*/
	void findidle();

	/**
	 * @brief 对所有事务按照时间进行排序
	*/
	void reorder();

    int &getID() { return ID; };
    int &getpassword(){return password;};
    QString &getname(){return name;};

	friend class Students;
    friend class Form1;
private:
    QString name;
	int ID;
	int password;

    int type_num; //事件种类的数量
    int curriculun_type_num; //课表种类数量
    int collective_event_type_num;//集体事务种类数量
    int personal_event_type_num; //个人事务种类数量
    vector<Event> perEvents[DAY][HOURS];//储存单个学生的所有事件
    vector<vector<int>> seq_to_event_index;  //储存每种事件所有的下标

    unordered_map<QString, int> namequeue;           //通过事件名字可以找到该事件序号
    unordered_map<int, arrayindex> perevents_map;     //判断该时间是否有事件以及事件在perevents中的位置

	/*Building position;	*/			            //学生当前位置
	unsigned Tag;
};


class Students                              //一个储存所有学生的信息的类
{
public:
	Students() {};
	~Students() {};

	/**
	 * @brief 从文件里获取所有学生的信息（id、name、password），每次有用户登录时调用一次。
	* @param 无参数，直接修改students类里面的vector<Person> students。
	 * @return 无返回值
	*/
    void get_students_information();

	/**
	 * @brief 打印出所有学生信息
	*/
	void show_students_information();

	/**
	 * @brief 获取Students类中储存所有学生信息的私有变量vector<Person> students
	 * @return vector<Person> students的引用。
	*/
	vector<Person>& students_information() { return students; };

	friend Person code_put();
    int getindex(int ID){return ID_index[ID];};//参数为学生ID，返回该学生信息在students数组中的下标
private:
    unordered_map<int, int>  ID_index;     // 通过学生ID查找在students数组的下标
	vector<Person> students;               // Students类的私有成员变量，储存所有学生id、name、password

};
#endif 
