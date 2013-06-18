#include "Button.h"
#include "Keycodes.h"

Button::Button(void)
{
	text = "";
	listener = 0;
	id = 0;
}

Button::Button(int pid) {
	text = "";
	listener = 0;
	id = pid;
}

Button::Button(int pid, std::string initval, int nx, int ny) : MenuElement(nx, ny, 10, 3)
{
	text = initval;
	listener = 0;
	id = pid;
}


Button::~Button(void)
{
}

void Button::render(AbstractConsole* pConsole)
{
	int width = getText().length();
	int right = getX() + width;

	for(int i = getX(); i < right; i++) {
		pConsole->write(isFocused() ? (223) : (196), i, getY() - 1);
		pConsole->write(isFocused() ? (220) : (196), i, getY() + 1);
	}
	pConsole->write(isFocused() ? (219) : (218), getX() - 1, getY() - 1);
	pConsole->write(isFocused() ? (219) : (179), getX() - 1, getY());
	pConsole->write(isFocused() ? (219) : (192), getX() - 1, getY() + 1);

	pConsole->write(isFocused() ? (219) : (191), right, getY() - 1);
	pConsole->write(isFocused() ? (219) : (179), right, getY());
	pConsole->write(isFocused() ? (219) : (217), right, getY() + 1);

	pConsole->write(getText(), getX(), getY());
}

void Button::setText(std::string pText)
{
	text = pText;
}

std::string Button::getText()
{
	return text;
}

void Button::onKeyDown(int keycode) {
	if (keycode == KC_SPACE || keycode == KC_ENTER) {
		throwEvent();
	}
}

void Button::setListener(ActionListener * lst) {
	listener = lst;
}

ActionListener *Button::removeListener() {
	ActionListener* tmp = listener;

	listener = 0;

	return tmp;
}

void Button::throwEvent() {
	if (listener != 0) {
		listener->actionPerformed(id, -1);
	}
}

bool Button::isFocusable() {
	return true;
}