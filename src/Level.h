#pragma once
#include "Snake.h";
#include "PowerUpList.h"
#include "AbstractConsole.h"
#include <vector>
#include "LevelEffect.h"
#include "HPSpawnEffect.h"
#include "Gamerules.h"

const int FIELD_W = 76;
const int FIELD_H = 36;

class Level
{
private:
	std::vector<LevelEffect*> effects;

	int snake_speed;

	Snake * snake;
	PowerUpList * powerupList;
	bool running;
	bool is_dead;
	long lastRenderTime;
	long lastPowerupAdd;

	virtual void renderPowerups(AbstractConsole *console);
	virtual void renderSnake(AbstractConsole *console);
	virtual void renderEffects(AbstractConsole *console);

	virtual void runEffects(AbstractConsole *console);
public:
	Level(void);
	virtual ~Level(void);

	virtual void render(AbstractConsole* pConsole);
	virtual void onKeyDown(int keycode);

	virtual void run(AbstractConsole* pConsole);

	
	virtual void addMissingHealthPowerUps(AbstractConsole * pConsole);
	virtual void addHealthPowerUps(AbstractConsole *pconsole, int count);
	virtual void addHealthPowerUps(AbstractConsole *pconsole, int hpux, int hpuy);
	virtual void addEffect(AbstractConsole *console, LevelEffect * effect);

	virtual bool testForHPCollision();
	virtual void testForDeath();

	virtual bool isPositionPowerUp(int xx, int yy);
	virtual bool isPositionSnake(int xx, int yy);
	virtual bool isPositionUsed(int xx, int yy);

	virtual Snake * getSnake();
	virtual PowerUpList * getPowerUpList();

	virtual void start();
	virtual void stop();
	virtual void onDie();

	virtual bool isRunning();
	virtual bool isDead();
};

