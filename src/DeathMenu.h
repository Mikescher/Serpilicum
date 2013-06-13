#pragma once

#include "menu.h"
#include "Label.h"
#include "Button.h"
#include "ListenerCollection.h"
#include "Highscore.h"

class DeathMenu :
	public Menu
{
private:
	virtual void createMenu(ActionListener * restartListener);
public:
	DeathMenu(ActionListener * restartListener, int pscore);
	virtual ~DeathMenu(void);
};

