#include "AutoSnake.h"
#include "Level.h"
#include "AbstractConsole.h"

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
}

void AutoSnake::moveForward() {
	setDirection(calcDirection());

	Snake::moveForward();
}


void AutoSnake::extendForward() {
	setDirection(calcDirection());

	Snake::extendForward();
}

Direction AutoSnake::calcDirection() {
	int tx;
	int ty;
	getNearestPowerUp(tx, ty);

	if (ty == -1 || tx == -1) {
		return getDirection();
	}

	if (algo.hasToRecalc(tx, ty)) {
		for (int x = 0; x < BUFFER_W; x++)
		{
			for (int y = 0; y < BUFFER_H; y++)
			{
				algo.map[x][y] = getFieldIdent(x, y);
			}
		}
	}

	int result = algo.getNextDirection(getHead()->getX(), getHead()->getY(), tx, ty);

	if (result == -1) {
		return getDirection();
	} else {
		switch(result) {
		case 0:
			return NORTH;
		case 1:
			return EAST;
		case 2:
			return SOUTH;
		case 3:
			return WEST;
		default:
			std::cout << "Undefinied Algorith return value" << std::endl;
			return getDirection();
		}
	}
}

int AutoSnake::getDistance(Direction& direction, int depth, int px, int py) {
	if (depth <= 0) {
		return INT_MAX;
	}

	double n;
	double e;
	double s;
	double w;

	int nx = px;
	int ny = (py - 1) % BUFFER_H;

	int ex = (px + 1) % BUFFER_W;
	int ey = py;

	int sx = px;
	int sy = (py + 1) % BUFFER_H;

	int wx = (px - 1) % BUFFER_W;
	int wy = py;

	n = getFieldIdent(nx, ny);
	e = getFieldIdent(ex, ey);
	s = getFieldIdent(sx, sy);
	w = getFieldIdent(wx, wy);

	if (n == 1) {
		direction = NORTH;
		return 0;
	} else if (e == 1) {
		direction = EAST;
		return 0;
	} else if (s == 1) {
		direction = SOUTH;
		return 0;
	} else if (w == 1) {
		direction = WEST;
		return 0;
	}

	int dn = INT_MAX;
	int de = INT_MAX;
	int ds = INT_MAX;
	int dw = INT_MAX;

	Direction dir = NORTH;

	if (n == 0) {
		dn = getDistance(dir, depth - 1, nx, ny);
	}
	if (e == 0) {
		de = getDistance(dir, depth - 1, ex, ey);
	}
	if (s == 0) {
		ds = getDistance(dir, depth - 1, sx, sy);
	}
	if (w == 0) {
		dw = getDistance(dir, depth - 1, wx, wy);
	}

	int min_d = std::min(std::min(dn, de), std::min(ds, dw));

	if (dn == min_d) {
		direction = NORTH;
		return dn+1;
	} else if (de == min_d) {
		direction = EAST;
		return de+1;
	} else if (ds == min_d) {
		direction = SOUTH;
		return ds+1;
	} else if (dw == min_d) {
		direction = WEST;
		return dw+1;
	}

	return INT_MAX;
}

int AutoSnake::getFieldIdent(int px, int py) { // TODO Proper PathFinding | Walk over Edge
	if (level->isPositionPowerUp(px, py)) {
		return 0;
	} else if (level->isPositionSnake(px, py)) {
		return 1;
	} else {
		return 0;
	}
}

void AutoSnake::getNearestPowerUp(int& px, int& py) {
	double minDis = INT_MAX;

	PowerUp * pelem = level->getPowerUpList()->getFirst();

	while(pelem != 0) {
		int dx = pelem->getX() - getHead()->getX();
		int dy = pelem->getY() - getHead()->getY();

		double d = std::sqrt(dx*dx + dy*dy);
		if (d < minDis) {
			minDis = d;
			px = pelem->getX();
			py = pelem->getY();
		}

		pelem = pelem->getNextElement();
	}

	if (minDis == INT_MAX) {
		px = -1;
		py = -1;
	}
}