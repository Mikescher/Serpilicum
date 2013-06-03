#include "Label.h"


Label::Label(void)
{
	text = "";
}


Label::~Label(void)
{
}

void Label::render(DBConsole* pConsole)
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