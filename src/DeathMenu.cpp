#include "DeathMenu.h"


DeathMenu::DeathMenu(ActionListener * restartListener, int pscore, Game* game)
{
	Highscore* highscore = new Highscore();
	createMenu(restartListener, highscore, pscore);
	highscore->writeScore(game->getPlayerName(), pscore);
}

void DeathMenu::createMenu(ActionListener * restartListener, Highscore* phighscore, int pscore) {
	addElement(new Label("You loose", 8, 3));
	addElement(new Label("You have reached: " + to_string(pscore) + " Points", 8, 4));

	Button *startBtn = new Button(201, "Restart", 8, 7);
	addElement(startBtn);
	startBtn->setListener(restartListener);

	addElement(new Label("Top 20 players", 8, 12));

	std::vector<HighscoreElement> highscore = phighscore->readScore();
	int position = 1;
	for (unsigned int z = 0; z < highscore.size() && z < 21; z++)
	{
		if (z > 0 && (highscore.at(z-1).point > highscore.at(z).point)) position++;

		Label* highLbn = new Label(std::to_string(position) + ". " + highscore.at(z).name + ": " + std::to_string(highscore.at(z).point), 8, 14+z);
		addElement(highLbn);
	}

	Button* mainBtn = new Button(202, "Back to Mainmenu", 18, 7);
	addElement(mainBtn);
	mainBtn->setListener(restartListener);


	focusElement(2);
}