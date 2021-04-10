//
// Created by MagicXin on 2021/4/9.
//

#ifndef PLYVISUALIZATION_READPLY_H
#define PLYVISUALIZATION_READPLY_H

#include "tinyply.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <cstring>

typedef struct {
    float x, y, z;
}
        float3;

void read_ply_file(const std::string filepath, std::vector<float3>& verts);

class manual_timer
{
    std::chrono::high_resolution_clock::time_point t0;
    double timestamp{ 0.0 };
public:
    void start();

    void stop();

    const double & get();
};

#endif //PLYVISUALIZATION_READPLY_H
