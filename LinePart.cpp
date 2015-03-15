#include "LinePart.h"

LinePart::LinePart(void)
{
}

LinePart::~LinePart(void)
{
}

LinePart::LinePart(Point _start, Point _finish){
        start = _start;
        finish = _finish;
        isVertical = (start.x == finish.x);

        if(!isVertical) {
            gradient = (finish.y - start.y) / (finish.x - start.x);
            heightFromOrigin = start.y - gradient * start.x;
        }
}

Point* LinePart::crosses(LinePart linePart) {
		if (linePart.start == linePart.finish || start == finish){
			return NULL;
		}
		Line line(start, finish);
		Point* junctionPoint = line.crosses(linePart);
		if(junctionPoint == NULL) {
			return NULL;
		}
		else {
			if ((junctionPoint->x > start.x && junctionPoint->x < finish.x) ||
				(junctionPoint->x > finish.x && junctionPoint->x < start.x) ||
				(junctionPoint->y > start.y && junctionPoint->y < finish.y) ||
				(junctionPoint->y > finish.y && junctionPoint->y < start.y)){
					return junctionPoint;
			}
			else {
				return NULL;
			}
		}
	}