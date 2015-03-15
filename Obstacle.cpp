#include "Obstacle.h"
#include "LinePart.h"
Obstacle::Obstacle(void)
{
}

Obstacle::~Obstacle(void)
{
}

bool Obstacle::blocks(Point source, Point destination)
{
	int i,j;
	LinePart sourceToDest(source, destination);
    LinePart* verticeConnector = NULL;
    Point* junctionPoint = NULL;
	for (i = 0;i < vertices.size(); i++){
        for(j = 0;j < vertices.size(); j++){
            if(!(vertices[j] == vertices[i])){
                verticeConnector = new LinePart(vertices[i], vertices[j]);
                if ((junctionPoint = sourceToDest.crosses(*verticeConnector)) != NULL)
                    return true;
				delete verticeConnector;
            }
        }
    }

    return false;
}
