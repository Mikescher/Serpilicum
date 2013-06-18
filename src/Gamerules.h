#pragma once

enum DisplayMethod {WINDOWS_CONSOLE, OGL_CONSOLE};

const DisplayMethod DISPLAYMETHOD = OGL_CONSOLE;

const int INITIAL_SPEED_SNAKE = 30;
const int INITIAL_SNAKE_LENGTH = 5;
const int INITIAL_LIFE_SHARDS = 3;

//#########################################

const bool GAMERULE_EnableCheats = true;
const bool GAMERULE_InfiniteField = true;
const bool GAMERULE_DieOnSelfContact = false;
const bool GAMERULE_DecreaseShardsOnSelfContact = true;
const bool GAMERULE_BiteOnSelfContact = true;
