#include "Menu.h"
#include "Keycodes.h"


Menu::Menu(void)
{
	focusIndex = -1;
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
			updateFocus();
			return tmp;
		}
	}

	return 0;
}

MenuElement* Menu::getFocusedElement() {
	if (isElementFocused()) {
		return elements.at(focusIndex);
	} else {
		return 0;
	}
}

bool Menu::isElementFocused() {
	if (focusIndex >= 0 && focusIndex < elements.size()) {
		return true;
	} else {
		focusIndex = -1;
		return false;
	}
}

MenuElement* Menu::focusNextElement() {
	int max = elements.size();

	focusIndex = (focusIndex + 1) % elements.size();

	while(! getFocusedElement()->isFocusable() && max-- > 0) {
		focusIndex = (focusIndex + 1) % elements.size();
	}

	if (max == 0) {
		removeFocus();
	}

	updateFocus();

	return getFocusedElement();
}

MenuElement* Menu::focusPrevElement() {
	int max = elements.size();

	focusIndex = (focusIndex + elements.size() - 1) % elements.size();

	while(! getFocusedElement()->isFocusable() && max-- > 0) {
		focusIndex = (focusIndex + elements.size() - 1) % elements.size();
	}

	if (max == 0) {
		removeFocus();
	}

	updateFocus();

	return getFocusedElement();
}

bool Menu::focusElement(int idx) {
	if (idx >= 0 && idx < elements.size()) {
		focusIndex = idx;
		updateFocus();

		return true;
	} else {
		return false;
	}
}

void Menu::removeFocus() {
	focusIndex = -1;

	updateFocus();
}

void Menu::onKeyDown(int keycode) {
	if (isElementFocused()) {
		if (keycode == KC_UP) {
			focusPrevElement();
		} else if (keycode == KC_DOWN) {
			focusNextElement();
		} else {
			getFocusedElement()->onKeyDown(keycode);
		}
	} else {
		if (keycode == KC_UP) {
			focusElement(0);
		} else if (keycode == KC_DOWN) {
			focusElement(0);
		} else {
			// Event remains unconsumed
		}
	}
}

void Menu::updateFocus() {
	for(unsigned int z = 0; z < elements.size(); z++){
		elements[z]->setFocused(z == focusIndex);	
	}
}