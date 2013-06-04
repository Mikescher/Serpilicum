#pragma once
#include "DBConsole.h"
class MenuElement {
private:
	int x;
	int y;
	int width;
	int height;

	bool focused;
public:
	MenuElement(void);
	MenuElement(int nx, int ny, int nw, int nh);
	virtual ~MenuElement(void);

	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
	virtual int getWidth();
	virtual int getHeight();
	virtual void setWidth(int width);
	virtual void setHeight(int heigt);
	virtual void render(DBConsole* pConsole) = 0;
	virtual void onKeyDown(int keycode) = 0;
	virtual bool isFocused();
	virtual void setFocused(bool foc);
};