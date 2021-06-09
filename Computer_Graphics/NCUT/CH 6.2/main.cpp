#include <iostream>
#include "GLUT/glut.h"

const int winW = 600;
const int winH = 600;
const char* title = "CH 6.2";

GLuint texture[0];
GLuint textures[6];


float xRot = 0.0f, yRot = 0.0f;

unsigned char* loadTexture(const char* filepath, const int bmp_width = 2048, const int bmp_height = 2048) {
    unsigned char* data;

    FILE * file;
    file = fopen( filepath, "rb" );
    data = (unsigned char *)malloc( bmp_width * bmp_height * 3 );
    fread( data, bmp_width * bmp_height * 3, 1, file );
    fclose(file);

    for(int i = 0; i < bmp_width * bmp_height ; i++) {
        int index = i * 3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;
    }

    return data;
}

void genTexture(GLuint texture, const char* filepath, const int bmp_width = 2048, const int bmp_height = 2048) {
    unsigned char* image = loadTexture(filepath);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE , GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp_width, bmp_height, GL_RGB, GL_UNSIGNED_BYTE, image);
}

void setupRC() {
    glEnable(GL_DEPTH_TEST);

    glGenTextures(6, textures);
    glGenTextures(1, texture);

    genTexture(textures[0], "../skybox/FR.bmp");
    genTexture(textures[1], "../skybox/BK.bmp");
    genTexture(textures[2], "../skybox/LF.bmp");
    genTexture(textures[3], "../skybox/RT.bmp");
    genTexture(textures[4], "../skybox/UP.bmp");
    genTexture(textures[5], "../skybox/DN.bmp");

    genTexture(texture[0], "../skybox/FULL.bmp", 1024, 1024);

    glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
}

void Reshape(int w, int h) {
    float nRange = 80.0f;

    h = (h == 0 ? 1 : h);
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) xRot -= 5.0f;
    if (key == GLUT_KEY_DOWN) xRot += 5.0f;
    if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
    if (key == GLUT_KEY_RIGHT) yRot += 5.0f;

    if (xRot > 356.0f) xRot = 0.0f;
    if (xRot < -1.0f) xRot = 355.0f;
    if (yRot > 356.0f) yRot = 0.0f;
    if (yRot < -1.0f) yRot = 355.0f;

    glutPostRedisplay();
}

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Single Texture
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    // Front
    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, 20.0f);
        glTexCoord2f(0.5f, 0.0f);
        glVertex3f(20.0f, -20.0f, 20.0f);
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-20.0f, 20.0f, 20.0f);
    }
    glEnd();
    glPopMatrix();
    // Back
    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.5f, 0.0f);
        glVertex3f(20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.5f);
        glVertex3f(-20.0f, 20.0f, -20.0f);
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(20.0f, 20.0f, -20.0f);
    }
    glEnd();
    glPopMatrix();
    // Left
    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-20.0f, -20.0f, -20.0f);
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(-20.0f, -20.0f, 20.0f);
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(-20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, -20.0f);
    }
    glEnd();
    glPopMatrix();
    // Right
    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(20.0f, -20.0f, 20.0f);
        glTexCoord2f(1.0f, 0.5f);
        glVertex3f(20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, -20.0f);
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(20.0f, 20.0f, 20.0f);
    }
    glEnd();
    glPopMatrix();
    // Up
    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(20.0f, 20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-20.0f, 20.0f, -20.0f);
    }
    glEnd();
    glPopMatrix();
    // Down
    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(20.0f, -20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-20.0f, -20.0f, 20.0f);
    }
    glEnd();
    glPopMatrix();

    // Multi Texture
    // Front
    glPushMatrix();
    glTranslatef(40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, 20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(20.0f, -20.0f, 20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, 20.0f);
    }
    glEnd();
    glPopMatrix();
    // Back
    glPushMatrix();
    glTranslatef(40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, -20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, -20.0f);
    }
    glEnd();
    glPopMatrix();
    // Left
    glPushMatrix();
    glTranslatef(40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, 20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, -20.0f);
    }
    glEnd();
    glPopMatrix();
    // Right
    glPushMatrix();
    glTranslatef(40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(20.0f, -20.0f, 20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, -20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, 20.0f);
    }
    glEnd();
    glPopMatrix();
    // Up
    glPushMatrix();
    glTranslatef(40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(20.0f, 20.0f, 20.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(20.0f, 20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-20.0f, 20.0f, -20.0f);
    }
    glEnd();
    glPopMatrix();
    // Down
    glPushMatrix();
    glTranslatef(40, 0, 0);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(20.0f, -20.0f, -20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(20.0f, -20.0f, 20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-20.0f, -20.0f, 20.0f);
    }
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(winW, winH);
    glutCreateWindow(title);

    glutReshapeFunc(Reshape);
    glutDisplayFunc(RenderScene);
    glutSpecialFunc(SpecialKeys);

    setupRC();

    glutMainLoop();
    return 0;
}
