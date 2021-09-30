#include <bits/stdc++.h>
using namespace std;

class NPC
{
private:
    int pos;
    int speed;
    string name;

public:
    NPC(string _name, int _speed);
    ~NPC();
    void move();
    void display();
};

NPC::NPC(string _name, int _speed) : name(_name), speed(_speed)
{
    pos = 0;
}

NPC::~NPC()
{
}

void NPC::move()
{
    pos += speed;
    return;
}

void NPC::display()
{
    cout << name << ".pos=" << pos << endl;
}

int main()
{
    NPC *npc0 = new NPC("npc0", 1);
    NPC *npc1 = new NPC("npc1", 2);
    NPC *npc2 = new NPC("npc2", -1);
    NPC *npc3 = new NPC("npc3", -2);
    NPC *npc4 = new NPC("npc4", 10);

    for (int i = 0; i < 5; i++)
    {
        npc0->move();
        npc1->move();
        npc2->move();
        npc3->move();
        npc4->move();
    }

    npc0->display();
    npc1->display();
    npc2->display();
    npc3->display();
    npc4->display();

    delete[] npc0;
    delete[] npc1;
    delete[] npc2;
    delete[] npc3;
    delete[] npc4;

    return 0;
}