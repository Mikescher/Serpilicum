#include "DeathMenu.h"


DeathMenu::DeathMenu(ActionListener * restartListener, int pscore)
{
	Highscore* highscore = new Highscore();
	createMenu(restartListener, highscore);
	highscore->writeScore("pname", pscore);
}


DeathMenu::~DeathMenu(void)
{
}

void DeathMenu::createMenu(ActionListener * restartListener, Highscore* phighscore) {
	addElement(new Label("You loose", 8, 3));

	Button *startBtn = new Button(201, "Restart", 8, 6);
	addElement(startBtn);
	startBtn->setListener(restartListener);

	addElement(new Label("Top 20 players", 8, 11));

	std::vector<HighscoreElement> highscore = phighscore->readScore();
	int position = 1;
	for (unsigned int z = 0; z < highscore.size() && z < 20; z++)
	{
		if (z > 0 && (highscore.at(z-1).point > highscore.at(z).point)) position++;

		Label* highLbn = new Label(std::to_string(position) + ". " + highscore.at(z).name + ": " + std::to_string(highscore.at(z).point), 8, 13+z);
		addElement(highLbn);
	}


	focusElement(1);
}