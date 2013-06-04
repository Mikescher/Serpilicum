#include "DBConsole.h"
#include <Windows.h>
#include <iostream>
#include "Keycodes.h"
#include <chrono>

DBConsole::DBConsole(void) {
    init();
}


DBConsole::~DBConsole(void) {
}

void DBConsole::init() {
    // Init Arrays
    for (int x = 0; x < BUFFER_W; x++) {
        for (int y = 0; y < BUFFER_H; y++) {
            buffer[x][y] = ' ';
            display[x][y] = ' ';
        }
    }

    // Hide Cursor
    showConsoleCursor(false);
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

void DBConsole::showConsoleCursor(bool bShow)
{
    static HANDLE hOut;
    static BOOL firstTime = TRUE;
    CONSOLE_CURSOR_INFO cursorInfo;
 
    if( firstTime ) {
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        firstTime = FALSE;
 
    }
 
    cursorInfo.dwSize = 10;
    cursorInfo.bVisible = bShow;
 
    SetConsoleCursorInfo( hOut, &cursorInfo );
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

void DBConsole::clearBuffer() {
    for (int x = 0; x < BUFFER_W; x++) {
        for (int y = 0; y < BUFFER_H; y++) {
            buffer[x][y] = ' ';
        }
    }
}

int DBConsole::getKeyState() {
    if (GetAsyncKeyState(VK_UP)) {
		return KC_UP;
    } else if (GetAsyncKeyState(VK_DOWN)) {
		return KC_DOWN;
    } else if (GetAsyncKeyState(VK_LEFT)) {
		return KC_LEFT;
    } else if (GetAsyncKeyState(VK_RIGHT)) {
		return KC_RIGHT;
	} else if (GetAsyncKeyState(VK_SPACE)) {
		return KC_SPACE;
    } else if (GetAsyncKeyState(VK_ESCAPE)) {
		return KC_ESCAPE;
    }
	return 0;
}


int DBConsole::getFullKeyEvent() {
	int kc = getKeyState();

	if (kc != 0) while (getKeyState() == kc); // Wait

	return kc;
}

int DBConsole::getBlockingFullKeyEvent() {
	int kc = 0;

	while ((kc = getFullKeyEvent()) == 0);

	return kc;
}

long DBConsole::getCurrentTimeMillis() {
	auto time = std::chrono::system_clock::now();

	auto since_epoch = time.time_since_epoch(); 

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

	return millis.count(); 
}