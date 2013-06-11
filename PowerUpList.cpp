#include "PowerUpList.h"
#include "HealthPowerUp.h"
#include <stdlib.h>
#include "DBConsole.h"

PowerUpList::PowerUpList(void)
{
	//create
}


PowerUpList::~PowerUpList(void)
{
}

int PowerUpList::getLength() {
	int l = 0;

	PowerUp * el = first;

	while(el != 0) {
		el = el->getNextElement();
		l++;
	}

	return l;
}

PowerUp * PowerUpList::getFirst() {
	return first;
}

PowerUp * PowerUpList::getLast() {
	PowerUp * el = first;

	while(el != 0 && el->hasNextElement()) {
		el = el->getNextElement();
	}

	return el;
}

bool PowerUpList::isEmpty() {
	return first == 0;
}

void PowerUpList::add(PowerUp * p) {
	if (!isEmpty()) {
		getLast()->setNextElement(p);
	} else {
		first = p;
	}
}

bool PowerUpList::remove(PowerUp * p) {
	if (first == 0) {
		return false;
	}

	if (first == p) {
		first = first->getNextElement();
		p->setNextElement(0);
		delete p;
		return true;
	}

	PowerUp * el = first;
	while(el->hasNextElement() && el->getNextElement() != p) {
		el = el->getNextElement();
	}

	if (el->hasNextElement()) {
		el->setNextElement(el->getNextElement()->getNextElement());
		p->setNextElement(0);
		delete p;
		return true;
	} else {
		return false;
	}
}