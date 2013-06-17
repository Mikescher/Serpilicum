#pragma once

#include "SnakeElement.h"
#include <cmath>
#include "SnakeModifier.h"
#include "PathFindingAlgorithm.h"

class Level;

const int SNAKEPARTCHARS[] = {186, 205, 186, 205, 200, 201, 187, 188, 'X'};

enum Direction {NORTH=0, EAST=1, SOUTH=2, WEST=3};
enum SnakeIntersecton {SIS_NULL=8, SIS_N=0, SIS_NE=4, SIS_E=1, SIS_ES=5, SIS_S=2, SIS_SW=6, SIS_W=3, SIS_NW=7};

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
	Direction getDirectionBetween(int x1, int y1, int x2, int y2);
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
	virtual SnakeElement* getElementAt(int pos);
	virtual Direction getDirection();
	virtual SnakeIntersecton getIntersectionOrientation(int position);
	virtual int findElement(SnakeElement* el);

	virtual void extendForward(int c);

	virtual void moveForward();
	virtual void extendForward();

	virtual void autoMoveForward();
	virtual void autoExtendForward();

	virtual void setDirection(Direction dir);
};

