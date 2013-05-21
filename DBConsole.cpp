#include "DBConsole.h"
#include <Windows.h>
#include <iostream>


DBConsole::DBConsole(void) {
	init();
}


DBConsole::~DBConsole(void) {
}

void DBConsole::init() {
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			buffer[x][y] = ' ';
			display[x][y] = ' ';
		}
	}
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

void DBConsole::writeToConsole(char c, int x, int y) {
	HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

	if ( INVALID_HANDLE_VALUE != hConsole )
	{
		COORD pos = {x, y};
		SetConsoleCursorPosition ( hConsole, pos );
		printf ("%c", c);
	}
}

void DBConsole::swap() {
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