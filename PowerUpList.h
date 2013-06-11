#pragma once

#include "PowerUp.h"
#include "DBConsole.h"

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

