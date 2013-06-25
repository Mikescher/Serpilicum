#include "HighscoreMenu.h"


HighscoreMenu::HighscoreMenu(ActionListener* highMenuListener)
{
	Highscore* pHighscore = new Highscore();
	createMenu(highMenuListener, pHighscore);
}


HighscoreMenu::~HighscoreMenu(void)
{
}

void HighscoreMenu::createMenu(ActionListener * highMenuListener, Highscore* pHighscore){
	addElement(new Label("The Highscore of best the 30 players in the Gamemode \"Normal\"", 8, 3));


	std::vector<HighscoreElement> highscore = pHighscore->readScore(2);
	int position = 1;
	for (unsigned int z = 0; z < highscore.size() && z < 31; z++)
	{
		if (z > 0 && (highscore.at(z-1).point > highscore.at(z).point)) position++;

		Label* highLbn = new Label(std::to_string(position) + ". " + highscore.at(z).name + ": " + std::to_string(highscore.at(z).point), 8, 5+z);
		addElement(highLbn);
	}

	Button* mainBtn = new Button(501, "Back to Menu", 30, 6);
	addElement(mainBtn);
	mainBtn->setListener(highMenuListener);

	Button* highscoreEasy = new Button(901, "Easy", 30, 10);
	addElement(highscoreEasy);
	highscoreEasy->setListener(highMenuListener);

	addElement(new Button(902, "Normal", 30, 13));

	Button* highscoreHard = new Button(903, "Hardcore", 30, 16);
	addElement(highscoreHard);
	highscoreHard->setListener(highMenuListener);

	focusElement(5);
}