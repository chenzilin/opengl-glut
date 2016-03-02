#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int day = 200;

void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

    // 红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(60000000, 100, 100);

    // 蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 100, 100);

    // 黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 100, 100);

    glFlush();
    glutSwapBuffers();
}

void myIdle()
{
    if (++day >= 360) day = 0;

    display();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(450, 450);
    glutCreateWindow("OpenGL GLUT DEMO3");

    glutDisplayFunc(&display);
    glutIdleFunc(&myIdle);

    glutMainLoop();

    return 0;
}
