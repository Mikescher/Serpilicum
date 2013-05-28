#include "PowerUp.h"


PowerUp::PowerUp(int px, int py)
{
	x = px;
	y = py;
}


PowerUp::~PowerUp(void)
{
	if (hasNextElement()) {
		delete next;
	}
}

bool PowerUp::hasNextElement() {
	return next != 0;
}

PowerUp * PowerUp::getNextElement() {
	return next;
}

void PowerUp::setNextElement(PowerUp * pnext) {
	next = pnext;
}

int PowerUp::getX() {
	return x;
}

int PowerUp::getY() {
	return y;
}