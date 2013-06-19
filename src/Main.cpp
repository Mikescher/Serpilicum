#include "xoxoMain.h"

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

Crazy Powerup := RAndom char (speed fast), sometimes 1x3, sometimes 3x1, sometimes 1x1->3x3->5x5->3x3->1x1
Crazy Mode (Shader Transformations Color, in COnsole implementated) (What to do with WinConsole ???)
FPS Limiter
Where do we loose FPS with looooooooong snake (20 FPS with BUFFER_H*4 Length)

::GM::
EASY
RETRO
NORMAL
HARDCORE
ASPIRIN
*/
