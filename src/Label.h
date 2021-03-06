#pragma once
#include "MenuElement.h"
#include "AbstractConsole.h"
class Label:public MenuElement
{
private:
	std::string text;
public:
	Label(void);
	Label(std::string initval, int nx, int ny);
	virtual ~Label(void);

	virtual void render(AbstractConsole* pConsole);
	virtual void onKeyDown(int keycode);
	virtual bool isFocusable();

	virtual void setText(std::string pText);
	virtual std::string getText();

};

