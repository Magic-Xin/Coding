#include <bits/stdc++.h>
using namespace std;

class Image
{
protected:
    int w, h;
    char *buf;

public:
    void virtual Create(int width, int height) = 0;
    Image();
};

class GrayImage : public Image
{
public:
    GrayImage();
    void Create(int width, int height);
};

class RGBImage : public Image
{
public:
    RGBImage();
    void Create(int width, int height);
};

class XRGBImage : public Image
{
public:
    XRGBImage();
    void Create(int width, int height);
};

Image::Image()
{
    w = 0;
    h = 0;
    buf = 0;
}
GrayImage::GrayImage()
{
}
RGBImage::RGBImage()
{
}
XRGBImage::XRGBImage()
{
}
void GrayImage::Create(int width, int height)
{
    w = width;
    h = height;
    buf = new char[width * height];
}
void RGBImage::Create(int width, int height)
{
    w = width;
    h = height;
    buf = new char[width * height * 3];
}
void XRGBImage::Create(int width, int height)
{
    w = width;
    h = height;
    buf = new char[width * height * 4];
}

int main()
{
    GrayImage g;
    RGBImage r;
    XRGBImage x;
    g.Create(640, 480);
    r.Create(640, 480);
    x.Create(640, 480);
    return 0;
}