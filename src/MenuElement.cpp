#include "MenuElement.h"


MenuElement::MenuElement(void)
{
	x = 0;
	y = 0;

	width = 0;
	height = 0;

	focused = false;
}

MenuElement::MenuElement(int nx, int ny, int nw, int nh) 
{
	x = nx;
	y = ny;

	width = nw;
	height = nh;

	focused = false;
}


MenuElement::~MenuElement(void)
{
}

int MenuElement::getX()
{
	return x;
}

int MenuElement::getY()
{
	return y;
}

void MenuElement::setX(int pX)
{
	x = pX;
}

void MenuElement::setY(int pY)
{
	y = pY;
}

int MenuElement::getHeight()
{
	return height;
}

int MenuElement::getWidth()
{
	return width;
}

void MenuElement::setHeight(int pheight)
{
	height = pheight;
}

void MenuElement::setWidth(int pwidth)
{
	width = pwidth;
}

bool MenuElement::isFocused() {
	return focused;
}

void MenuElement::setFocused(bool foc) {
	focused = foc;
}
