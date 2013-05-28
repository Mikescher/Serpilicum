#pragma once
#include "DBConsole.h"
#include "Level.h"

class Game
{
private:
	DBConsole *console;
	bool running;
	Level *level;

	virtual void render();
	virtual void renderSnake();
	virtual void renderPowerups();
public:
	Game(DBConsole *pconsole);
	~Game(void);

	virtual void start();
	virtual void stop();
	virtual bool isRunning();
	virtual void run();
};

