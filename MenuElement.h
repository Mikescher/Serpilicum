#pragma once
#include "DBConsole.h"
class MenuElement
{
private:
	int  x, y, width, height;

public:
	MenuElement(void);
	~MenuElement(void);

	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
	virtual int getWidth();
	virtual int getHeight();
	virtual void setWidth(int width);
	virtual void setHeight(int heigt);
	virtual void render(DBConsole* pConsole) = 0;
	virtual void onClick() = 0;

};

