#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <string>
using namespace std;

class Point
{
public:
	Point();
	~Point();

private:
	int x = 0;
	int y = 0;
};

Point::Point()
{
}

Point::~Point()
{
}


class Building
{
public:
	Building();
	~Building();

private:
	string Name;
	Point point;
};

Building::Building()
{
}

Building::~Building()
{
}



class Road
{
public:
	Road();
	~Road();

private:
	Building A;
	Building B;
};

Road::Road()
{
}

Road::~Road()
{
}

#endif // !_BUILDING_H_

#pragma once