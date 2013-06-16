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



//#############################################
/*

AutoSnake PowerUp := - -> / -> | -> \
Crazy Powerup := RAndom char (speed fast), sometimes 1x3, sometimes 3x1, sometimes 1x1->3x3->5x5->3x3->1x1
Crazy Mode (Shader Transformations Color, in COnsole implementated) (What to do with WinConsole ???)
Explosion when Bite/kill -> Effect -> StarDelay bigger when more behind -> chainreaction (particle, vector, chars flying away)
3 Lives System (Biting)
Message displaying -> Message in  Black'n'White bmp -> first 1x1 px big -> extend (math) to actual size -> fast flying aout of monitor
(GAME OVER,  N Lives Left,  CRAZY Mode)
Zoom In PowerUp (1x1->3x3->5x5->3x3->1x1->3x3...) Half Speed but 2x Zoom (everything 4x4)


*/
