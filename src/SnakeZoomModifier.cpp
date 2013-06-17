#include "SnakeZoomModifier.h"


SnakeZoomModifier::SnakeZoomModifier(Level* lvl, AbstractConsole *pConsole) : SnakeModifier()
{
	startTime = pConsole->getCurrentTimeMillis();
	runDelta = 0;
}

void SnakeZoomModifier::run(Level* lvl, AbstractConsole *pConsole) {
	runDelta = pConsole->getCurrentTimeMillis() - startTime;

	if (runDelta > 15 * 1000) {
		running = false;
	}
}

SnakeModifierType SnakeZoomModifier::getType() {
	return SNAKEMODTYPE_ZOOM;
}