//
//  Drawing.hpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#ifndef Drawing_hpp
#define Drawing_hpp

#include <cstdlib>
#include <vector>
#include <utility>
#ifdef __APPLE__
#include <GLUT/glut.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#include <GL/glut.h>
#endif

class Drawing
{
private:
    struct Color
    {
        float r = 0.0f, g = 0.0f, b = 0.0f;
        bool operator==(const Color b) const
        {
            return this->r == b.r && this->g == b.g && this->b == b.b;
        }
    };

    struct Points
    {
        int x = 0, y = 0, size = 0;
        Color color;
    };

    struct Lines
    {
        int x_s = 0, y_s = 0, x_e = 0, y_e = 0, size = 0;
        Color color;
    };

    struct Polygons
    {
        std::vector<std::pair<int, int>> pos;
        int size = 0, fillMode = 0;
        Color color;
    };

    int winW, winH;
    int drawMode, fillMode, polystate, linestate;
    float size;
    Color color, bgcolor;

    std::vector<Points> points;
    std::vector<Lines> lines;
    std::vector<Polygons> polygons;

    void setupCallback();
    void createMenu();
    void drawPoints();
    void drawLines();
    void drawPolygons();

public:
    Drawing(int argc, char *argv[]);
    void init(const char *title, int w, int h);

    void RenderScene();
    void Reshape(int w, int h);
    void ProcessMenu(int value);
    void ProcessColorMenu(int value);
    void ProcessModeMenu(int value);
    void ProcessBGMenu(int value);
    void ProcessSizeMenu(int value);
    void ProcessFillModeMenu(int value);
    void ProcessMouse(int button, int state, int x, int y);
    void ProcessMotion(int x, int y);
};

#endif /* Drawing_hpp */
