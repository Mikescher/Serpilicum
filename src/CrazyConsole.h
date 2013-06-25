#pragma once
#define _USE_MATH_DEFINES
#include "oglconsole.h"
class CrazyConsole :
	public OGLConsole
{
private:
	GLfloat depth;
protected:
	virtual void startRenderOGL();
	virtual void renderOGLPos(int x, int y, int chr);
public:
	virtual void initOGL();
};

