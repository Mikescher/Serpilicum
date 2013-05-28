#include "Snake.h"


Snake::Snake(void)
{
	direction = NORTH;
	head = new SnakeElement(0, 0);
}

Snake::Snake(int sx, int sy, Direction dir)
{
	direction = dir;
	head = new SnakeElement(sx, sy);
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