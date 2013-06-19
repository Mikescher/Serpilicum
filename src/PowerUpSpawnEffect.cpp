#include "PowerUpSpawnEffect.h"
#include "Gamerules.h"

PowerUpSpawnEffect::PowerUpSpawnEffect(int px, int py) : LevelEffect(px, py)
{
}

PowerUpSpawnEffect::~PowerUpSpawnEffect(void)
{
}

void PowerUpSpawnEffect::start(AbstractConsole *console) {
	startTime = console->getCurrentTimeMillis();
	mode = 3;
}

void PowerUpSpawnEffect::run(AbstractConsole *console) {
	long delta = console->getCurrentTimeMillis() - startTime;

	mode = delta / HPSE_EFFECT_DELAY;

	if (mode > 3) {
		mode = 3;
		stop();
	}
}

void PowerUpSpawnEffect::render(AbstractConsole *console) {
	if (mode == 0){
		renderMode0(console);
	} else if (mode == 1){
		renderMode1(console);
	} else if (mode == 2){
		renderMode2(console);
	}

}

void PowerUpSpawnEffect::renderMode0(AbstractConsole *console) {
	write(console, '/', x-1, y-3);
	write(console, '^', x, y-3);
	write(console, '\\', x+1, y-3);

	write(console, '/', x-2, y-2);
	write(console, '\\', x+2, y-2);

	write(console, '/', x-3, y-1);
	write(console, '\\', x+3, y-1);

	write(console, '<', x-3, y);
	write(console, '>', x+3, y);

	write(console, '\\', x-3, y+1);
	write(console, '/', x+3, y+1);

	write(console, '\\', x-2, y+2);
	write(console, '/', x+2, y+2);

	write(console, '\\', x-1, y+3);
	write(console, 'v', x, y+3);
	write(console, '/', x+1, y+3);
}

void PowerUpSpawnEffect::renderMode1(AbstractConsole *console) {
	write(console, '-', x-1, y-2);
	write(console, '^', x, y-2);
	write(console, '-', x+1, y-2);

	write(console, '|', x-2, y-1);
	write(console, '/', x-1, y-1);
	write(console, '\\', x+1, y-1);
	write(console, '|', x+2, y-1);

	write(console, '<', x-2, y);
	write(console, '>', x+2, y);

	write(console, '|', x-2, y+1);
	write(console, '\\', x-1, y+1);
	write(console, '/', x+1, y+1);
	write(console, '|', x+2, y+1);

	write(console, '-', x-1, y+2);
	write(console, 'v', x, y+2);
	write(console, '-', x+1, y+2);
}

void PowerUpSpawnEffect::renderMode2(AbstractConsole *console) {
	write(console, '/', x-1, y-1);
	write(console, '-', x, y-1);
	write(console, '\\', x+1, y-1);

	write(console, '|', x-1, y);
	write(console, '|', x+1, y);

	write(console, '\\', x-1, y+1);
	write(console, '-', x, y+1);
	write(console, '/', x+1, y+1);
}

void PowerUpSpawnEffect::write(AbstractConsole* console, int cr, int x, int y) {
	if (GAMERULE_InfiniteField) {
		x += BUFFER_W;
		y += BUFFER_H;
		x %= BUFFER_W;
		y %= BUFFER_H;
	}

	console->write(cr, x, y);
}