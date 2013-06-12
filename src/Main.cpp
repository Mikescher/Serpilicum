#include <iostream>
#include "OGLConsole.h"
#include "WindowsConsole.h"
#include "AbstractConsole.h"
#include "Game.h"
#include <windows.h>
#include "Keycodes.h"
#include <time.h>

class Main : public ActionListener 
{
private:
	AbstractConsole *dbc;
	Game *game;
public:
	virtual void start();
	virtual void actionPerformed(int id);
};

int main() {
	Main *main = new Main();
	main->start();

	delete main;
}

void Main::start() {
	dbc = new WindowsConsole();
	game = new Game(dbc);

	dbc->init();

	dbc->startLoop(this);

	delete game;
	delete dbc;
}

void Main::actionPerformed(int id) {
	game->run(dbc);

	int keycode = dbc->getCurrentKeyState();
	if (keycode != 0) {
		game->onKeyDown(keycode);
	}
}
