#include "Point.h"
#include "LinePart.h"
#include <iostream>
using namespace std;

#ifndef LINE_LINE_LINE_LINE_LINE_LINE_LINE_LINE_LINE
#define LINE_LINE_LINE_LINE_LINE_LINE_LINE_LINE_LINE

class LinePart;

class Line
{
public:
	Point first;
	Point second;
	double gradient;
	double heightFromOrigin;
	bool isVertical;
	Line(void);
	Line(Point _first, Point _second);
	Point* crosses(LinePart);

	~Line(void);
};
#endif