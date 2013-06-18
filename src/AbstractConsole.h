#pragma once

#include <string>
#include "ListenerCollection.h"

const int BUFFER_W = 80;
const int BUFFER_H = 40;

class AbstractConsole
{
public:
	virtual void init() = 0;

	virtual void redraw() = 0;

	virtual void write(int c, int x, int y) = 0;
	virtual void write(std::string s, int x, int y) = 0;

	virtual void clearBuffer() = 0;
	virtual void swap() = 0;

	virtual void zoomIn(int centerX, int centerY) = 0;

	virtual unsigned char getCurrentKeyState() = 0;
	virtual void setDimensions(short w, short h) = 0;
	virtual long getCurrentTimeMillis() = 0;
	virtual double getFPS() = 0;
	virtual bool* getBoolImageResource(int id) = 0;

	virtual void startLoop(ActionListener *looplistener, KeyEventListener *keyListener) = 0;
};

