#include "MainMenu.h"
#include "Label.h"
#include "Button.h"


MainMenu::MainMenu(ActionListener * startGamelistener)
{
	createMenu(startGamelistener);
}


MainMenu::~MainMenu(void)
{
}

void MainMenu::createMenu(ActionListener * startGamelistener) {
	addElement(new Label("Welcome to da game", 8, 2));
	addElement(new Label("Move ya thingz wid da keyZ", 8, 3));

	Button *startBtn = new Button(101, "Start den Game", 8, 6);
	addElement(startBtn);
	startBtn->setListener(startGamelistener);

	addElement(new Button(102, "Multiplayer", 8, 10));

	Button *highBtn = new Button(103, "Highscore", 8, 14);
	addElement(highBtn);
	highBtn->setListener(startGamelistener);
	
	addElement(new Button(106, "Options", 8, 18));
	addElement(new Button(105, "Credits", 8, 22));
	addElement(new Button(104, "Exit", 8, 26));


	focusElement(2);
}