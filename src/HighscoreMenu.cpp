#include "HighscoreMenu.h"


HighscoreMenu::HighscoreMenu(ActionListener* highMenuListener)
{
	Highscore* highscore = new Highscore();
	createMenu(highMenuListener, highscore);
}


HighscoreMenu::~HighscoreMenu(void)
{
}

void HighscoreMenu::createMenu(ActionListener * highMenuListener, Highscore* pHighscore){
	addElement(new Label("The Highscore", 8, 3));
}