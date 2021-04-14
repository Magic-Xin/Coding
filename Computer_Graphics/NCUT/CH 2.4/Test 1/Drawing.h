//
//  Drawing.hpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#ifndef Drawing_h
#define Drawing_h

#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <cmath>

#ifdef __APPLE__

#include <GLUT/glut.h>

#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#include <GL/glut.h>
#endif

class Drawing {
private:
    struct Color {
        float r = 0.0f, g = 0.0f, b = 0.0f;

        bool operator==(const Color b) const {
            return this->r == b.r && this->g == b.g && this->b == b.b;
        }
    };

    struct Points {
        int x, y, size;
        Color color;
    };

    struct Lines {
        int x_s, y_s, x_e, y_e, size;
        Color color;
    };

    struct Rectangles {
        int x_s, y_s, x_e, y_e, size, fillmode;
        Color color;
    };

    struct Circles {
        int x_s, y_s, x_e, y_e, size, fillmode;
        Color color;
    };

    struct Ovals {
        int x, y, a = 0, b = 0, size, fillmode;
        Color color;
    };

    int winW, winH;
    int drawMode, fillMode, linestate, rectstate, circlestate, ovalstate, size;
    Color color, bgcolor;

    const int verify = 0x1a2b3c4d;
    std::string filePath;

    std::vector<Points> points;
    std::vector<Lines> lines;
    std::vector<Rectangles> rects;
    std::vector<Circles> circles;
    std::vector<Ovals> ovals;

    void setupCallback();

    void createMenu();

    void drawPoints();

    void drawLines();

    void drawRects();

    void drawCircles();

    void drawOvals();

public:
    Drawing(int argc, char *argv[]);

    void init(const char *title, int w, int h);

    void RenderScene();

    void Reshape(int w, int h);

    void ProcessMenu(int value);

    void ProcessSLMenu(int value);

    void ProcessColorMenu(int value);

    void ProcessBGMenu(int value);

    void ProcessSizeMenu(int value);

    void ProcessFillModeMenu(int value);

    void ProcessModeMenu(int value);

    void ProcessMouse(int button, int state, int x, int y);

    void ProcessMotion(int x, int y);
};

#endif /* Drawing_h */
