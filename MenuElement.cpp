#include "MenuElement.h"


MenuElement::MenuElement(void)
{
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


