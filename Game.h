#pragma once
#include "DBConsole.h"
#include "Level.h"
#include "MenuDisplay.h"
#include "ActionListener.h"
#include "Highscore.h"

class Game : public ActionListener
{
private:
	DBConsole *console;

	Level *level;
	MenuDisplay *menu;

	bool active;

	virtual void render();

	Game * highscore;
public:
	Game(DBConsole *pconsole);
	virtual ~Game(void);

	virtual bool isActive();
	virtual void onKeyDown (int keycode);
	virtual void actionPerformed(int id);

	virtual void run(DBConsole *pConsole);
};

