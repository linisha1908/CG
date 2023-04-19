/*#include <GL/glut.h>
#include<stdio.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Define two points
    int x1 = 100, y1 = 100, x2 = 300, y2 = 400;

    // Determine the change in x and y
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Determine the number of steps needed
    //int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    if(abs(dx) > abs(dy))
    {
        int steps = abs(dx);

    }
    else
    {
        int steps = abs(dy);
    }

    // Calculate the increment in x and y
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;

    // Draw the line using DDA algorithm
    float x = x1, y = y1;
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Algorithm");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}*/
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Define the vertices of the line
float x1 = 0, y1 = 0, x2 = 300, y2 = 200;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Set color to red

    // Calculate the slope of the line
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;

    // Determine the number of steps required to draw the line
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    // Calculate the incremental values for x and y
    float xi = dx / steps;
    float yi = dy / steps;

    // Set the initial point of the line
    float x = x1;
    float y = y1;

    // Draw the line using DDA algorithm
    glBegin(GL_POINTS);
    for (int i = 0; i < steps; i++) {
        glVertex2f(round(x), round(y)); // Round to the nearest integer
        x += xi;
        y += yi;
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480); // Set the coordinate system for the window
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
