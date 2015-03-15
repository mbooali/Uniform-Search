
#include "Point.h"

#include <iostream>

using namespace std;
#ifndef LINEPART_LINEPART_LINEPART_LINEPART_LINEPART
#define LINEPART_LINEPART_LINEPART_LINEPART_LINEPART
#include "Line.h"

class LinePart
{
public:
	double gradient;
	double heightFromOrigin;
	bool isVertical;
	Point start;
	Point finish;

	LinePart(Point _start, Point _finish);
	Point* crosses(LinePart linePart);

	LinePart(void);
	~LinePart(void);
};
#endif