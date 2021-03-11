//
//  main.cpp
//  Test1
//
//  Created by MagicXin on 2021/3/3.
//
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif //引入头文件

void RenderScene(){
    glClear(GL_COLOR_BUFFER_BIT); //清除颜色缓冲
    glRectf(-0.5, -0.5, 0.5, 0.5); //通过坐标绘制矩形
    glFlush(); //刷新缓冲
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv); //GLUT 初始化
    glutCreateWindow("Simple"); //创建窗口
    glutDisplayFunc(RenderScene); //注册绘图函数
    glutMainLoop(); //进入 GLUT 主循环
    return 0;
}
