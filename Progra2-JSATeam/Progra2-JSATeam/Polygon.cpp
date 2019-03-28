
#include "stdafx.h";
#include <GL/glut.h>;

void plot(int i, int y) {
	glVertex2i(i, y);
}

// BRESENHAM
void linesBresen(int x0, int y0, int x1, int y1)
{
	int Delta_E, Delta_NE, d, Xp, Yp;
	Delta_E = 2 * (y1 - y0);
	Delta_NE = 2 * ((y1 - y0) - (x1 - x0));
	Xp = x0;
	Yp = y0;

	plot(Xp, Yp);

	d = 2 * (y1 - y0) - (x1 - x0);
	while (Xp < x1)
	{
		if (d <= 0)
		{ /* Pintar E */
			Xp++;
			d = d + Delta_E;
		}
		else
		{ /* Pintar NE */
			Xp++;
			Yp++;
			d = d + Delta_NE;
		}

		plot(Xp, Yp);

	}
}

