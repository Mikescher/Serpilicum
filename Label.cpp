#include "Label.h"


Label::Label(void)
{
	text = "";
}

Label::Label(std::string initval, int nx, int ny) : 
	MenuElement(nx, ny, 10, 1)
{
	text = initval;
}


Label::~Label(void)
{
}

void Label::render(AbstractConsole* pConsole)
{
	pConsole->write(getText(), getX(), getY());
}

void Label::setText(std::string pText)
{
	text = pText;
}

std::string Label::getText()
{
	return text;
}

void Label::onKeyDown(int keycode) {
// nothing to do here
}

bool Label::isFocusable() {
	return false;
}