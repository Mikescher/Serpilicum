#pragma once
#include "displayimagetextmenu.h"
class SplashMenu :
	public DisplayImageTextMenu
{
private:
	long startTime;
public:
	SplashMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID);

	virtual void render(AbstractConsole* pConsole);
};

