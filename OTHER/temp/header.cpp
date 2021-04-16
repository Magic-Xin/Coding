//
// Created by MagicXin on 2021/4/15.
//

#include "header.h"
Object::Object(int _loc, int _size, int _moves, int _HP) {
    location = _loc;
    size = _size;
    movespeed = _moves;
    HP = _HP;
}
void Object::move() {
    char ch;
    ch = getchar();
    while (ch != '$') {
        if (ch == 's') {
            location = location - 1;
        }
        else if (ch == 'a') {
            location = location + 1;
        }
        else
        {
            location =location;
        }
        ch = getchar();
    }


}
void Object::HPminus(){
    HP--;
}
void Object::HPplus() {
    HP++;
}

void Tank::fire() {
    bullet--;
}