#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float px, py; //player position

int mapX = 8, mapY = 8, mapS = 64;
int map[] = 
{
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,1,1,
    1,0,0,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,1,0,1,0,0,1,
    1,0,0,0,1,0,0,1,
    1,1,1,1,1,1,1,1,
};

void drawMap2D()
{
    int x, y, xo, yo;
    for (y = 0; y < mapY; y++)
    {
        for (x = 0; x < mapX; x++)
        {
            if (map[y * mapX + x] == 1) 
            {
                 glColor3f(1,1,1); 
            }
            else
            {
                glColor3f(0,0,0);
            }
            xo = x * mapS;
            yo = y * mapS;
            glBegin(GL_QUADS);
            glVertex2i(xo + 1       , yo        + 1 );
            glVertex2i(xo + 1       , yo + mapS - 1 );
            glVertex2i(xo + mapS - 1, yo + mapS - 1 );
            glVertex2i(xo + mapS - 1, yo        + 1 );
            glEnd();
        }
    }
}

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
    drawMap2D();
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