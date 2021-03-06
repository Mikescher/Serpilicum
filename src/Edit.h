#pragma once
#include "menuelement.h"
class Edit :
	public MenuElement
{
private:
	int id;
	ActionListener * listener;
	std::string text;

	virtual void throwEvent();
public:
	Edit(int id, std::string initval, int nx, int ny);
	~Edit(void);

	virtual void render(AbstractConsole* pConsole);
	virtual std::string getText();

	virtual bool isFocusable();
	virtual void onKeyDown(int keycode);

	virtual void setListener(ActionListener * lst);
	virtual ActionListener *removeListener();
};

