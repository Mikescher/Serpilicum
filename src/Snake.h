#pragma once

#include "SnakeElement.h"
#include <cmath>
#include "SnakeModifier.h"
#include "PathFindingAlgorithm.h"

class Level;

enum Direction {NORTH=0, EAST=1, SOUTH=2, WEST=3};

class Snake
{
private: // PathFinding
	Level *level;
	PathFindingAlgorithm* algo;
	bool lastSearchFailed;
	bool doNotRecalc;

	Direction calcDirection();
	int getFieldIdent(int px, int py);
	void getNearestPowerUp(int& px, int& py);
	void getRandomPowerUp(int& px, int& py);
	bool isDirectionFree(Direction d);
private:
	SnakeElement * head;
	Direction direction;
public:
	Snake(Level *lvl, int sx, int sy, Direction dir);
	virtual ~Snake(void);

	virtual void onBeforeMove(Level* lvl, AbstractConsole* pConsole);
	virtual void onAfterMove(Level* lvl, AbstractConsole* pConsole); 

	virtual int getLength();
	virtual SnakeElement * getHead();
	virtual Direction getDirection();

	virtual void extendForward(int c);

	virtual void moveForward();
	virtual void extendForward();

	virtual void autoMoveForward();
	virtual void autoExtendForward();

	virtual void setDirection(Direction dir);
	
};

