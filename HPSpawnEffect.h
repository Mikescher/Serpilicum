#pragma once
#include "leveleffect.h"

const int HPSE_EFFECT_DELAY = 125;

class HPSpawnEffect :
	public LevelEffect
{
private:
	long startTime;
	int mode;

	virtual void renderMode0(AbstractConsole *console);
	virtual void renderMode1(AbstractConsole *console);
	virtual void renderMode2(AbstractConsole *console);
public:
	HPSpawnEffect(int px, int py);
	~HPSpawnEffect(void);

	virtual void start(AbstractConsole *console);
	virtual void run(AbstractConsole *console);
	virtual void render(AbstractConsole *console);
};

