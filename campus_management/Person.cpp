#include"Person.h"
#include<QDebug>


void Person::get_perevents()
{
    bool judge;/*用于判断集体或者选修课是否有该学生*/
    int seq = 0;/*计数，每种事件第一次出现给它编号*/
    Event tempevent; /*临时变量，储存每次从文件读入的一个事件*/
    duration temptime; /*临时变量，储存时间*/
    Map m;
    m.get_Map();
    int Building_id=0;

    QFile inFile1("./information_file/curriculum.txt");
    if (!inFile1.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";
    QTextStream in1(&inFile1);

    QFile inFile2("./information_file/collective_event.txt");
    if (!inFile2.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";
    QTextStream in2(&inFile2);

    QString filename ="./information_file/perevent/";
    filename += QString::number(ID);
    filename += ".txt";    /*读取储存学生个人事务临时事务的文件*/
    QFile inFile3(filename);
    if(!inFile3.open(QIODevice::ReadOnly))
        qDebug() << "open failed"<< ID <<".txt";
    QTextStream in3(&inFile3);


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
        in1 >> Building_id;
        tempevent.building=m.Get_i_Building(Building_id);

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
            int row_index=tempevent.start.day()-1;
            int col_index=tempevent.start.hour()-6;
            for(int temphour = tempevent.start.hour();temphour!=tempevent.end.hour();temphour++)
            {
                perEvents[row_index][temphour-6].push_back(tempevent);
            }

            if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
                 event_names.push_back(tempevent.name);

            namequeue[tempevent.name].push_back({row_index,col_index,(int)perEvents[row_index][col_index].size()});
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
        in2 >> Building_id;
        tempevent.building=m.Get_i_Building(Building_id);

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

            if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
                event_names.push_back(tempevent.name);

            namequeue[tempevent.name].push_back({row_index,col_index,(int)perEvents[row_index][col_index].size()});
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
        in3 >> Building_id;
        tempevent.building=m.Get_i_Building(Building_id);

        perEvents[tempevent.start.day()-1][tempevent.start.hour()-6].push_back(tempevent); /*将临时变量读入类中对应的成员变量*/
        int row_index=tempevent.start.day()-1;
        int col_index=tempevent.start.hour()-6;


        if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
            event_names.push_back(tempevent.name);

        namequeue[tempevent.name].push_back({row_index,col_index,(int)perEvents[row_index][col_index].size()});
    }

       inFile3.close();

    init_perevents_time_set();

}

void Person::update_perevents()
{
    const QString filename_collective = "./information_file/collective_event.txt";    //更新储存学生集体事务临时事务的文件
    const QString filename_perevent = "./information_file/perevent/" + QString::number(ID) + ".txt";    //更新储存学生个人事务临时事务的文件
    QFile outFile1(filename_collective);
    QFile outFile2(filename_perevent);

    QTextStream out1(&outFile1);
    QTextStream out2(&outFile2);
    if(!outFile1.open(QIODevice::WriteOnly))
    {
        qDebug() << "open failed"<<QString::number(ID)<<".txt";
        return;
    }

    else if(!outFile2.open(QIODevice::WriteOnly))
    {
        qDebug()<<"./information_file/collective_event.txt";
        return ;
    }

    for(int day=0;day<DAY;day++)
        for(int hour =0;hour<HOURS;hour++)
        {
            if(perEvents[day][hour].size()!=0)
                for(auto a:perEvents[day][hour])
                {
                    if(a.Tag ==1 ||a.Tag==2)
                        ;
                    else if(a.Tag==3)
                    {
                        out1<<a.weeks.size()<<"  ";
                        for(auto tempweek:a.weeks)
                            out1<<tempweek<<" ";
                        out1<<"  ";
                        out1<<a.start.day()<<" ";
                        out1<<a.start.hour()<<" ";
                        out1<<a.end.hour()<<"  ";
                        out1<<a.name<<"   ";
                        out1<<a.building.id_() << " ";
                        for(auto tempID:a.ID)
                            out1<<tempID<<" ";
                        out1<<0<<"\n";
                    }
                    else if(a.Tag ==4 ||a.Tag==5)
                    {
                        out2<<a.Tag<<"  ";
                        out2<<a.weeks.size();
                        for(auto tempweek:a.weeks)
                            out2<<tempweek<<" ";
                        out2<<"  ";
                        out2<<a.start.day()<<" ";
                        out2<<a.start.hour()<<" ";
                        out2<<a.end.hour()<<"  ";
                        out2<<a.name<<"\n";
                        out2<<a.building.id_() << " ";
                    }
                }
        }

    outFile1.close();
    outFile2.close();

}

void Students::get_students_information() {
    int count=0;//用于记录学生信息在文件中的位置，即第几个
    QFile inFile("./information_file/students.txt");
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

    if ( perevents_time_set.find(day * MAX_ONE_DAY + temphour) !=  perevents_time_set.end())//先检测与必修选修是否冲突
        return { 0,day,temphour,0 };
    for (auto tempweek : a.weeks)//检测与其他事务是否冲突
    {
        if ( perevents_time_set.find(tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + temphour) !=  perevents_time_set.end())
        {
            if(a.Tag == 5)//临时事务与其他临时事务可以不冲突
            {
                vector<int> temporary_event =find_index(tempweek,day,temphour);
                if(temporary_event.size()==1 && perEvents[day-1][temphour-6][temporary_event[0]].Tag !=5)//如果该时间点已经有的事务不是临时事务则冲突
                    return { tempweek,day,temphour,0 };
                else if(temporary_event.size() == 5)//如果该时间点已经有的事务是临时事务且临时事务已经到5则冲突
                    return { tempweek,day,temphour,0 };
                else   //否则不冲突
                    ;
            }
            else
                return { tempweek,day,temphour,0 };
        }
    }
    return {0,0,0,1};//无冲突
}

vector<int> Person::find_index(int week,int day,int hour)
{
    qDebug()<<perEvents[day-1][hour-6].size();
    vector<int> index_;
    if(perEvents[day-1][hour-6].size()<1)
        ;
    else if(perEvents[day-1][hour-6].size()==1 && (perEvents[day-1][hour-6][0].Tag == 1 || perEvents[day-1][hour-6][0].Tag==2))
        index_.push_back(0);
    else
    {
        for(int count =0;count< (int)perEvents[day-1][hour-6].size();count++)//遍历该时间点所有事件(day/hour)
        {
            //qDebug()<<count;
            for(auto a:perEvents[day-1][hour-6][count].weeks)//遍历改时间点每个事件所有周数，是否与week匹配
            {
                qDebug()<<a;
                if(a==week)//匹配成功插入index
                {
                    index_.push_back(count);
                    break;
                }
            }
        }
    }
    return index_;
}

vector<seektime> Person::findidle(seektime temp_time)
{
    int week = temp_time.week;
    int day = temp_time.day;
    int hour = temp_time.hour;
    vector<seektime> idle_time;

    while(1)
    {
        hour++;
        if(perevents_time_set.find(day * MAX_ONE_DAY + hour) ==  perevents_time_set.end() && perevents_time_set.find(week*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour) ==  perevents_time_set.end())
        {
            idle_time.push_back({week,day,hour,1});
            if((int)idle_time.size()==3)
                break;
        }
        if(hour == 21)
        {
            hour=0;
            day++;
        }
        if(day == 8)
        {
            day=0;
            week++;
        }
        if(week > 16)
            break;
    }
    return idle_time;
}

void Person::reorder(QString q)
{
    if((int)namequeue[q].size() > 1)
        sort(namequeue[q].begin(), namequeue[q].end(), cmp);
    else
        return;
}

bool cmp(arrayindex a, arrayindex b)
{
    return (a.first_index < b.first_index)||((a.first_index == b.first_index)&&(a.second_index < b.second_index));
}

void Person::init_perevents_time_set()
{
    perevents_time_set.clear();
    for(int day=0;day<DAY;day++)
        for(int hour=0;hour<HOURS;hour++)
        {
            for(int count=0;count<(int)perEvents[day][hour].size();count++)
            {
                if(perEvents[day][hour][count].Tag==1 || perEvents[day][hour][count].Tag==2)
                {
                    if(perevents_time_set.find(day*MAX_ONE_DAY + hour)==perevents_time_set.end())
                        perevents_time_set.insert(day*MAX_ONE_DAY + hour);
                }
                else
                {
                    for(auto x:perEvents[day][hour][count].weeks)
                    {
                        if(perevents_time_set.find(x*MAX_ONE_WEEK + day*MAX_ONE_DAY + hour)==perevents_time_set.end())
                            perevents_time_set.insert(x*MAX_ONE_WEEK + day*MAX_ONE_DAY + hour);
                    }
                }
            }
        }
}
