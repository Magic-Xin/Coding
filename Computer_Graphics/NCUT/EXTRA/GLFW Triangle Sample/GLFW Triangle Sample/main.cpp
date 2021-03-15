//
//  main.cpp
//  GLFW Triangle Sample
//
//  Created by MagicXin on 2021/3/15.
//

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, const char * argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // insert code here...

    return 0;
}
