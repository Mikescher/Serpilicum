#include "AspirinObstacle.h"
#include "Level.h"

AspirinObstacle::AspirinObstacle(int px, int py, int deltax, int deltay) : LevelObstacle(px, py)
{
	dx = deltax;
	dy = deltay;
}


void AspirinObstacle::init(AbstractConsole* pConsole)
{
	lastMove = pConsole->getCurrentTimeMillis();
}

void AspirinObstacle::run(AbstractConsole* pConsole)
{
	long delta = pConsole->getCurrentTimeMillis() - lastMove;

	if (delta > 75) {
		x += dx;
		y += dy;

		if (x == 0 || y == 0 || x == BUFFER_W-1 || y == BUFFER_H-1) {
			dx *= -1;
			dy *= -1;
		}

		lastMove = pConsole->getCurrentTimeMillis();
	}
}

void AspirinObstacle::render(AbstractConsole* pConsole)
{
	pConsole->write(isHorizontal() ? 196 : 179, getX(), getY());
}

bool AspirinObstacle::onSnakeHit(Level* level)
{
	level->onDie();
	return 0;
}

bool AspirinObstacle::isHorizontal() {
	return dx != 0;
}