#pragma once

#include "SnakeElement.h"

enum Direction {NORTH=0, EAST=1, SOUTH=2, WEST=3};

class Snake
{
private:
	SnakeElement * head;
	Direction direction;
public:
	Snake(void);
	Snake(int sx, int sy, Direction dir);
	~Snake(void);

	virtual int getLength();
	virtual SnakeElement * getHead();
	virtual void moveForward();
	virtual void extendForward();
};

