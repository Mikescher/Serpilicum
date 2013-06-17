#pragma once
#include "leveleffect.h"
class BiteEffect :
	public LevelEffect
{
private:
	long startTime;
	int delay;

	long delta;
	int mode;
	int elementchar;
public:
	BiteEffect(int px, int py, int delayID, int elchar);
	~BiteEffect(void);

	virtual void start(AbstractConsole *console);
	virtual void run(AbstractConsole *console);
	virtual void render(AbstractConsole *console);
};

