#include "CrazyConsole.h"

CrazyConsole::CrazyConsole() : OGLConsole() {
	heightshift = new CrazyDouble(this, 0, 0.05, 0.00008, -150, 50);

	zangleShift = new CrazyDouble(this, 0, 0.1, 0.00016, -10, 10);
	xangleShift = new CrazyDouble(this, 0, 0.1, 0.00016, -50, 50);

	rcolorShift = new CrazyDouble(this, 255, 0.05, 0.00008, 64, 255);
	gcolorShift = new CrazyDouble(this, 255, 0.05, 0.00008, 64, 255);
	bcolorShift = new CrazyDouble(this, 255, 0.05, 0.00008, 64, 255);

	xscaleShift = new CrazyDouble(this, 0, 0.025, 0.00004, -50, 0);
	yscaleShift = new CrazyDouble(this, 0, 0.025, 0.00004, -50, 0);

	stopCrazy();
}

void CrazyConsole::restartCrazy() {
	heightshift->restart();

	zangleShift->restart();
	xangleShift->restart();

	rcolorShift->restart();
	gcolorShift->restart();
	bcolorShift->restart();

	xscaleShift->restart();
	yscaleShift->restart();
}

void CrazyConsole::stopCrazy() {
	heightshift->stop();

	zangleShift->stop();
	xangleShift->stop();

	rcolorShift->stop();
	gcolorShift->stop();
	bcolorShift->stop();
	
	xscaleShift->stop();
	yscaleShift->stop();
}

void CrazyConsole::initOGL() {
	depth = - (6.0*BUFFER_H) / tan(M_PI * 22.5 / 180.0);

	int argc = 0;
	char *pc = 0;

	glutInit(&argc, &pc);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(8 * BUFFER_W, 12 * BUFFER_H);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 8 * BUFFER_W) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 12 * BUFFER_H) / 2);
	glutCreateWindow("Fight da Snake");

	glewInit();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (8.0 * BUFFER_W), (12 * BUFFER_H));
	gluPerspective(45,(8.0 * BUFFER_W) / (12 * BUFFER_H), 1, 1000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);

	loadTextures();
}

void CrazyConsole::startRenderOGL() {
	glLoadIdentity();

	OGLConsole::startRenderOGL();

	heightshift->run(this);
	zangleShift->run(this);
	xangleShift->run(this);

	rcolorShift->run(this);
	gcolorShift->run(this);
	bcolorShift->run(this);

	xscaleShift->run(this);
	yscaleShift->run(this);

	glScalef(1, -1, 1);

	glRotatef(xangleShift->get() / 5.0, 1, 0, 0);
	glRotatef(zangleShift->get(), 0, 0, 1);
	glTranslatef(0, 0, heightshift->get());
	glScalef(1 + xscaleShift->get() / 300.0, 1, 1);
	glScalef(1, 1 + yscaleShift->get() / 300.0, 1);

	glTranslatef((8 * BUFFER_W) / -2, (12 * BUFFER_H) / -2, depth);
}

void CrazyConsole::renderOGLPos(int x, int y, int chr) {
	int dchar = chr % 255;

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

	glColor3f(rcolorShift->get() / 255.0, gcolorShift->get() / 255.0, bcolorShift->get() / 255.0);
	glBindTexture(GL_TEXTURE_2D, chartextures);

	glBegin(GL_QUADS);
	glTexCoord2d(tx1, ty1); glVertex3d(x1, y1, 0);
	glTexCoord2d(tx1, ty2); glVertex3d(x1, y2, 0);
	glTexCoord2d(tx2, ty2); glVertex3d(x2, y2, 0);
	glTexCoord2d(tx2, ty1); glVertex3d(x2, y1, 0);
	glEnd();
}

void CrazyConsole::onLevelStart() {
	restartCrazy();
}

void CrazyConsole::onLevelStop() {
	stopCrazy();
}