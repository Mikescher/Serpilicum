#pragma once
#include "MenuElement.h"
#include "DBConsole.h"
class Label:public MenuElement
{
private:
	std::string text;
public:
	Label(void);
	~Label(void);

	virtual void render(DBConsole* pConsole);
	virtual void setText(std::string pText);
	virtual std::string getText();

};

