#include"Building.h"
#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QChar>


    //Buildings文件的格式为：编号 建筑名 坐标 能到达的建筑的编号 换行 最后一行没有换行
int Building::get_Building(QString& inLine)
{
    int s = 0,r = 0;
	Roads.clear();
    name.clear();
    //qDebug()<<inLine;
    QString::iterator itr = inLine.begin();
    id=0;
    for( ;itr != inLine.end()&&(*itr!=' '&&*itr!='\t');itr++)
    {
        s =itr->toLatin1()-'0';
        id=id*10+s;
    }
    itr++;
    for( ;itr != inLine.end()&&*itr!=' '&&*itr!='\t';itr++)
        name.append(*itr);
    for( ;itr != inLine.end()&&(*itr==' '||*itr=='\t');itr++);

    point.x=0;
    for( ;itr != inLine.end()&&(*itr!=' '&&*itr!='\t');itr++)
    {
        s =itr->toLatin1()-'0';
        point.x=point.x*10+s;

    }
    itr++;

    point.y=0;
    for( ;itr != inLine.end()&&(*itr!=' '&&*itr!='\t');itr++)
    {
        s =itr->toLatin1()-'0';
        point.y=point.y*10+s;

    }
    itr++;
    while (*itr!='\t')
    {
        r=0;
        for( ;itr != inLine.end()&&(*itr!=' '&&*itr!='\t');itr++)
        {
            s =itr->toLatin1()-'0';
            r=r*10+s;   
        }
        Roads.push_back(r);
        if(*itr=='\t')
            break;
        itr++;
    }
    return 0;
}
void Building::Building_clear()
{
    id=0;
    point={0,0};
    name="";
    Roads.clear();
}
Building::Building(const Building& p)
{
	id = p.id;
	point = p.point;
	name = p.name;
    Roads.clear();
    for (auto iter=p.Roads.begin();iter!=p.Roads.end();iter++)
        Roads.push_back(*iter);
}
int Map::get_Map() 
{
    QFile file(":/txt/Buildings.txt");
    bool isOk=file.open(QIODevice::ReadOnly);
    if (!isOk)
	{
        qDebug() << "open failed";
		return 1;
	}
	Building A;
    QTextStream in(&file);

    for (int i=0;i<Building_Number;i++)
	{
        QString qstr=in.readLine();
        A.get_Building(qstr);
        Buildings.push_back(A);
//        qDebug()<<A.name<<A.id<<A.point.x<<A.point.y;
//        for(auto it=A.Roads_().begin();it!=A.Roads_().end();it++)
//            qDebug()<<' '<<*it;
	}

    for (auto &b : Buildings)
        for (auto& a : b.Roads)
            b.distance[a] = b - Buildings[a];

    file.close();

    QChar c;
    QFile netfile("./information_file/net.txt");
    if(netfile.open(QIODevice::ReadOnly)==false)
    {
        qDebug()<<"net.txt读打开失败";
        return 0;
    }
    QTextStream netin(&netfile);
    while(!netin.atEnd())
    {
        Building netA;
        netin>>netA.id>>c>>netA.name>>c;
                qDebug()<<netA.name<<netA.id<<netA.point.x<<netA.point.y;
                for(auto it=netA.Roads_().begin();it!=netA.Roads_().end();it++)
                    qDebug()<<' '<<*it;
        Buildings.push_back(netA);
    }

    netfile.close();
    return 0;
}
int Map::findBuilding(const QString &name)
{
    int id=0;
    auto iter=Buildings.begin();
    for( ;iter!=Buildings.end();iter++)
    {
        if(iter->name==name)
            break;
        id++;
    }
    if(iter==Buildings.end())
        return -1;
    return id;
}
void Map::save_netBuilding(const QString& netname)
{
    Building netA;
    netA.id=Buildings.size();
    netA.name=netname;
    Buildings.push_back(netA);

    QFile file("./information_file/net.txt");
    QTextStream in(&file);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append )==false)
        qDebug()<<"net.txt读打开失败";
    else
    {
        in<<netA.id<<' '<<netA.name<<'\n';
    }
    file.close();

}
