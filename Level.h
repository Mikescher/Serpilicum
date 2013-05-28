#pragma once

#include "Snake.h";
#include "PowerUpList.h"

const int FIELD_W = 76;
const int FIELD_H = 36;

class Level
{
private:
	Snake * snake;
	PowerUpList * powerupList;
public:
	Level(void);
	~Level(void);

	virtual void run();
	virtual Snake * getSnake();
	virtual PowerUpList * getPowerUpList();
};

