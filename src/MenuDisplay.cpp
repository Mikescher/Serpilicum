#include "MenuDisplay.h"


MenuDisplay::MenuDisplay(void)
{
	menu = 0;
}


MenuDisplay::~MenuDisplay(void)
{
	delete menu;
}

Menu* MenuDisplay::setMenu(Menu* pMenu)
{
	removeMenu();

	Menu *tmp = menu;
	menu = pMenu;

	menu->onStart();

	return tmp;
}

Menu* MenuDisplay::getMenu()
{
	return menu;
}

void MenuDisplay::render(AbstractConsole* pConsole)
{
	pConsole->clearBuffer();
	if(isMenuset()){
		menu->render(pConsole);
	}
	pConsole->swap();
}

bool MenuDisplay::isMenuset()
{
	return menu != 0;
}

void MenuDisplay::removeMenu()
{
	if (isMenuset()){
		delete menu;
	}
	menu = 0;
}

void MenuDisplay::onKeyDown(AbstractConsole *pConsole, int keycode) {
	if (isMenuset()) {
		menu->onKeyDown(keycode);
	}
}