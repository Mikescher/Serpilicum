#include "Game.h"

#include "AbstractConsole.h"
#include "Level.h"
#include "MainMenu.h"
#include "DeathMenu.h"
#include "Keycodes.h"
#include "ListenerCollection.h"
#include "IntroMenu.h"
#include "HighscoreMenu.h"
#include "GameOverDisplayMenu.h"
#include "SplashMenu.h"

Game::Game(AbstractConsole *pconsole)
{
	active = true;

	console = pconsole;
	
	level = 0;
	menu = new MenuDisplay();

	menu->setMenu(new SplashMenu(601, pconsole, this, 103));
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
			//menu->setMenu(new DeathMenu(this, level->getSnake()->getLength(), (this)));
			menu->setMenu(new GameOverDisplayMenu(401, pConsole, this, 102, level->getSnake()->getLength()));		
		}
	} else {
		menu->getMenu()->run(pConsole);
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

void Game::actionPerformed(int id, int param) {
	if (id == 101) { // MAINEMNU -> START LEVEL
		menu->removeMenu();
		level = new Level();
		level->start(console);
	} else if (id == 201) { // DEATHMENU -> RESTART
		menu->removeMenu();
		level = new Level();
		level->start(console);
	} else if (id == 301 || id == 302) { // INTROMENU -> MAINMENU
		playerName = ((IntroMenu *)(menu->getMenu()))->getEditText();
		menu->removeMenu();
		MainMenu* main = new MainMenu(this);
		menu->setMenu(main);
	}  else if (id == 103) { // MAINMENU -> HIGHSCOREMENU
		menu->removeMenu();
		HighscoreMenu* highmen = new HighscoreMenu(this);
		menu->setMenu(highmen);
	}  else if (id == 401) { // DispayDeathMessage -> ACTIONPERFORMED
		menu->removeMenu();
		DeathMenu* dmenu = new DeathMenu(this, param, this);
		menu->setMenu(dmenu);
	}	else if (id == 501) { // HIGHSCOREMENU -> MAINMENU
		menu->removeMenu();
		MainMenu* main = new MainMenu(this);
		menu->setMenu(main);
	}	else if (id == 601) { // SPLASHMENU -> ACTIONPERFORMED
		menu->removeMenu();
		IntroMenu* main = new IntroMenu(this);
		menu->setMenu(main);
	}	else if (id == 202) { // DEATHMENU -> MAINMENU
		menu->removeMenu();
		MainMenu* main = new MainMenu(this);
		menu->setMenu(main);
	}
}

std::string Game::getPlayerName(void)
{
	return playerName;
}
