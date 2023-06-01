#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <QString>
#include <vector>
#include <QTextStream>
#include <deque>
#include <vector>
#include <unordered_map>

using namespace std;
constexpr int Building_Number = 134;

class Map;

class Point
{
public:
    Point(int a = 0, int b = 0) :
		x(a), y(b) {};
	~Point() { ; };
    int& x_() { return x; }
    int& y_() { return y; }
	friend class Building;
	friend class Road;
	friend class Map;

    /**
     * @brief 在Point类中重载运算符-
     * @param rhs 另一个操作数
     * @return 返回两点之间的距离
    */
    int operator- (const Point& rhs) { return abs(rhs.x - this->x + rhs.y - this->y); }

private:
    int x = 0;
    int y = 0;
};


class Building
{
public:
    Building(int n = 0, QString a = "unknow", vector<int> r = {  }) :
        id(n),name(a),Roads(r) {};
	~Building() { ; };
	Building(const Building& p);  //拷贝构造
    void Building_clear();  //清除
    int  get_Building(QString& inLine); //返回0读取成功，返回1则读取失败，遇到文件结尾
    int& id_() { return id; }
    QString& name_() { return name; }
	Point& point_() { return point; }
	vector<int>& Roads_() { return Roads; }
	friend class Map;

    /**
     * @brief 构建本建筑的最短路径树
     * @param mp 北邮地图
     * @return 建筑的前节点与距离的数组
    */
    vector<pair<int, int>> Dijkstra(Map& mp);

    /**
     * @brief 计算本建筑到指定建筑的最短距离
     * @param end 指定建筑
     * @param tree 最短路径树，第一个元素是每个建筑的前驱，第二个元素是两者之间距离
     * @return 最短路径
    */
    int Calculate_length(int end, vector<pair<int, int>>& tree);

    /**
     * @brief 计算本建筑到指定建筑的最短路径编号
     * @param end 指定建筑
     * @param mp 北邮地图
     * @return 最短路径编号
    */
    deque<int> ShortestPath(int end, Map& mp);

    deque<int> ShortestPath(int end, vector<pair<int, int>>& tree);

    /**
     * @brief 计算本建筑到指定建筑的最短路径编号
     * @param end 指定建筑数组
     * @param tree 北邮地图
     * @return 最短路径编号
    */
    deque<int> ShortestPath(vector<int> end, Map& mp);

    /**
     * @brief 在Building类中重载运算符-
     * @param rhs 另一个操作符
     * @return 两建筑物之间的距离
    */
    int operator- (const Building& rhs) { return this->point - rhs.point; }

private:
    int id = 0;
    Point point;
    QString name;
	vector<int> Roads;
    unordered_map<int, int> distance;
};
class Map
{
public:
	Map() { ; };
	~Map() { ; };

	vector<Building>& Buildings_() { return Buildings; }
    int findBuilding(const QString &name);  //找到返回位置，没有返回-1
	int get_Map();
    void save_netBuilding(const QString& netname);

    /**
     * @brief 获取第i个Building
     * @param i 想要获取的建筑的编号
     * @return 第i个Building的全部信息
    */
    Building& Get_i_Building(int i) { return Buildings[i]; };
private:
	vector<Building>  Buildings;

};


#endif // !_BUILDING_H_

#pragma once
