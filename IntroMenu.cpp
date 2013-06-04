#include "IntroMenu.h"
#include "Label.h"
#include "Button.h"


IntroMenu::IntroMenu(ActionListener * startGamelistener)
{
	createMenu(startGamelistener);
}


IntroMenu::~IntroMenu(void)
{
}

void IntroMenu::createMenu(ActionListener * startGamelistener) {
	addElement(new Label("Welcome to da game", 8, 2));
	addElement(new Label("Move ya thingz wid da keyZ", 8, 3));

	Button *startBtn = new Button(1, "Start den Game", 8, 6);
	addElement(startBtn);
	startBtn->setListener(startGamelistener);

	addElement(new Button(2, "Do Nix", 8, 10));
	addElement(new Button(2, "Do Nix", 8, 14));
	addElement(new Button(2, "Do Nix", 8, 18));
	addElement(new Button(2, "Do Nix", 8, 22));
	addElement(new Button(2, "Do Nix", 8, 26));
	addElement(new Button(2, "Do Nix", 8, 30));
	addElement(new Button(2, "Do Nix", 8, 34));

	focusElement(2);
}