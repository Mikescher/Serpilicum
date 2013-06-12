#pragma once

#include "menu.h"
#include "Label.h"
#include "Button.h"
#include "ListenerCollection.h"

class DeathMenu :
	public Menu
{
private:
	virtual void createMenu(ActionListener * restartListener);
public:
	DeathMenu(ActionListener * restartListener);
	virtual ~DeathMenu(void);
};

