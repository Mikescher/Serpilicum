#include "Main.h"
#include "Gamerules.h"

int main() {
	Main *main = new Main();
	main->start();

	delete main;
}

//#############################################

void Main::start() {
	switch(DISPLAYMETHOD) {
	case WINDOWS_CONSOLE:
		dbc = new WindowsConsole();
		break;
	case OGL_CONSOLE:
		dbc = new OGLConsole();
		((OGLConsole*)dbc)->initOGL();
		break;
	case CRAZY_CONSOLE:
		dbc = new CrazyConsole();
		((CrazyConsole*)dbc)->initOGL();
		break;
	}

	game = new Game(dbc);

	dbc->init();

	dbc->startLoop(this, this);

	delete game;
	delete dbc;
}

void Main::actionPerformed(int id, int param) {

	game->run(dbc);
}

void Main::keyEventPerformed(int keycode) {
	game->onKeyDown(keycode);
}

//#############################################
/*
Where do we loose FPS with looooooooong snake (20 FPS with BUFFER_H*4 Length)
*/