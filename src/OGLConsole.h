#pragma once

#include "DBConsole.h"
#include <Windows.h>
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
	GLuint chartextures;

	virtual void loadTextures();

	virtual unsigned char* loadBMPRaw(const unsigned char * image, unsigned int outWidth, unsigned int outHeight, bool flipY);
	virtual GLuint LoadTextureRAW(int id, int w, int h);
protected:
	virtual void writeToConsole(char c, int x, int y);
	virtual void showConsoleCursor(bool bShow);
	virtual unsigned char getKeyState();
	virtual long getSystemCurrTimeMillis();
	virtual void setDimensions(short w, short h);

	virtual void renderOGL();
public:
	OGLConsole(void);
	~OGLConsole(void);

	virtual void clearBuffer();
	virtual void swap();

	virtual void startLoop(ActionListener *looplistener, KeyEventListener *keyListener);
};

