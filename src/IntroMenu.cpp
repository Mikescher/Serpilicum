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

	Button *startBtn = new Button(101, "Start den Game", 8, 6);
	addElement(startBtn);
	startBtn->setListener(startGamelistener);

	addElement(new Button(102, "Multiplayer", 8, 10));
	addElement(new Button(103, "Highscore", 8, 14));
	addElement(new Button(104, "Exit", 8, 18));

	focusElement(2);
}