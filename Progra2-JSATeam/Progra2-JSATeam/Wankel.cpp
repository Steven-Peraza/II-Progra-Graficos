
#include <GLUT/GLUT.h> 



void rotate(int degrees,int cam) {
	glPushMatrix();
	glTranslatef(cam, cam, 0);
	glRotatef((GLfloat)degrees, 0, 0, 1);
	glutPostRedisplay();
}
