#pragma once
#include "AbstractConsole.h"
#include "Level.h"
#include "MenuDisplay.h"
#include "ActionListener.h"

class Game : public ActionListener
{
private:
	AbstractConsole *console;

	Level *level;
	MenuDisplay *menu;

	bool active;

	virtual void render();
public:
	Game(AbstractConsole *pconsole);
	virtual ~Game(void);

	virtual bool isActive();
	virtual void onKeyDown (int keycode);
	virtual void actionPerformed(int id);

	virtual void run(AbstractConsole *pConsole);
};

