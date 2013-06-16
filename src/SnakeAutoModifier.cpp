#include "SnakeAutoModifier.h"
#include "Level.h"

SnakeAutoModifier::SnakeAutoModifier(Level* lvl, AbstractConsole *pConsole) : SnakeModifier()
{
	//
}

void SnakeAutoModifier::run(Level* lvl, AbstractConsole *pConsole) {
	if (lvl->getPowerUpList()->getLength() == 0) {
		running = false;
	}
}

SnakeModifierType SnakeAutoModifier::getType() {
	return SNAKEMODTYPE_AUTO;
}