#include <GL/glut.h> 
#include <cmath>


float centerX = 0.0f, centerY = 0.0f, centerZ = -1.0f;

float eyeX = 0.0f, eyeY = 0.0f, eyeZ = 5.0f;

float angle = 0.0f;


void draw()
{

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	glVertex3f(1.0f, 0.0f, -5.0f);
	glVertex3f(0.0f, 1.0f, -5.0f);
	glVertex3f(-1.0f, 0.0f, -5.0f);

	glEnd();

}

void changeSize(int w, int h)
{

	if (h == 0) { h = 1; }

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera: (eyex, eyey, eyez, centerx, centery, centerz, upx, upy,upz);

	gluLookAt(eyeX, eyeY, eyeZ, eyeX + centerX, eyeY + centerY, eyeZ + centerZ, 0.0, 0.1, 0.0);

	// Call method
	//draw();

	// Call the buffer
	glutSwapBuffers();
}
/*
void mouseClick(int btn, int state, int x, int y) {

	//mouse wheel scrolls

	float fraction = 0.1f;

	switch (btn) {

	case 3:
		eyeX += centerX * fraction;
		eyeZ += centerZ * fraction;
		break;
	case 4:
		eyeX -= centerX * fraction;
		eyeZ -= centerZ * fraction;
		break;
	default:
		break;
	}

}

void processSpecialKeys(int key, int xx, int yy)
{

	float move_unit = 0.02f;

	switch (key) {

	case GLUT_KEY_RIGHT:
		angle -= 0.01f;
		centerX = sin(angle);
		centerZ = -cos(angle);
		break;
	case GLUT_KEY_LEFT:
		angle += 0.01f;
		centerX = sin(angle);
		centerZ = -cos(angle);
		break;
	case GLUT_KEY_UP:
		centerY -= move_unit;
		break;
	case GLUT_KEY_DOWN:
		centerY += move_unit;
		break;
	}
}

int main(int argc, char **argv)
{

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);

	glutMouseFunc(mouseClick);
	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}*/