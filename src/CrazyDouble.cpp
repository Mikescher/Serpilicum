#include "CrazyDouble.h"


CrazyDouble::CrazyDouble(AbstractConsole* pConsole, double initial, double speedmax, double acc, double min, double max)
{
	max_speed = speedmax;
	max_value = max;
	min_value = min;

	initial_val = initial;
	value = initial_val;

	acceleration = acc;

	speed = 0;
	target = 0;
	running = true;

	lastRun = pConsole->getCurrentTimeMillis();

	newTarget();
}

void CrazyDouble::newTarget() {
	if (! running) {
		target = initial_val;
		return;
	}

	target = (rand() / (RAND_MAX * 1.0)) * abs(max_value - min_value) + min_value;
}

void CrazyDouble::run(AbstractConsole* pConsole) {
	if (! running && value == target) return; 


	long delta = pConsole->getCurrentTimeMillis() - lastRun;
	delta = std::min(delta, 100l);

	int direction = (value - target) < 0 ? 1 : -1;

	speed += acceleration * direction * delta;

	if (abs(speed) > max_speed) {
		if (speed < 0) {
			speed = -max_speed;
		} else {
			speed = max_speed;
		}
	}

	double prev = value;

	value += speed * delta;

	if ((((prev - target) * (value - target)) < 0) || (abs(value - target) < 1.0)) {
		newTarget();
		if (! running) value = target;
	}

	lastRun = pConsole->getCurrentTimeMillis();
}

void CrazyDouble::restart() {
	running = true;
	newTarget();
}

void CrazyDouble::stop() {
	running = false;
	newTarget();
}