#include "AutoPowerUp.h"


AutoPowerUp::AutoPowerUp(AbstractConsole* pCons, int px, int py) : PowerUp(px, py)
{
	console = pCons;
}


AutoPowerUp::~AutoPowerUp(void)
{
}

char AutoPowerUp::getSymbol() {
	int p = (console->getCurrentTimeMillis() / 250) % 4;

	switch (p) {
	case 0: return '-';
	case 1: return '\\';
	case 2: return '|';
	case 3: return '/';
	default: return '+';
	}
}

PowerUpType AutoPowerUp::getType() {
return POWERUP_AUTO;
}