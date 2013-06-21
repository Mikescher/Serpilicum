#include "ChooseGameModeMenu.h"
#include "Keycodes.h"
#include "Gamerules.h"

ChooseGameModeMenu::ChooseGameModeMenu(int pid, AbstractConsole* pConsole, ActionListener * quitListener) : DisplayImageTextMenu(pid, pConsole, quitListener, 106, 0)
{
	transistion = 0;
	transistionDirection = 0;
	currmode = 2;
	console = pConsole;
	lastRun = pConsole->getCurrentTimeMillis();
	
	update();
}

void ChooseGameModeMenu::onKeyDown(int keycode) {
	DisplayImageTextMenu::onKeyDown(keycode);

	if (keycode == KC_LEFT) {
		/*currmode = (currmode + GAMEMODECOUNT - 1) % GAMEMODECOUNT;*/
		transistionDirection = 1;
		update();
	} else if (keycode == KC_RIGHT) {
		//currmode = (currmode + 1) % GAMEMODECOUNT;
		transistionDirection = -1;
		update();
	}
}

void ChooseGameModeMenu::update() {
	int currID = 104 + currmode;

	int nextID = 104 + (currmode - 1 + 6) % 6;
	int prevID = 104 + (currmode + 1 + 6) % 6;

	resourceArray = console->getBoolImageResource(currID);
	traNext = console->getBoolImageResource(nextID);
	traPrev = console->getBoolImageResource(prevID);
}

void ChooseGameModeMenu::throwAction() {
	switch(currmode) {
	case 0: // EASY
		GAMERULES::i().INITIAL_SPEED_SNAKE = 100;
		GAMERULES::i().INITIAL_SNAKE_LENGTH = 5;
		GAMERULES::i().INITIAL_LIFE_SHARDS = 5;
		GAMERULES::i().MAXIMAL_HP_PU_COUNT = 64;
		GAMERULES::i().InfiniteField = true;
		GAMERULES::i().DieOnSelfContact = false;
		GAMERULES::i().DecreaseShardsOnSelfContact = true;
		GAMERULES::i().BiteOnSelfContact = true;
		GAMERULES::i().expandOnHPCollection = true;
		GAMERULES::i().AddPointsOnHPCollect = true;
		GAMERULES::i().FactorialPointCalculation = true;
		GAMERULES::i().SpawnAspirinObstaclesOnHPCollect = false;
		GAMERULES::i().AlwaysUseAutoSnake = false;
		GAMERULES::i().EnableAutoPowerUp = true;
		GAMERULES::i().EnableZoomPowerUp = true;
		GAMERULES::i().InstantDeath = false;
		break;
	case 1: // RETRO
		GAMERULES::i().INITIAL_SPEED_SNAKE = 200;
		GAMERULES::i().INITIAL_SNAKE_LENGTH = 5;
		GAMERULES::i().INITIAL_LIFE_SHARDS = 1;
		GAMERULES::i().MAXIMAL_HP_PU_COUNT = 16;
		GAMERULES::i().InfiniteField = false;
		GAMERULES::i().DieOnSelfContact = true;
		GAMERULES::i().DecreaseShardsOnSelfContact = false;
		GAMERULES::i().BiteOnSelfContact = false;
		GAMERULES::i().expandOnHPCollection = true;
		GAMERULES::i().AddPointsOnHPCollect = true;
		GAMERULES::i().FactorialPointCalculation = false;
		GAMERULES::i().SpawnAspirinObstaclesOnHPCollect = false;
		GAMERULES::i().AlwaysUseAutoSnake = false;
		GAMERULES::i().EnableAutoPowerUp = false;
		GAMERULES::i().EnableZoomPowerUp = false;
		GAMERULES::i().InstantDeath = false;
		break;
	case 2: //NORMAL
		GAMERULES::i().INITIAL_SPEED_SNAKE = 30;
		GAMERULES::i().INITIAL_SNAKE_LENGTH = 5;
		GAMERULES::i().INITIAL_LIFE_SHARDS = 3;
		GAMERULES::i().MAXIMAL_HP_PU_COUNT = 32;
		GAMERULES::i().InfiniteField = true;
		GAMERULES::i().DieOnSelfContact = false;
		GAMERULES::i().DecreaseShardsOnSelfContact = true;
		GAMERULES::i().BiteOnSelfContact = true;
		GAMERULES::i().expandOnHPCollection = true;
		GAMERULES::i().AddPointsOnHPCollect = true;
		GAMERULES::i().FactorialPointCalculation = true;
		GAMERULES::i().SpawnAspirinObstaclesOnHPCollect = false;
		GAMERULES::i().AlwaysUseAutoSnake = false;
		GAMERULES::i().EnableAutoPowerUp = true;
		GAMERULES::i().EnableZoomPowerUp = true;
		GAMERULES::i().InstantDeath = false;
		break;
	case 3: // HARDCORE
		GAMERULES::i().INITIAL_SPEED_SNAKE = 20;
		GAMERULES::i().INITIAL_SNAKE_LENGTH = 2;
		GAMERULES::i().INITIAL_LIFE_SHARDS = 1;
		GAMERULES::i().MAXIMAL_HP_PU_COUNT = 16;
		GAMERULES::i().InfiniteField = false;
		GAMERULES::i().DieOnSelfContact = true;
		GAMERULES::i().DecreaseShardsOnSelfContact = false;
		GAMERULES::i().BiteOnSelfContact = false;
		GAMERULES::i().expandOnHPCollection = true;
		GAMERULES::i().AddPointsOnHPCollect = true;
		GAMERULES::i().FactorialPointCalculation = false;
		GAMERULES::i().SpawnAspirinObstaclesOnHPCollect = false;
		GAMERULES::i().AlwaysUseAutoSnake = false;
		GAMERULES::i().EnableAutoPowerUp = false;
		GAMERULES::i().EnableZoomPowerUp = false;
		GAMERULES::i().InstantDeath = false;
		break;
	case 4: // ASPIRIN
		GAMERULES::i().INITIAL_SPEED_SNAKE = 60;
		GAMERULES::i().INITIAL_SNAKE_LENGTH = 3;
		GAMERULES::i().INITIAL_LIFE_SHARDS = 1;
		GAMERULES::i().MAXIMAL_HP_PU_COUNT = 3;
		GAMERULES::i().InfiniteField = false;
		GAMERULES::i().DieOnSelfContact = true;
		GAMERULES::i().DecreaseShardsOnSelfContact = false;
		GAMERULES::i().BiteOnSelfContact = false;
		GAMERULES::i().expandOnHPCollection = false;
		GAMERULES::i().AddPointsOnHPCollect = true;
		GAMERULES::i().FactorialPointCalculation = false;
		GAMERULES::i().SpawnAspirinObstaclesOnHPCollect = true;
		GAMERULES::i().AlwaysUseAutoSnake = false;
		GAMERULES::i().EnableAutoPowerUp = false;
		GAMERULES::i().EnableZoomPowerUp = false;
		GAMERULES::i().InstantDeath = false;
		break;
	case 5: // AUTO
		GAMERULES::i().INITIAL_SPEED_SNAKE = 30;
		GAMERULES::i().INITIAL_SNAKE_LENGTH = 5;
		GAMERULES::i().INITIAL_LIFE_SHARDS = 1;
		GAMERULES::i().MAXIMAL_HP_PU_COUNT = 32;
		GAMERULES::i().InfiniteField = true;
		GAMERULES::i().DieOnSelfContact = true;
		GAMERULES::i().DecreaseShardsOnSelfContact = false;
		GAMERULES::i().BiteOnSelfContact = false;
		GAMERULES::i().expandOnHPCollection = true;
		GAMERULES::i().AddPointsOnHPCollect = true;
		GAMERULES::i().FactorialPointCalculation = true;
		GAMERULES::i().SpawnAspirinObstaclesOnHPCollect = false;
		GAMERULES::i().AlwaysUseAutoSnake = true;
		GAMERULES::i().EnableAutoPowerUp = false;
		GAMERULES::i().EnableZoomPowerUp = true;
		GAMERULES::i().InstantDeath = false;
		break;
	}



	DisplayImageTextMenu::throwAction();
}

void ChooseGameModeMenu::run(AbstractConsole* pConsole) {
	long delta = std::min(500l, pConsole->getCurrentTimeMillis() - lastRun);

	double transBefore = transistion;
	transistion += transistionDirection * delta/600.0;

	if (transistion > 1) {
		transistionDirection = 0;
		transistion = 0;
		currmode = (currmode + GAMEMODECOUNT - 1) % GAMEMODECOUNT;

		update();
	} else if (transistion < -1) {
		transistionDirection = 0;
		transistion = 0;
		currmode = (currmode + GAMEMODECOUNT + 1) % GAMEMODECOUNT;

		update();
	} else if ((transBefore < 0 && 0 < transistion) || (transBefore > 0 && 0 > transistion)) {
		transistionDirection = 0;
		transistion = 0;

		update();
	}

	lastRun = pConsole->getCurrentTimeMillis();
}

void ChooseGameModeMenu::render(AbstractConsole* pConsole) {
	bool inTrans = transistionDirection != 0;

	int offset1 = (int)(BUFFER_W * transistion);
	int offsetN = offset1 + -1 * BUFFER_W;
	int offsetP = offset1 +  1 * BUFFER_W;

	for (int xx = (inTrans ? 5 : 0); xx < (inTrans ? BUFFER_W - 5 : BUFFER_W); xx++)
	{
		for (int yy = 0; yy < BUFFER_H; yy++)
		{
			double px = xx;
			double py = (BUFFER_H - yy - 1);

			pConsole->write((resourceArray[yy * BUFFER_W + xx]) ? ('#') : (' '), offset1 + (int)std::floor(px + 0.5), (int)std::floor(py + 0.5));
			pConsole->write((traNext[yy * BUFFER_W + xx]) ? ('#') : (' '), offsetN + (int)std::floor(px + 0.5), (int)std::floor(py + 0.5));
			pConsole->write((traPrev[yy * BUFFER_W + xx]) ? ('#') : (' '), offsetP + (int)std::floor(px + 0.5), (int)std::floor(py + 0.5));
		}
	}
}