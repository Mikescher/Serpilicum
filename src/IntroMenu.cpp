#include "IntroMenu.h"

IntroMenu::IntroMenu(ActionListener* mainMenuListener)
{
	createMenu(mainMenuListener);
}


IntroMenu::~IntroMenu(void)
{
}

void IntroMenu::createMenu(ActionListener* mainMenuListener)
{
	addElement(new Label("Welcome to da game", 8,2));
	addElement(new Label("Please enter your Name", 8, 4));

	Button* mainBtn = new Button(301, "Enter Main Menu", 8, 20);
	addElement(mainBtn);
	mainBtn->setListener(mainMenuListener);

	nameEdt = new Edit(302, "", 8, 6);
	addElement(nameEdt);
	focusElement(3);
}

std::string IntroMenu::getEditText(void)
{
	return nameEdt->getText();
}