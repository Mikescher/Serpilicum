#pragma once
#include "Snake.h";
#include "PowerUpList.h"
#include "DBConsole.h"
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

	virtual void renderPowerups(DBConsole *console);
	virtual void renderSnake(DBConsole *console);
	virtual void renderEffects(DBConsole *console);

	virtual void runEffects(DBConsole *console);
public:
	Level(void);
	virtual ~Level(void);

	virtual void render(DBConsole* pConsole);
	virtual void onKeyDown(int keycode);

	virtual void run(DBConsole* pConsole);

	
	virtual void addMissingHealthPowerUps(DBConsole * pConsole);
	virtual void addHealthPowerUps(DBConsole *pconsole, int count);
	virtual void addHealthPowerUps(DBConsole *pconsole, int hpux, int hpuy);
	virtual void addEffect(DBConsole *console, LevelEffect * effect);

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

