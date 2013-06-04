#pragma once
#include "Snake.h";
#include "PowerUpList.h"
#include "DBConsole.h"

const int FIELD_W = 76;
const int FIELD_H = 36;

class Level
{
private:
	Snake * snake;
	PowerUpList * powerupList;
	bool running;
	long lastRenderTime;

	virtual void renderPowerups(DBConsole *console);
	virtual void renderSnake(DBConsole *console);
public:
	Level(void);
	virtual ~Level(void);

	virtual void render(DBConsole* pConsole);
	virtual void onKeyDown(int keycode);


	virtual void run(DBConsole* pConsole);
	virtual bool testForHPCollision();

	virtual Snake * getSnake();
	virtual PowerUpList * getPowerUpList();

	virtual void start();
	virtual void stop();

	virtual bool isRunning();
};

