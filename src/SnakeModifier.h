#pragma once

#include "AbstractConsole.h"

enum SnakeModifierType {SNAKEMODTYPE_NULL, SNAKEMODTYPE_PREAUTO, SNAKEMODTYPE_AUTO};

class Level;

class SnakeModifier
{
protected:
	bool running;
public:
	SnakeModifier(): running(true) {};
	virtual bool isRunning() {return running;};

	virtual void run(Level* lvl, AbstractConsole *pConsole) = 0;
	virtual SnakeModifierType getType() = 0;
};