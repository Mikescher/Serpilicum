#pragma once

#include "DBConsole.h"

class LevelEffect
{
protected:
	int x;
	int y;
private:
	bool is_alive;
public:
	LevelEffect(int px, int py);
	virtual ~LevelEffect(void);

	virtual void start(DBConsole *console) = 0;
	virtual void run(DBConsole *console) = 0;
	virtual void render(DBConsole *console) = 0;

	virtual void stop();
	virtual void start();

	virtual int getX();
	virtual int getY();

	virtual bool isAlive();
};

