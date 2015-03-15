#pragma once
#include <vector>
#include "Point.h"

using namespace std;
class Obstacle
{
public:
	int numOfVertices;
	vector<Point> vertices;
	
	bool blocks(Point source, Point destination);

	Obstacle(void);
	~Obstacle(void);
};
