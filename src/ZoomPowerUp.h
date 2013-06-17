#pragma once

#include "powerup.h"
#include "AbstractConsole.h"

class ZoomPowerUp : public PowerUp
{
private:
	long ctime;
	AbstractConsole* console;
public:
	ZoomPowerUp(AbstractConsole* pCons, int px, int py);
	~ZoomPowerUp(void);

	virtual char getSymbol();
	virtual PowerUpType getType();
};

