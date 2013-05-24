#include "Game.h"
#include "DBConsole.h"
#include "Level.h"


Game::Game(DBConsole *pconsole)
{
	console = pconsole;
	running = false;
	Level *level = new Level();
}


Game::~Game(void)
{
	delete level;
}

void Game::start(){
	running = true;
}

void Game::stop(){

}

bool Game::isRunning(){
	return running;
}

void Game::run(){
}