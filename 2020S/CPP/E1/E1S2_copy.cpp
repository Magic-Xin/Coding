#include <iostream>
using namespace std;

class Character
{
private:
    int pos;
    int move;
    int HP;
    int MP;

public:
    Character()
    {
        pos = 0;
        move = 0;
    }
    void moveRight()
    {
        pos++;
        move = 1;
    }
    void moveLeft()
    {
        pos--;
        move = -1;
    }
    void show()
    {
        cout << pos << " " << move << endl;
    }
};

int main()
{
    Character C1;
    char status;
    while (cin >> status)
    {
        if (status == 's' || status == 'S')
        {
            C1.moveRight();
        }
        if (status == 'a' || status == 'A')
        {
            C1.moveLeft();
        }
        C1.show();
    }
    return 0;
}