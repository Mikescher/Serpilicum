#include "Level.h"
#include <iostream>
#include "HealthPowerUp.h"
#include "Keycodes.h"

Level::Level(void)
{
	running = false;
	lastRenderTime = 0;

	snake = new Snake(FIELD_W / 2, FIELD_H / 2, EAST);
	powerupList = new PowerUpList();

	snake->extendForward();
	snake->extendForward();
	snake->extendForward();
	snake->extendForward();
}


Level::~Level(void)
{
	delete snake;
}

void Level::start(){
	running = true;
}

void Level::stop(){
	running = false;
}

void Level::run(DBConsole* pConsole) {
	long curr = pConsole->getCurrentTimeMillis();

	if ((curr - lastRenderTime) > 50) {
		if (! testForHPCollision()) {
			snake->moveForward();
		}

		getPowerUpList()->addMissingHealthPowerUps(pConsole);

		lastRenderTime = curr;
	}
}

Snake * Level::getSnake() {
	return snake;
}

PowerUpList * Level::getPowerUpList() {
	return powerupList;
}

bool Level::isRunning(){
	return running;
}

void Level::render(DBConsole* pConsole)
{
	renderSnake(pConsole);
	renderPowerups(pConsole);
}

void Level::renderSnake(DBConsole *console) {
	SnakeElement * snakeelement = getSnake()->getHead();

	while(snakeelement != 0) {
		console->write('#', snakeelement->getX(), snakeelement->getY());

		snakeelement = snakeelement->getNextElement();
	}
}

void Level::renderPowerups(DBConsole *console) {
	PowerUp * pelem = getPowerUpList()->getFirst();

	while(pelem != 0) {
		console->write(pelem->getSymbol(), pelem->getX(), pelem->getY());

		pelem = pelem->getNextElement();
	}
}

void Level::onKeyDown(int keycode) {
	if (keycode == KC_UP) {
		snake->setDirection(NORTH);
	} else if (keycode == KC_DOWN) {
		snake->setDirection(SOUTH);
	} else if (keycode == KC_LEFT) {
		snake->setDirection(WEST);
	} else if (keycode == KC_RIGHT) {
		snake->setDirection(EAST);
	}
}

bool Level::testForHPCollision() {
	PowerUp * pelem = getPowerUpList()->getFirst();

	while(pelem != 0) {
		if (pelem->getX() == snake->getHead()->getX() && pelem->getY() == snake->getHead()->getY()) {
			getPowerUpList()->remove(pelem);
			snake->extendForward();
			return true;
		}

		pelem = pelem->getNextElement();
	}

	return false;
}