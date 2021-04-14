//
//  main.cpp
//  Test4
//
//  Created by MagicXin on 2021/3/3.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();

    glPointSize(6.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, -0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Mutipoint");
    glutDisplayFunc(RenderScene);
    glutMainLoop();
}
