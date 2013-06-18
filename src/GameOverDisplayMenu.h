#pragma once
#include "displayimagetextmenu.h"
class GameOverDisplayMenu :
	public DisplayImageTextMenu
{
private:
	int cpoints;
public:
	GameOverDisplayMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID, int points);
};

