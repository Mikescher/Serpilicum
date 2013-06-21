#pragma once

#include "menu.h"
#include <math.h>

class DisplayImageTextMenu :
	public Menu
{
protected:
	int id;
	ActionListener* listener;

	bool* resourceArray;

	long startTime;
	int duration;

	virtual void throwAction();
	virtual void createMenu(ActionListener * quitListener);
public:
	DisplayImageTextMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID, int pduration);

	virtual void render(AbstractConsole* pConsole);
	virtual void run(AbstractConsole* pConsole);

	virtual void onKeyDown(int keycode);
};

