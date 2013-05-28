#pragma once
#include "powerup.h"
class HealthPowerUp :
	public PowerUp
{
public:
	HealthPowerUp(int px, int py);
	~HealthPowerUp(void);

	virtual char getSymbol();
};

