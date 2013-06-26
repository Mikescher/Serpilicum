#include "HighscoreMenu.h"


HighscoreMenu::HighscoreMenu(ActionListener* highMenuListener)
{
	listener = highMenuListener;
}


HighscoreMenu::~HighscoreMenu(void)
{
}

void HighscoreMenu::onStart() {
	Highscore* pHighscore = new Highscore();
	createMenu(listener, pHighscore);
}

void HighscoreMenu::createMenu(ActionListener * highMenuListener, Highscore* pHighscore){
	addElement(new Label("The Highscore of best the 30 players in the Gamemode \"" + getName() + "\"", 8, 3));

	Button* mainBtn = new Button(501, "Back to Menu", 30, 6);
	addElement(mainBtn);
	mainBtn->setListener(highMenuListener);

	//########################################

	Button* hs0 = new Button(901, "Easy", 30, 10);
	addElement(hs0);
	hs0->setListener(highMenuListener);

	Button* hs1 = new Button(902, "Retro", 30, 13);
	addElement(hs1);
	hs1->setListener(highMenuListener);

	Button* hs2 = new Button(903, "Normal", 30, 16);
	addElement(hs2);
	hs2->setListener(highMenuListener);

	Button* hs3 = new Button(904, "Hardcore", 30, 19);
	addElement(hs3);
	hs3->setListener(highMenuListener);

	Button* hs4 = new Button(905, "Aspirin", 30, 22);
	addElement(hs4);
	hs4->setListener(highMenuListener);

	Button* hs5 = new Button(906, "Auto", 30, 25);
	addElement(hs5);
	hs5->setListener(highMenuListener);

	//#########################

	std::vector<HighscoreElement> highscore = pHighscore->readScore(getHSID());
	int position = 1;
	for (unsigned int z = 0; z < highscore.size() && z < 31; z++)
	{
		if (z > 0 && (highscore.at(z-1).point > highscore.at(z).point)) position++;

		Label* highLbn = new Label(std::to_string(position) + ". " + highscore.at(z).name + ": " + std::to_string(highscore.at(z).point), 8, 5+z);
		addElement(highLbn);
	}

	focusElement(2 + getHSID());
}