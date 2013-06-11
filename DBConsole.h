#pragma once
#include <string>
#include "AbstractConsole.h"

class DBConsole : 
	public AbstractConsole
{
private:
	char display[BUFFER_W][BUFFER_H];
	char buffer[BUFFER_W][BUFFER_H];

	

protected:
	virtual void writeToConsole(char c, int x, int y) = 0;
	virtual void showConsoleCursor(bool bShow) = 0;
	virtual int getKeyState() = 0;
	virtual long getSystemCurrTimeMillis() = 0;
	virtual void setDimensions(short w, short h) = 0;
public:
	DBConsole(void);
	virtual ~DBConsole(void);

	virtual void init();

	virtual void redraw();

	virtual void write(char c, int x, int y);
	virtual void write(std::string s, int x, int y);

	virtual void clearBuffer();
	virtual void swap();

	virtual int getCurrentKeyState();
	virtual int getFullKeyEvent();
	virtual int getBlockingFullKeyEvent();
	virtual long getCurrentTimeMillis();
};

