#include "SnakeElement.h"


SnakeElement::SnakeElement(int px, int py)
{
	next = 0;
	x = px;
	y = py;
}


SnakeElement::~SnakeElement(void)
{
	if (hasNextElement()) {
		delete next;
	}
	next = 0;
}

bool SnakeElement::hasNextElement(){
	return next != 0;
}

SnakeElement* SnakeElement::getNextElement(){
	if(hasNextElement()){
		return next;
	} else {
		return 0;
	}
}

void SnakeElement::setNextElement(SnakeElement* pnext){
	next = pnext;
}

void SnakeElement::setX(int px){
	x = px;
}
void SnakeElement::setY(int py){
	y = py;
}

int SnakeElement::getX(){
	return x;
}

int SnakeElement::getY(){
	return y;
}

int SnakeElement::moveX(int dx){
	return x += dx;
}

int SnakeElement::moveY(int dy){
	return y += dy;
}

void SnakeElement::set(int px, int py){
	setX(px);
	setY(py);
}

void SnakeElement::move(int dx, int dy){
	moveX(dx);
	moveY(dy);
}

void SnakeElement::moveRecursively(int tox, int toy) {
	int oldx = x;
	int oldy = y;

	set(tox, toy);

	if(hasNextElement()) {
		getNextElement()->moveRecursively(oldx, oldy);
	}
}

void SnakeElement::extendRecursively(int tox, int toy) {
	int oldx = x;
	int oldy = y;

	set(tox, toy);

	if(hasNextElement()) {
		getNextElement()->extendRecursively(oldx, oldy);
	} else {
		setNextElement(new SnakeElement(oldx, oldy));
	}
}