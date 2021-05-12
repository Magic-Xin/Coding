#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


#include "GLUT/glut.h"

#define PI 3.1415926

int iWidth = 600;
int iHeight = 600;

int iSize = 100;

float xRot = 0.0;
float yRot = 0.0;

void SetColor(int red, int green, int blue) {
    glColor3ub(red, green, blue);
}

void RenderAHelix(float fRadiusInner, float fRadiusOuter, float fZStart = -60, float fZEnd = -10, int iNumofDot = 200) {
    float RadiusStep, ZStep;
    RadiusStep = (fRadiusOuter - fRadiusInner) / iNumofDot;
    ZStep = (fZEnd - fZStart) / iNumofDot;
    float x, y, z;

    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    srand(time(NULL));
    for(int i = 0 ; i < iNumofDot ; i++) {
        float a = 3 * 2.0f * PI * (float) i / 100.0f;

        float radius = fRadiusInner + i * RadiusStep;
        x = radius * std::cos(a);
        y = radius * std::sin(a);
        z = fZStart + i * ZStep;

        SetColor(rand() % 256, rand() % 256, rand() % 256);
        glVertex3f(x, y, z);
    }
    glEnd();
}

void RenderASphere(float fRadius, int iSlice = 4, int iStack = 4) {
    float x, y, z;

    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    for (float i = 0.0; i < PI; i += PI / iSlice) {
        for (float j = 0.0; j < 2.0 * PI; j += PI / iSlice) {
            x = fRadius * std::cos(j) * std::sin(i);
            y = fRadius * std::sin(j) * std::sin(i);
            z = fRadius * std::cos(i);
            glVertex3f(x, y, z);
            x = fRadius * std::cos(j) * std::sin(i + PI / iSlice);
            y = fRadius * std::sin(j) * std::sin(i + PI / iSlice);
            z = fRadius * std::cos(i + PI / iSlice);
            glVertex3f(x, y, z);
        }
    }
    glEnd();
}

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    //glutSolidTeapot(30);
    //glutWireTeapot(30);

    RenderAHelix(10, 60);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    SetColor(255, 255, 255);
    RenderASphere(30,10,10);
    //RenderASphere(30);

    //glutWireSphere(30, 50, 50);
    glPopMatrix();

    glutSwapBuffers();
}

void ChangeSize(int width, int height) {
    if (height == 0) {
        height = 1;
    }

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width <= height) {
        glOrtho(-iSize, iSize, -iSize * height / width, iSize * height / width, -iSize, iSize);
    } else {
        glOrtho(-iSize * width / height, iSize * width / height, -iSize, iSize, -iSize, iSize);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void ProcessSpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        xRot -= 5.0f;
    }

    if (key == GLUT_KEY_DOWN) {
        xRot += 5.0f;
    }

    if (key == GLUT_KEY_LEFT) {
        yRot -= 5.0f;
    }

    if (key == GLUT_KEY_RIGHT) {
        yRot += 5.0f;
    }

    glutPostRedisplay();
}

void InitWindow() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(iWidth, iHeight);

    glutCreateWindow("Ex5.2");

}

void Init() {
    InitWindow();
}

void Process() {

}

void Output() {
    //int iSize = 200;
    glOrtho(-iSize, iSize, -iSize, iSize, -iSize, iSize);

    //glutKeyboardFunc();

    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(ProcessSpecialKeys);

    glutDisplayFunc(RenderScene);

    glutMainLoop();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    Init();
    Process();
    Output();

    return 1;
}
