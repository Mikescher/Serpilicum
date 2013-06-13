#pragma once

#include "snake.h"
#include <math.h>
#include <algorithm>
#include <limits>
#include <stdlib.h>
#include "PathFindingAlgorithm.h"
#include "Gamerules.h"

class Level;

class AutoSnake :
	public Snake
{
private:
	Level *level;
	PathFindingAlgorithm* algo;
	bool lastSearchFailed;

private:
	Direction calcDirection();
	int getFieldIdent(int px, int py);
	void getNearestPowerUp(int& px, int& py);
	void getRandomPowerUp(int& px, int& py);
	bool isDirectionFree(Direction d);
public:
	AutoSnake(void);
	AutoSnake(Level *lvl, int sx, int sy, Direction dir);
	~AutoSnake(void);

	void moveForward();
	void extendForward();
};

