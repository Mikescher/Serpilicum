#include <iostream>
#include "DBConsole.h"
#include "Game.h"
#include <windows.h>
#include "Keycodes.h"
#include <time.h>

int main() {
	srand (time(NULL));

	DBConsole *dbc = new DBConsole();
	Game *game = new Game(dbc);

	while(game->isActive()){
		game->run(dbc);

		int keycode = dbc->getKeyState();
		if (keycode != 0) {
			game->onKeyDown(keycode);
		}
	}

	delete game;
	delete dbc;
}

