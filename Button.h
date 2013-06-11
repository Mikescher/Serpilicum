#pragma once
#include "MenuElement.h"
#include "ActionListener.h"
class Button:
	public MenuElement
{
private:
	std::string text;
	ActionListener * listener;
	int id;
	
	virtual void throwEvent();
public:
	Button(void);
	Button(int id);
	Button(int id, std::string initval, int nx, int ny);
	virtual ~Button(void);

	virtual void render(AbstractConsole* pConsole);
	virtual void onKeyDown(int keycode);
	virtual bool isFocusable();

	virtual void setText(std::string pText);
	virtual std::string getText();

	virtual void setListener(ActionListener * lst);
	virtual ActionListener *removeListener();
};

