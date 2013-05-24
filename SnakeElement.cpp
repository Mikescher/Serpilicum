#include "SnakeElement.h"


SnakeElement::SnakeElement(int px, int py)
{
	next = 0;
	x = px;
	y = py;
}


SnakeElement::~SnakeElement(void)
{
}

bool SnakeElement::hasNextElement(){
	return next != 0;
}

SnakeElement* SnakeElement::getNextElement(){
	if(hasNextElement()){
		return next;
	}
	
}

void SnakeElement::setNextElement(SnakeElement* element){
	next = element;
}

bool hasNextElement(){
}
void setNextElement(SnakeElement* element){
}

void setX(int x){
}
void setY(int y){
}
int getX(){
}
int getY(){
}
int moveX(int x){
}
int moveY(int y){
}
void set(int x, int y){
}
void move(int x, int y){
}
