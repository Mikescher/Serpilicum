#include "GameOverDisplayMenu.h"
#include "Keycodes.h"

GameOverDisplayMenu::GameOverDisplayMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID, int points) : 
	DisplayImageTextMenu(pid, console, quitListener, resourceID, 1500) 
{
	cpoints = points;
}