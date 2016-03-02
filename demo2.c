#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1.0, 0);

    glBegin(GL_TRIANGLES);
    glVertex3f(-3.0, -3.0, 0.0);
    glVertex3f(3.0, -3.0, 0.0);
    glVertex3f(0.0, 3.0, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("OpenGL GLUT DEMO2");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
