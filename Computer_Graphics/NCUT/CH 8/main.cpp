#include "GLUT/glut.h"

const int winW = 600;
const int winH = 600;
const char* title = "CH 8";

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}

void processMenu(int value){}

void createMenu() {
    int file, edit, rendering;

    file = glutCreateMenu(processMenu);
    glutAddMenuEntry("New", 0);
    glutAddMenuEntry("Open", 1);
    glutAddMenuEntry("Save", 2);

    edit = glutCreateMenu(processMenu);
    glutAddMenuEntry("Copy", 0);
    glutAddMenuEntry("Cut", 1);
    glutAddMenuEntry("Paste", 2);

    rendering = glutCreateMenu(processMenu);
    glutAddMenuEntry("Points", 0);
    glutAddMenuEntry("Line", 1);
    glutAddMenuEntry("Fill", 2);

    glutCreateMenu(processMenu);
    glutAddSubMenu("File", file);
    glutAddSubMenu("Edit", edit);
    glutAddSubMenu("Rendering", rendering);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void setupRC() {
    glClearColor(0.2f, 0.3f, 0.3f, 0.0f);

    createMenu();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(winW, winH);
    glutCreateWindow(title);

    glutDisplayFunc(RenderScene);
    setupRC();

    glutMainLoop();
    return 0;
}
