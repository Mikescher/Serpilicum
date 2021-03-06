#include "DBConsole.h"
#include <iostream>
#include "Gamerules.h"

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
	//Init Vars
	firstTimeMillis = getSystemCurrTimeMillis();

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

	//Show Console
	if (! SHOWCONSOLE) {
		hideConsole();
	}
}

void DBConsole::write(int c, int x, int y) {
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
	//## SHOW FPS #####
	write("FPS: " + std::to_string((int)getFPS()), BUFFER_W - 10, 0);

	//## FPS #####

	long delta = getCurrentTimeMillis() - lastRenderTime;

	if (FPS_LIMITER > 0) {
		while (delta < (1000.0 / (FPS_LIMITER + 3))) {
			delta = getCurrentTimeMillis() - lastRenderTime;
			doSystemSleep(0);
		}
	}

	fpsSum += delta;
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
			display[x][y] = (char)255;
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
	return getSystemCurrTimeMillis() - firstTimeMillis;
}

double DBConsole::getFPS() {
	return fps;
}

void DBConsole::zoomIn(int centerX, int centerY) {
	int newbuffer[BUFFER_W][BUFFER_H];

	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			int nbx = x;
			int nby = y;

			nbx /= 2;
			nby /= 2;

			nbx -= BUFFER_W/4;
			nby -= BUFFER_H/4;

			nbx += centerX;
			nby += centerY;

			if (GAMERULES::i().InfiniteField) {
				nbx = (nbx + BUFFER_W) % BUFFER_W;
				nby = (nby + BUFFER_H) % BUFFER_H;
			}

			if (nbx >= 0 && nby >= 0 && nbx < BUFFER_W && nby < BUFFER_H)
				newbuffer[x][y] = buffer[nbx][nby];
			else
				newbuffer[x][y] = 178;
		}
	}

	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			buffer[x][y] = newbuffer[x][y];
		}
	}
}

void DBConsole::onLevelStart() {
	// Do nothing
}

void DBConsole::onLevelStop() {
	// Do nothing
}