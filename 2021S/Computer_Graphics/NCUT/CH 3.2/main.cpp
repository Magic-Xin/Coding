#include <GLUT/glut.h>

const int winW = 800;
const int winH = 800;

float fRotateTri = 0;
float fRotateQuad = 0;

void Init() {
    glEnable(GL_DEPTH_TEST); //启用深度测试

    glClearColor(0.0f, 0.0f, 0.0f, 0.8f); //背景为黑色
}

void Reshape(int w, int h) {
    if (0 == h)
        h = 1;

    glViewport(0, 0, w, h); //设置视区尺寸

    glMatrixMode(GL_PROJECTION); //指定当前操作投影矩阵堆栈
    glLoadIdentity(); //重置投影矩阵
    gluPerspective(45.0f, (float) w / (float) h, 1.0f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void RenderMovingTris() {
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.5f, 1.5f, -8.0f);
    glRotatef(fRotateTri, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(1.5f, 1.5f, -8.0f);
    glRotatef(fRotateTri, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void RenderMovingQuads() {
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.5f, -1.5f, -8.0f);
    glRotatef(fRotateQuad, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(1.5f, -1.5f, -8.0f);
    glRotatef(fRotateQuad, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.75f, 0.8f);
    glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
    glPopMatrix();
}

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    RenderMovingTris();
    RenderMovingQuads();

    glutSwapBuffers();

}

void timeFunc(int value) //在空闲时调用，达到动画效果
{
    fRotateTri += 0.5f;
    fRotateQuad += 1.5f;

    RenderScene();

    glutTimerFunc(10, timeFunc, 1);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winW, winH);
    glutCreateWindow("Demo");

    glutReshapeFunc(Reshape);

    glutDisplayFunc(RenderScene);

    glutTimerFunc(33, timeFunc, 1);

    Init();

    glutMainLoop();

    return 0;

}
