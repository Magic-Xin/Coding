//
//  main.cpp
//  Test2
//
//  Created by MagicXin on 2021/3/3.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void RenderScene(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glRectf(-0.5, -0.5, 0.5, 0.5);
    glFlush();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutCreateWindow("Yellow");
    glutDisplayFunc(RenderScene);
    glutMainLoop();
}
