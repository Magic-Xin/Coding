#include <iostream>
using namespace std;
class Shape
{
public:
    virtual ~Shape() {}
    virtual void printArea() const = 0;
    double Radius;
    Shape(double r) : Radius(r) {}
};
class Circle : public Shape
{
private:
    static double pi;

public:
    Circle(double r) : Shape(r) {}
    void printArea() const
    {
        cout << pi * Radius * Radius << endl;
    }
};
double Circle::pi = 3.1415926535898;

class Square : public Shape
{
private:
    ;

public:
    Square(double r) : Shape(r) {}
    void printArea() const
    {
        cout << Radius * Radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    double len;

public:
    Rectangle(double r, double _len) : Shape(r), len(_len) {}
    void printArea() const
    {
        cout << len * Radius << endl;
    }
};
int main()
{
    Shape *c = new Circle(2);
    Shape *s = new Square(3);
    Shape *r = new Rectangle(3, 4);
    c->printArea();
    s->printArea();
    r->printArea();
    delete c;
    delete s;
    delete r;
    return 0;
}
