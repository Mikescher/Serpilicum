#include <iostream>
#include "WindowsConsole.h"
#include "AbstractConsole.h"
#include "Game.h"
#include <windows.h>
#include "Keycodes.h"
#include <time.h>

int main() {
	srand (time(NULL));

	AbstractConsole *dbc = new WindowsConsole();
	Game *game = new Game(dbc);

	dbc->init();

	while(game->isActive()){
		game->run(dbc);

		int keycode = dbc->getCurrentKeyState();
		if (keycode != 0) {
			game->onKeyDown(keycode);
		}
	}

	delete game;
	delete dbc;
}

