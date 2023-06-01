#ifndef _PERSON_H_
#define _PERSON_H_

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
#define WEEKS 16
//#include "Building.h"

using namespace std;

struct arrayindex  //储存perevent下标，用于map第二个参数
{
    int first_index;//天-1
    int second_index;//小时-6
    int count; //自动计数器,分每个value,注意每次获取下标要-1
};

struct seektime //储存时间,用于iscollision函数返回值
{
	int week;
	int day;
	int hour;
    int tag;   //判断该时间点是否空闲||1--是否找到空闲时间||2--找到的是冲突最少的时间
};


/**
 * @brief  sort函数的cmp
 * @param  a 要比较的第一个事件
 * @param  b 要比较的第二个事件
 * @return 从小到大排序
*/
bool cmp_reorder(arrayindex, arrayindex);

bool cmp_findidle(pair<int,int> a,pair<int,int> b);

QString number_to_week(int week);


class Person               // 一个储存单个学生信息的类，储存学生姓名、id、密码、课表
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
    vector<seektime> findidle(seektime temp_time,int tag);

	/**
	 * @brief 对所有事务按照时间进行排序
	*/
    void reorder(QString);

    void init_perevents_time_set();

    vector<int> find_index(int week,int day,int hour);//第A周第B天第B小时的事件在perEvents[B-1][B-6]中的下标位置,如果是临时事务可能有多个

    vector<arrayindex> find_name(QString p){return namequeue[p];};

    int &getID() { return ID; };
    int &getpassword(){return password;};
    QString &getname(){return name;};
    vector<QString> &getevent_name(){return event_names;};
    void inputlog(QString a){log.append(a);};//输入学生消息通知

	friend class Students;
    friend class Form1;
    friend class Form2;
    friend class Form3;

private:
    QString name;
	int ID;
	int password;
    QString log;

    vector<Event> perEvents[DAY][HOURS];//储存单个学生的所有事件,第一个下标为事件day-1，第二个为事件开始时间-6

    vector<Event> othercollective;

    unordered_map<QString, vector<arrayindex>> namequeue;           //通过事件名字可以找到该事件序号
    unordered_set<int> perevents_time_set;     //判断该时间是否有事件以及事件在perevents中的位置
    vector<QString> event_names;

	/*Building position;	*/			            //学生当前位置
    unsigned Tag;
    enum {STUDENT, ADMIN};

    /*暂时用来储存其他学生的信息*/
    unordered_set <int> other_user; //添加临时事务时用来储存学生学号
    unordered_map<int,int> allcollective_event_set;//所有集体事务的时间，用于检测集体事务冲突，第二个参数为当前时间点的事务个数
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
