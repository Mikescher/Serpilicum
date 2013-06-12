#include "WindowsConsole.h"


WindowsConsole::WindowsConsole(void) : DBConsole()
{
	srand(time(NULL));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
}


WindowsConsole::~WindowsConsole(void)
{
}

void WindowsConsole::writeToConsole(char c, int x, int y) {
	if ( INVALID_HANDLE_VALUE != hConsole )
	{
		COORD pos = {x, y};
		SetConsoleCursorPosition ( hConsole, pos );
		printf ("%c", c);
	}
}

void WindowsConsole::showConsoleCursor(bool bShow)
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

unsigned char WindowsConsole::getKeyState() {
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

long WindowsConsole::getSystemCurrTimeMillis() {
	auto time = std::chrono::system_clock::now();

	auto since_epoch = time.time_since_epoch(); 

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

	return millis.count(); 
}

void WindowsConsole::setDimensions(short w, short h) {
	HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );
	SMALL_RECT size;
	COORD b_size;

	size.Left = 0;
	size.Top = 0;
	size.Right = w - 1;
	size.Bottom = h - 1;
	b_size.X = w;
	b_size.Y = h;

	SetConsoleWindowInfo( hCon , true , & size );
	SetConsoleScreenBufferSize( hCon , b_size );
}

void WindowsConsole::startLoop(ActionListener *looplistener) {
	while(true){
		looplistener->actionPerformed(0);
	}
}