//
//  Drawing.hpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#ifndef Drawing_hpp
#define Drawing_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#include <GL/glut.h>
#endif
#include <cstdlib>
#include <vector>

class Drawing
{
private:
    struct Color
    {
        float r, g, b;
        bool operator==(const Color b) const
        {
            return this->r == b.r && this->g == b.g && this->b == b.b;
        }
    };
    
    struct Points
    {
        int x, y, size;
        Color color;
    };
    
    struct Lines
    {
        int x_s, y_s, x_e, y_e, size;
        Color color;
    };
    
    int winW, winH;
    int drawMode;
    float size;
    Color color, bgcolor;
    
    std::vector<Points> points;
    std::vector<Lines>  lines;
    
    void setupCallback();
    void createMenu();
    void drawPoints();
    void drawLines();
public:
    Drawing(int argc, char * argv[]);
    void init(const char* title, int w, int h);
    
    void RenderScene();
    void Reshape(int w, int h);
    void ProcessMenu(int value);
    void ProcessColorMenu(int value);
    void ProcessModeMenu(int value);
    void ProcessBGMenu(int value);
    void ProcessSizeMenu(int value);
    void ProcessMouse(int button, int state, int x, int y);
    void ProcessMotion(int x, int y);
};

#endif /* Drawing_hpp */
