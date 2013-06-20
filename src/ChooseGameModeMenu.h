#pragma once

#include "displayimagetextmenu.h"

#define GAMEMODECOUNT 6

class ChooseGameModeMenu :
	public DisplayImageTextMenu
{
protected:
	virtual void throwAction();
private:
	int currmode;
	AbstractConsole* console;

	void update();
public:
	ChooseGameModeMenu(int pid, AbstractConsole* console, ActionListener * quitListener);
	virtual void onKeyDown(int keycode);
};

