#include <sstream>
#include <cmath>
#include "GLUT/glut.h"

const int winW = 800, winH = 600;
const char *title = "CH_5.3";

float initFrame = glutGet(GLUT_ELAPSED_TIME);
int frameCount = 0;
float xRot = 0.0f, yRot = 0.0f;
float lRot = 0.0f;

float light0_position[] = {0.0f, 0.0f, 1.0f, 0.0f};
float light1_position[] = {0.0f, 0.0f, 1.0f, 0.0f};
float light2_position[] = {0.0f, 0.0f, 1.0f, 0.0f};

void DrawShapes() {
    // TEAPOT
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(-60, 30, 0);
    glutSolidTeapot(20);
    glPopMatrix();
    // SPHERE
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(60, 30, 0);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();
    // CUBE
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(60, -30, 0);
    glutSolidCube(35);
    glPopMatrix();
    // TORUS
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(-60, -30, 0);
    glutSolidTorus(5, 20, 30, 30);
    glPopMatrix();

    // LIGHT0
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(light0_position[0] * 80, light0_position[1] * 80, light0_position[2] * 80);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireSphere(2, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    // LIGHT1
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(light1_position[0] * 80, light1_position[1] * 80, light1_position[2] * 80);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutWireSphere(2, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    // LIGHT2
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(light2_position[0] * 80, light2_position[1] * 80, light2_position[2] * 80);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutWireSphere(2, 20, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    DrawShapes();
    glutSwapBuffers();
}

void Reshape(int w, int h) {
    h = (h == 0 ? 1 : h);
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish viewing volume
    gluPerspective(45.0f, (GLfloat) w / (GLfloat) h, 1.0f, 500.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -250.0f);
}

void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) xRot -= 5.0f;
    if (key == GLUT_KEY_DOWN) xRot += 5.0f;
    if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
    if (key == GLUT_KEY_RIGHT) yRot += 5.0f;

    if (key > 356.0f) xRot = 0.0f;
    if (key < -1.0f) xRot = 355.0f;
    if (key > 356.0f) yRot = 0.0f;
    if (key < -1.0f) yRot = 355.0f;

    glutPostRedisplay();
}

void initLight() {
    float red_light[] = {1.0f, 0.0f, 0.0f, 1.0f};
    float green_light[] = {0.0f, 1.0f, 0.0f, 1.0f};
    float blue_light[] = {0.0f, 0.0f, 1.0f, 1.0f};
    float ambient_light[] = {0.2f, 0.2f, 0.2f, 1.0f};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, red_light);

    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, green_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, green_light);

    glLightfv(GL_LIGHT2, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, blue_light);
    glLightfv(GL_LIGHT2, GL_SPECULAR, blue_light);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
}

void idleFunc() {
    float currentFrame = glutGet(GLUT_ELAPSED_TIME);
    frameCount++;
    lRot += 0.01f;

    RenderScene();

    light0_position[0] = std::sin(lRot);
    light0_position[1] = std::cos(lRot);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    light1_position[0] = std::sin(lRot);
    light1_position[2] = std::cos(lRot);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    light2_position[1] = std::sin(lRot);
    light2_position[2] = std::cos(lRot);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

    if (currentFrame - initFrame >= 1000.0f) {
        std::stringstream ss;
        ss << title << " (" << frameCount << "fps)";
        glutSetWindowTitle(ss.str().c_str());
        frameCount = 0;
        initFrame = currentFrame;
    }
}

int main(int argv, char *argc[]) {
    glutInit(&argv, argc);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(winW, winH);
    glutCreateWindow(title);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);

    glutReshapeFunc(Reshape);
    glutDisplayFunc(RenderScene);
    glutIdleFunc(idleFunc);
    glutSpecialFunc(SpecialKeys);

    initLight();

    glutMainLoop();
    return 0;
}
