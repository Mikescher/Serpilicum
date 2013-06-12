#pragma once
#include <string>
#include "AbstractConsole.h"

class DBConsole : 
	public AbstractConsole
{
protected:
	char display[BUFFER_W][BUFFER_H];
	char buffer[BUFFER_W][BUFFER_H];

	bool currKeyStates[256];
protected:
	virtual void writeToConsole(char c, int x, int y) = 0;
	virtual void showConsoleCursor(bool bShow) = 0;
	virtual unsigned char getKeyState() = 0;
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

	virtual unsigned char getCurrentKeyState();
	virtual unsigned char getFullKeyEvent();
	virtual long getCurrentTimeMillis();

	virtual void startLoop(ActionListener *looplistener) = 0;
};

