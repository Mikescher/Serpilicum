#pragma once

#include "AbstractConsole.h"
#include <GL/glut.h>

class CrazyDouble
{
private:
	long lastRun;
protected:
	double max_speed;
	double max_value;
	double min_value;

	double initial_val;
	double value;

	double acceleration;
	double speed;
	double target;

	bool running;
private:
	virtual void newTarget();
public:
	CrazyDouble(AbstractConsole* pConsole, double initial, double speedmax, double acc, double min, double max);

	virtual GLfloat get() {return GLfloat(value);}

	virtual void run(AbstractConsole* pConsole);

	virtual void restart();
	virtual void stop();
};

