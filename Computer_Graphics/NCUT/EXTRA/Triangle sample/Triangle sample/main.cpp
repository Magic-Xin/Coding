//
//  main.cpp
//  Triangle sample
//
//  Created by MagicXin on 2021/3/10.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <GLUT/glut.h>
#include <cstdlib>

float Zrotate[4] = {0.0f, 0.0f, 0.0f, 1.0f};
float Xrotate[4] = {0.0f, 1.0f, 0.0f, 0.0f};
const int winW = 400, winH = 400;

void Reshape(int w, int h){
    float ratio = w * 1.0f / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void Rotation(){
    glRotatef(Zrotate[0], Zrotate[1], Zrotate[2], Zrotate[3]);
    glRotatef(Xrotate[0], Xrotate[1], Xrotate[2], Xrotate[3]);
}

void RenderScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, 0.0f, 0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.5f, 0.0f, 0.5f);
    glEnd();
    
    glPushMatrix();
    glLoadIdentity();
    Rotation();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.5f, 0.0f, 0.3f);
        glVertex3f(0.0f, -0.5f, 0.3f);
        glVertex3f(0.0f, 0.5f, 0.3f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnd();
    glPopMatrix();
    
    glutSwapBuffers();
}

void ProcessKeys(unsigned char key,int x,int y){
    switch(key){
        case 27:
            exit(0);
        case 'A':
        case 'a':
            Zrotate[0] += 10.0f;
            break;
        case 'D':
        case 'd':
            Zrotate[0] -= 10.0f;
            break;
        case 'W':
        case 'w':
            Xrotate[0] += 10.0f;
            break;
        case 'S':
        case 's':
            Xrotate[0] -= 10.0f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 0.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE); //Anitaliasing
    //Z Buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(winW, winH);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutCreateWindow("Triangle sample");
    init();
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(ProcessKeys);
    glutMainLoop();
    return 0;
}
