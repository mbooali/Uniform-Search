#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "FringeElement.h"
#include "Point.h"
#include "Obstacle.h"
using namespace std;

class Program
{
public:
	int dimension;
    int numOfObstacles;
    Point start;
    Point finish;
    vector<Obstacle> obstacles;
    vector<FringeElement> fringe;
    vector<Point> path;      //path of nodes into goal
    vector<FringeElement> elements;
	Program(void);

	void setAttribute();
	bool isStraightPathBlocked(Point source, Point destination);
	vector<Point> getAllVertices();
	void updateFringe (vector<FringeElement>& fringe, Point point, FringeElement* parent);

	void expand (FringeElement fringeElem, vector<Point> allVertices);

	void uniformCostSearch()
	{
		int i;
		vector<Point> allVertices = getAllVertices();
		bool finishExplored = false;
		FringeElement source(start,0);
		source.parent = NULL;
		fringe.push_back(source);
		do {
			FringeElement minElem = fringe[0];
			for (i = 0; i < fringe.size(); i++) {
				if (fringe[i].vertice == finish) {
					path.push_back(finish);
					finishExplored = true;
					break;
				}
				else if (fringe[i].cost < minElem.cost) {
					minElem = fringe[i];
				}
			}
			if (!finishExplored) {
				if (path.empty()) {
					path.push_back(minElem.vertice);
				}
				else if ( !(path[path.size()-1] == minElem.vertice)) {
					path.push_back(minElem.vertice);
				}
				expand(minElem, allVertices);

				for (i = 0; i < fringe.size(); i++)
					if(minElem.vertice == fringe[i].vertice)
						break;
				fringe.erase(fringe.begin() + i);
			}
		} while (!finishExplored);
	}

	~Program(void);
};
