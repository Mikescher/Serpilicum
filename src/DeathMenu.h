#pragma once

#include "menu.h"
#include "Label.h"
#include "Button.h"
#include "ListenerCollection.h"
#include "Highscore.h"
#include "Game.h"
#include "Gamerules.h"

class DeathMenu :
	public Menu
{
private:
	virtual void createMenu(ActionListener * restartListener,Highscore* pHighscore, int pscore);
public:
	DeathMenu(ActionListener * restartListener, int pscore, Game* game);
};

