#pragma once

#include "DBConsole.h"
#include <Windows.h>
#include <WinBase.h>
#include <chrono>
#include "Keycodes.h"
#include "ListenerCollection.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

class OGLConsole :
	public DBConsole
{
private:
	virtual unsigned char* loadBMPRaw(const unsigned char * image, unsigned int outWidth, unsigned int outHeight, bool flipY);
	virtual GLuint LoadTextureRAW(int id, int w, int h);
protected:
	GLuint chartextures;

	virtual void loadTextures();
protected:
	virtual void writeToConsole(int c, int x, int y);
	virtual void showConsoleCursor(bool bShow);
	virtual unsigned char getKeyState();
	virtual void hideConsole();
	virtual long getSystemCurrTimeMillis();
	virtual void doSystemSleep(long duration);
	virtual void setDimensions(short w, short h);

	virtual void startRenderOGL();
	virtual void renderOGL();
	virtual void renderOGLPos(int x, int y, int chr);
public:
	OGLConsole(void);
	~OGLConsole(void);

	virtual void initOGL();

	virtual void clearBuffer();
	virtual void swap();

	virtual bool* getBoolImageResource(int id);

	virtual void startLoop(ActionListener *looplistener, KeyEventListener *keyListener);
};

