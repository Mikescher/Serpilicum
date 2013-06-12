#pragma once
#include "Menu.h"
#include "ListenerCollection.h"
class IntroMenu :
	public Menu
{
private:
	virtual void createMenu(ActionListener * startGamelistener);
public:
	IntroMenu(ActionListener * startGamelistener);
	virtual ~IntroMenu(void);
};

