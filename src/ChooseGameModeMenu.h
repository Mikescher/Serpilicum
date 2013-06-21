#pragma once

#include "displayimagetextmenu.h"

#define GAMEMODECOUNT 6

class ChooseGameModeMenu :
	public DisplayImageTextMenu
{
protected:
	virtual void throwAction();
private:
	long lastRun;
	bool* traNext;
	bool* traPrev;

	int currmode;
	AbstractConsole* console;
	double transistion;
	int transistionDirection;

	void update();
public:
	ChooseGameModeMenu(int pid, AbstractConsole* console, ActionListener * quitListener);

	virtual void run(AbstractConsole* pConsole);
	virtual void render(AbstractConsole* pConsole);

	virtual void onKeyDown(int keycode);
};

