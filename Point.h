#pragma once
#include <math.h>

class Point
{
public:
	float x,y;
	Point(float _x,float _y){x = _x; y = _y;}
	Point(void)
	{
		x = y = 0;
	}

	bool operator == (Point param)
	{
		if(x == param.x && y == param.y)
			return true;
		return false;
	}

	float distance(Point another){
        return (float) pow((double)(pow((double)(another.x - x), 2.0) + pow((double)(another.y - y), 2.0)),0.5);
    }
	~Point(void);
};
