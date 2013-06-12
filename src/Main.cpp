#include <iostream>
#include "OGLConsole.h"
#include "WindowsConsole.h"
#include "AbstractConsole.h"
#include "Game.h"
#include <windows.h>
#include "Keycodes.h"
#include <time.h>

class Main : 
	public ActionListener,
	public KeyEventListener
{
private:
	AbstractConsole *dbc;
	Game *game;
public:
	virtual void start();
	virtual void actionPerformed(int id);
	virtual void keyEventPerformed(int key);
};

int main() {
	Main *main = new Main();
	main->start();

	delete main;
}

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