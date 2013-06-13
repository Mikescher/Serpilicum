#include "DBConsole.h"
#include <iostream>

DBConsole::DBConsole(void) : AbstractConsole()
{
	showFPS = true;

	lastRenderTime = 0;
	fpsCount = 0;
	fpsSum = 0;
	fps = 1;
}


DBConsole::~DBConsole(void) {
}

void DBConsole::init() {
	//Init KeyStates
	for(int p = 0; p < (sizeof(currKeyStates)/sizeof(bool)); p++) {
		currKeyStates[p] = false;
	}

	// Init Arrays
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			buffer[x][y] = ' ';
			display[x][y] = ' ';
		}
	}

	// Hide Cursor
	showConsoleCursor(false);

	// Set Size
	setDimensions(BUFFER_W, BUFFER_H);
}

void DBConsole::write(char c, int x, int y) {
	if (x >= 0 && y >= 0 && x < BUFFER_W && y < BUFFER_H) {
		buffer[x][y] = c;
	}
}


void DBConsole::write(std::string s, int x, int y) {
	for(unsigned i = 0; i < s.length(); i++) {
		write(s.at(i), x, y);

		x++;
		if (x > BUFFER_W) {
			x = 0;
			y++;
		}
	}
}

void DBConsole::swap() {
	//## FPS #####

	fpsSum += getCurrentTimeMillis() - lastRenderTime;
	lastRenderTime = getCurrentTimeMillis();
	fpsCount++;
	if (fpsSum > 1000) {
		fps = 1 / (fpsSum / (fpsCount * 1000.0));
		fpsSum = fpsCount = 0;
	}

	//## SWAPPING #####
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			if (buffer[x][y] != display[x][y]) {
				writeToConsole(buffer[x][y], x, y);
				display[x][y] = buffer[x][y];
			}
		}
	}
}

void DBConsole::redraw() {
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			display[x][y] = 255;
		}
	}
}

void DBConsole::clearBuffer() {
	// Clear Buffer
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			buffer[x][y] = ' ';
		}
	}

	//SHOW FPS
	write("FPS: " + std::to_string((int)getFPS()), 0, 0);
}

unsigned char DBConsole::getCurrentKeyState() {
	unsigned char ks = getKeyState();
	bool curr = currKeyStates[ks];

	unsigned char result;
	if (ks == 0 || curr) {
		result = 0;
	} else {
		result = ks;
	}

	//RESET
	for(int p = 0; p < (sizeof(currKeyStates)/sizeof(bool)); p++) {
		currKeyStates[p] = false;
	}
	if (ks != 0) {
		currKeyStates[ks] = true;
	}

	return result;
}

long DBConsole::getCurrentTimeMillis() {
	return getSystemCurrTimeMillis();
}

double DBConsole::getFPS() {
	return fps;
}