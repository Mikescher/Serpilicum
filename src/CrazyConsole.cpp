#include "CrazyConsole.h"

void CrazyConsole::initOGL() {
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

	//glTranslatef(0, 0, 0.005);

	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0, 0);glVertex3f(-0.5,-0.5, -5);  
	glColor3f(0, 0.5, 0);glVertex3f( 0.5,-0.5, -5);
	glColor3f(0, 0, 0.5);glVertex3f( 0, 0.5, -5);
	glEnd();
}

void CrazyConsole::swap() {
	DBConsole::swap();

	startRenderOGL();

	//<RENDER OGL>
	renderOGL();
	//</RENDER OGL>

	glutSwapBuffers();
}