#include "WindowsConsole.h"


WindowsConsole::WindowsConsole(void) : DBConsole()
{
	srand((unsigned int) time(NULL));
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
}


WindowsConsole::~WindowsConsole(void)
{
}

void WindowsConsole::writeToConsole(int c, int x, int y) {
	if (x == BUFFER_W-1 && y == BUFFER_H-1) return; // Prevent scrolling

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
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		return KC_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		return KC_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		return KC_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE)) {
		return KC_SPACE;
	}
	if (GetAsyncKeyState(VK_ESCAPE)) {
		return KC_ESCAPE;
	}
	if (GetAsyncKeyState(VK_BACK)) {
		return KC_BACKSPACE;
	}
	if (GetAsyncKeyState(VK_RETURN)) {
		return KC_ENTER;
	}
	
	for (char cc = 'A'; cc <= 'Z'; cc++) {
		if (GetAsyncKeyState(cc)) {
			return cc; // Windows Keycodes == KC Keycodes
		}
	}

	for (char cc = VK_F1; cc <= VK_F2; cc++) {
		if (GetAsyncKeyState(cc)) {
			return cc; // Windows Keycodes == KC Keycodes
		}
	}

	return 0;
}

long WindowsConsole::getSystemCurrTimeMillis() {
	auto time = std::chrono::system_clock::now();

	auto since_epoch = time.time_since_epoch(); 

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

	return (long) millis.count(); 
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

void WindowsConsole::startLoop(ActionListener *looplistener, KeyEventListener *keyListener) {
	while(true){
		looplistener->actionPerformed(0, -1);

		int keycode = getCurrentKeyState();
		if (keycode != 0) {
			keyListener->keyEventPerformed(keycode);
		}
	}
}

bool* WindowsConsole::getBoolImageResource(int id) {
	HMODULE hModule = GetModuleHandle(NULL);
	HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(id), RT_RCDATA);
	HGLOBAL hMemory = LoadResource(hModule, hResource);
	DWORD dwSize = SizeofResource(hModule, hResource);
	LPVOID lpAddress = LockResource(hMemory);

	unsigned char *bytes = new unsigned char[dwSize];
	memcpy(bytes, lpAddress, dwSize);

	unsigned char header[54];
	memcpy(header, bytes, 54);

	int width      = *(int*)&(header[0x12]);
	int height     = *(int*)&(header[0x16]);

	unsigned int imageSize = width*height*3;
	unsigned char * data;
	const unsigned char *datastart = bytes + 54;
	data = new byte[width*height*3];
	memcpy(data, datastart, imageSize);

	bool* result = (bool*)malloc(width*height);

	for (int i = 0; i < width*height; i++)
	{
		result[i] = (data[i*3] == 0);
	}

	if ( header[0]!='B' || header[1]!='M' ){ printf("Not a correct BMP file\n"); return NULL;}
	if ( *(int*)&(header[0x1E])!=0 ) {printf("Not a correct BMP file\n"); return NULL;}
	if ( *(int*)&(header[0x1C])!=24 ) {printf("Not a correct BMP file\n"); return NULL;}

	return result;
}

void WindowsConsole::hideConsole() {
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
}