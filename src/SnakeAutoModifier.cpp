#include "SnakeAutoModifier.h"
#include "Level.h"

SnakeAutoModifier::SnakeAutoModifier(Level* lvl, AbstractConsole *pConsole) : SnakeModifier()
{
	startTime = pConsole->getCurrentTimeMillis();
	runDelta = 0;
}

void SnakeAutoModifier::run(Level* lvl, AbstractConsole *pConsole) {
	runDelta = pConsole->getCurrentTimeMillis() - startTime;

	if (lvl->getPowerUpList()->getLength() == 0) {
		running = false;
	}
}

SnakeModifierType SnakeAutoModifier::getType() {
	return (runDelta > 250)? SNAKEMODTYPE_AUTO : SNAKEMODTYPE_PREAUTO;
}