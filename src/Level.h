#pragma once
#include "Snake.h"
#include "PowerUpList.h"
#include "AbstractConsole.h"
#include <vector>
#include "LevelEffect.h"
#include "LevelObstacle.h"
#include "PowerUpSpawnEffect.h"
#include "Gamerules.h"
#include <limits>

class Level
{
private:
	std::vector<LevelEffect*> effects;
	std::vector<LevelObstacle*> obstacles;
	SnakeModifier* modifier;

	AbstractConsole* console;

	int lifes;
	int snake_speed;
	int score;

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
	virtual void renderObstacles(AbstractConsole *console);
	virtual void renderShards(AbstractConsole *console);
	virtual void renderPoints(AbstractConsole *console);

	virtual void addMissingHealthPowerUps(AbstractConsole * pConsole);
	virtual void addMissingSpecialPowerUps(AbstractConsole * pConsole);
	virtual void addHealthPowerUps(AbstractConsole *pconsole, int count);
	virtual void addHealthPowerUps(AbstractConsole *pconsole, int hpux, int hpuy);
	
	virtual PowerUpType testForPowerUpCollision();
	virtual void testForDeath(AbstractConsole* pConsole);
	virtual void testForObstacleCollision(AbstractConsole* pConsole);

	virtual void runEffects(AbstractConsole *console);
	virtual void runObstacles(AbstractConsole *console);
	virtual void runModifier(AbstractConsole *console);

	virtual void onHPCollect(AbstractConsole* pConsole);

	virtual void removeSnakePieceWithEffect(AbstractConsole* pConsole, SnakeElement* prevelement, int depth);
	virtual void decreaseLifeShardsBy(int by);
	virtual void spawnNewAspirinObstacle(AbstractConsole* pConsole);
	virtual void addPoints();
public:
	Level();
	virtual ~Level(void);

	virtual void render(AbstractConsole* pConsole);
	virtual void onKeyDown(AbstractConsole* pConsole, int keycode);

	virtual void run(AbstractConsole* pConsole);

	virtual bool isPositionPowerUp(int xx, int yy);
	virtual bool isPositionSnake(int xx, int yy);
	virtual bool isPositionUsed(int xx, int yy);
	virtual bool isSpecialPowerUpOnField();
	virtual double getMinimalSnakeDistance(int px, int py);

	virtual Snake * getSnake();
	virtual PowerUpList * getPowerUpList();
	virtual SnakeModifier* getModifier();
	virtual SnakeModifierType getModifierType();
	virtual int getLifeShards();

	virtual void addEffect(AbstractConsole *console, LevelEffect * effect);
	virtual void setModifier(SnakeModifier* mod);
	virtual void addObstacle(AbstractConsole *console, LevelObstacle * obs);

	virtual void start(AbstractConsole* pConsole);
	virtual void stop();
	virtual void onDie();

	virtual bool isRunning();
	virtual bool isDead();

	virtual int getScore();

};

