#include "BiteEffect.h"


BiteEffect::BiteEffect(int px, int py, int delayID, int elchar) : LevelEffect(px, py) {
	delta = 0;
	startTime = 0;
	delay = delayID * 50;
	mode = 0;
	elementchar = elchar;
}

BiteEffect::~BiteEffect(void) {

}

void BiteEffect::start(AbstractConsole *console) {
	startTime = console->getCurrentTimeMillis();
}

void BiteEffect::run(AbstractConsole *console) {
	delta = console->getCurrentTimeMillis() - startTime;

	if (delta < delay) {
		mode = 0;
	} else if (delta < (delay + 250)){
		mode = 1;
	} else {
		stop();
	}
}

void BiteEffect::render(AbstractConsole *console) {
	if (mode == 0) {
		console->write(elementchar, getX(), getY());
	} else if (mode == 1){
		double dist = ((delta-delay) / 250.0) * 10.5;

		for (int i = 0; i < 20; i++)
		{
			int xx = (int) (cos(2 * 3.141459 * (i / 20.0)) * dist);
			int yy = (int) (sin(2 * 3.141459 * (i / 20.0)) * dist);

			console->write(250, (getX() + xx + BUFFER_W) % BUFFER_W, (getY() + yy + BUFFER_H) % BUFFER_H);
		}

	}
}