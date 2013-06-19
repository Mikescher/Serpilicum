#include "ChooseGameModeMenu.h"
#include "Keycodes.h"

ChooseGameModeMenu::ChooseGameModeMenu(int pid, AbstractConsole* pConsole, ActionListener * quitListener) : DisplayImageTextMenu(pid, pConsole, quitListener, 106, 0)
{
	currmode = 2;
	console = pConsole;
}

void ChooseGameModeMenu::onKeyDown(int keycode) {
	DisplayImageTextMenu::onKeyDown(keycode);

	if (keycode == KC_LEFT) {
		currmode = (currmode + (GAMEMODECOUNT-1)) % GAMEMODECOUNT;
		update();
	} else if (keycode == KC_RIGHT) {
		currmode = (currmode + 1) % GAMEMODECOUNT;
		update();
	}
}

void ChooseGameModeMenu::update() {
	switch(currmode) {
	case 0: 
		resourceArray = console->getBoolImageResource(104); 
		break;
	case 1: 
		resourceArray = console->getBoolImageResource(105); 
		break;
	case 2: 
		resourceArray = console->getBoolImageResource(106); 
		break;
	case 3: 
		resourceArray = console->getBoolImageResource(107); 
		break;
	case 4: 
		resourceArray = console->getBoolImageResource(108); 
		break;
	case 5: 
		resourceArray = console->getBoolImageResource(109); 
		break;
	}
}