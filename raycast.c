#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float px, py; //player position

void drawPlayer() 
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPlayer();
    glutSwapBuffers();
}

void buttons(unsigned char key, int x, int y)
{
    int playerSpeed = 10;
    if (key == 'a') { px -= playerSpeed; }
    if (key == 'd') { px += playerSpeed; }
    if (key == 'w') { py -= playerSpeed; }
    if (key == 's') { py += playerSpeed; }

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 1024, 512, 0);

    //initialise player position
    px = 300;
    py = 300;
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("Coding Cartel - Raycaster");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}