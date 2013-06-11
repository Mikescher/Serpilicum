#include "AutoSnake.h"
#include "Level.h"
#include "DBConsole.h"

AutoSnake::AutoSnake(void)
{
	level = 0;
}

AutoSnake::AutoSnake(Level *lvl, int sx, int sy, Direction dir) : Snake(sx, sy, dir)
{
	level = lvl;
}

AutoSnake::~AutoSnake(void)
{
	//--
}

void AutoSnake::moveForward() {	
	calcDirection();

	Snake::moveForward();
}


void AutoSnake::extendForward() {
	calcDirection();

	Snake::extendForward();
}

void AutoSnake::calcDirection() {
	double n = 99999;
	double e = 99999;
	double s = 99999;
	double w = 99999;

	if (getDirection() != SOUTH)
		n = getDistanceToNearestPowerUp(getHead()->getX(), getHead()->getY() - 1);
	if (getDirection() != WEST)
		e = getDistanceToNearestPowerUp(getHead()->getX() + 1, getHead()->getY());
	if (getDirection() != NORTH)
		s = getDistanceToNearestPowerUp(getHead()->getX(), getHead()->getY() + 1);
	if (getDirection() != EAST)
		w = getDistanceToNearestPowerUp(getHead()->getX() - 1, getHead()->getY());

	double min = min(min(n, e), min(s, w));

	if (n == min) {
		setDirection(NORTH);
	} else if (e == min) {
		setDirection(EAST);
	} else if (s == min) {
		setDirection(SOUTH);
	} else if (w == min) {
		setDirection(WEST);
	}
}

double AutoSnake::getDistanceToNearestPowerUp(int px, int py) { // TODO Proper PathFinding | Walk over Edge
	double minDist = 999999;

	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			if (level->isPositionPowerUp(x, y)) {
				int dx = px - x;
				int dy = py - y;

				double dist = sqrt(dx*dx + dy*dy);

				if (dist < minDist) {
					minDist = dist;
				}
			}
		}
	}

	return minDist;
}