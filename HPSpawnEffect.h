#pragma once
#include "leveleffect.h"

const int HPSE_EFFECT_DELAY = 125;

class HPSpawnEffect :
	public LevelEffect
{
private:
	long startTime;
	int mode;

	virtual void renderMode0(DBConsole *console);
	virtual void renderMode1(DBConsole *console);
	virtual void renderMode2(DBConsole *console);
public:
	HPSpawnEffect(int px, int py);
	~HPSpawnEffect(void);

	virtual void start(DBConsole *console);
	virtual void run(DBConsole *console);
	virtual void render(DBConsole *console);
};

