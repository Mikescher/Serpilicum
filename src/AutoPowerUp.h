#pragma once

#include "powerup.h"
#include "AbstractConsole.h"

class AutoPowerUp :
	public PowerUp
{
private:
	long ctime;
	AbstractConsole* console;
public:
	AutoPowerUp(AbstractConsole* pCons, int px, int py);
	~AutoPowerUp(void);

	virtual char getSymbol();
	virtual PowerUpType getType();
};

