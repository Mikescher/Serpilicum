#pragma once
#include "oglconsole.h"
class CrazyConsole :
	public OGLConsole
{
protected:
	virtual void startRenderOGL();
	virtual void swap();
public:
	virtual void initOGL();
};

