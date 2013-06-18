#pragma once
#include "leveleffect.h"

const int HPSE_EFFECT_DELAY = 125;

class PowerUpSpawnEffect :
	public LevelEffect
{
private:
	long startTime;
	int mode;

	virtual void renderMode0(AbstractConsole *console);
	virtual void renderMode1(AbstractConsole *console);
	virtual void renderMode2(AbstractConsole *console);

	virtual void write(AbstractConsole* console, int cr, int x, int y);
public:
	PowerUpSpawnEffect(int px, int py);
	~PowerUpSpawnEffect(void);

	virtual void start(AbstractConsole *console);
	virtual void run(AbstractConsole *console);
	virtual void render(AbstractConsole *console);
};

