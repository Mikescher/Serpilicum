#pragma once

enum DisplayMethod {WINDOWS_CONSOLE, OGL_CONSOLE, CRAZY_CONSOLE};

const DisplayMethod DISPLAYMETHOD = CRAZY_CONSOLE;
const bool SHOWCONSOLE = false;
const int FPS_LIMITER = 60; // 0 == UNLIMITED

//#########################################

const bool GR_EnableCheats = false;

//########################################


class GAMERULES {
public:
	int INITIAL_SPEED_SNAKE;
	int INITIAL_SNAKE_LENGTH;
	int INITIAL_LIFE_SHARDS;

	int MAXIMAL_HP_PU_COUNT;

	int choosen_gamemode;

	bool InfiniteField;
	bool DieOnSelfContact;
	bool DecreaseShardsOnSelfContact;
	bool BiteOnSelfContact;
	bool expandOnHPCollection;
	bool AddPointsOnHPCollect;
	bool FactorialPointCalculation;
	bool SpawnAspirinObstaclesOnHPCollect;
	bool AlwaysUseAutoSnake;
	bool InstantDeath;

	bool EnableAutoPowerUp;
	bool EnableZoomPowerUp;


public:
	static GAMERULES &i() {static GAMERULES i; return i;}
private:
	GAMERULES(){};
};