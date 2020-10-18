#include <iostream>
using namespace std;
class Shape
{
public:
    virtual ~Shape() {}
    virtual void printArea() const = 0;
    double R;
    Shape(double r) : R(r) {}
};
class Circle : public Shape
{
private:
    static double pi;

public:
    Circle(double r) : Shape(r) {}
    void printArea() const
    {
        cout << pi * R * R << endl;
    }
};
double Circle::pi = 3.14;

class Square : public Shape
{
private:
    ;

public:
    Square(double r) : Shape(r) {}
    void printArea() const
    {
        cout << R * R << endl;
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
        cout << len * R << endl;
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
