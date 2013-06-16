#pragma once

#include "AutoSnake.h"
#include "PowerUpList.h"
#include "AbstractConsole.h"
#include <vector>
#include "LevelEffect.h"
#include "PowerUpSpawnEffect.h"
#include "Gamerules.h"
#include <limits>

class Level
{
private:
	std::vector<LevelEffect*> effects;
	SnakeModifier* modifier;

	int snake_speed;

	Snake * snake;
	PowerUpList * powerupList;
	bool running;
	bool is_dead;
	long lastRenderTime;
	long lastHPPowerupAdd;
	long lastSpecPowerupAdd;
	long lastSpecPowerupAddTest;

	virtual void renderPowerups(AbstractConsole *console);
	virtual void renderSnake(AbstractConsole *console);
	virtual void renderEffects(AbstractConsole *console);

	virtual void runEffects(AbstractConsole *console);
	virtual void runModifier(AbstractConsole *console);
public:
	Level(void);
	virtual ~Level(void);

	virtual void render(AbstractConsole* pConsole);
	virtual void onKeyDown(int keycode);

	virtual void run(AbstractConsole* pConsole);
	
	virtual void addMissingHealthPowerUps(AbstractConsole * pConsole);
	virtual void addMissingSpecialPowerUps(AbstractConsole * pConsole);
	virtual void addHealthPowerUps(AbstractConsole *pconsole, int count);
	virtual void addHealthPowerUps(AbstractConsole *pconsole, int hpux, int hpuy);
	virtual void addEffect(AbstractConsole *console, LevelEffect * effect);

	virtual PowerUpType testForPowerUpCollision();
	virtual void testForDeath();

	virtual bool isPositionPowerUp(int xx, int yy);
	virtual bool isPositionSnake(int xx, int yy);
	virtual bool isPositionUsed(int xx, int yy);
	virtual bool isSpecialPowerUpOnField();

	virtual Snake * getSnake();
	virtual PowerUpList * getPowerUpList();
	virtual SnakeModifier* getModifier();
	virtual SnakeModifierType getModifierType();

	virtual void setModifier(SnakeModifier* mod);

	virtual void start();
	virtual void stop();
	virtual void onDie();

	virtual bool isRunning();
	virtual bool isDead();
};

