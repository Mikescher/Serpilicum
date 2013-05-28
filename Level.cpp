#include "Level.h"
#include <iostream>
#include "HealthPowerUp.h"

Level::Level(void)
{
	snake = new Snake(FIELD_W / 2, FIELD_H / 2, EAST);
	powerupList = new PowerUpList();

	powerupList->add(new HealthPowerUp(3, 3));
	powerupList->add(new HealthPowerUp(5, 3));
	powerupList->add(new HealthPowerUp(5, 9));
	powerupList->add(new HealthPowerUp(9, 12));

	snake->extendForward();
	snake->extendForward();
	snake->extendForward();
	snake->extendForward();
}


Level::~Level(void)
{
	delete snake;
}

void Level::run(){
	snake->moveForward();
}

Snake * Level::getSnake() {
	return snake;
}

PowerUpList * Level::getPowerUpList() {
	return powerupList;
}