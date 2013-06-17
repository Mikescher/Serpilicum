#pragma once
#include "Menu.h"
#include "ListenerCollection.h"
class MainMenu :
	public Menu
{
private:
	virtual void createMenu(ActionListener * startGamelistener);
public:
	MainMenu(ActionListener * startGamelistener);
	virtual ~MainMenu(void);
};

