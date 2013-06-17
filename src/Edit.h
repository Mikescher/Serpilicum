#pragma once
#include "menuelement.h"
class Edit :
	public MenuElement
{
private:
	std::string text;
public:
	Edit(int id, std::string initval, int nx, int ny);
	~Edit(void);

	virtual void render(AbstractConsole* pConsole);
	virtual std::string getText();
	virtual bool isFocusable();
	virtual void onKeyDown(int keycode);
};

