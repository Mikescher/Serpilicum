#include "Game.h"
#include "DBConsole.h"
#include "Level.h"
#include "IntroMenu.h"
#include "Keycodes.h"
#include "ActionListener.h"

Game::Game(DBConsole *pconsole)
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

void Game::run(DBConsole * pConsole){
	if (! menu->isMenuset()) {
		level->run(pConsole);
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
		level->onKeyDown(keycode);
	}
}

void Game::actionPerformed(int id) {
	menu->removeMenu();
	level = new Level();
}