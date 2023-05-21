#ifndef _TIMET_H_
#define _TIMET_H_
#include<iostream>
using namespace std;

class Time         // 储存时间的类，包括week_、day_、hour_,有三个public成员函数可以返回这三个变量的引用
{
public:
    Time(int m = 0, int d = 0, int h = 0) :
        week_(m), day_(d), hour_(h) {};
    ~Time() { ; };

    /**
     * @brief 返回Time储存的私有成员变量week_的引用 
    */
    int& week() { return week_; };

	/**
	* @brief 返回Time储存的私有成员变量day_的引用
   */
	int& day() { return day_; };

	/**
	* @brief 返回Time储存的私有成员变量hour_的引用
   */
	int& hour() { return hour_; };

	int week_ = 0;
	int day_ = 0;
	int hour_ = 0;
};
 
#endif 
