#include"Person.h"
#include<QDebug>


void Person::get_perevents()
{

    bool judge;/*用于判断集体或者选修课是否有该学生*/
    int seq = 0;/*计数，每种事件第一次出现给它编号*/
    Event tempevent; /*临时变量，储存每次从文件读入的一个事件*/
    duration temptime; /*临时变量，储存时间*/

    QFile inFile1("curriculum.txt");
    if (!inFile1.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";
    QTextStream in1(&inFile1);

    QFile inFile2("collective_event.txt");
    if (!inFile2.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";
    QTextStream in2(&inFile2);

    const QString filename = name + ".txt";    /*读取储存学生个人事务临时事务的文件*/
    QFile inFile3(filename);
    if(!inFile3.open(QIODevice::ReadOnly))
        qDebug() << "open failed"<<name<<".txt";
    QTextStream in3(&inFile3);

    int num;
    in1 >> num; type_num = num; curriculun_type_num = num;

    in2 >> num; type_num += num; collective_event_type_num = num;

    in3 >> num; type_num += num; personal_event_type_num = num;

    seq_to_event_index.resize(type_num);

     /*从文件读入数据，顺序为事件标签、周数、分别第几周、开始时间、结束时间、时间名称*/

    /*从文件里读入课表数据*/

    while (!in1.atEnd())
    {
        judge = false;

        in1>>tempevent.Tag; /*读取事件类型*/

        if(tempevent.Tag==0) /*判断文件是否读到末尾*/
            break;

        /*读取事件开始和结束时间*/
        in1 >> tempevent.start.day();
        in1 >> tempevent.start.hour();
        tempevent.end.day() = tempevent.start.day();
        in1 >> tempevent.end.hour();
        in1 >> tempevent.name;/*读取事件名称*/

        /*输入学生学号，学生学号有多个，所以以0结尾*/
        int temp; /*临时变量，储存学号*/
        if(tempevent.Tag == 2)
        {
            in1 >> temp;
            while(temp)/*循环读取学生学号*/
            {
                tempevent.ID.push_back(temp);
                if(temp == ID)
                    judge = true;
                in1 >> temp;
            }
        }
        else
            judge = true;

        if(judge)
        {
            perEvents[tempevent.start.day()-1][tempevent.start.hour()-6].push_back(tempevent);
            int row_index=tempevent.start.day()-1;
            int col_index=tempevent.start.hour()-6;
            for(int temphour = tempevent.start.hour();temphour!=tempevent.end.hour();temphour++)
                perevents_map[tempevent.start.day()*MAX_ONE_DAY + temphour] = {row_index,col_index,temphour};/*将非空闲时间插入perevents_map中，便于之后检测时间冲突*/
            if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
            {
                namequeue[tempevent.name]=seq;
                seq++;
                seq_to_event_index[seq].push_back(row_index * MAX_ONE_DAY + col_index);/*储存同一种事件的所有下标,便于查找*/
            }
            else /*如果该事件已经出现了，通过namequeue容器找到该事件序号，然后在seq_to_event_index[seq]数组里添加当前事件下标*/
                seq_to_event_index[namequeue[tempevent.name]].push_back(row_index * MAX_ONE_DAY + col_index);
        }

    }

    inFile1.close();

    /*从collective_event文件中读取集体事务*/

    while(!in2.atEnd())
    {
        judge = false;

        tempevent.periodicity = 0;/*判断文件是否到末尾*/
        tempevent.Tag = 3; /*全是集体事务*/
        in2 >> tempevent.periodicity;/*首先输出该集体事件周期数*/

        if(!tempevent.periodicity)
            break;

        tempevent.weeks.resize(tempevent.periodicity); /*根据读取的事件周数来分配事件发生周weeks的大小*/
        for (auto& x : tempevent.weeks)
            in2 >> x;

        in2 >> tempevent.start.day();
        in2 >> tempevent.start.hour();
        in2 >> tempevent.end.hour(); /*开始和结束同一天，不重复读入day*/
        in2 >> tempevent.name;/*读取事件名称*/

        /*输入学生学号，学生学号有多个，所以以0结尾*/
        int temp; /*临时变量，储存学号*/
        in2 >> temp; /*循环读取学生学号*/
        while (temp)
        {
            tempevent.ID.push_back(temp);
            if(temp == ID)
                judge = true;
            in2 >> temp;
        }

        if(judge)
        {
            perEvents[tempevent.start.day()-1][tempevent.start.hour()-6].push_back(tempevent);
            int row_index=tempevent.start.day()-1;
            int col_index=tempevent.start.hour()-6;
            /*将非空闲时间插入perevents_map中，便于之后检测时间冲突*/
            for(auto x:tempevent.weeks)
                perevents_map[x*MAX_ONE_WEEK + tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour()] = {row_index,col_index,x};
            if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
            {
                namequeue[tempevent.name]=seq;
                seq++;
                seq_to_event_index[seq].push_back(row_index * MAX_ONE_DAY + col_index);/*储存同一种事件的所有下标,便于查找*/
            }
            else /*如果该事件已经出现了，通过namequeue容器找到该事件序号，然后在seq_to_event_index[seq]数组里添加当前事件下标*/
                seq_to_event_index[namequeue[tempevent.name]].push_back(row_index * MAX_ONE_DAY + col_index);
        }
    }

    inFile2.close();

    /*从个人文件中读取个人、临时事务*/

    while (!in3.atEnd())
	{
        in3 >> tempevent.Tag;

        if(!tempevent.Tag)
            break;
        in3 >> tempevent.periodicity;

        tempevent.weeks.resize(tempevent.periodicity); /*根据读取的事件周数来分配 事件发生周weeks的大小*/
		for (auto& x : tempevent.weeks)
            in3 >> x;

        in3 >> tempevent.start.day();
        in3 >> tempevent.start.hour();
        in3 >> tempevent.end.hour(); /*开始和结束同一天，不重复读入day*/
        in3 >> tempevent.name;

        perEvents[tempevent.start.day()-1][tempevent.start.hour()-6].push_back(tempevent); /*将临时变量读入类中对应的成员变量*/
        int row_index=tempevent.start.day()-1;
        int col_index=tempevent.start.hour()-6;
        /*将非空闲时间插入perevents_map中，便于之后检测时间冲突*/
        for(auto x:tempevent.weeks)
            perevents_map[x*MAX_ONE_WEEK + tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour()] = {row_index,col_index,x};
        if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
        {
            namequeue[tempevent.name]=seq;
            seq++;
            seq_to_event_index[seq].push_back(row_index * MAX_ONE_DAY + col_index);/*储存同一种事件的所有下标,便于查找*/
        }
        else /*如果该事件已经出现了，通过namequeue容器找到该事件序号，然后在seq_to_event_index[seq]数组里添加当前事件下标*/
            seq_to_event_index[namequeue[tempevent.name]].push_back(row_index * MAX_ONE_DAY + col_index);
	}

    type_num = seq;
    qDebug()<<type_num;

    inFile3.close();

}

void Person::update_perevents()
{
    const QString filename = name + ".txt";    //更新储存学生个人事务临时事务的文件
    QFile outFile(filename);
    QTextStream out(&outFile);
    if(!outFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "open failed"<<name<<".txt";
        return;
    }

    /*for(auto y:perevents)
		for (auto x : y)
		{
            out << x.Tag<<"  ";
            out << x.periodicity << "    ";
			for (auto p : x.weeks)
                out << p<<" ";
            out << "   ";
            out << x.start.day() << " ";
            out << x.start.hour() << " ";
            out << x.end.hour() << " ";
            out << x.name;
            out << "\n";
        }*/

    outFile.close();

}


void Students::get_students_information() {
    int count=0;//用于记录学生信息在文件中的位置，即第几个
    QFile inFile("students.txt");
    if (!inFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "open failed students.txt";
    }
    QTextStream in(&inFile);
    while (!in.atEnd())
	{
		Person a("\0",0,0,0);
        in >> a.ID;

		if (!a.ID)
			break;
        in >> a.name;

        ID_index[a.ID] = count;
        in >> a.password;

		students.push_back(a);
        count++;
	}
}


seektime Person::iscollision(Event &a)
{
	int temphour = a.start.hour();
    int day = a.start.day();

    if ( perevents_map.find(day * MAX_ONE_DAY + temphour) !=  perevents_map.end())//先检测与必修选修是否冲突
        return { 0,day,temphour,0 };
    for (auto tempweek : a.weeks)//检测与其他事务是否冲突
    {
        if ( perevents_map.find(tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + temphour) !=  perevents_map.end())
            return { tempweek,day,temphour,0 };
    }
    return {0,0,0,1};
}



/*
void Person::findidle()
{

}

void Person::reorder()
{
	for (int day = 0; day < 7; day++)
	{
		sort(perCurriculum[day].begin(), perCurriculum[day].end(), cmp);
		sort(peractivity[day].begin(), peractivity[day].end(), cmp);
	}
}

bool cmp(Event a, Event b)
{
	if (a.start.hour() > b.start.hour())
		return 0;
	else
		return 1;
}
*/
