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
	addElement(new Label("The Highscore of best the 30 players", 8, 3));


	std::vector<HighscoreElement> highscore = pHighscore->readScore();
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
	focusElement(1);
}