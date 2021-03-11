//
//  Drawing.cpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#include "Drawing.hpp"

Drawing::Drawing(int argc, char* argv[])
{
    glutInit(&argc, argv);
    winW = 0;
    winH = 0;
    drawMode = 0;
    size = 1.0f;
    color.r = color.g = color.b = 1.0f;
    bgcolor.r = bgcolor.g = bgcolor.b = 0.0f;
}

void Drawing::init(const char* title, int w, int h)
{
    winW = w;
    winH = h;
    glutInitWindowSize(winW, winH);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutCreateWindow(title);
    setupCallback();
    glutMainLoop();
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0,400,0,400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void Drawing::drawPoints()
{
    for(auto i:points){
        if(i.color == bgcolor) continue;
        glPointSize(i.size);
        glColor3f(i.color.r, i.color.g, i.color.b);
        glBegin(GL_POINTS);
        glVertex2f(i.x, winH-i.y);
        glEnd();
    }
    glutSwapBuffers();
}

Drawing* Callback;

extern "C" void RenderCallback()
{
    Callback->RenderScene();
}

extern "C" void ReshapeCallback(int w, int h)
{
    Callback->Reshape(w, h);
}

extern "C" void MenuCallback(int value)
{
    Callback->ProcessMenu(value);
}

extern "C" void colorMenuCallback(int value)
{
    Callback->ProcessColorMenu(value);
}

extern "C" void modeMenuCallback(int value)
{
    Callback->ProcessModeMenu(value);
}

extern "C" void bgMenuCallback(int value)
{
    Callback->ProcessBGMenu(value);
}

extern "C" void sizeMenuCallback(int value)
{
    Callback->ProcessSizeMenu(value);
}

extern "C" void MouseCallback(int button, int state, int x, int y)
{
    Callback->ProcessMouse(button, state, x, y);
}

extern "C" void MotionCallback(int x, int y)
{
    Callback->ProcessMotion(x, y);
}

void Drawing::setupCallback()
{
    ::Callback = this;
    ::glutDisplayFunc(::RenderCallback);
    ::glutReshapeFunc(::ReshapeCallback);
    createMenu();
    ::glutMouseFunc(::MouseCallback);
    ::glutMotionFunc(::MotionCallback);
}

void Drawing::RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPoints();
    glutSwapBuffers();
}

void Drawing::Reshape(int w, int h)
{
    winW = w;
    winH = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, winW, winH);
    gluOrtho2D(0, winW, 0, winH);
}

void Drawing::ProcessMouse(int button, int state, int x, int y)
{
    switch (drawMode) {
        case 0:
            if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
                Points point;
                point.x = x;
                point.y = y;
                point.size = size;
                point.color = color;
                points.push_back(point);
            }
            break;
        case 1:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                
            }
        default:
            break;
    }
    glutPostRedisplay();
}

void Drawing::ProcessMotion(int x, int y)
{
    switch (drawMode) {
        case 0:
            break;
        case 1:
            
        default:
            break;
    }
}

void Drawing::ProcessMenu(int value)
{
    switch (value) {
        case 0:
            exit(0);
            break;
        default:
            break;
    }
}

void Drawing::ProcessColorMenu(int value)
{
    switch (value) {
        case 0:
            color.r = color.g = color.b = 1.0f;
            break;
        case 1:
            color.r = color.g = color.b = 0.0f;
            break;
        case 2:
            color.r = 1.0f;
            color.g = color.b = 0.0f;
            break;
        case 3:
            color.g = 1.0f;
            color.r = color.b = 0.0f;
            break;
        case 4:
            color.b = 1.0f;
            color.r = color.g = 0.0f;
            break;
        default:
            break;
    }
}

void Drawing::ProcessModeMenu(int value)
{
    drawMode = value;
}

void Drawing::ProcessBGMenu(int value)
{
    switch (value) {
        case 0:
            bgcolor.r = bgcolor.g = bgcolor.b = 1.0f;
            break;
        case 1:
            bgcolor.r = bgcolor.g = bgcolor.b = 0.0f;
        default:
            break;
    }
    glClearColor(bgcolor.r, bgcolor.g, bgcolor.b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}

void ProcessSizeMenu(int value)
{
    
}

void Drawing::createMenu()
{
    ::Callback = this;
    int Menu, colorMenu, modeMenu, bgMenu, sizeMenu;
    
    colorMenu = ::glutCreateMenu(::colorMenuCallback);
    glutAddMenuEntry("白色", 0);
    glutAddMenuEntry("黑色", 1);
    glutAddMenuEntry("红色", 2);
    glutAddMenuEntry("绿色", 3);
    glutAddMenuEntry("蓝色", 4);
    
    modeMenu = ::glutCreateMenu(::modeMenuCallback);
    glutAddMenuEntry("点", 0);
    glutAddMenuEntry("直线", 1);
    glutAddMenuEntry("三角形", 2);
    
    bgMenu = ::glutCreateMenu(::bgMenuCallback);
    glutAddMenuEntry("白色", 0);
    glutAddMenuEntry("黑色", 1);
    
    sizeMenu = ::glutCreateMenu(::sizeMenuCallback);
    for(int i = 1 ; i <= 10 ; i++)
    {
    }
    
    Menu = ::glutCreateMenu(::MenuCallback);
    glutAddSubMenu("背景颜色", bgMenu);
    glutAddSubMenu("画笔颜色", colorMenu);
    glutAddSubMenu("绘画图形", modeMenu);
    glutAddMenuEntry("退出", 0);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
