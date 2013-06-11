#include "LevelEffect.h"


LevelEffect::LevelEffect(int px, int py) {
	start();

	x = px;
	y = py;
}

LevelEffect::~LevelEffect(void){
	// Die Hard XXX
}

int LevelEffect::getX(){
	return x;
}

int LevelEffect::getY(){
	return y;
}


bool LevelEffect::isAlive(){
	return is_alive;
}

void LevelEffect::stop() {
	is_alive = false;
}

void LevelEffect::start() {
	is_alive = true;
}