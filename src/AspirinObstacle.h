#pragma once

#include "levelobstacle.h"

class Level;

class AspirinObstacle :
	public LevelObstacle
{
private:
	int dx;
	int dy;
	long lastMove;
public:
	AspirinObstacle(int px, int py, int deltax, int deltay);

	virtual bool isHorizontal();

	virtual void init(AbstractConsole* pConsole);
	virtual void run(AbstractConsole* pConsole);
	virtual void render(AbstractConsole* pConsole);
	virtual bool onSnakeHit(Level* level);
};

