// Progra2-JSATeam.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include <stdlib.h>

//#include <utility>
//#include <algorithm>
#include "ScanFill.h"
#include <GLUT/GLUT.h>
#include "Polygon.h"
#include <stdio.h>


using namespace std;

FILE *provincias;

char mangos[] = "Provincias/alajuela.txt";
char papa[] = "Provincias/cartago.txt";
char guana[] = "Provincias/guanacaste.txt";
char flores[] = "Provincias/heredia.txt";
char limoncho[] = "Provincias/limon.txt";
char punta[] = "Provincias/puntarenas.txt";
char chepe[] = "Provincias/sanjose.txt";

/*FILE *papa;
 FILE *guana;
 
 FILE *flores;
 FILE *limoncho;
 
 FILE *;
 FILE *fp;*/

//std::pair <std::pair <int, int>, std::pair <int, int>> * tablaLineas;;


void cargarLineas(char * provAct)
{
    
    provincias = fopen(provAct, "r");
    if (provincias == NULL)
    {
        printf("Could not open file");
        return;
    }
    
    int count = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    rewind(provincias);
    while (!feof(provincias))
    {
        count++;
        if (count > 2)
        {
            x1 = x2;
            y1 = y2;
            count = 2;
        }
        if (count == 1)
        {
            fscanf(provincias, "%d,%d", &x1, &y1);
        }
        else {
            fscanf(provincias, "%d,%d", &x2, &y2);
            printf("\npar1 %d,%d", x1, y1);
            printf("\npar2 %d,%d", x2, y2);
            //llamo a bresenham
            glBegin(GL_POINTS);
            linesBresen(x1*2, y1*2, x2*2, y2*2);
            glEnd();
            storeEdgeInTable(x1*2, y1*2, x2*2, y2*2);//storage of edges in edge table.
            
            glFlush();
        }
    }
    
    /*
     for (int i = 0; i < lineas; i++)
     {
     x1 = rand() % resolux + 1;
     x2 = rand() % resolux + 1;
     y1 = rand() % resolux + 1;
     y2 = rand() % resolux + 1;
     //printf("\nx1 = %d, y1 = %d, x2 = %d, y2 = %d",x1,y1,x2,y2);
     // se almacena el par de pares dentro de la tabla de lineas
     tablaLineas[i] = std::make_pair(std::make_pair(x1, y1), std::make_pair(x2, y2));
     }*/
}



void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 500, 500);
    glColor3f(0.0, 1.0, 1.0);
    initEdgeTable();
    cargarLineas(mangos);
    ScanlineFill(0.7f, 0.7f, 0.0f);
    initEdgeTable();
    cargarLineas(papa);
    ScanlineFill(0.0f, 0.0f, 0.5f);
    initEdgeTable();
    cargarLineas(guana);
    ScanlineFill(0.7f, 0.2f, 0.5f);
    initEdgeTable();
    cargarLineas(flores);
    ScanlineFill(0.7f, 0.2f, 0.2f);
    initEdgeTable();
    cargarLineas(limoncho);
    ScanlineFill(0.0f, 0.5f, 0.0f);
    initEdgeTable();
    cargarLineas(punta);
    ScanlineFill(0.1f, 0.2f, 0.2f);
    initEdgeTable();
    cargarLineas(chepe);
    ScanlineFill(0.2f, 0.2f, 0.2f);
    glFlush();

}

void rotate(){
    glPushMatrix();
    glTranslatef(700,0, 0);
    glRotatef((GLfloat) 90, 0, 0, 1);
    glutPostRedisplay();
    //glPopMatrix();
}

int main(int argc, char** argv) {
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Progra 2");
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
    glutDisplayFunc(MyDisplay);
    rotate();
    rotate();
    //glPopMatrix();

    glutMainLoop();
    return 0;
}


