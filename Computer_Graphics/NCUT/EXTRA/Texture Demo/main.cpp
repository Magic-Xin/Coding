#include <cstdlib>
#include <cstdio>
#include "GLUT/glut.h"

const int winW = 800;
const int winH = 800;

const int num = 50;

float zoom = -15.0f;
float tilt = -90.0f;
float spin = 0;
bool twinkle = false;
GLuint texture[1];

typedef struct {
    GLuint w;
    GLuint h;
    GLubyte *data;
} RGBIMG;

typedef struct {
    int r, g, b;
    GLfloat dist,
            angle;
} stars;

stars star[num];

bool load_rgb_image(const char *file_name, int w, int h, RGBIMG *refimg) {
    GLuint sz;
    FILE *file;
    long fsize;
    GLubyte *p;

    refimg->w = (GLuint) w;
    refimg->h = (GLuint) h;
    sz = (((3 * refimg->w + 3) >> 2) << 2) * refimg->h;
    refimg->data = new GLubyte[sz];
    if (refimg->data == NULL) return false;

    file = fopen(file_name, "rb");
    if (!file) return false;
    fseek(file, 0L, SEEK_END);
    fsize = ftell(file);
    if (fsize != (long) sz) {
        fclose(file);
        return false;
    }
    fseek(file, 0L, SEEK_SET);
    p = refimg->data;
    while (fsize > 0) {
        fread(p, 1, 1, file);
        p++;
        fsize--;
    }
    fclose(file);
    return true;
}

bool setup_textures() {
    RGBIMG img;

    glGenTextures(1, texture);
    if (!load_rgb_image("Data/star_128x128.raw", 128, 128, &img)) return false;
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, img.w, img.h, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
    delete img.data;
    return true;
}

bool Init() {
    if (!setup_textures()) return false;
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);

    for (int i = 0; i < num; i++) {
        star[i].angle = 0.0f;
        star[i].dist = (float(i) / num) * 5.0f;
        star[i].r = rand() % 256;
        star[i].g = rand() % 256;
        star[i].b = rand() % 256;
    }
    return true;
}

void Reshape(int w, int h) {
    if (0 == h)
        h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) w / (float) h, 0.1f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void DrawHex() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    for (int i = 0; i < num; i++) {
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, zoom);
        glRotatef(tilt, 1.0f, 0.0f, 0.0f);
        glRotatef(star[i].angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(star[i].dist, 0.0f, 0.0f);
        glRotatef(-star[i].angle, 0.0f, 1.0f, 0.0f);
        glRotatef(-tilt, 1.0f, 0.0f, 0.0f);

        if (twinkle) {
            glColor4ub(star[(num - i) - 1].r, star[(num - i) - 1].g, star[(num - i) - 1].b, 255);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-1.0f, -1.0f, 0.0f);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, 0.0f);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, 0.0f);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 0.0f);
            glEnd();
        }

        glRotatef(spin, 0.0f, 0.0f, 1.0f);
        glColor4ub(star[i].r, star[i].g, star[i].b, 255);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glEnd();

        spin += 0.01;
        star[i].angle += float(i) / num;
        star[i].dist -= 0.01f;
        if (star[i].dist < 0.0f) {
            star[i].dist += 5.0f;
            star[i].r = rand() % 256;
            star[i].g = rand() % 256;
            star[i].b = rand() % 256;
        }
    }
}

void RenderScene() {
    DrawHex();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winW, winH);
    glutCreateWindow("Demo");

    glutReshapeFunc(Reshape);
    glutDisplayFunc(RenderScene);
    glutIdleFunc(RenderScene);

    if (!Init()) return -1;

    glutMainLoop();

    return 0;

}
