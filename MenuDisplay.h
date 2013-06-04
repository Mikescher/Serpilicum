#pragma once
#include "Menu.h"
#include "DBConsole.h"

class MenuDisplay
{
private:
	Menu *menu;
public:
	MenuDisplay(void);
	~MenuDisplay(void);

	virtual Menu* getMenu();
	virtual Menu* setMenu(Menu* pMenu); 
	virtual void render(DBConsole* pConsole);
	virtual bool isMenuset();
	virtual void removeMenu();

	virtual void onKeyDown (DBConsole *pConsole, int keycode);
};