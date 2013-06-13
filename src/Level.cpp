#include "Level.h"
#include <iostream>
#include "HealthPowerUp.h"
#include "Keycodes.h"

Level::Level(void)
{
	running = false;
	is_dead = false;

	snake_speed = 50;

	lastRenderTime = 0;
	lastPowerupAdd = 0;

	snake = new AutoSnake(this, FIELD_W / 2, FIELD_H / 2, EAST);
	powerupList = new PowerUpList();
	
	snake->extendForward(5);

	//snake->extendForward(BUFFER_W - 2 - 5);
	//snake->setDirection(NORTH);
	//snake->extendForward(1);
	//snake->setDirection(EAST);

	//snake->extendForward(BUFFER_W - 2);
	//snake->setDirection(NORTH);
	//snake->extendForward(1);
	//snake->setDirection(EAST);

	//snake->extendForward(BUFFER_W - 2);
	//snake->setDirection(NORTH);
	//snake->extendForward(1);
	//snake->setDirection(EAST);

	//snake->extendForward(BUFFER_W - 2);
	//snake->setDirection(NORTH);
	//snake->extendForward(1);
	//snake->setDirection(EAST);
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

void Level::run(AbstractConsole* pConsole) {
	long curr = pConsole->getCurrentTimeMillis();

	if ((curr - lastRenderTime) > snake_speed) {
		if (! testForHPCollision()) {
			snake->moveForward();
		} else {
			snake->extendForward();
		}

		addMissingHealthPowerUps(pConsole);

		lastRenderTime = curr;

		testForDeath();
	}

	runEffects(pConsole);
}

void Level::runEffects(AbstractConsole *console) {
	for(int i = effects.size()-1; i >= 0; i--) {
		effects.at(i)->run(console);

		if (! (effects.at(i)->isAlive())) { // remove dead
			effects.erase(effects.begin() + i);
		}
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

void Level::render(AbstractConsole* pConsole)
{
	renderEffects(pConsole);
	renderPowerups(pConsole);
	renderSnake(pConsole);
}

void Level::renderSnake(AbstractConsole *console) {
	SnakeElement * snakeelement = getSnake()->getHead();

	while(snakeelement != 0) {
		console->write('#', snakeelement->getX(), snakeelement->getY());

		snakeelement = snakeelement->getNextElement();
	}
}

void Level::renderPowerups(AbstractConsole *console) {
	PowerUp * pelem = getPowerUpList()->getFirst();

	while(pelem != 0) {
		console->write(pelem->getSymbol(), pelem->getX(), pelem->getY());

		pelem = pelem->getNextElement();
	}
}

void Level::renderEffects(AbstractConsole *console) {
	for(unsigned int i = 0; i < effects.size(); i++) {
		effects.at(i)->render(console);
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
			return true;
		}

		pelem = pelem->getNextElement();
	}
	return false;
}

void Level::addMissingHealthPowerUps(AbstractConsole * pConsole) {
	long curr = pConsole->getCurrentTimeMillis();

	if ((curr - lastPowerupAdd) > 500) {

		if (getPowerUpList()->getLength() < 32) {
			addHealthPowerUps(pConsole, 1);
		}

		lastPowerupAdd = curr;
	}
}

void Level::addHealthPowerUps(AbstractConsole *pconsole, int count) {
	for(int i = 0; i < count; i++) {
		int x = rand() % BUFFER_W;
		int y = rand() % BUFFER_H;
		if (! isPositionUsed(x, y)) {
			addHealthPowerUps(pconsole, x, y);
		}
	}
}

void Level::addHealthPowerUps(AbstractConsole *pConsole, int hpux, int hpuy) {
	getPowerUpList()->add(new HealthPowerUp(hpux, hpuy));
	addEffect(pConsole, new HPSpawnEffect(hpux, hpuy));
}

bool Level::isPositionPowerUp(int xx, int yy) {
	PowerUp * pelem = getPowerUpList()->getFirst();

	while(pelem != 0) {
		if (pelem->getX() == xx && pelem->getY() == yy) {
			return true;
		}

		pelem = pelem->getNextElement();
	}

	return false;
}

bool Level::isPositionSnake(int xx, int yy) {
	SnakeElement * snakeelement = getSnake()->getHead();

	while(snakeelement != 0) {
		if (snakeelement->getX() == xx && snakeelement->getY() == yy) {
			return true;
		}

		snakeelement = snakeelement->getNextElement();
	}

	return false;
}

bool Level::isPositionUsed(int xx, int yy) {
	return isPositionPowerUp(xx, yy) || isPositionSnake(xx, yy);
}

void Level::testForDeath() {
	//##############################
	// COLLSION WITH SNAKE PIECE
	//#############################
	
	SnakeElement * snakeelement = getSnake()->getHead();
	while(snakeelement != 0) {
		SnakeElement * prevelem = 0;

		SnakeElement * snakeelement2 = getSnake()->getHead();
		while(snakeelement2 != 0) {
			if (snakeelement->getX() == snakeelement2->getX() && snakeelement->getY() == snakeelement2->getY() && snakeelement != snakeelement2) {
				if (GAMERULE_DieOnSelfContact) {
					onDie();
				} else if (GAMERULE_BiteOnSelfContact && prevelem != 0){
					std::cout << "BITE DA SNAKE" << std::endl;
					prevelem->removeNextElement();
				}
				return;
			}

			prevelem = snakeelement2;
			snakeelement2 = snakeelement2->getNextElement();
		}
		snakeelement = snakeelement->getNextElement();
	}

	//##############################
	// OUT OF BORDER
	//#############################

	SnakeElement * snakeelement3 = getSnake()->getHead();
	while(snakeelement3 != 0) {
		if (snakeelement3->getX() < 0 || snakeelement3->getY() < 0 || snakeelement3->getX() >= BUFFER_W || snakeelement3->getY() >= BUFFER_H) {
			onDie();
		}

		snakeelement3 = snakeelement3->getNextElement();
	}
}

void Level::onDie() {
	is_dead = true;
	stop();
}

bool Level::isDead() {
	return is_dead;
}

void Level::addEffect(AbstractConsole *console, LevelEffect * effect) {
	effects.push_back(effect);
	effect->start(console);
}