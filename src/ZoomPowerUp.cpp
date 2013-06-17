#include "ZoomPowerUp.h"


ZoomPowerUp::ZoomPowerUp(AbstractConsole* pCons, int px, int py) : PowerUp(px, py)
{
	console = pCons;
}


ZoomPowerUp::~ZoomPowerUp(void)
{
}

char ZoomPowerUp::getSymbol() {
	int p = (console->getCurrentTimeMillis() / 150) % 4;

	switch (p) {
	case 0: return '+';
	case 1: return '#';
	case 2: return '-';
	case 3: return '#';
	default: return '#';
	}
}

PowerUpType ZoomPowerUp::getType() {
return POWERUP_ZOOM;
}