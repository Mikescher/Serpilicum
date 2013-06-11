#include "HPSpawnEffect.h"


HPSpawnEffect::HPSpawnEffect(int px, int py) : LevelEffect(px, py)
{
}

HPSpawnEffect::~HPSpawnEffect(void)
{
}

void HPSpawnEffect::start(AbstractConsole *console) {
	startTime = console->getCurrentTimeMillis();
	mode = 3;
}

void HPSpawnEffect::run(AbstractConsole *console) {
	long delta = console->getCurrentTimeMillis() - startTime;

	mode = delta / HPSE_EFFECT_DELAY;

	if (mode > 3) {
		mode = 3;
		stop();
	}
}

void HPSpawnEffect::render(AbstractConsole *console) {
	if (mode == 0){
		renderMode0(console);
	} else if (mode == 1){
		renderMode1(console);
	} else if (mode == 2){
		renderMode2(console);
	}

}

void HPSpawnEffect::renderMode0(AbstractConsole *console) {
	console->write('/', x-1, y-3);
	console->write('^', x, y-3);
	console->write('\\', x+1, y-3);

	console->write('/', x-2, y-2);
	console->write('\\', x+2, y-2);

	console->write('/', x-3, y-1);
	console->write('\\', x+3, y-1);

	console->write('<', x-3, y);
	console->write('>', x+3, y);

	console->write('\\', x-3, y+1);
	console->write('/', x+3, y+1);

	console->write('\\', x-2, y+2);
	console->write('/', x+2, y+2);

	console->write('\\', x-1, y+3);
	console->write('v', x, y+3);
	console->write('/', x+1, y+3);
}

void HPSpawnEffect::renderMode1(AbstractConsole *console) {
	console->write('-', x-1, y-2);
	console->write('^', x, y-2);
	console->write('-', x+1, y-2);

	console->write('|', x-2, y-1);
	console->write('/', x-1, y-1);
	console->write('\\', x+1, y-1);
	console->write('|', x+2, y-1);

	console->write('<', x-2, y);
	console->write('>', x+2, y);

	console->write('|', x-2, y+1);
	console->write('\\', x-1, y+1);
	console->write('/', x+1, y+1);
	console->write('|', x+2, y+1);

	console->write('-', x-1, y+2);
	console->write('v', x, y+2);
	console->write('-', x+1, y+2);
}

void HPSpawnEffect::renderMode2(AbstractConsole *console) {
	console->write('/', x-1, y-1);
	console->write('-', x, y-1);
	console->write('\\', x+1, y-1);

	console->write('|', x-1, y);
	console->write('|', x+1, y);

	console->write('\\', x-1, y+1);
	console->write('-', x, y+1);
	console->write('/', x+1, y+1);
}
