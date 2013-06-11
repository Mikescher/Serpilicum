#pragma once

#include "snake.h"
#include <math.h>

class Level;

class AutoSnake :
	public Snake
{
private:
	Level *level;
public:
	AutoSnake(void);
	AutoSnake(Level *lvl, int sx, int sy, Direction dir);
	~AutoSnake(void);

	void moveForward();
	void extendForward();

	void calcDirection();
	double getDistanceToNearestPowerUp(int x, int y);
};

