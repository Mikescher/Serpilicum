#include "LevelObstacle.h"


LevelObstacle::LevelObstacle(int px, int py)
{
	x = px;
	y = py;
}

int LevelObstacle::getX() {
	return x;
}

int LevelObstacle::getY() {
	return y;
}