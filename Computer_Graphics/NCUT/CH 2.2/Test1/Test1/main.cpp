//
//  main.cpp
//  Drawing Pad Demo
//
//  Created by MagicXin on 2021/3/11.
//

#include "Drawing.hpp"

int main(int argc, char *argv[])
{
    Drawing d(argc, argv);
    d.init("CH03 Test1", 800, 800);
    return 0;
}