#pragma once
#include "AbstractConsole.h"
#include "Level.h"
#include "MenuDisplay.h"
#include "ListenerCollection.h"

class Game : public ActionListener
{
private:
	AbstractConsole *console;

	Level *level;
	MenuDisplay *menu;

	bool active;
	std::string playerName;

	virtual void render();
public:
	Game(AbstractConsole *pconsole);
	virtual ~Game(void);

	virtual bool isActive();
	virtual void onKeyDown (int keycode);
	virtual void actionPerformed(int id, int param);

	virtual void run(AbstractConsole *pConsole);
	virtual std::string getPlayerName(void);
};

