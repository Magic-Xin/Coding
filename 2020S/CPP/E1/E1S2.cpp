#include <bits/stdc++.h>
using namespace std;

class Char
{
private:
    int pos = 0;
    char move = 'n';
    int HP;
    int MP;

public:
    Char();
    ~Char();
    moveRight();
    moveLeft();
    show();
};

Char::Char()
{
}

Char::~Char()
{
}

Char::moveRight()
{
    pos++;
    move = 'r';
    return 0;
}

Char::moveLeft()
{
    pos--;
    move = 'l';
    return 0;
}

Char::show()
{
    cout << pos << " " << move << endl;
    return 0;
}

int main()
{
    Char Char1;
    char status;
    while (cin >> status)
    {
        if (status == 's' || status == 'S')
        {
            Char1.moveRight();
        }
        if (status == 'a' || status == 'A')
        {
            Char1.moveLeft();
        }
        Char1.show();
    }
    return 0;
}