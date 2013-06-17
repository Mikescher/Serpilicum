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
		pConsole->write(isFocused() ? (205) : (196), i, getY() - 1);
		pConsole->write(isFocused() ? (205) : (196), i, getY() + 1);
	}
	pConsole->write(isFocused() ? (201) : (218), getX() - 1, getY() - 1);
	pConsole->write(isFocused() ? (186) : (179), getX() - 1, getY());
	pConsole->write(isFocused() ? (200) : (192), getX() - 1, getY() + 1);

	pConsole->write(isFocused() ? (187) : (191), right, getY() - 1);
	pConsole->write(isFocused() ? (186) : (179), right, getY());
	pConsole->write(isFocused() ? (188) : (217), right, getY() + 1);

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
	if (keycode >= 'A' && keycode <= 'Z') {
		text += (char)keycode;
	}

	if (keycode == KC_BACKSPACE && ! text.empty()) {
		text = text.substr(0, text.length() - 1);
	}
}