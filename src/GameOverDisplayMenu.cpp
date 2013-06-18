#include "GameOverDisplayMenu.h"
#include "Keycodes.h"

GameOverDisplayMenu::GameOverDisplayMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID, int points) : 
	DisplayImageTextMenu(pid, console, quitListener, resourceID, 1500) 
{
	cpoints = points;
}

void GameOverDisplayMenu::onKeyDown(int keycode) {
	if (keycode == KC_SPACE || keycode == KC_ENTER) {
		if (listener != 0) {
			listener->actionPerformed(id, cpoints);
		}
	}
}