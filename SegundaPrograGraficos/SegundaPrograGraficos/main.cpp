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
#include <stdlib.h>
#include "Wankel.h"

using namespace std;

FILE *provincias;

char mangos[] = "Provincias/alajuela.txt";
char papa[] = "Provincias/cartago.txt";
char guana[] = "Provincias/guanacaste.txt";
char flores[] = "Provincias/heredia.txt";
char limoncho[] = "Provincias/limon.txt";
char punta[] = "Provincias/puntarenas.txt";
char chepe[] = "Provincias/sanjose.txt";

bool borders, philly, texmex, sanic;

//GLfloat xRotated, yRotated, zRotated;

int resetCounter = 0;

double rotate_by_key = 0;
double rotate_x = 0;


int tipo_sombreado = 0; /* 0: borderLineCR() , 1: ScanFill(), 2: por definir */


//std::pair <std::pair <int, int>, std::pair <int, int>> * tablaLineas;;


void cargarLineas(char * provAct)
{
    
    provincias = fopen(provAct, "r");
    
    if (provincias == NULL)
    {
        printf("Could not open file");
        return;
    }
    
    int count = 0, x1, y1, x2, y2;
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
            linesBresen(x1 * 2, y1 * 2, x2 * 2, y2 * 2);
            glEnd();
            storeEdgeInTable(x1 * 2, y1 * 2, x2 * 2, y2 * 2);//storage of edges in edge table.
            
            
            //glFlush();
        }
    }
}


void ScanFill() {
    //
    initEdgeTable();
    cargarLineas(mangos);
    ScanlineFill(0.7f, 0.7f, 0.0f);
    //
    initEdgeTable();
    cargarLineas(papa);
    ScanlineFill(0.0f, 0.0f, 0.5f);
    //
    initEdgeTable();
    cargarLineas(guana);
    ScanlineFill(0.7f, 0.2f, 0.5f);
    //
    initEdgeTable();
    cargarLineas(flores);
    ScanlineFill(0.7f, 0.2f, 0.2f);
    //
    initEdgeTable();
    cargarLineas(limoncho);
    ScanlineFill(0.0f, 0.5f, 0.0f);
    //
    initEdgeTable();
    cargarLineas(punta);
    ScanlineFill(0.1f, 0.2f, 0.2f);
    //
    initEdgeTable();
    cargarLineas(chepe);
    ScanlineFill(0.2f, 0.2f, 0.2f);
    //ScanlineFill(3);
    glFlush();
}

void TextureFill() {
    
    initEdgeTable();
    cargarLineas(mangos);
    ScanlineFill(0);
    initEdgeTable();
    cargarLineas(papa);
    ScanlineFill(1);
    initEdgeTable();
    cargarLineas(guana);
    ScanlineFill(2);
    initEdgeTable();
    cargarLineas(flores);
    ScanlineFill(3);
    initEdgeTable();
    cargarLineas(limoncho);
    ScanlineFill(5);
    initEdgeTable();
    cargarLineas(punta);
    ScanlineFill(4);
    initEdgeTable();
    cargarLineas(chepe);
    ScanlineFill(6);
    glFlush();
}

void borderLineCR() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0.7f, 0.7f, 0.0f);
    cargarLineas(mangos);
    
    glColor3f(0.0f, 0.0f, 0.5f);
    cargarLineas(papa);
    
    glColor3f(0.7f, 0.2f, 0.5f);
    cargarLineas(guana);
    
    glColor3f(0.7f, 0.2f, 0.2f);
    cargarLineas(flores);
    
    glColor3f(0.0f, 0.5f, 0.0f);
    cargarLineas(limoncho);
    
    glColor3f(0.1f, 0.2f, 0.2f);
    cargarLineas(punta);
    
    glColor3f(0.2f, 0.2f, 0.2f);
    cargarLineas(chepe);
    
    glFlush();
}
void pinta() {
    
    if (tipo_sombreado == 0) { borderLineCR(); }
    if (tipo_sombreado == 1) { ScanFill(); }
    if (tipo_sombreado == 2) { TextureFill(); }
    glutPostRedisplay();
}

void restart() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 500, 500);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < resetCounter; i++)
    {
        glPopMatrix();
    }
    resetCounter = 0;
}



void mazda(int x, int y) {
    glPushMatrix();
    resetCounter++;
    glTranslatef(x, y, 0);
    glScalef(rotate_x, rotate_x, 1.0f);
    //ifs
    //borderLineCR();
}



void autobots(int x, int y) {
    
    resetCounter++;
    glPushMatrix();
    glTranslatef(x, y, 0);
    
    //IFS
}

void MyDisplay() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 500, 500);
    glColor3f(1.0, 1.0, 1.0);
    //glFlush();
}

void shiftry() {
    
    int modi = glutGetModifiers();
    if (modi == GLUT_ACTIVE_CTRL)
        sanic = true;
    else
        sanic = false;
}



void specialKeys(int key, int x, int y)
{
    float fraction = 0.1f;
    if (key == GLUT_KEY_UP) {
        shiftry();
        if (!sanic)
            rotate_x = 0.8; // Or whatever you want the step to be
        else
            rotate_x = 0.5;
        mazda(100, 75);
        
    }
    
    if (key == GLUT_KEY_DOWN) {
        shiftry();
        if (!sanic)
            rotate_x = 1.2; // Or whatever you want the step to be
        else
            rotate_x = 2.0;
        mazda(-100, -75);
    }
    if (key == GLUT_KEY_LEFT) {
        
        resetCounter++;
        shiftry();
        
        if (!sanic) {
            rotate(5, 150);
            
        }
        else {
            rotate(25, 150);
            
            
        }
    }
    
    if (key == GLUT_KEY_RIGHT) {
        
        resetCounter++;
        shiftry();
        
        if (!sanic) {
            rotate(-5, -150);
            
        }
        else {
            rotate(-25, -150);
            
        }
    }
    
    
    if (key == GLUT_KEY_F1)
        tipo_sombreado = 0;
    if (key == GLUT_KEY_F2)
        tipo_sombreado = 1;
    if (key == GLUT_KEY_F3)
        tipo_sombreado = 2;
    
    pinta();
    
}



void normalKeys(unsigned char key, int x, int y)
{
    
    if (key == 't') {
        
        borderLineCR();
    }
    
    if (key == 'w') {
        
        shiftry();
        
        if (!sanic) {
            autobots(0, 100);
        }
        else {
            autobots(0, 200);
        }
        
    }
    if (key == 'a') {
        
        shiftry();
        
        if (!sanic) {
            autobots(-100, 0);
        }
        else {
            autobots(-200, 0);
        }
    }
    if (key == 's') {
        
        shiftry();
        
        if (!sanic) {
            autobots(0, -100);
        }
        else {
            autobots(0, -200);
        }
    }
    if (key == 'd') {
        
        shiftry();
        
        if (!sanic) {
            autobots(100, 0);
        }
        else {
            autobots(200, 0);
        }
    }
    if (key == 'r')
        restart();
    if (key == 'f')
        exit(0);
    
    pinta();
}

char* filename[] = {"texturas/1.bmp","texturas/2.bmp","texturas/3.bmp","texturas/4.bmp","texturas/5.bmp","texturas/6.bmp","texturas/7.bmp"};

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Progra 2");
    loadTextures(filename);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
    
    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(normalKeys);
    
    
    glutMainLoop();
    return 0;
}


