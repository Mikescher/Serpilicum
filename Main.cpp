#include <iostream>
#include "DBConsole.h"
#include "Game.h"
#include <windows.h>

int main() {
	DBConsole *dbc = new DBConsole();
	Game *game = new Game(dbc);
	game->start();
	while(game->isRunning()){
		game->run();
		Sleep(500);
	}
	delete game;
	delete dbc;
}