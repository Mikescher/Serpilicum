#pragma once

#include "menuelement.h"
#include "Highscore.h"
#include "menu.h"
#include "Label.h"
#include "Button.h"
#include "ListenerCollection.h"
#include "Game.h"

class HighscoreMenuEasy :
	public Menu
{
private:
	virtual void createMenu(ActionListener* highMenuListener, Highscore* pHighscore);
public:
	HighscoreMenuEasy(ActionListener * highMenuListener);
	~HighscoreMenuEasy(void);
};

