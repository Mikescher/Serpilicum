#include "Level.h"
#include "Snake.h"
#include <iostream>
#include "HealthPowerUp.h"
#include "AutoPowerUp.h"
#include "Keycodes.h"
#include "SnakeAutoModifier.h"
#include "AutoModifierStartEffect.h"
#include "SnakeZoomModifier.h"
#include "BiteEffect.h"
#include "ZoomPowerUp.h"

Level::Level(void)
{
	running = false;
	is_dead = false;
	modifier = 0;

	lifes = INITIAL_LIFE_SHARDS;
	snake_speed = INITIAL_SPEED_SNAKE;

	lastRenderTime = 0;
	lastHPPowerupAdd = 0;
	lastSpecPowerupAdd = 0;
	lastSpecPowerupAddTest = 0;

	snake = new Snake(this, BUFFER_W / 2, BUFFER_H / 2, EAST);
	powerupList = new PowerUpList();
	
	snake->extendForward(INITIAL_SNAKE_LENGTH);

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

void Level::start(AbstractConsole* pConsole){
	lastHPPowerupAdd = pConsole->getCurrentTimeMillis();
	lastSpecPowerupAdd = pConsole->getCurrentTimeMillis();
	running = true;
}

void Level::stop(){
	running = false;
}

void Level::run(AbstractConsole* pConsole) {
	long curr = pConsole->getCurrentTimeMillis();

	int l_s_speed = snake_speed;
	if (getModifierType() == SNAKEMODTYPE_AUTO) {
		l_s_speed /= 4;
	} else if (getModifierType() == SNAKEMODTYPE_PREAUTO) {
		l_s_speed = INT_MAX;
	} else if (getModifierType() == SNAKEMODTYPE_ZOOM) {
		l_s_speed *= 2;
	}

	if ((curr - lastRenderTime) > l_s_speed) {
		PowerUpType collectedPowerUp = testForPowerUpCollision();

		snake->onBeforeMove(this, pConsole);
		if (getModifierType() == SNAKEMODTYPE_AUTO) {
			if (collectedPowerUp == POWERUP_HEALTH) {
				snake->autoExtendForward();
			} else {
				snake->autoMoveForward();
			}
		} else {
			if (collectedPowerUp == POWERUP_HEALTH) {
				snake->extendForward();
			} else {
				snake->moveForward();
			}
		}
		snake->onAfterMove(this, pConsole);

		if (collectedPowerUp == POWERUP_AUTO) {
			setModifier(new SnakeAutoModifier(this, pConsole));
			addEffect(pConsole, new AutoModifierStartEffect(getSnake()->getHead()->getX(), getSnake()->getHead()->getY()));
		} else if (collectedPowerUp == POWERUP_ZOOM) {
			setModifier(new SnakeZoomModifier(this, pConsole));
		}

		if (getModifierType() != SNAKEMODTYPE_AUTO) {
			addMissingHealthPowerUps(pConsole);
			addMissingSpecialPowerUps(pConsole);
		}

		testForDeath(pConsole);

		lastRenderTime = curr;
	}

	runModifier(pConsole);
	runEffects(pConsole);
}

void Level::runModifier(AbstractConsole *console) {
	if (getModifier() != 0) {
		modifier->run(this, console);

		if (! getModifier()->isRunning()) {
			modifier = 0;
		}
	}
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
	renderPowerups(pConsole);
	
	renderEffects(pConsole);

	renderSnake(pConsole);

	if (getModifierType() == SNAKEMODTYPE_ZOOM) {
		pConsole->zoomIn(getSnake()->getHead()->getX(), getSnake()->getHead()->getY());
	}

	renderShards(pConsole);
}

void Level::renderSnake(AbstractConsole *console) {
	SnakeElement * snakeelement = getSnake()->getHead();
	int pos = 0;
	while(snakeelement != 0) {
		console->write(SNAKEPARTCHARS[getSnake()->getIntersectionOrientation(pos)], snakeelement->getX(), snakeelement->getY());

		snakeelement = snakeelement->getNextElement();
		pos++;
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

void Level::renderShards(AbstractConsole *console) {
	for (int x = 0; x < getLifeShards(); x++)
	{
		console->write(3, x, 0);
	}
}

void Level::onKeyDown(AbstractConsole* pConsole, int keycode) {
	if (keycode == KC_UP) {
		snake->setDirection(NORTH);
	} else if (keycode == KC_DOWN) {
		snake->setDirection(SOUTH);
	} else if (keycode == KC_LEFT) {
		snake->setDirection(WEST);
	} else if (keycode == KC_RIGHT) {
		snake->setDirection(EAST);
	} else if (keycode == KC_F1 && GAMERULE_EnableCheats) { // Spawn AutoPowerUp
		int pux = rand() % BUFFER_W;
		int puy = rand() % BUFFER_H;
		if (! isPositionUsed(pux, puy))
			getPowerUpList()->add(new AutoPowerUp(pConsole, pux, puy));
	} else if (keycode == KC_F2 && GAMERULE_EnableCheats) { // Spawn ZoomPowerUp
		int pux = rand() % BUFFER_W;
		int puy = rand() % BUFFER_H;
		if (! isPositionUsed(pux, puy))
			getPowerUpList()->add(new ZoomPowerUp(pConsole, pux, puy));
	} else if (keycode == KC_F3 && GAMERULE_EnableCheats) { // InstaDeath
		onDie();
	}
}

PowerUpType Level::testForPowerUpCollision() {
	PowerUp * pelem = getPowerUpList()->getFirst();

	while(pelem != 0) {
		if (pelem->getX() == snake->getHead()->getX() && pelem->getY() == snake->getHead()->getY()) {
			PowerUpType ptype = pelem->getType();
			getPowerUpList()->remove(pelem);
			return ptype;
		}

		pelem = pelem->getNextElement();
	}
	return POWERUP_NULL;
}

void Level::addMissingHealthPowerUps(AbstractConsole * pConsole) {
	long curr = pConsole->getCurrentTimeMillis();

	if ((curr - lastHPPowerupAdd) > 500) {

		if (getPowerUpList()->getLength() < 32) {
			addHealthPowerUps(pConsole, 1);
		}

		lastHPPowerupAdd = curr;
	}
}

void Level::addMissingSpecialPowerUps(AbstractConsole * pConsole) {
	long curr = pConsole->getCurrentTimeMillis();

	if ((curr - lastSpecPowerupAddTest) > 2000 && (curr - lastSpecPowerupAdd) > 20000) {
		if (rand() % 5 == 0) { // 1:5
			int pux = rand() % BUFFER_W;
			int puy = rand() % BUFFER_H;
			if (! (isPositionUsed(pux, puy) || isSpecialPowerUpOnField() || getModifierType() != SNAKEMODTYPE_NULL)) {
				switch(rand()%2) {
				case 0: 
					getPowerUpList()->add(new AutoPowerUp(pConsole, pux, puy)); 
					break;
				case 1: 
					getPowerUpList()->add(new ZoomPowerUp(pConsole, pux, puy)); 
					break;
				}
				
				addEffect(pConsole, new PowerUpSpawnEffect(pux, puy));

				lastSpecPowerupAdd = curr;
			}
		}

		lastSpecPowerupAddTest = curr;
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
	addEffect(pConsole, new PowerUpSpawnEffect(hpux, hpuy));
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

void Level::testForDeath(AbstractConsole* pConsole) {
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
				}
				if (GAMERULE_BiteOnSelfContact && prevelem != 0){
					removeSnakePieceWithEffect(pConsole, prevelem, 0);
				}
				if (GAMERULE_DecreaseShardsOnSelfContact){
					decreaseLifeShardsBy(1);
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

void Level::removeSnakePieceWithEffect(AbstractConsole* pConsole, SnakeElement* prevelement, int depth) {
	if (!prevelement->hasNextElement()) return;

	int cr = SNAKEPARTCHARS[getSnake()->getIntersectionOrientation(getSnake()->findElement(prevelement->getNextElement()))];
	addEffect(pConsole, new BiteEffect(prevelement->getNextElement()->getX(), prevelement->getNextElement()->getY(), depth, cr));
	removeSnakePieceWithEffect(pConsole, prevelement->getNextElement(), depth + 1);
	
	prevelement->removeNextElement();
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

void Level::setModifier(SnakeModifier* mod) {
	modifier = mod;
}

SnakeModifier* Level::getModifier() {
	return modifier;
}

SnakeModifierType Level::getModifierType() {
	if (getModifier() == 0) {
		return SNAKEMODTYPE_NULL;
	} else {
		return getModifier()->getType();
	}
}

bool Level::isSpecialPowerUpOnField() {
	PowerUp * pelem = getPowerUpList()->getFirst();

	while(pelem != 0) {
		if (pelem->getType() != POWERUP_HEALTH) {
			return true;
		}

		pelem = pelem->getNextElement();
	}

	return false;
}

int Level::getLifeShards() {
	return lifes;
}

void Level::decreaseLifeShardsBy(int by) {
	lifes -= by;

	if (lifes <= 0) {
		onDie();
	}
}