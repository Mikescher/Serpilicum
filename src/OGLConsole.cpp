#include "OGLConsole.h"


OGLConsole::OGLConsole(void)
{
	srand((int) time(NULL));

	int argc = 0;
	char *pc = 0;

	glutInit(&argc, &pc);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(8 * BUFFER_W, 12 * BUFFER_H);
	glutCreateWindow("GLEW Test");

	glewInit();

	glOrtho(0, 8 * BUFFER_W, 12 * BUFFER_H, 0, 0, -100);
	glEnable(GL_TEXTURE_2D);
	loadTextures();
}


OGLConsole::~OGLConsole(void)
{
}

void OGLConsole::writeToConsole(char c, int x, int y)
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

	//TODO RENDER OGL
	renderOGL();
	//TODO RENDER OGL

	glutSwapBuffers();
}

void OGLConsole::renderOGL() {
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			if (display[x][y] != ' ') {
				GLdouble tx = display[x][y] % 80;
				GLdouble ty = display[x][y] / 80;

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

unsigned char* OGLConsole::loadBMPRaw(const char * imagepath, unsigned int& outWidth, unsigned int& outHeight, bool flipY){
	printf("Reading image %s\n", imagepath);
	outWidth = -1;
	outHeight = -1;
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int imageSize;
	unsigned char * data;
	FILE * file = fopen(imagepath,"rb");
	if (!file)	{printf("Image could not be opened\n"); return NULL;}
	if ( fread(header, 1, 54, file)!=54 ){
		printf("Not a correct BMP file\n");
		return NULL;
	}
	if ( header[0]!='B' || header[1]!='M' ){
		printf("Not a correct BMP file\n");
		return NULL;
	}
	if ( *(int*)&(header[0x1E])!=0 ) {printf("Not a correct BMP file\n"); return NULL;}
	if ( *(int*)&(header[0x1C])!=24 ) {printf("Not a correct BMP file\n"); return NULL;}
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	outWidth = *(int*)&(header[0x12]);
	outHeight = *(int*)&(header[0x16]);
	if (imageSize==0) imageSize=outWidth*outHeight*3;
	if (dataPos==0) dataPos=54;
	data = new unsigned char [imageSize];
	fread(data,1,imageSize,file);
	fclose (file);
	if (flipY){
		unsigned char * tmpBuffer = new unsigned char[outWidth*3];
		int size = outWidth*3;
		for (unsigned int i=0; i <outHeight/2; i++){
			memcpy_s(tmpBuffer,size,data+outWidth*3*i,size);
			memcpy_s(data+outWidth*3*i, size, data+outWidth*3*(outHeight-i-1), size);
			memcpy_s(data+outWidth*3*(outHeight-i-1), size,tmpBuffer, size);
		}
		delete [] tmpBuffer;
	}
	return data;
}

GLuint OGLConsole::LoadTextureRAW(const char* filename, int wrap)
{
	GLuint texture;
	glGenTextures( 1, &texture );

	glBindTexture(GL_TEXTURE_2D, texture);
	unsigned int w = 1024;
	unsigned int h = 64;
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 1024, 64, 0, GL_BGR, GL_UNSIGNED_BYTE, loadBMPRaw(filename, w, h, false));
 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return texture;
}

void OGLConsole::loadTextures() {
	chartextures = LoadTextureRAW("res/Font.bmp", 1);
}

ActionListener *ogl_global_looplistener;
KeyEventListener *ogl_global_keylistener;

void onMainLoopLoopCallback() {
	ogl_global_looplistener->actionPerformed(0);
}

void onMainLoopKeyCallback(int key, int x, int y) {
	printf("Key %d Event\n", key);

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
	printf("ASCII-Key %d Event\n", key);

	if (key == ' ') {
		ogl_global_keylistener->keyEventPerformed(KC_SPACE);
		return;
	} else if (key == 27) {
		ogl_global_keylistener->keyEventPerformed(KC_ESCAPE);
		return;
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


