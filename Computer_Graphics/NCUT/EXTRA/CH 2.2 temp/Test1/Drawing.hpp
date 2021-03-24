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
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <iostream>

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

    int winW, winH;
    float size;
    Color color, bgcolor;
    
    const int verify = 0x1a2b3c4d;
    std::string filePath;

    std::vector<Points> points;

    void setupCallback();
    void createMenu();
    void drawPoints();

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
    void ProcessMouse(int button, int state, int x, int y);
};

#endif /* Drawing_hpp */
