//
//  Drawing.cpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#include "Drawing.hpp"

Drawing::Drawing(int argc, char *argv[])
{
    glutInit(&argc, argv);
    winW = 0;
    winH = 0;
    size = 1.0f;
    color.r = color.g = color.b = 1.0f;
    bgcolor.r = bgcolor.g = bgcolor.b = 0.0f;
    filePath = getcwd(NULL, 0);
    filePath += "/Data";
    std::cout << filePath << std::endl;
}

void Drawing::init(const char *title, int w, int h)
{
    winW = w;
    winH = h;
    glutInitWindowSize(winW, winH);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutCreateWindow(title);
    setupCallback();
    glutMainLoop();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 400, 0, 400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
#ifdef __APPLE__
    glEnable(GL_MULTISAMPLE);
#endif
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Drawing::drawPoints()
{
    for (auto i : points)
    {
        if (i.color == bgcolor)
            continue;
        glPointSize(i.size);
        glColor3f(i.color.r, i.color.g, i.color.b);
        glBegin(GL_POINTS);
        glVertex2f(i.x, i.y);
        glEnd();
    }
}

Drawing *Callback;

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

extern "C" void bgMenuCallback(int value)
{
    Callback->ProcessBGMenu(value);
}

extern "C" void sizeMenuCallback(int value)
{
    Callback->ProcessSizeMenu(value);
}

extern "C" void slMenuCallback(int value)
{
    Callback->ProcessSLMenu(value);
}

extern "C" void MouseCallback(int button, int state, int x, int y)
{
    Callback->ProcessMouse(button, state, x, y);
}

void Drawing::setupCallback()
{
    ::Callback = this;
    ::glutDisplayFunc(::RenderCallback);
    ::glutReshapeFunc(::ReshapeCallback);
    createMenu();
    ::glutMouseFunc(::MouseCallback);
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
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        Points point;
        point.x = x;
        point.y = winH - y;
        point.size = size;
        point.color = color;
        points.push_back(point);
        glutPostRedisplay();
    }
}

void Drawing::ProcessMenu(int value)
{
    switch (value)
    {
        case -1:
        {
            if (!points.empty())
            {
                points.pop_back();
            }
            glutPostRedisplay();
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
            break;
    }
}

void Drawing::ProcessColorMenu(int value)
{
    glutChangeToMenuEntry(1, "白色", 1);
    glutChangeToMenuEntry(2, "黑色", 2);
    glutChangeToMenuEntry(3, "红色", 3);
    glutChangeToMenuEntry(4, "绿色", 4);
    glutChangeToMenuEntry(5, "蓝色", 5);
    switch (value)
    {
    case 1:
    {
        glutChangeToMenuEntry(1, "白色<-", 1);
        color.r = color.g = color.b = 1.0f;
        break;
    }
    case 2:
    {
        glutChangeToMenuEntry(2, "黑色<-", 2);
        color.r = color.g = color.b = 0.0f;
        break;
    }
    case 3:
    {
        glutChangeToMenuEntry(3, "红色<-", 3);
        color.r = 1.0f;
        color.g = color.b = 0.0f;
        break;
    }
    case 4:
    {
        glutChangeToMenuEntry(4, "绿色<-", 4);
        color.g = 1.0f;
        color.r = color.b = 0.0f;
        break;
    }
    case 5:
    {
        glutChangeToMenuEntry(5, "蓝色<-", 5);
        color.b = 1.0f;
        color.r = color.g = 0.0f;
        break;
    }
    default:
        break;
    }
}

void Drawing::ProcessBGMenu(int value)
{
    switch (value)
    {
    case 1:
    {
        glutChangeToMenuEntry(1, "白色<-", 1);
        glutChangeToMenuEntry(2, "黑色", 2);
        bgcolor.r = bgcolor.g = bgcolor.b = 1.0f;
        break;
    }
    case 2:
    {
        glutChangeToMenuEntry(1, "白色", 1);
        glutChangeToMenuEntry(2, "黑色<-", 2);
        bgcolor.r = bgcolor.g = bgcolor.b = 0.0f;
        break;
    }
    default:
        break;
    }
    glClearColor(bgcolor.r, bgcolor.g, bgcolor.b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}

void Drawing::ProcessSizeMenu(int value)
{
    for (int i = 1; i < 10; i++)
    {
        char label[] = "0";
        label[0] += i;
        const char *ptr = label;
        glutChangeToMenuEntry(i, ptr, i);
    }
    char label[] = "0<-";
    label[0] += value;
    const char* ptr = label;
    glutChangeToMenuEntry(value, ptr, value);
    size = (float)value;
}

void Drawing::ProcessSLMenu(int value)
{
    if(!value)
    {
        std::ofstream ofile(filePath.c_str(), std::ios::binary);
        if(ofile.is_open() == false){
            std::cout << "Open file fail!" << std::endl;
            return;
        }
        ofile.write((char*)&verify, sizeof(int));
        unsigned long Vlength = points.size();
        ofile.write((char*)&Vlength, sizeof(unsigned long));
        unsigned long Vsize = points.size()*sizeof(Points);
        ofile.write((char*)&Vsize, sizeof(unsigned long));
        ofile.write((char*)&points[0], Vsize);
        ofile.write((char*)&verify, sizeof(int));
        ofile.close();
        std::cout << "Write succeed!" << std::endl;
    }
    else
    {
        std::ifstream ifile(filePath.c_str(), std::ios::binary);
        int tempVerify;
        unsigned long Vlength, Vsize;
        ifile.read((char*)&tempVerify, sizeof(int));
        if(tempVerify != verify)
        {
            std::cout << "Unknow format!" << std::endl;
            return;
        }
        ifile.read((char*)&Vlength, sizeof(unsigned long));
        ifile.read((char*)&Vsize, sizeof(unsigned long));
        points.clear();
        points.resize(Vlength);
        ifile.read((char*)&points[0], Vsize);
        ifile.read((char*)&tempVerify, sizeof(int));
        if(tempVerify != verify)
        {
            std::cout << "Unknow format!" << std::endl;
            return;
        }
        std::cout << "Read succeed!" << std::endl;
        glutPostRedisplay();
    }
}

void Drawing::createMenu()
{
    ::Callback = this;
    int Menu, colorMenu, bgMenu, sizeMenu, slMenu;

    colorMenu = ::glutCreateMenu(::colorMenuCallback);
    glutAddMenuEntry("白色<-", 1);
    glutAddMenuEntry("黑色", 2);
    glutAddMenuEntry("红色", 3);
    glutAddMenuEntry("绿色", 4);
    glutAddMenuEntry("蓝色", 5);

    bgMenu = ::glutCreateMenu(::bgMenuCallback);
    glutAddMenuEntry("白色", 1);
    glutAddMenuEntry("黑色<-", 2);

    sizeMenu = ::glutCreateMenu(::sizeMenuCallback);
    for (int i = 1; i < 10; i++)
    {
        char label[] = "0";
        label[0] += i;
        const char *ptr = label;
        glutAddMenuEntry(ptr, i);
    }
    glutChangeToMenuEntry(1, "1<-", 1);
    
    slMenu = ::glutCreateMenu(::slMenuCallback);
    glutAddMenuEntry("保存", 0);
    glutAddMenuEntry("载入", 1);

    Menu = ::glutCreateMenu(::MenuCallback);
    glutAddSubMenu("背景颜色", bgMenu);
    glutAddSubMenu("画笔颜色", colorMenu);
    glutAddSubMenu("画笔大小", sizeMenu);
    glutAddSubMenu("保存/载入", slMenu);
    glutAddMenuEntry("撤销", -1);
    glutAddMenuEntry("退出", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
