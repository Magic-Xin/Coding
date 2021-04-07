//
//  Drawing.cpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#include "Drawing.hpp"

#define FILL 1
#define NOFILL 2
#define PI 3.14159265

Drawing::Drawing(int argc, char *argv[]) {
    glutInit(&argc, argv);
    winW = 0;
    winH = 0;
    size = 1;
    drawMode = 1;
    fillMode = FILL;
    linestate = 0;
    rectstate = 0;
    circlestate = 0;
    ovalstate = 0;
    color.r = color.g = color.b = 1.0f;
    bgcolor.r = bgcolor.g = bgcolor.b = 0.0f;
    filePath = getcwd(NULL, 0);
    filePath += "/Data";
    std::cout << filePath << std::endl;
}

void Drawing::init(const char *title, int w, int h) {
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

void Drawing::drawPoints() {
    for (auto i : points) {
        if (i.color == bgcolor)
            continue;
        glPointSize(i.size);
        glColor3f(i.color.r, i.color.g, i.color.b);
        glBegin(GL_POINTS);
        glVertex2f(i.x, i.y);
        glEnd();
    }
}

void Drawing::drawLines() {
    for (auto i : lines) {
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

void Drawing::drawRects() {
    for (auto i : rects) {
        if (i.color == bgcolor)
            continue;
        if (i.fillmode == NOFILL) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glLineWidth(i.size);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        glColor3f(i.color.r, i.color.g, i.color.b);
        glRecti(i.x_s, i.y_s, i.x_e, i.y_e);
    }
}

void Drawing::drawCircles() {
    for (auto i : circles) {
        if (i.color == bgcolor)
            continue;
        if (i.fillmode == NOFILL) {
            glBegin(GL_LINE_LOOP);
            glLineWidth(i.size);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glBegin(GL_POLYGON);
        }
        float radius = std::sqrt(
                std::pow(((float) i.x_s - (float) i.x_e), 2) + std::pow(((float) i.y_s - (float) i.y_e), 2));
        glColor3f(i.color.r, i.color.g, i.color.b);
        for (int j = 0; j < 100; j++) {
            float a = 2.0f * PI * (float) j / 100.0f;

            float dx = radius * std::cos(a);
            float dy = radius * std::sin(a);

            glVertex2f(i.x_s + dx, i.y_s + dy);
        }
        glEnd();
    }
}

void Drawing::drawOvals() {
    for (auto i : ovals) {
        if (i.color == bgcolor)
            continue;
        if (i.fillmode == NOFILL) {
            glBegin(GL_LINE_LOOP);
            glLineWidth(i.size);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glBegin(GL_POLYGON);
        }
        glColor3f(i.color.r, i.color.g, i.color.b);
        for (int j = 0; j < 100; j++) {
            float a = 2.0f * PI * (float) j / 100.0f;

            float dx, dy;
            if(ovalstate == 1 || ovalstate == 2) {
                dx = i.a * std::cos(a);
                dy = i.a * std::sin(a);
            }
            else {
                dx = i.a * std::cos(a);
                dy = i.b * std::sin(a);
            }

            glVertex2f(i.x + dx, i.y + dy);
        }
        glEnd();
    }
}

Drawing *Callback;

extern "C" void RenderCallback() {
    Callback->RenderScene();
}

extern "C" void ReshapeCallback(int w, int h) {
    Callback->Reshape(w, h);
}

extern "C" void MenuCallback(int value) {
    Callback->ProcessMenu(value);
}

extern "C" void colorMenuCallback(int value) {
    Callback->ProcessColorMenu(value);
}

extern "C" void bgMenuCallback(int value) {
    Callback->ProcessBGMenu(value);
}

extern "C" void sizeMenuCallback(int value) {
    Callback->ProcessSizeMenu(value);
}

extern "C" void slMenuCallback(int value) {
    Callback->ProcessSLMenu(value);
}

extern "C" void fillModeMenuCallback(int value) {
    Callback->ProcessFillModeMenu(value);
}

extern "C" void modeMenuCallback(int value) {
    Callback->ProcessModeMenu(value);
}

extern "C" void MouseCallback(int button, int state, int x, int y) {
    Callback->ProcessMouse(button, state, x, y);
}

extern "C" void MotionCallback(int x, int y) {
    Callback->ProcessMotion(x, y);
}

void Drawing::setupCallback() {
    ::Callback = this;
    ::glutDisplayFunc(::RenderCallback);
    ::glutReshapeFunc(::ReshapeCallback);
    createMenu();
    ::glutMouseFunc(::MouseCallback);
    ::glutMotionFunc(::MotionCallback);
}

void Drawing::RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPoints();
    drawLines();
    drawRects();
    drawCircles();
    drawOvals();
    glutSwapBuffers();
}

void Drawing::Reshape(int w, int h) {
    winW = w;
    winH = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, winW, winH);
    gluOrtho2D(0, winW, 0, winH);
}

void Drawing::ProcessMouse(int button, int state, int x, int y) {
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    switch (drawMode) {
        case 1: {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
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
        case 2: {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
                Lines line;
                line.x_s = x;
                line.y_s = winH - y;
                line.size = size;
                line.color = color;
                lines.push_back(line);
                linestate = 1;
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                linestate = 0;
                lines.back().x_e = x;
                lines.back().y_e = winH - y;
                glutPostRedisplay();
            }
            break;
        }
        case 3: {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
                Rectangles rect;
                rect.x_s = x;
                rect.y_s = winH - y;
                rect.color = color;
                rect.size = size;
                rect.fillmode = fillMode;
                rects.push_back(rect);
                rectstate = 1;
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                rectstate = 0;
                rects.back().x_e = x;
                rects.back().y_e = winH - y;
                glutPostRedisplay();
            }
            break;
        }
        case 4: {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
                Circles circle;
                circle.x_s = x;
                circle.y_s = winH - y;
                circle.color = color;
                circle.size = size;
                circle.fillmode = fillMode;
                circles.push_back(circle);
                circlestate = 1;
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                circlestate = 0;
                circles.back().x_e = x;
                circles.back().y_e = winH - y;
                glutPostRedisplay();
            }
            break;
        }
        case 5: {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !ovalstate) {
                Ovals oval;
                oval.x = x;
                oval.y = winH - y;
                oval.color = color;
                oval.size = size;
                oval.fillmode = fillMode;
                ovals.push_back(oval);
                ovalstate = 1;
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && ovalstate == 1) {
                ovalstate = 2;
                ovals.back().a = std::sqrt(
                        std::pow((x - ovals.back().x), 2) + std::pow((winH - y - ovals.back().y), 2));
                glutPostRedisplay();
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ovalstate == 2) {
                ovalstate = 3;
                glutPostRedisplay();
            }
            if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && ovalstate == 3) {
                ovalstate = 0;
                ovals.back().b = std::sqrt(
                        std::pow((x - ovals.back().x), 2) + std::pow((winH - y - ovals.back().y), 2));
                glutPostRedisplay();
            }
        }
    }
}

void Drawing::ProcessMotion(int x, int y) {
    switch (drawMode) {
        case 1:
            break;
        case 2: {
            if (linestate) {
                lines.back().x_e = x;
                lines.back().y_e = winH - y;
            }
            break;
        }
        case 3: {
            if (rectstate) {
                rects.back().x_e = x;
                rects.back().y_e = winH - y;
            }
            break;
        }
        case 4: {
            if (circlestate) {
                circles.back().x_e = x;
                circles.back().y_e = winH - y;
            }
            break;
        }
        case 5: {
            if (ovalstate == 1) {
                ovals.back().a = std::sqrt(
                        std::pow((x - ovals.back().x), 2) + std::pow((winH - y - ovals.back().y), 2));
            }
            if (ovalstate == 3) {
                ovals.back().b = std::sqrt(
                        std::pow((x - ovals.back().x), 2) + std::pow((winH - y - ovals.back().y), 2));
            }
            break;
        }
    }
    glutPostRedisplay();
}

void Drawing::ProcessMenu(int value) {
    switch (value) {
        case -1: {
            switch (drawMode) {
                case 1: {
                    if (!points.empty()) {
                        points.pop_back();
                    }
                    glutPostRedisplay();
                    break;
                }
                case 2: {
                    if (!lines.empty()) {
                        lines.pop_back();
                    }
                    glutPostRedisplay();
                    break;
                }
                case 3: {
                    if (!rects.empty()) {
                        rects.pop_back();
                    }
                    glutPostRedisplay();
                    break;
                }
                case 4: {
                    if (!circles.empty()) {
                        circles.pop_back();
                    }
                    glutPostRedisplay();
                    break;
                }
                case 5: {
                    if (!ovals.empty()) {
                        ovals.pop_back();
                    }
                    glutPostRedisplay();
                    break;
                }
            }
            break;
        }
        case 0: {
            exit(0);
        }
        default:
            break;
    }
}

void Drawing::ProcessColorMenu(int value) {
    glutChangeToMenuEntry(1, "白色", 1);
    glutChangeToMenuEntry(2, "黑色", 2);
    glutChangeToMenuEntry(3, "红色", 3);
    glutChangeToMenuEntry(4, "绿色", 4);
    glutChangeToMenuEntry(5, "蓝色", 5);
    switch (value) {
        case 1: {
            glutChangeToMenuEntry(1, "白色<-", 1);
            color.r = color.g = color.b = 1.0f;
            break;
        }
        case 2: {
            glutChangeToMenuEntry(2, "黑色<-", 2);
            color.r = color.g = color.b = 0.0f;
            break;
        }
        case 3: {
            glutChangeToMenuEntry(3, "红色<-", 3);
            color.r = 1.0f;
            color.g = color.b = 0.0f;
            break;
        }
        case 4: {
            glutChangeToMenuEntry(4, "绿色<-", 4);
            color.g = 1.0f;
            color.r = color.b = 0.0f;
            break;
        }
        case 5: {
            glutChangeToMenuEntry(5, "蓝色<-", 5);
            color.b = 1.0f;
            color.r = color.g = 0.0f;
            break;
        }
        default:
            break;
    }
}

void Drawing::ProcessBGMenu(int value) {
    switch (value) {
        case 1: {
            glutChangeToMenuEntry(1, "白色<-", 1);
            glutChangeToMenuEntry(2, "黑色", 2);
            bgcolor.r = bgcolor.g = bgcolor.b = 1.0f;
            break;
        }
        case 2: {
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

void Drawing::ProcessSizeMenu(int value) {
    for (int i = 1; i < 10; i++) {
        char label[] = "0";
        label[0] += i;
        const char *ptr = label;
        glutChangeToMenuEntry(i, ptr, i);
    }
    char label[] = "0<-";
    label[0] += value;
    const char *ptr = label;
    glutChangeToMenuEntry(value, ptr, value);
    size = (float) value;
}

void Drawing::ProcessSLMenu(int value) {
    if (!value) {
        std::ofstream ofile(filePath.c_str(), std::ios::binary);
        if (ofile.is_open() == false) {
            std::cout << "Open file fail!" << std::endl;
            return;
        }
        ofile.write((char *) &verify, sizeof(int));
        unsigned long Vlength = points.size();
        ofile.write((char *) &Vlength, sizeof(unsigned long));
        unsigned long Vsize = points.size() * sizeof(Points);
        ofile.write((char *) &Vsize, sizeof(unsigned long));
        ofile.write((char *) &points[0], Vsize);
        ofile.write((char *) &verify, sizeof(int));
        ofile.close();
        std::cout << "Write succeed!" << std::endl;
    } else {
        std::ifstream ifile(filePath.c_str(), std::ios::binary);
        int tempVerify;
        unsigned long Vlength, Vsize;
        ifile.read((char *) &tempVerify, sizeof(int));
        if (tempVerify != verify) {
            std::cout << "Unknow format!" << std::endl;
            return;
        }
        ifile.read((char *) &Vlength, sizeof(unsigned long));
        ifile.read((char *) &Vsize, sizeof(unsigned long));
        points.clear();
        points.resize(Vlength);
        ifile.read((char *) &points[0], Vsize);
        ifile.read((char *) &tempVerify, sizeof(int));
        if (tempVerify != verify) {
            std::cout << "Unknow format!" << std::endl;
            return;
        }
        std::cout << "Read succeed!" << std::endl;
        glutPostRedisplay();
    }
}

void Drawing::ProcessFillModeMenu(int value) {
    glutChangeToMenuEntry(1, "实色填充", FILL);
    glutChangeToMenuEntry(2, "无填充", NOFILL);
    switch (value) {
        case 1: {
            glutChangeToMenuEntry(1, "实色填充<-", FILL);
            break;
        }
        case 2: {
            glutChangeToMenuEntry(2, "无填充<-", NOFILL);
        }
    }
    fillMode = value;
}


void Drawing::ProcessModeMenu(int value) {
    glutChangeToMenuEntry(1, "点", 1);
    glutChangeToMenuEntry(2, "直线", 2);
    glutChangeToMenuEntry(3, "矩形", 3);
    glutChangeToMenuEntry(4, "圆", 4);
    glutChangeToMenuEntry(5, "椭圆", 5);
    switch (value) {
        case 1: {
            glutChangeToMenuEntry(1, "点<-", 1);
            break;
        }
        case 2: {
            glutChangeToMenuEntry(2, "直线<-", 2);
            break;
        }
        case 3: {
            glutChangeToMenuEntry(3, "矩形<-", 3);
            break;
        }
        case 4: {
            glutChangeToMenuEntry(4, "圆<-", 4);
            break;
        }
        case 5: {
            glutChangeToMenuEntry(5, "椭圆<-", 5);
            break;
        }
    }
    drawMode = value;
}

void Drawing::createMenu() {
    ::Callback = this;
    int Menu, colorMenu, bgMenu, sizeMenu, slMenu, modeMenu, fillMenu;

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
    for (int i = 1; i < 10; i++) {
        char label[] = "0";
        label[0] += i;
        const char *ptr = label;
        glutAddMenuEntry(ptr, i);
    }
    glutChangeToMenuEntry(1, "1<-", 1);

    slMenu = ::glutCreateMenu(::slMenuCallback);
    glutAddMenuEntry("保存", 0);
    glutAddMenuEntry("载入", 1);

    fillMenu = ::glutCreateMenu(::fillModeMenuCallback);
    glutAddMenuEntry("实色填充<-", FILL);
    glutAddMenuEntry("无填充", NOFILL);

    modeMenu = ::glutCreateMenu(::modeMenuCallback);
    glutAddMenuEntry("点<-", 1);
    glutAddMenuEntry("直线", 2);
    glutAddMenuEntry("矩形", 3);
    glutAddMenuEntry("圆", 4);
    glutAddMenuEntry("椭圆", 5);

    Menu = ::glutCreateMenu(::MenuCallback);
    glutAddSubMenu("背景颜色", bgMenu);
    glutAddSubMenu("画笔颜色", colorMenu);
    glutAddSubMenu("画笔大小", sizeMenu);
    glutAddSubMenu("填充模式", fillMenu);
    glutAddSubMenu("图元模式", modeMenu);
    glutAddSubMenu("保存/载入", slMenu);
    glutAddMenuEntry("撤销", -1);
    glutAddMenuEntry("退出", 0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
