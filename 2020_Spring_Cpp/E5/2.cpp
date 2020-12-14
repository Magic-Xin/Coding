#include <bits/stdc++.h>
using namespace std;

class Image
{
protected:
    int weight, height;
    char *buf;

public:
    void virtual Create(int, int) = 0;
    Image();
};

class GrayImage : public Image
{
public:
    GrayImage();
    void Create(int, int);
};

class RGBImage : public Image
{
public:
    RGBImage();
    void Create(int, int);
};

Image::Image()
{
    weight = 0;
    height = 0;
    buf = 0;
}
GrayImage::GrayImage()
{
}
RGBImage::RGBImage()
{
}
void GrayImage::Create(int w, int h)
{
    weight = w;
    height = h;
    buf = new char[w * h];
}
void RGBImage::Create(int w, int h)
{
    weight = w;
    height = h;
    buf = new char[w * h * 3];
}

int main()
{
    GrayImage g;
    RGBImage r;
    g.Create(640, 480);
    r.Create(640, 480);
    return 0;
}