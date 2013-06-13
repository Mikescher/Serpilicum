#include "Main.h"

int main() {
	Main *main = new Main();
	main->start();

	delete main;
}

//#############################################

void Main::start() {
	dbc = new OGLConsole();
	game = new Game(dbc);

	dbc->init();

	dbc->startLoop(this, this);

	delete game;
	delete dbc;
}

void Main::actionPerformed(int id) {

	game->run(dbc);
}

void Main::keyEventPerformed(int keycode) {
	game->onKeyDown(keycode);
}