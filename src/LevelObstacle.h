#pragma once

#include "AbstractConsole.h"

class Level;

class LevelObstacle
{
protected:
	int x;
	int y;
public:
	LevelObstacle(int px, int py);
	
	virtual int getX();
	virtual int getY();

	virtual void init(AbstractConsole* pConsole) = 0;
	virtual void run(AbstractConsole* pConsole) = 0;
	virtual void render(AbstractConsole* pConsole) = 0;
	virtual bool onSnakeHit(Level* level) = 0;
};

