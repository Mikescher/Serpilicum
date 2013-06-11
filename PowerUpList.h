#pragma once

#include "PowerUp.h"
#include "AbstractConsole.h"

class PowerUpList
{
private:
	PowerUp * first;
public:
	PowerUpList(void);
	~PowerUpList(void);

	virtual int getLength();
	virtual PowerUp * getFirst();
	virtual PowerUp * getLast();
	virtual bool isEmpty();
	virtual void add(PowerUp * p);
	virtual bool remove(PowerUp * p);
};

