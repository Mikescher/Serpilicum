#pragma once
#include <string>
#include <algorithm>
#include "AbstractConsole.h"

class DBConsole : 
	public AbstractConsole
{
private:
	long firstTimeMillis;

	long lastRenderTime;
	int fpsCount;
	long fpsSum;
	double fps;
	bool showFPS;
protected:
	int display[BUFFER_W][BUFFER_H];
	int buffer[BUFFER_W][BUFFER_H];

	bool currKeyStates[256];
protected:
	virtual void writeToConsole(int c, int x, int y) = 0;
	virtual void showConsoleCursor(bool bShow) = 0;
	virtual void hideConsole() = 0;
	virtual unsigned char getKeyState() = 0;
	virtual long getSystemCurrTimeMillis() = 0;
	virtual void doSystemSleep(long duration) = 0;
	virtual void setDimensions(short w, short h) = 0;
public:
	DBConsole(void);
	virtual ~DBConsole(void);

	virtual void init();

	virtual void redraw();

	virtual void write(int c, int x, int y);
	virtual void write(std::string s, int x, int y);

	virtual void clearBuffer();
	virtual void swap();

	virtual void zoomIn(int centerX, int centerY);

	virtual unsigned char getCurrentKeyState();
	virtual long getCurrentTimeMillis();
	virtual double getFPS();

	virtual void onLevelStart();
	virtual void onLevelStop();
};

