#pragma once

enum DisplayMethod {WINDOWS_CONSOLE, OGL_CONSOLE};

const DisplayMethod DISPLAYMETHOD = WINDOWS_CONSOLE;

const int INITIAL_SPEED_SNAKE = 30;
const int INITIAL_SNAKE_LENGTH = 45;

//#########################################

const bool GAMERULE_InfiniteField = true;
const bool GAMERULE_DieOnSelfContact = true;
const bool GAMERULE_BiteOnSelfContact = false;
