#include "CrazyConsole.h"

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
	gluPerspective(45,(8.0 * BUFFER_W) / (12 * BUFFER_H),1,1000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);

	loadTextures();
}

void CrazyConsole::startRenderOGL() {
	OGLConsole::startRenderOGL();

	glLoadIdentity();

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

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, chartextures);

	glBegin(GL_QUADS);
	glTexCoord2d(tx1, ty1); glVertex3d(x1, y1, 0);
	glTexCoord2d(tx1, ty2); glVertex3d(x1, y2, 0);
	glTexCoord2d(tx2, ty2); glVertex3d(x2, y2, 0);
	glTexCoord2d(tx2, ty1); glVertex3d(x2, y1, 0);
	glEnd();
}