#include "Program.h"

Program::Program(void)
{
}

Program::~Program(void)
{
}

void Program::setAttribute()
{
	Obstacle obstacle;
	Point vertice;
	fstream in;
	int i,j;
	char* a;
	char x;
	in.open("input.txt", fstream::in);
	in >> dimension >> start.x >> start.y >> finish.x >> finish.y >> numOfObstacles;
	a = new char[100];
	in.getline(a,100);
	delete a;

	for(i = 0; i < numOfObstacles; i++){
		obstacle.vertices.clear();
		stringstream ss;
		a = new char[100];		
		in.getline(a,100);
		int sp_tedad = 0;
		j = 0;
		while(a[j] != NULL)
		{
			if(a[j] == ' ')
				sp_tedad++;
			j++;
		}
		ss << a;
		delete a;
		sp_tedad++;

		obstacle.numOfVertices = sp_tedad / 2;

		for(int j=0; j<obstacle.numOfVertices; j++)
		{
			ss >> vertice.x >> vertice.y;
			obstacle.vertices.push_back(vertice);
		}
		obstacles.push_back(obstacle);
	}
	return;
}

bool Program::isStraightPathBlocked(Point source, Point destination)
{
	int i;
	for (i = 0; i < obstacles.size(); i++)
		if (obstacles[i].blocks(source, destination))
			return true;
	return false;
}

vector<Point> Program::getAllVertices()
{
	int i,j;
    vector<Point> allVertices;
    allVertices.push_back(start);
    allVertices.push_back(finish);
	for(i = 0; i < obstacles.size(); i++)
		for(j = 0; j < obstacles.size(); j++)
			allVertices.push_back(obstacles[i].vertices[j]);
    return allVertices;
}

void Program::updateFringe (vector<FringeElement>& fringe, Point point, FringeElement* parent)
{
	int i;
	bool exists = false;
	float newCost = parent->cost + parent->vertice.distance(point);

	for (i = 0; i < fringe.size(); i++) {
		if (fringe[i].vertice == point) {
			exists = true;

			if (newCost < fringe[i].cost) {
				fringe[i].cost = newCost;
				fringe[i].parent = parent;
			}                
		}
	}
	if (!exists) {
		FringeElement elem;
		elem.vertice = point;
		elem.cost = newCost;
		elem.parent = parent;
		fringe.push_back(elem);
	}

}
void Program::expand (FringeElement fringeElem, vector<Point> allVertices)
{
	int i;
	for (i = 0; i < allVertices.size(); i++)
		if (!(allVertices[i] == fringeElem.vertice))
			if (!isStraightPathBlocked(fringeElem.vertice, allVertices[i]))
				updateFringe(fringe, allVertices[i], &fringeElem);
}