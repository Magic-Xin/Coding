//
//  main.cpp
//  Test3
//
//  Created by MagicXin on 2021/3/3.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <GLUT/glut.h>

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Tripoint");
    glutDisplayFunc(RenderScene);
    glutMainLoop();
}
