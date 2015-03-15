#include "Line.h"


Line::Line(void)
{
}

Line::~Line(void)
{
}

Line::Line(Point _first, Point _second){
    first = _first;
    second = _second;

    isVertical = (first.x == second.x);

    if(!isVertical) {
        gradient = (second.y - first.y) / (second.x - first.x);
        heightFromOrigin = first.y - gradient * first.x;
    }
}

Point* Line::crosses(LinePart linePart) {
	if (linePart.start == linePart.finish) {
		return NULL;
	}
	Point* crossPoint = new Point();
	if (isVertical && linePart.isVertical) {
		return NULL;
	}
	else if (!isVertical && linePart.isVertical){
		crossPoint->x = linePart.start.x;
		crossPoint->y = (float)(gradient * crossPoint->x + heightFromOrigin);
	}
	else if (isVertical && !linePart.isVertical){
		crossPoint->x = first.x;
		crossPoint->y = (float)(linePart.gradient * crossPoint->x + linePart.heightFromOrigin);
	}
	else if (!isVertical && !linePart.isVertical) {
		/*returns true only crosses the line part not any of its continuations */
		if (gradient == linePart.gradient){
			return NULL;
		}
		else {
			crossPoint->x = (float)((linePart.heightFromOrigin - heightFromOrigin) / (gradient - linePart.gradient));
			crossPoint->y = (float)(gradient * crossPoint->x + heightFromOrigin);
		}
	}
	if ((crossPoint->y > linePart.start.y && crossPoint->y < linePart.finish.y)
		|| (crossPoint->y > linePart.finish.y && crossPoint->y < linePart.start.y)){
			return crossPoint;
	}
	if ((crossPoint->x > linePart.start.x && crossPoint->x < linePart.finish.x)
		|| (crossPoint->x > linePart.finish.x && crossPoint->x < linePart.start.x)){
			return crossPoint;
	}
	return NULL;
}
