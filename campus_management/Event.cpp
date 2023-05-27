#include"Event.h"
#include<QDebug>


void Event::init()
{
    if(!time.empty())
        time.clear();

    building.Building_clear();
    start.day() = start.hour() = end.day() = end.hour() = Tag = 0;
    name.clear();

    if (!ID.empty())
        ID.clear();

    if (!weeks.empty())
        weeks.clear();
}

void Curriculum::createcurriculum()
{
    type_num = 0;
    Event a; /*临时变量，储存每次从文件里读取的事件*/
    duration temptime; /*临时变量，储存时间*/
    QFile inFile("./information_file/curriculum.txt");
    unordered_set<QString> NAME;

    if (!inFile.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";

    QTextStream in(&inFile);

    while (!in.atEnd())/*文件格式:事件类型-事件时间-事件名称-参与学生(可选)*/
	{
        in>>a.Tag; /*读取事件类型*/

        if(a.Tag==0) /*判断文件是否读到末尾*/
            break;

        /*读取事件开始和结束时间*/
        in >> a.start.day();
        in >> a.start.hour();
        a.end.day() = a.start.day();
        in >> a.end.hour();
        in >> a.name;/*读取事件名称*/

        if(NAME.find(a.name)==NAME.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
        {
            NAME.insert(a.name);
            type_num++;
        }

        /*输入学生学号，学生学号有多个，所以以0结尾*/
        int temp; /*临时变量，储存学号*/
        while (a.Tag == 2)
        {
            in >> temp; /*循环读取学生学号*/

            if (!temp)
				break;
			else
				a.ID.push_back(temp);
        }

        events.push_back(a); /*将临时变量读入储存所有课表信息的容器events*/

        a.init();/*清空临时变量*/
	}

    inFile.close();
}

void Curriculum::updatecurriculum()
{
    QFile outFile("curriculum.txt");

    if (!outFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "open failed curriculum.txt";
    }

    QTextStream out(&outFile);

		for (auto x : events)
		{
            out << x.Tag << " ";

            out << x.start.day() << " ";
            out << x.start.hour() << " ";
            out << x.end.hour() << " ";
            out << x.name << " ";
            out << x.building.id_() << " ";

            if (x.Tag == 2)
			{
				for (auto id : x.ID)
                    out << id << " ";
                out << 0 ;
			}
         out << "\n";
		}
        outFile.close();
}


