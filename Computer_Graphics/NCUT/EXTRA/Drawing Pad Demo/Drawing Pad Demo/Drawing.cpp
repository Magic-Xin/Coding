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
    drawMode = 0;
    fillMode = 0;
    polystate = 0;
    linestate = 0;
    size = 1.0f;
    color.r = color.g = color.b = 1.0f;
    bgcolor.r = bgcolor.g = bgcolor.b = 0.0f;
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

void Drawing::drawLines()
{
    for (auto i : lines)
    {
        if (i.color == bgcolor)
            continue;
        glLineWidth(i.size);
        glColor3f(i.color.r, i.color.g, i.color.b);
        glBegin(GL_LINES);
        glVertex2f(i.x_s, i.y_s);
        glVertex2f(i.x_e, i.y_e);
        glEnd();
    }
}

void Drawing::drawPolygons()
{
    for (auto i : polygons)
    {
        glColor3f(i.color.r, i.color.g, i.color.b);
        std::vector<std::pair<int, int>> p = i.pos;
        if (p.size() == 2)
        {
            glBegin(GL_LINES);
            glVertex2f(p[0].first, p[0].second);
            glVertex2f(p[1].first, p[1].second);
            glEnd();
        }
        else
        {
            if (!i.fillMode)
            {
                glLineWidth(i.size);
                glBegin(GL_LINE_LOOP);
            }
            else
                glBegin(GL_POLYGON);
            for (auto j : p)
            {
                glVertex2f(j.first, j.second);
            }
            glEnd();
        }
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

extern "C" void fillModeMenuCallback(int value)
{
    Callback->ProcessFillModeMenu(value);
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
    drawLines();
    drawPolygons();
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
    switch (drawMode)
    {
    case 0:
    {
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
        break;
    }
    case 1:
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            Lines line;
            line.x_s = x;
            line.y_s = winH - y;
            line.size = size;
            line.color = color;
            lines.push_back(line);
            linestate = 1;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            linestate = 0;
            lines.back().x_e = x;
            lines.back().y_e = winH - y;
            glutPostRedisplay();
        }
        break;
    }
    case 2:
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            std::pair<int, int> p;
            p = std::make_pair(x, winH - y);
            if (!polystate)
            {
                Polygons polygon;
                polygon.pos.push_back(p);
                polygon.pos.push_back(p);
                polygon.color = color;
                polygon.size = size;
                polygon.fillMode = fillMode;
                polygons.push_back(polygon);
                polystate = 1;
            }
            else
            {
                polygons.back().pos.push_back(p);
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            std::pair<int, int> p;
            p = std::make_pair(x, winH - y);
            polygons.back().pos.pop_back();
            polygons.back().pos.push_back(p);
        }
        if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        {
            polystate = 0;
            glutPostRedisplay();
        }
        break;
    }
    default:
        break;
    }
}

void Drawing::ProcessMotion(int x, int y)
{
    switch (drawMode)
    {
    case 0:
        break;
    case 1:
    {
        if (linestate)
        {
            lines.back().x_e = x;
            lines.back().y_e = winH - y;
        }
        break;
    }
    case 2:
    {
        if (polystate)
        {
            std::pair<int, int> p;
            p = std::make_pair(x, winH - y);
            polygons.back().pos.pop_back();
            polygons.back().pos.push_back(p);
        }
        break;
    }
    default:
        break;
    }
    glutPostRedisplay();
}

void Drawing::ProcessMenu(int value)
{
    switch (value)
    {
    case -1:
    {
        switch (drawMode)
        {
        case 0:
        {
            if (!points.empty())
                points.pop_back();
            break;
        }
        case 1:
        {
            if (!lines.empty())
                lines.pop_back();
            break;
        }
        case 2:
        {
            if (!polygons.empty())
            {
                polygons.pop_back();
                polystate = 0;
            }
        }
        default:
            break;
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
    switch (value)
    {
    case 0:
    {
        color.r = color.g = color.b = 1.0f;
        break;
    }
    case 1:
    {
        color.r = color.g = color.b = 0.0f;
        break;
    }
    case 2:
    {
        color.r = 1.0f;
        color.g = color.b = 0.0f;
        break;
    }
    case 3:
    {
        color.g = 1.0f;
        color.r = color.b = 0.0f;
        break;
    }
    case 4:
    {
        color.b = 1.0f;
        color.r = color.g = 0.0f;
        break;
    }
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
    switch (value)
    {
    case 0:
    {
        bgcolor.r = bgcolor.g = bgcolor.b = 1.0f;
        break;
    }
    case 1:
    {
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
    size = (float)value;
}

void Drawing::ProcessFillModeMenu(int value)
{
    fillMode = value;
}

void Drawing::createMenu()
{
    ::Callback = this;
    int Menu, colorMenu, modeMenu, bgMenu, sizeMenu, fillModeMenu;

    colorMenu = ::glutCreateMenu(::colorMenuCallback);
    glutAddMenuEntry("白色", 0);
    glutAddMenuEntry("黑色", 1);
    glutAddMenuEntry("红色", 2);
    glutAddMenuEntry("绿色", 3);
    glutAddMenuEntry("蓝色", 4);

    modeMenu = ::glutCreateMenu(::modeMenuCallback);
    glutAddMenuEntry("点", 0);
    glutAddMenuEntry("直线", 1);
    glutAddMenuEntry("多边形（鼠标中键停止）", 2);

    bgMenu = ::glutCreateMenu(::bgMenuCallback);
    glutAddMenuEntry("白色", 0);
    glutAddMenuEntry("黑色", 1);

    sizeMenu = ::glutCreateMenu(::sizeMenuCallback);
    for (int i = 1; i < 10; i++)
    {
        char label[] = "0";
        label[0] += i;
        const char *ptr = label;
        glutAddMenuEntry(ptr, i);
    }

    fillModeMenu = ::glutCreateMenu(::fillModeMenuCallback);
    glutAddMenuEntry("无填充", 0);
    glutAddMenuEntry("纯色填充", 1);

    Menu = ::glutCreateMenu(::MenuCallback);
    glutAddSubMenu("背景颜色", bgMenu);
    glutAddSubMenu("画笔颜色", colorMenu);
    glutAddSubMenu("画笔大小", sizeMenu);
    glutAddSubMenu("多边形填充方式", fillModeMenu);
    glutAddSubMenu("绘画图形", modeMenu);
    glutAddMenuEntry("撤销", -1);
    glutAddMenuEntry("退出", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
