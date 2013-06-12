#pragma once

#include "DBConsole.h"
#include "Keycodes.h"
#include <Windows.h>
#include <chrono>
#include "ActionListener.h"

class WindowsConsole :
	public DBConsole
{
private:
	HANDLE hConsole;
protected:
	virtual void writeToConsole(char c, int x, int y);
	virtual void showConsoleCursor(bool bShow);
	virtual unsigned char getKeyState();
	virtual long getSystemCurrTimeMillis();
	virtual void setDimensions(short buffW, short buffH);
public:
	WindowsConsole(void);
	~WindowsConsole(void);

	virtual void startLoop(ActionListener *looplistener);
};
