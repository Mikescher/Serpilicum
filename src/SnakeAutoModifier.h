#pragma once

#include "snakemodifier.h"
#include "AbstractConsole.h"

class Level;

class SnakeAutoModifier :
	public SnakeModifier
{
public:
	long startTime;
	long runDelta;
public:
	SnakeAutoModifier(Level* lvl, AbstractConsole *pConsole);
	virtual void run(Level* lvl, AbstractConsole *pConsole);

	virtual SnakeModifierType getType();
};

