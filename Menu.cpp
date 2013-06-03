#include "Menu.h"



Menu::Menu(void)
{
}


Menu::~Menu(void)
{
	for(unsigned int z = 0; z < elements.size(); z++){
		delete elements[z];
	}
}

void Menu::render(DBConsole* pConsole)
{
	for(unsigned int z = 0; z < elements.size(); z++){
		elements[z]->render(pConsole);		
	}
}

void Menu::addElement(MenuElement* pElement)
{
	elements.push_back(pElement);
}

MenuElement* Menu::removeElement(MenuElement* pElement)
{
	for(std::vector<MenuElement*>::iterator it = elements.begin(); it != elements.end(); it++){
		if(*it == pElement)
		{
			MenuElement* tmp = *it;
			elements.erase(it);
			return tmp;
		}
	}

	return 0;
}