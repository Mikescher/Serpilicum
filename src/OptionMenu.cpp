#include "OptionMenu.h"


OptionMenu::OptionMenu(ActionListener * optionListener, std::string playername)
{
	createMenu(optionListener, game);
}


OptionMenu::~OptionMenu(void)
{
}

void OptionMenu::createMenu(ActionListener* optionListener, std::string playername)
{
	addElement(new Label("Options:", 8,2));
	addElement(new Label("Playername", 8,4));

	nameEdt = new Edit(701,playername, 8, 6);
	addElement(nameEdt);
	nameEdt->setListener(optionListener);

	Button* mainBtn = new Button(702, "Enter Main Menu", 8, 20);
	addElement(mainBtn);
	mainBtn->setListener(optionListener);

	focusElement(2);

}

std::string OptionMenu::getEditText(void)
{
	return nameEdt->getText();
}