#include <iostream>

class Character
{
private:
    int pos = 0;
    int speed;

public:
    Character(int a) : speed(a) {}
    ~Character() {}
    void move()
    {
        pos += speed;
    }
    void show()
    {
        printf("%d\n", pos);
    }
};

int main()
{
    Character *npc1 = new Character(1);
    Character *npc2 = new Character(-1);
    Character *npc3 = new Character(2);
    Character *npc4 = new Character(-2);
    Character *npc5 = new Character(3);

    int n = 0;
    while (n < 5)
    {
        npc1->move();
        npc2->move();
        npc3->move();
        npc4->move();
        npc5->move();
        n++;
    }

    npc1->show();
    npc2->show();
    npc3->show();
    npc4->show();
    npc5->show();

    return 0;
}