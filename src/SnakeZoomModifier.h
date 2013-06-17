#pragma once
#include "snakemodifier.h"
class SnakeZoomModifier :
	public SnakeModifier
{
private:
	long startTime;
	long runDelta;
public:
	SnakeZoomModifier(Level* lvl, AbstractConsole *pConsole);
	virtual void run(Level* lvl, AbstractConsole *pConsole);

	virtual SnakeModifierType getType();
};

