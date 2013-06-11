#pragma once
#include <vector>
#include "MenuElement.h"
#include "AbstractConsole.h"

class Menu {
private:
	std::vector<MenuElement*> elements;
	int focusIndex;

	virtual void updateFocus();
public:
	Menu(void);
	virtual ~Menu(void);

	virtual void render(AbstractConsole* pConsole);
	virtual void addElement(MenuElement* pElement);
	virtual MenuElement* removeElement(MenuElement* pElement);

	virtual MenuElement* getFocusedElement();
	virtual bool isElementFocused();
	virtual MenuElement* focusNextElement();
	virtual MenuElement* focusPrevElement();
	virtual bool focusElement(int el);
	virtual void removeFocus();
	virtual void onKeyDown(int keycode);
};