#pragma once

#include "menuelement.h"
#include "Highscore.h"
#include "menu.h"
#include "Label.h"
#include "Button.h"
#include "ListenerCollection.h"
#include "Game.h"

class HighscoreMenu :
	public Menu
{
private:
	ActionListener* listener;

	virtual void createMenu(ActionListener* highMenuListener, Highscore* pHighscore);
protected:
	virtual std::string getName() = 0;
	virtual int getHSID() = 0;
public:
	HighscoreMenu(ActionListener * highMenuListener);
	~HighscoreMenu(void);

	virtual void onStart();
};

