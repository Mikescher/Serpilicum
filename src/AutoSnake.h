#pragma once

#include "snake.h"
#include <math.h>
#include <algorithm>
#include <limits>
#include "PathFindingAlgorithm.h"

class Level;

class AutoSnake :
	public Snake
{
private:
	Level *level;
	PathFindingAlgorithm algo;
public:
	AutoSnake(void);
	AutoSnake(Level *lvl, int sx, int sy, Direction dir);
	~AutoSnake(void);

	void moveForward();
	void extendForward();

	Direction calcDirection();
	int getDistance(Direction& direction, int depth, int px, int py);
	int getFieldIdent(int px, int py);
	void getNearestPowerUp(int& px, int& py);
};

