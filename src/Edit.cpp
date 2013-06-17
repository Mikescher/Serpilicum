#include "Edit.h"
#include "Keycodes.h"


Edit::Edit(int pid, std::string initval, int nx, int ny) : MenuElement(nx, ny, 10, 3)
{
	text = initval;
}


Edit::~Edit(void)
{
}

void Edit::render(AbstractConsole* pConsole)
{
	int width = 15;
	int right = getX() + width;

	for(int i = getX(); i < right; i++) {
		pConsole->write(isFocused() ? ('#') : ('-'), i, getY() - 1);
		pConsole->write(isFocused() ? ('#') : ('-'), i, getY() + 1);
	}
	pConsole->write('/', getX() - 1, getY() - 1);
	pConsole->write('|', getX() - 1, getY());
	pConsole->write('\\', getX() - 1, getY() + 1);

	pConsole->write('\\', right, getY() - 1);
	pConsole->write('|', right, getY());
	pConsole->write('/', right, getY() + 1);

	pConsole->write(getText(), getX(), getY());
}

std::string Edit::getText()
{
	return text;
}

bool Edit::isFocusable() {
	return true;
}


void Edit::onKeyDown(int keycode) {
	if (keycode >= 'A' && keycode <= 'Z') text += (char)keycode;
}