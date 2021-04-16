//
// Created by MagicXin on 2021/4/15.
//

#ifndef TEMP_HEADER_H
#define TEMP_HEADER_H
#include <iostream>
class Object {
public:
    Object();
    //~Object();
    Object(int _loc, int _size, int _moves, int _HP);
    void move();
    void HPminus();
    void HPplus();

private:
    int location;
    int size;
    int movespeed;
    int HP;

};

class Tank:public Object {
public:
    Tank(){};
    ~Tank();
    void fire();
    int bullet=35;

};
#endif //TEMP_HEADER_H
