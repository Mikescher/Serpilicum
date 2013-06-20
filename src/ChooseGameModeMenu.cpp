#include "ChooseGameModeMenu.h"
#include "Keycodes.h"
#include "Gamerules.h"

ChooseGameModeMenu::ChooseGameModeMenu(int pid, AbstractConsole* pConsole, ActionListener * quitListener) : DisplayImageTextMenu(pid, pConsole, quitListener, 106, 0)
{
	currmode = 2;
	console = pConsole;
}

void ChooseGameModeMenu::onKeyDown(int keycode) {
	DisplayImageTextMenu::onKeyDown(keycode);

	if (keycode == KC_LEFT) {
		currmode = (currmode + (GAMEMODECOUNT-1)) % GAMEMODECOUNT;
		update();
	} else if (keycode == KC_RIGHT) {
		currmode = (currmode + 1) % GAMEMODECOUNT;
		update();
	}
}

void ChooseGameModeMenu::update() {
	switch(currmode) {
	case 0: 
		resourceArray = console->getBoolImageResource(104); 
		break;
	case 1: 
		resourceArray = console->getBoolImageResource(105); 
		break;
	case 2: 
		resourceArray = console->getBoolImageResource(106); 
		break;
	case 3: 
		resourceArray = console->getBoolImageResource(107); 
		break;
	case 4: 
		resourceArray = console->getBoolImageResource(108); 
		break;
	case 5: 
		resourceArray = console->getBoolImageResource(109); 
		break;
	}
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