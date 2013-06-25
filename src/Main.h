#pragma once

#include <iostream>
#include "Gamerules.h"
#include "OGLConsole.h"
#include "WindowsConsole.h"
#include "CrazyConsole.h"
#include "AbstractConsole.h"
#include "Game.h"
#include <windows.h>
#include "Keycodes.h"
#include <time.h>

class Main : 
	public ActionListener,
	public KeyEventListener
{
private:
	AbstractConsole *dbc;
	Game *game;
public:
	virtual void start();
	virtual void actionPerformed(int id, int param);
	virtual void keyEventPerformed(int key);
};