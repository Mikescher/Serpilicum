#pragma once

#define _USE_MATH_DEFINES
#include "oglconsole.h"
#include <vector>
#include "CrazyDouble.h"

class CrazyConsole :
	public OGLConsole
{
private:
	GLfloat depth;
	CrazyDouble* heightshift;

	CrazyDouble* xangleShift;
	CrazyDouble* yangleShift;
	CrazyDouble* zangleShift;

	CrazyDouble* rcolorShift;
	CrazyDouble* gcolorShift;
	CrazyDouble* bcolorShift;

	CrazyDouble* xscaleShift;
	CrazyDouble* yscaleShift;
protected:
	virtual void startRenderOGL();
	virtual void renderOGLPos(int x, int y, int chr);
public:
	CrazyConsole();

	virtual void initOGL();

	virtual void restartCrazy();
	virtual void stopCrazy();

	virtual void onLevelStart();
	virtual void onLevelStop();
};

