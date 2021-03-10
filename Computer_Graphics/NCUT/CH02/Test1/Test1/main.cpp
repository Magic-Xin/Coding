//
//  main.cpp
//  Test1
//
//  Created by MagicXin on 2021/3/10.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <cstdlib>
#include <GLUT/glut.h>

#define WHITE glColor3f(1.0f, 1.0f, 1.0f)
#define RED glColor3f(1.0f, 0.0f, 0.0f)
#define GREEN glColor3f(0.0f, 1.0f, 0.0f)
#define BLUE glColor3f(0.0f, 0.0f, 1.0f)
#define EXIT exit(0)

int COLOR = 0;

void SwitchColor(){
    switch (COLOR) {
        case 0:
            WHITE;
            break;
        case 1:
            RED;
            break;
        case 2:
            GREEN;
            break;
        case 3:
            BLUE;
            break;
        case 4:
            EXIT;
    }
    glutPostRedisplay();
}

void RenderScene(){
    glClear(GL_COLOR_BUFFER_BIT);
    SwitchColor();
    glRectf(-0.5, -0.5, 0.5, 0.5);
    glFlush();
}

void MenuProcess(int value){
    COLOR = value;
}

void CreateMenu(){
    glutCreateMenu(MenuProcess);
    glutAddMenuEntry("White", 0);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init(){
    glutCreateWindow("CH02 Test1");
    glutDisplayFunc(RenderScene);
    CreateMenu();
    glutMainLoop();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    init();
    return 0;
}
