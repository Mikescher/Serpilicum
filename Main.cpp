#include <iostream>
#include "DBConsole.h"
#include "Game.h"

int main() {
	DBConsole *dbc = new DBConsole();
	Game *game = new Game(dbc);
	game->start();
	for(;;game->isRunning()){
		game->run();
	}
	delete game;
	delete dbc;
}