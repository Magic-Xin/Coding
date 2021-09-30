//
//  main.cpp
//  Test2
//
//  Created by MagicXin on 2021/3/17.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <cmath>
#include <GLUT/GLUT.h>

#define PI 3.14259265

void RenderACircle(float radius)
{
    float x = 0.0f, y = 0.0f;
    glBegin(GL_POINTS);
    for(float  a = 0 ; a <= 2 * PI ; a += 0.1)
    {
        x = radius * std::cos(a);
        y = radius * std::sin(a);
        glVertex2f(x, y);
    }
    glEnd();
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    RenderACircle(0.5);
    glFlush();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("CH03 Test2");
    glutDisplayFunc(RenderScene);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glutMainLoop();
    return 0;
}
