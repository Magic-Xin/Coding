#include <iostream>
#include "GLUT/glut.h"

#define QUADS

const char* title = "CH 6.1";
const int winW = 800;
const int winH = 600;

GLuint texture[1];
const int bmp_width = 512;
const int bmp_height = 512;

unsigned char* loadTexture(const char* filepath) {
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

void setupRC() {
    glEnable(GL_DEPTH_TEST);

    glGenTextures(1, texture);

#ifdef QUADS
    unsigned char* image = loadTexture("../data/QUADS.TGA");
#else
    unsigned char* image = loadTexture("../data/TRIANGLES.TGA");
#endif

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE , GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp_width, bmp_height, GL_RGB, GL_UNSIGNED_BYTE, image);

    glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
}

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);

#ifdef QUADS
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-5.0f, -5.0f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(5.0f, -5.0f, -20.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(5.0f, 5.0f, -20.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-5.0f, 5.0f, -20.0f);
    }
#else
    glBegin(GL_TRIANGLES);
    {
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0f, 2.5f, -20.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-2.5f, -2.5f, -20.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(2.5f, -2.5f, -20.0f);
    }
#endif
    glEnd();
    glutSwapBuffers();
}

void Reshape(int w, int h) {
    h = (h == 0 ? 1 : h);
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat) w / (GLfloat) h, 1.0f, 500.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(winW, winH);
    glutCreateWindow(title);

    glutReshapeFunc(Reshape);
    glutDisplayFunc(RenderScene);

    setupRC();

    glutMainLoop();
    return 0;
}
