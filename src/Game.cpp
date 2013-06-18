#include "Game.h"

#include "AbstractConsole.h"
#include "Level.h"
#include "MainMenu.h"
#include "DeathMenu.h"
#include "Keycodes.h"
#include "ListenerCollection.h"
#include "IntroMenu.h"
#include "HighscoreMenu.h"

Game::Game(AbstractConsole *pconsole)
{
	active = true;

	console = pconsole;
	
	level = 0;
	menu = new MenuDisplay();

	menu->setMenu(new IntroMenu(this));
}


Game::~Game(void)
{
	delete level;
}

void Game::run(AbstractConsole* pConsole){
	if (! menu->isMenuset()) {
		if (level->isRunning()) {
			level->run(pConsole);
		} else if (level->isDead()) {
			menu->setMenu(new DeathMenu(this, level->getSnake()->getLength(), (this)));
						
		}
	} else {
		// run menu;
	}

	render();
}

void Game::render() {
	console->clearBuffer();

	if (menu->isMenuset()) {
		menu->render(console);
	} else {
		level->render(console);
	}

	console->swap();
}

bool Game::isActive() {
	return active;
}

void Game::onKeyDown (int keycode) {
	if (keycode == KC_ESCAPE) {
		active = false;
	} else if (menu->isMenuset()) {
		menu->onKeyDown(console, keycode);;
	} else {
		level->onKeyDown(console, keycode);
	}
}

void Game::actionPerformed(int id) {
	if (id == 101) { // MAINEMNU -> START LEVEL
		menu->removeMenu();
		level = new Level();
		level->start(console);
	} else if (id == 201) { // DEATHMENU -> RESTART
		menu->removeMenu();
		level = new Level();
		level->start(console);
	} else if (id == 301) { // INTROMENU -> MAINMENU
		playerName = ((IntroMenu *)(menu->getMenu()))->getEditText();
		menu->removeMenu();
		MainMenu* main = new MainMenu(this);
		menu->setMenu(new MainMenu(this));
	}  else if (id == 103) { // MAINMENU -> HIGHSCOREMENU
		menu->removeMenu();
		HighscoreMenu* highmen = new HighscoreMenu(this);
		menu->setMenu(new HighscoreMenu(this));
	}

}

std::string Game::getPlayerName(void)
{
	return playerName;
}
