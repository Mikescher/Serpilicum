#include "OGLConsole.h"


OGLConsole::OGLConsole(void)
{
	int argc = 0;
	char *pc = 0;

	glutInit(&argc, &pc);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800,600);
	glutCreateWindow("GLEW Test");

	glewInit();
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

long OGLConsole::getSystemCurrTimeMillis()
{
	auto time = std::chrono::system_clock::now();

	auto since_epoch = time.time_since_epoch(); 

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

	return millis.count(); 
}

void OGLConsole::setDimensions(short w, short h)
{
	// DO NOTHING ???
}

void OGLConsole::clearBuffer() {
	DBConsole::clearBuffer();

	glClearColor(1.f, 0.f, 0.f, 1.f);
	glClear (GL_COLOR_BUFFER_BIT);
}

void OGLConsole::swap() {
	DBConsole::swap();

	//TODO RENDER OGL
	renderOGL();
	//TODO RENDER OGL

	glutSwapBuffers();
}

void OGLConsole::renderOGL() {
	for (int x = 0; x < BUFFER_W; x++) {
		for (int y = 0; y < BUFFER_H; y++) {
			if (display[x][y] != ' ') {
				double x1 = ((2.0 / BUFFER_W) * x) - 1;
				double x2 = ((2.0 / BUFFER_W) * (x+1)) - 1;

				double y1 = ((2.0 / BUFFER_H) * y) - 1;
				double y2 = ((2.0 / BUFFER_H) * (y+1)) - 1;

				glColor3f(0.5f, 0.5f, 0.5f);
				glBegin(GL_QUADS);
					glVertex3f(x1, y1,0.0);
					glVertex3f(x2, y1,0.0);
					glVertex3f(x2, y2,0.0);
					glVertex3f(x1, y2,0.0);
				glEnd();
			}
		}
	}
}

ActionListener *ogl_global_looplistener;

void onMainLoopCallback() {
	ogl_global_looplistener->actionPerformed(0);
}

void OGLConsole::startLoop(ActionListener *looplistener) {
	ogl_global_looplistener = looplistener;

	while (true) { //TODO Remove me - recomment things under me
		onMainLoopCallback();
	}

	//glutDisplayFunc(onMainLoopCallback);
	//glutMainLoop();
}