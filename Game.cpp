#include "Game.h"
#include "DBConsole.h"
#include "Level.h"


Game::Game(DBConsole *pconsole)
{
	console = pconsole;
	running = false;
	level = new Level();
}


Game::~Game(void)
{
	delete level;
}

void Game::start(){
	running = true;
}

void Game::stop(){
	running = false;
}

bool Game::isRunning(){
	return running;
}

void Game::run(){
	level->run();

	render();
}

void Game::render() {
	console->clearBuffer();

	renderSnake();
	renderPowerups();

	console->swap();
}

void Game::renderSnake() {
	SnakeElement * snakeelement = level->getSnake()->getHead();

	while(snakeelement != 0) {
		console->write('#', snakeelement->getX(), snakeelement->getY());

		snakeelement = snakeelement->getNextElement();
	}
}

void Game::renderPowerups() {
	PowerUp * pelem = level->getPowerUpList()->getFirst();

	while(pelem != 0) {
		console->write(pelem->getSymbol(), pelem->getX(), pelem->getY());

		pelem = pelem->getNextElement();
	}
}