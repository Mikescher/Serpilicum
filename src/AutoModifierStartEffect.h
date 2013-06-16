#pragma once
#include "leveleffect.h"
class AutoModifierStartEffect :
	public LevelEffect
{
private:
	long startTime;
	int x1;
	int x2;
	int y1;
	int y2;
public:
	AutoModifierStartEffect(int px, int py);
	~AutoModifierStartEffect(void);

	virtual void start(AbstractConsole *console);
	virtual void run(AbstractConsole *console);
	virtual void render(AbstractConsole *console);
};

