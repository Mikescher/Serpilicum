#include "AutoModifierStartEffect.h"


AutoModifierStartEffect::AutoModifierStartEffect(int px, int py) : LevelEffect(px, py)
{
	startTime = 0;
	x1 = 0;
	y1 = 0;
	x2 = BUFFER_W;
	y2 = BUFFER_H;
}


AutoModifierStartEffect::~AutoModifierStartEffect(void)
{
}

void AutoModifierStartEffect::start(AbstractConsole *console) {
	startTime = console->getCurrentTimeMillis();
}

void AutoModifierStartEffect::run(AbstractConsole *console) {
	long delta = console->getCurrentTimeMillis() - startTime;

	double perc = delta / 250.0;

	if (perc >= 1.0) {
		stop();
	} else {
		x1 = (int) (x * perc);
		x2 = (int) (BUFFER_W - (BUFFER_W - x) * perc);
		y1 = (int) (y * perc);
		y2 = (int) (BUFFER_H - (BUFFER_H - y) * perc);
	}
}

void AutoModifierStartEffect::render(AbstractConsole *console) {
	for (int ix= x1 + 1; ix < x2; ix++) {
		console->write('-', ix, y1);
		console->write('-', ix, y2);
	}

	for (int iy= y1 + 1; iy < y2; iy++) {
		console->write('|', x1, iy);
		console->write('|', x2, iy);
	}
}
