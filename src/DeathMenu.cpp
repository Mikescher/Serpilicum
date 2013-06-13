#include "DeathMenu.h"


DeathMenu::DeathMenu(ActionListener * restartListener, int pscore)
{
	Highscore* highscore = new Highscore();
	createMenu(restartListener);
	highscore->writeScore("pname", pscore);
}


DeathMenu::~DeathMenu(void)
{
}

void DeathMenu::createMenu(ActionListener * restartListener) {
	addElement(new Label("You loose", 8, 3));

	Button *startBtn = new Button(201, "Restart", 8, 6);
	addElement(startBtn);
	startBtn->setListener(restartListener);

	focusElement(1);
}