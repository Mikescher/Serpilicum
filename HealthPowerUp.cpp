#include "HealthPowerUp.h"


HealthPowerUp::HealthPowerUp(int px, int py) : PowerUp(px, py)
{
}


HealthPowerUp::~HealthPowerUp(void)
{
}

char HealthPowerUp::getSymbol() {
	return 'O';
}