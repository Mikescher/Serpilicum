#include "DisplayImageTextMenu.h"
#include "Keycodes.h"


DisplayImageTextMenu::DisplayImageTextMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID, int pduration) : Menu() {
	resourceArray = console->getBoolImageResource(resourceID);
	listener = quitListener;
	id = pid;
	duration = pduration;
	startTime = console->getCurrentTimeMillis();
}

void DisplayImageTextMenu::createMenu(ActionListener * quitListener) {
	//
}

void DisplayImageTextMenu::render(AbstractConsole* pConsole) {
	double perc = (pConsole->getCurrentTimeMillis() - startTime * 1.0) / duration;
	perc = std::min(1.0, perc);

	for (int xx = 0; xx < BUFFER_W; xx++)
	{
		for (int yy = 0; yy < BUFFER_H; yy++)
		{
			double px = xx;
			double py = (BUFFER_H - yy - 1);

			px -= BUFFER_W/2;
			py -= BUFFER_H/2;

			px *= perc;
			py *= perc;

			px = BUFFER_W/2 + px;
			py = BUFFER_H/2 + py;

			pConsole->write((resourceArray[yy * BUFFER_W + xx]) ? ('#') : (' '), (int)std::floor(px + 0.5), (int)std::floor(py + 0.5));
		}
	}
}

void DisplayImageTextMenu::onKeyDown(int keycode) {
	if (keycode == KC_SPACE || keycode == KC_ENTER) {
		throwAction();
	}
}

void DisplayImageTextMenu::run(AbstractConsole* pConsole) {
	//--
}

void DisplayImageTextMenu::throwAction() {
	if (listener != 0) {
			listener->actionPerformed(id, -1);
	}
}