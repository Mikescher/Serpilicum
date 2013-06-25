#pragma once

#include "menuelement.h"
#include "Highscore.h"
#include "menu.h"
#include "Label.h"
#include "Button.h"
#include "ListenerCollection.h"
#include "Game.h"

class HighscoreMenuHard :
	public Menu
{
private:
	virtual void createMenu(ActionListener* highMenuListener, Highscore* pHighscore);
public:
	HighscoreMenuHard(ActionListener * highMenuListener);
	~HighscoreMenuHard(void);
};

