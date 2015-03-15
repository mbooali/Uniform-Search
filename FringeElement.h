#pragma once
#include "Point.h"
#include <iostream>

using namespace std;

class FringeElement
{
public:
	Point vertice;
    float cost;
    FringeElement* parent;
	FringeElement(Point _vertice, float _cost){
        vertice = _vertice;
        cost = _cost;
        parent = NULL;
    }

	FringeElement(){
		Point pp(0,0);
        vertice = pp;
        cost = 0;
        parent = NULL;
    }

	~FringeElement(void);
};
