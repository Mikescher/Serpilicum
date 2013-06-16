#include "Snake.h"
#include "Level.h"

Snake::Snake(Level* lvl, int sx, int sy, Direction dir)
{
	lastSearchFailed = false;
	doNotRecalc = false;
	level = lvl;
	direction = dir;

	head = new SnakeElement(sx, sy);
	
	if (GAMERULE_InfiniteField) {
		algo = new PathFindingAlgorithm(BUFFER_W * 3, BUFFER_H * 3);
	} else {
		algo = new PathFindingAlgorithm(BUFFER_W, BUFFER_H);
	}
}


Snake::~Snake(void)
{
	delete head;
}

int Snake::getLength() {
	int l = 0;

	SnakeElement * el = head;

	while(el != 0) {
		el = el->getNextElement();
		l++;
	}

	return l;
}

SnakeElement * Snake::getHead() {
	return head;
}

void Snake::moveForward() {
	int cx = head->getX();
	int cy = head->getY();

	switch(direction) {
	case NORTH:
		cy--;
		break;
	case EAST:
		cx++;
		break;
	case SOUTH:
		cy++;
		break;
	case WEST:
		cx--;
		break;
	}

	head->moveRecursively(cx, cy);
}

void Snake::extendForward(int c) {
	for (int i = 0; i < c; i++) {
		extendForward();
	}
}

void Snake::extendForward() {
	int cx = head->getX();
	int cy = head->getY();

	switch(direction) {
	case NORTH:
		cy--;
		break;
	case EAST:
		cx++;
		break;
	case SOUTH:
		cy++;
		break;
	case WEST:
		cx--;
		break;
	}

	head->extendRecursively(cx, cy);
}

Direction Snake::getDirection() {
	return direction;
}

void Snake::setDirection(Direction dir) {
	//Test for direct collision

	int cx = head->getX();
	int cy = head->getY();
	switch(dir) {
	case NORTH:
		cy--;
		break;
	case EAST:
		cx++;
		break;
	case SOUTH:
		cy++;
		break;
	case WEST:
		cx--;
		break;
	}
	if (getHead()->hasNextElement() && getHead()->getNextElement()->getX() == cx && getHead()->getNextElement()->getY() == cy) {
		return;
	}

	direction = dir;
}

void Snake::onBeforeMove(Level* lvl, AbstractConsole* pConsole) {
	//--
}

void Snake::onAfterMove(Level* lvl, AbstractConsole* pConsole) {
	//--
}

Direction Snake::calcDirection() {
	int tx;
	int ty;

	if (lastSearchFailed) {
		getRandomPowerUp(tx, ty);
	} else {
		getNearestPowerUp(tx, ty);
	}

	if (ty == INT_MIN || tx == INT_MIN) {
		lastSearchFailed = false;
		doNotRecalc = false;
		return getDirection();
	}

	int head_x = getHead()->getX();
	int head_y = getHead()->getY();

	int prevhead_x;
	int prevhead_y;

	if (getHead()->hasNextElement()) {
		prevhead_x = getHead()->getNextElement()->getX();
		prevhead_y = getHead()->getNextElement()->getY();
	} else {
		prevhead_x = head_x;
		prevhead_y = head_y;
	}

	if (GAMERULE_InfiniteField) {
		head_x += BUFFER_W;
		head_y += BUFFER_H;
		prevhead_x += BUFFER_W;
		prevhead_y += BUFFER_H;
		tx += BUFFER_W;
		ty += BUFFER_H;
	}

	if (algo->hasToRecalc(tx, ty, doNotRecalc)) {
		for (int x = 0; x < algo->getWidth(); x++)
		{
			for (int y = 0; y < algo->getHeight(); y++)
			{
				algo->map[x][y] = 0;
			}
		}

		SnakeElement * snakeelement = getHead();

		while(snakeelement != 0) {
			algo->map[snakeelement->getX()][snakeelement->getY()] = (GAMERULE_DieOnSelfContact || GAMERULE_BiteOnSelfContact) ? 1 : 0;

			snakeelement = snakeelement->getNextElement();
		}


		if (GAMERULE_InfiniteField) {
			for (int x = 0; x < BUFFER_W; x++)
			{
				for (int y = 0; y < BUFFER_H; y++)
				{
					algo->map[x + BUFFER_W * 0][y + BUFFER_H * 1] = algo->map[x][y];
					algo->map[x + BUFFER_W * 0][y + BUFFER_H * 2] = algo->map[x][y];
					algo->map[x + BUFFER_W * 1][y + BUFFER_H * 0] = algo->map[x][y];
					algo->map[x + BUFFER_W * 1][y + BUFFER_H * 1] = algo->map[x][y];
					algo->map[x + BUFFER_W * 1][y + BUFFER_H * 2] = algo->map[x][y];
					algo->map[x + BUFFER_W * 2][y + BUFFER_H * 0] = algo->map[x][y];
					algo->map[x + BUFFER_W * 2][y + BUFFER_H * 1] = algo->map[x][y];
					algo->map[x + BUFFER_W * 2][y + BUFFER_H * 2] = algo->map[x][y];
				}
			}
		}
		
		algo->map[prevhead_x][prevhead_y] = 1; // Do not turn 180°
	}

	//for(int mmy = 0; mmy < algo->getHeight(); mmy++) {
	//	for(int mmx = 0; mmx < algo->getWidth(); mmx++) {
	//		if (mmx == tx && mmy == ty) {
	//			std::cout << "X";
	//		} else {
	//			std::cout << algo->map[mmx][mmy];
	//		}
	//		
	//	}
	//	std::cout << std::endl;
	//}
	//getchar();

	bool willrecalc = algo->hasToRecalc(tx, ty, true);

	int result = algo->getNextDirection(head_x, head_y, tx, ty, doNotRecalc);

	if (result == -1) {
		lastSearchFailed = ! doNotRecalc;
		doNotRecalc = false;

		if (isDirectionFree(getDirection())) {
			return getDirection();
		} else if (isDirectionFree(NORTH)) {
			return NORTH;
		} else if (isDirectionFree(EAST)) {
			return EAST;
		} else if (isDirectionFree(SOUTH)) {
			return SOUTH;
		} else if (isDirectionFree(WEST)) {
			return WEST;
		} else {
			return getDirection();
		}
	} else {
		doNotRecalc = (lastSearchFailed || doNotRecalc) && ! (willrecalc && doNotRecalc);
		lastSearchFailed = false;

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
			std::cout << "Undefinied Algorithm return value" << std::endl;
			return getDirection();
		}
	}
}

int Snake::getFieldIdent(int px, int py) {
	if (level->isPositionPowerUp(px, py)) {
		return 0;
	} else if (level->isPositionSnake(px, py)) {
		return (GAMERULE_DieOnSelfContact || GAMERULE_BiteOnSelfContact) ? 1 : 0;
	} else {
		return 0;
	}
}

void Snake::getNearestPowerUp(int& px, int& py) {
	double minDis = INT_MAX;

	PowerUp * pelem = level->getPowerUpList()->getFirst();

	int min_ax = 1;
	int min_ay = 1;
	int max_ax = 2;
	int max_ay = 2;

	if (GAMERULE_InfiniteField) {
		min_ax = 0;
		min_ay = 0;
		max_ax = 3;
		max_ay = 3;
	}

	while(pelem != 0) {
		int normx = pelem->getX();
		int normy = pelem->getY();

		for (int ax= min_ax; ax < max_ax; ax++)
		{
			for (int ay= min_ay; ay < max_ay; ay++)
			{
				int testx = normx + BUFFER_W * ax;
				int testy = normy + BUFFER_H * ay;

				int dx = testx - (getHead()->getX() + BUFFER_W);
				int dy = testy - (getHead()->getY() + BUFFER_H);

				double d = std::sqrt(dx*dx + dy*dy);
				if (d < minDis) {
					minDis = d;
					px = testx - BUFFER_W;
					py = testy - BUFFER_H;
				}
			}
		}

		pelem = pelem->getNextElement();
	}

	if (minDis == INT_MAX) {
		px = INT_MIN;
		py = INT_MIN;

		return;
	}
}

void Snake::getRandomPowerUp(int& px, int& py) {
	PowerUp * pelem = level->getPowerUpList()->getFirst();

	std::vector<int> posx;
	std::vector<int> posy;

	while(pelem != 0) {
		int normx = pelem->getX();
		int normy = pelem->getY();
		if (GAMERULE_InfiniteField) {
			for (int ax= -1; ax < 2; ax++)
			{
				for (int ay= -1; ay < 2; ay++)
				{
					posx.push_back(normx + BUFFER_W * ax);
					posy.push_back(normy + BUFFER_H * ay);
				}
			}
		} else {
			posx.push_back(normx);
			posy.push_back(normy);
		}

		pelem = pelem->getNextElement();
	}

	if (posx.size() <= 0) {
		px = INT_MIN;
		py = INT_MIN;
		return;
	}

	int rand = std::rand() % posx.size();
	px = posx.at(rand);
	py = posy.at(rand);
	// std::cout << "Random val:" << px << "," << py << std::endl;
}

bool Snake::isDirectionFree(Direction d) {
	int cx = getHead()->getX();
	int cy = getHead()->getY();

	switch(d) {
	case NORTH:
		cy--;
		break;
	case EAST:
		cx++;
		break;
	case SOUTH:
		cy++;
		break;
	case WEST:
		cx--;
		break;
	}

	if (! GAMERULE_InfiniteField) {
		if (cx < 0 || cy < 0 || cx >= BUFFER_W ||cy >= BUFFER_H) return false;
	}

	return (!GAMERULE_BiteOnSelfContact && !GAMERULE_DieOnSelfContact && std::abs(getDirection() - d) != 2) || !level->isPositionSnake(cx, cy);
}

void Snake::autoMoveForward() {
	setDirection(calcDirection());

	moveForward();
}

void Snake::autoExtendForward() {
	setDirection(calcDirection());

	extendForward();
}