#pragma once
#include <vector>
#include "MenuElement.h"
#include "DBConsole.h"
class Menu
{
private:
	std::vector<MenuElement*> elements;
public:
	Menu(void);
	~Menu(void);

	virtual void render(DBConsole* pConsole);
	virtual void addElement(MenuElement* pElement);
	virtual MenuElement* removeElement(MenuElement* pElement);
};

