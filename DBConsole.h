#pragma once

#include <string>

const int BUFFER_W = 80;
const int BUFFER_H = 40;

class DBConsole
{
private:
	char display[BUFFER_W][BUFFER_H];
	char buffer[BUFFER_W][BUFFER_H];

	virtual void init();

	virtual void writeToConsole(char c, int x, int y);
	virtual void showConsoleCursor(bool bShow);
public:
	DBConsole(void);
	~DBConsole(void);

	virtual void redraw();

	virtual void write(char c, int x, int y);
	virtual void write(std::string s, int x, int y);

	virtual void clearBuffer();
	virtual void swap();

	virtual int getKeyState();
	virtual int getFullKeyEvent();
	virtual int getBlockingFullKeyEvent();

	virtual long getCurrentTimeMillis();
};

