#include "OGLConsole.h"


OGLConsole::OGLConsole(void) : DBConsole()
{
	//########## WINDOWS #######################

	srand((int) time(NULL));

	//##########  OPENGL  ######################

	int argc = 0;
	char *pc = 0;

	glutInit(&argc, &pc);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(8 * BUFFER_W, 12 * BUFFER_H);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 8 * BUFFER_W) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 12 * BUFFER_H) / 2);
	glutCreateWindow("Fight da Snake");

	glewInit();

	glOrtho(0, 8 * BUFFER_W, 12 * BUFFER_H, 0, 0, -100);
	glEnable(GL_TEXTURE_2D);
	loadTextures();
}


OGLConsole::~OGLConsole(void)
{
}

void OGLConsole::writeToConsole(int c, int x, int y)
{
	// Do nothing
}

void OGLConsole::showConsoleCursor(bool bShow)
{
	// Do nothing
}

unsigned char OGLConsole::getKeyState()
{
	// Do nothing
	return 0;
}

long OGLConsole::getSystemCurrTimeMillis()
{
	auto time = std::chrono::system_clock::now();

	auto since_epoch = time.time_since_epoch(); 

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

	return (long) millis.count(); 
}

void OGLConsole::setDimensions(short w, short h)
{
	// DO NOTHING ???
}

void OGLConsole::clearBuffer() {
	DBConsole::clearBuffer();
}

void OGLConsole::swap() {
	DBConsole::swap();

	glClearColor(0, 0, 0, 1);
	glClear (GL_COLOR_BUFFER_BIT);

	//<RENDER OGL>
	renderOGL();
	//</RENDER OGL>

	glutSwapBuffers();
}

void OGLConsole::renderOGL() {
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			if (display[x][y] != ' ') {
				int dchar = display[x][y] % 255;

				GLdouble tx = dchar % 80;
				GLdouble ty = dchar / 80;

				GLdouble x1 = (x+0) * 8;
				GLdouble x2 = (x+1) * 8;

				GLdouble y1 = (y+0) * 12;
				GLdouble y2 = (y+1) * 12;

				GLdouble tx1 = (tx+0) / 128.0;
				GLdouble tx2 = (tx+1) / 128.0;

				GLdouble ty1 = 64 - (ty+0) / (16/3.0);
				GLdouble ty2 = 64 - (ty+1) / (16/3.0);

				glColor3f(1, 1, 1);
				glBindTexture(GL_TEXTURE_2D, chartextures);

				glBegin(GL_QUADS);
					glTexCoord2d(tx1, ty1); glVertex3d(x1, y1, 0);
					glTexCoord2d(tx1, ty2); glVertex3d(x1, y2, 0);
					glTexCoord2d(tx2, ty2); glVertex3d(x2, y2, 0);
					glTexCoord2d(tx2, ty1); glVertex3d(x2, y1, 0);
				glEnd();
			}
		}
	}
}

unsigned char* OGLConsole::loadBMPRaw(const unsigned char * rawdata, unsigned int outWidth, unsigned int outHeight, bool flipY){
	unsigned char header[54];

	unsigned int imageSize = outWidth*outHeight*3;
	unsigned char * data;
	const unsigned char *datastart = rawdata + 54;
	data = new byte[outWidth*outHeight*3];
	memcpy(header, rawdata, 54);
	memcpy(data, datastart, imageSize);

	if ( header[0]!='B' || header[1]!='M' ){ printf("Not a correct BMP file\n"); return NULL;}
	if ( *(int*)&(header[0x1E])!=0 ) {printf("Not a correct BMP file\n"); return NULL;}
	if ( *(int*)&(header[0x1C])!=24 ) {printf("Not a correct BMP file\n"); return NULL;}

	return data;
}

GLuint OGLConsole::LoadTextureRAW(int id, int w, int h) {
	HMODULE hModule = GetModuleHandle(NULL);
	HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(id), RT_RCDATA);
	HGLOBAL hMemory = LoadResource(hModule, hResource);
	DWORD dwSize = SizeofResource(hModule, hResource);
	LPVOID lpAddress = LockResource(hMemory);

	unsigned char *bytes = new unsigned char[dwSize];
	memcpy(bytes, lpAddress, dwSize);


	GLuint texture;
	glGenTextures( 1, &texture );

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, loadBMPRaw(bytes, w, h, false));
 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return texture;
}

void OGLConsole::loadTextures() {
	chartextures = LoadTextureRAW(101, 1024, 64);
}

ActionListener *ogl_global_looplistener;
KeyEventListener *ogl_global_keylistener;

void onMainLoopLoopCallback() {
	ogl_global_looplistener->actionPerformed(0);
}

void onMainLoopKeyCallback(int key, int x, int y) {
	if (key == (GLUT_KEY_UP)) {
		ogl_global_keylistener->keyEventPerformed(KC_UP);
		return;
	} else if (key == (GLUT_KEY_DOWN)) {
		ogl_global_keylistener->keyEventPerformed(KC_DOWN);
		return;
	} else if (key == (GLUT_KEY_LEFT)) {
		ogl_global_keylistener->keyEventPerformed(KC_LEFT);
		return;
	} else if (key == (GLUT_KEY_RIGHT)) {
		ogl_global_keylistener->keyEventPerformed(KC_RIGHT);
		return;
	}
}

void onMainLoopKeyCallbackASCII(unsigned char key, int x, int y) {
	if (key == ' ') {
		ogl_global_keylistener->keyEventPerformed(KC_SPACE);
		return;
	} else if (key == 27) {
		ogl_global_keylistener->keyEventPerformed(KC_ESCAPE);
		return;
	} else if(key >= 'A' && key <= 'Z') {
		ogl_global_keylistener->keyEventPerformed(key);
	} else if(key >= 'a' && key <= 'z'){
		ogl_global_keylistener->keyEventPerformed(key - 'a' + 'A');
	}
}

void OGLConsole::startLoop(ActionListener *looplistener, KeyEventListener *keyListener) {
	ogl_global_looplistener = looplistener;
	ogl_global_keylistener = keyListener;

	glutSpecialFunc(onMainLoopKeyCallback);
	glutKeyboardFunc(onMainLoopKeyCallbackASCII);
	glutIdleFunc(onMainLoopLoopCallback);
	glutMainLoop();
}


