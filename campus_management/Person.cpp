#include"Person.h"
#include<QDebug>


void Person::get_perevents()
{
    bool judge;/*用于判断集体或者选修课是否有该学生*/
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
        Event tempevent;
        judge = false;

        tempevent.Tag = 0;

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

        int temp; /*临时变量*/
        if(tempevent.name.endsWith("考试"))//如果是考试则读取后面的周数
        {
            in1 >> temp;
            while(temp)
            {
                tempevent.weeks.push_back(temp);
                in1 >> temp;
            }
        }

        if(tempevent.Tag == 2)//如果是选修事务则读取后面的学生ID
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

            if(tempevent.name.endsWith("考试"))//如果是考试
            {
                 for(auto tempweek:tempevent.weeks)
                    for(int temphour = tempevent.start.hour();temphour!=tempevent.end.hour();temphour++)
                        perevents_time_set.insert(tempweek*MAX_ONE_WEEK + tempevent.start.day()*MAX_ONE_DAY + temphour);
            }
            else
            {
                 for(int temphour = tempevent.start.hour();temphour!=tempevent.end.hour();temphour++)
                    perevents_time_set.insert(tempevent.start.day()*MAX_ONE_DAY + temphour);
            }
        }
    }

    inFile1.close();

    /*从collective_event文件中读取集体事务*/

    while(!in2.atEnd())
    {
        Event tempevent;
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
            if(temp == ID)//该集体事件包括目前登录的学生
            {
                 if( perevents_time_set.find(tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour())!=perevents_time_set.end())//看是否有更新的必修选课与该事务冲突
                 {
                    log.append(number_to_week(tempevent.start.day())).append(QString::number(tempevent.start.hour()))
                        .append(":00").append("的集体事务").append(tempevent.name).append("被其他事务占用").append("\n");
                 }
                 else
                    judge = true;
            }
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
            for (auto& x : tempevent.weeks)
                perevents_time_set.insert(x*MAX_ONE_WEEK + tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour());
        }
        else
            othercollective.push_back(tempevent);
    }

    inFile2.close();

    /*从个人文件中读取个人、临时事务*/

    while (!in3.atEnd())
    {
        Event tempevent;
        QString tag_name;
        judge = false;
        in3 >> tempevent.Tag;

        switch(tempevent.Tag)
        {
            case 4:tag_name="个人事务";
            case 5:tag_name="临时事务";
        }

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

        if( perevents_time_set.find(tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour())!=perevents_time_set.end())//看是否有更新的必修选课与该事务冲突
        {
            log.append(number_to_week(tempevent.start.day())).append(QString::number(tempevent.start.hour()))
                .append(":00的").append(tag_name).append(tempevent.name).append("被其他事务占用").append("\n");
            tempevent.weeks.clear();
        }

        else
        {
            vector<int> weeks;
            for(auto x:tempevent.weeks)
            {
                if(perevents_time_set.find(x*MAX_ONE_WEEK + tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour())!=perevents_time_set.end())
                {
                    vector<int> index = find_index(x,tempevent.start.day(),tempevent.start.hour());
                    if(perEvents[tempevent.start.day()-1][tempevent.start.hour()-6][index[0]].Tag!=5)
                    {
                        log.append("第").append(QString::number(x)).append("周").append(number_to_week(tempevent.start.day())).append(QString::number(tempevent.start.hour()))
                        .append(":00的").append(tag_name).append(tempevent.name).append("被其他事务占用").append("\n");
                    }
                    else
                        weeks.push_back(x);
                }
                else
                    weeks.push_back(x);
            }
            tempevent.weeks.clear();
            tempevent.weeks=weeks;
        }

        if(tempevent.weeks.size()!=0)
            judge = true;

        if(judge == true)
        {
            perEvents[tempevent.start.day()-1][tempevent.start.hour()-6].push_back(tempevent); /*将临时变量读入类中对应的成员变量*/
            int row_index=tempevent.start.day()-1;
            int col_index=tempevent.start.hour()-6;


            if(namequeue.find(tempevent.name)==namequeue.end())/*判断该事件是否已经在set容器里，目的是记录一共有多少种事件*/
                event_names.push_back(tempevent.name);

            namequeue[tempevent.name].push_back({row_index,col_index,(int)perEvents[row_index][col_index].size()});
            for (auto& x : tempevent.weeks)
                perevents_time_set.insert(x*MAX_ONE_WEEK + tempevent.start.day()*MAX_ONE_DAY + tempevent.start.hour());
        }
    }

    inFile3.close();

}

void Person::get_admin_perevents()
{
    Map m;
    m.get_Map();
    int Building_id=0;
    bool judge;/*用于判断集体事务是否有该管理员*/
    vector<int> all_Student = {2021210, 2021211, 2021212, 2021213, 2021214, 2021215, 2021216, 2021217, 2021218, 2021219};

    QFile inFile1("./information_file/curriculum.txt");
    if (!inFile1.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";
    QTextStream in1(&inFile1);



    while (!in1.atEnd())
    {
        Event tempevent;
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
                in1 >> temp;
            }
        }
        else
            tempevent.ID =  all_Student;

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

    inFile1.close();

    QFile inFile2("./information_file/collective_event.txt");
    if (!inFile2.open(QIODevice::ReadOnly))
        qDebug() << "open failed curriculum.txt";
    QTextStream in2(&inFile2);

    /*从collective_event文件中读取集体事务*/


    while(!in2.atEnd())
    {
        Event tempevent;
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
                        out2<<a.name<<" ";
                        out2<<a.building.id_() << "\n";
                    }
                }
        }

    for(auto tempevent:othercollective)
    {
        out1<<tempevent.weeks.size()<<"  ";
        for(auto tempweek:tempevent.weeks)
            out1<<tempweek<<" ";
        out1<<"  ";
        out1<<tempevent.start.day()<<" ";
        out1<<tempevent.start.hour()<<" ";
        out1<<tempevent.end.hour()<<"  ";
        out1<<tempevent.name<<"   ";
        out1<<tempevent.building.id_() << " ";
        for(auto tempID:tempevent.ID)
            out1<<tempID<<" ";
        out1<<0<<"\n";
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
    int tempday = a.start.day();
    other_user.clear();
    allcollective_event_set.clear();

    if ( perevents_time_set.find(tempday * MAX_ONE_DAY + temphour) !=  perevents_time_set.end())//先检测与必修选修是否冲突,如果冲突必定失败
        return { 0,tempday,temphour,0 };

    if(a.Tag == 3)//如果是集体事务则需要同时检测加入的其他几个学生的冲突
    {
        for (auto tempweek : a.weeks)//先检测与本人事务是否冲突
        {
             if ( perevents_time_set.find(tempweek*MAX_ONE_WEEK + tempday *MAX_ONE_DAY + temphour) !=  perevents_time_set.end() )
            {
                vector<int> temporary_event =find_index(tempweek,tempday,temphour);
                if(perEvents[tempday-1][temphour-6][temporary_event[0]].Tag !=5)//如果不是临时事务则冲突
                {
                    return { tempweek,tempday,temphour,0 };
                }
            }
        }

        for(auto tempID:a.ID)
            other_user.insert(tempID);

        QFile inFile1("./information_file/curriculum.txt");
        if (!inFile1.open(QIODevice::ReadOnly))
            qDebug() << "open failed curriculum.txt";
        QTextStream in1(&inFile1);

        while(!in1.atEnd())
        {
            QString name;
            QString trash;
            vector<int>weeks;
            int tempweek;
            int tag;
            int day;
            int hour_s;
            int hour_e;
            int ID;

            tag =0;
            in1 >> tag;/*首先输出该集体事件周期数*/
            if(!tag)
                break;
            in1 >> day;
            in1 >> hour_s;
            in1 >> hour_e;
            in1 >> name;

            if(tag==2 && name.endsWith("考试"))
            {
                in1>>trash;//地点
                in1>>tempweek;//周数
                while(tempweek)
                {
                    weeks.push_back(tempweek);
                    in1>>tempweek;
                }

                in1>> ID;//学生ID
                while (ID)
                {
                    if(other_user.find(ID)!=other_user.end())//如果添加的考试中有该学生，则时间容器中加入这个事件的时间
                    {
                        for (auto tempweek : weeks)
                            for(int temphour=hour_s;temphour!=hour_e;temphour++)
                            {
                                if(allcollective_event_set.find(tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + temphour)==allcollective_event_set.end())//当前时间点是否有事务以及事务的个数
                                    allcollective_event_set[tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + temphour]=1;
                                else
                                    allcollective_event_set[tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + temphour]++;
                            }
                        break;
                    }
                    in1 >> ID;
                }
            }
            else
                in1.readLine();
        }
        inFile1.close();

        //检验其他学生集体事务
        for(auto tempevent:othercollective)
        {
            int day = tempevent.start.day();
            int hour_s =tempevent.start.hour();
            for(auto ID:tempevent.ID)
            {
                if(other_user.find(ID)!=other_user.end())//如果添加的集体事务中有该学生，则时间容器中加入这个事件的时间
                {
                    for (auto tempweek : tempevent.weeks)
                    {
                        if(allcollective_event_set.find(tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour_s)==allcollective_event_set.end())//当前时间点是否有事务以及事务的个数
                            allcollective_event_set[tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour_s]=1;
                        else
                            allcollective_event_set[tempweek*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour_s]++;
                    }
                }
            }
        }

        for (auto tempweek : a.weeks)//检测与其他学生的集体事务是否冲突
        {
            if (allcollective_event_set.find(tempweek*MAX_ONE_WEEK + tempday *MAX_ONE_DAY + temphour) !=  allcollective_event_set.end())
            {
                return { tempweek,tempday,temphour,0 };
            }
        }
    }

    else if(a.Tag == 4||a.Tag == 5)
    {
        for (auto tempweek : a.weeks)//检测个人、临时事务是否冲突
        {
            if ( perevents_time_set.find(tempweek*MAX_ONE_WEEK + tempday *MAX_ONE_DAY + temphour) !=  perevents_time_set.end())
            {
                if(a.Tag == 5)//临时事务与其他临时事务可以不冲突
                {
                    vector<int> temporary_event =find_index(tempweek,tempday,temphour);
                    if(temporary_event.size()==1 && perEvents[tempday-1][temphour-6][temporary_event[0]].Tag !=5)//如果该时间点已经有的事务不是临时事务则冲突
                        return { tempweek,tempday,temphour,0 };
                    else if(temporary_event.size() == 5)//如果该时间点已经有的事务是临时事务且临时事务已经到5则冲突
                        return { tempweek,tempday,temphour,0 };
                    else   //否则不冲突
                        ;
                }
                else
                    return { tempweek,tempday,temphour,0 };
            }
        }
    }
    return {0,0,0,1};//无冲突
}

vector<int> Person::find_index(int week,int day,int hour)
{
    vector<int> index_;
    if(perevents_time_set.find(week*MAX_ONE_WEEK +day *MAX_ONE_DAY + hour) ==  perevents_time_set.end()&&perevents_time_set.find(day *MAX_ONE_DAY + hour) ==  perevents_time_set.end())
        ;
    else if(perEvents[day-1][hour-6].size()==1 && (perEvents[day-1][hour-6][0].Tag == 1 || perEvents[day-1][hour-6][0].Tag==2))
        index_.push_back(0);
    else
    {
        for(int count =0;count< (int)perEvents[day-1][hour-6].size();count++)//遍历该时间点所有事件(day/hour)
        {
            for(auto a:perEvents[day-1][hour-6][count].weeks)//遍历改时间点每个事件所有周数，是否与week匹配
            {
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

vector<seektime> Person::findidle(seektime temp_time,int tag)
{
    int week = temp_time.week;
    int day = temp_time.day;
    int hour = 6;
    vector<seektime> idle_time;
    vector<pair<int,int>>times;


    while(hour<22)
    {
        if(perevents_time_set.find(day * MAX_ONE_DAY + hour) ==  perevents_time_set.end())//如果与必修选修冲突必定失败
        {
            if(tag == 1||tag ==2)
            {
                idle_time.push_back({week,day,hour,1});
            }

            else if(tag == 3)//集体事务检测所有参加学生的集体事务
            {
                if(allcollective_event_set.find(week*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour) != allcollective_event_set.end())//检测与参加学生的集体事务是否冲突
                {
                    times.push_back(make_pair(hour,allcollective_event_set[week*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour]));
                }

                else//如果与集体事务不冲突则成功,集体事务高于个人和临时事务
                {
                    idle_time.push_back({week,day,hour,1});
                }
            }
            else if(tag == 4)//个人事务则检测本人是否有事件冲突，个人事务遇到集体事务和临时事务都会冲突
            {
                if(perevents_time_set.find(week*MAX_ONE_WEEK + day *MAX_ONE_DAY + hour)==perevents_time_set.end())
                {
                    idle_time.push_back({week,day,hour,1});
                }
            }

            if((int)idle_time.size()==3)//最多给出三个空闲时间
                break;
        }
        hour++;
    }

    if(idle_time.size()==0)
    {
        if(tag==4) //个人事务未找到空闲时间直接宣布失败
            return idle_time;
        else if(tag == 3)
        {
            sort(times.begin(),times.end(),cmp_findidle);
            for(auto a:times)
            {
                idle_time.push_back({week,day,a.first,2});
                if(idle_time.size() == 3)
                    break;
            }
        }

    }

    return idle_time;
}

void Person::reorder(QString q)
{
    if((int)namequeue[q].size() > 1)
        sort(namequeue[q].begin(), namequeue[q].end(), cmp_reorder);
    else
        return;
}

bool cmp_reorder(arrayindex a, arrayindex b)
{
    return (a.first_index < b.first_index)||((a.first_index == b.first_index)&&(a.second_index < b.second_index));
}

bool cmp_findidle(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

void Person::init_perevents_time_set()
{
    perevents_time_set.clear();
    for(int day=0;day<DAY;day++)
        for(int hour=0;hour<HOURS;hour++)
        {
            for(int count=0;count<(int)perEvents[day][hour].size();count++)
            {
                if((perEvents[day][hour][count].Tag==1 || perEvents[day][hour][count].Tag==2))
                {
                    if(perEvents[day][hour][count].name.endsWith("考试"))//考试只在特定周有
                    {
                        for(auto x:perEvents[day][hour][count].weeks)
                        {
                            if(perevents_time_set.find(x*MAX_ONE_WEEK + day*MAX_ONE_DAY + hour)==perevents_time_set.end())
                                perevents_time_set.insert(x*MAX_ONE_WEEK + day*MAX_ONE_DAY + hour);
                        }
                    }
                    else if(perevents_time_set.find(day*MAX_ONE_DAY + hour)==perevents_time_set.end())//必修选修每周都有
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

QString number_to_week(int week)
{
    QString week_ch;
    switch(week)
    {
        case 1: week_ch="周一";break;
        case 2: week_ch="周二";break;
        case 3: week_ch="周三";break;
        case 4: week_ch="周四";break;
        case 5: week_ch="周五";break;
        case 6: week_ch="周六";break;
        case 7: week_ch="周日";break;
    }
    return week_ch;
}

