#pragma once
#include "Menu.h"
#include "AbstractConsole.h"

class MenuDisplay
{
private:
	Menu *menu;
public:
	MenuDisplay(void);
	virtual ~MenuDisplay(void);

	virtual Menu* getMenu();
	virtual Menu* setMenu(Menu* pMenu); 
	virtual void render(AbstractConsole* pConsole);
	virtual bool isMenuset();
	virtual void removeMenu();

	virtual void onKeyDown (AbstractConsole *pConsole, int keycode);
};