#include"Event.h"
#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include<fstream>

void Event::init(Event& a)
{
	a.start.day = a.start.hour = a.end.day = a.end.hour = a.Tag = 0;
	a.name = '\0';
	if (!a.ID.empty())
		a.ID.clear();
	if (!a.weeks.empty())
		a.weeks.clear();
}

void Curriculum::createcurriculum()
{

	Event a; int temp;
	ifstream inFile;
	inFile.open("curriculum.txt", ios_base::in);
	if (!inFile.is_open())
	{
		cout << "open failed";
	}

	while (1)
	{
		a.init(a);
		inFile >> a.start.day;
		if (a.start.day == 0)
			break;
		inFile >> a.start.hour;
		a.end.day = a.start.day;
		inFile >> a.end.hour;
		/*inFile >> name;*/
		inFile >> a.name;
		inFile >> a.Tag;
		while (a.Tag != 1 && inFile >> temp)
		{
			if (!temp)
				break;
			else
				a.ID.push_back(temp);
		}

		if (a.Tag != 1 && a.Tag != 2)
			for (int i; inFile >> i;)
			{
				if (!i)
					break;
				else
					a.weeks.push_back(i);
			}
		events.push_back(a);
	}
}

void Curriculum::show(/*vector<Event>& a*/)
{
	int j = 0;
	for (int i = 0; i < events.size(); i++)
	{
		cout << "星期" << events[i].start.day << " " << left << setw(2) << events[i].start.hour << ":00--" << left << setw(2) << events[i].end.hour << ":00  ";
		cout << left << setw(18) << events[i].name;
		if (events[i].Tag == 1)
			cout << "  必修课";
		else if (events[i].Tag == 2)
		{
			j = 0;
			cout << "  选修课  该课学生有：";
			while (j < events[i].ID.size())
			{
				cout << events[i].ID[j] << " ";
				j++;
			}
		}
		cout << endl;
	}
}
void Curriculum::sort_time()          //按时间排序
{
	time_sort_.resize(7); /*int j;*/
	for (int i = 0; i < events.size(); i++)      //i代表文件输入时event的序号
	{
		time_sort_[events[i].start.day - 1].push_back(i);
	}
	//for(int i=0;i<7;i++)
	//	for (j = 0; j < time_sort_[i].size(); j++)
	//	{
	//		cout << time_sort_[i][j]<<"  ";
	//	}
}

void Curriculum::search_one_day(int day)   //查找一天课表
{
	int j = 0; day = day - 1;
	cout << "星期" << day + 1 << "的课表" << endl;
	for (int i = 0; i < time_sort_[day].size(); i++)
	{
		cout << left << setw(2) << events[time_sort_[day][i]].start.hour << ":00--" << left << setw(2) << events[time_sort_[day][i]].end.hour << ":00  ";
		cout << left << setw(18) << events[time_sort_[day][i]].name;
		if (events[time_sort_[day][i]].Tag == 1)
			cout << "  必修课";
		else if (events[time_sort_[day][i]].Tag == 2)
		{
			j = 0;
			cout << "  选修课  该课学生有：";
			while (j < events[time_sort_[day][i]].ID.size())
			{
				cout << events[time_sort_[day][i]].ID[j] << " ";
				j++;
			}
		}
		cout << endl;
	}
}
void Curriculum::search_one_class(string a)         //查找一门课的信息
{

}