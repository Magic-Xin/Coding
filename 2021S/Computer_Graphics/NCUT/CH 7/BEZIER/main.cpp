// Bezier.c
// OpenGL SuperBible
// Demonstrates OpenGL evaluators to draw bezier curve
// Program by Richard S. Wright Jr.

// #include "../../Common/OpenGLSB.h"	// System and OpenGL Stuff
// #include "../../Common/GLTools.h"   // GLTools
#include "GLUT/glut.h"

// The number of control points for this curve
GLint nNumPoints = 4;

GLfloat ctrlPoints[4][3]= {{  -4.0f, 0.0f, 0.0f},	// End Point
                           { -6.0f, 4.0f, 0.0f},	// Control Point
                           {  6.0f, -4.0f, 0.0f},	// Control Point
                           {  4.0f, 0.0f, 0.0f }};	// End Point

// This function is used to superimpose the control points over the curve
void DrawPoints(void)
{
    int i;	// Counting variable

    // Set point size larger to make more visible
    glPointSize(5.0f);

    // Loop through all control points for this example
    glBegin(GL_POINTS);
    for(i = 0; i < nNumPoints; i++)
        glVertex2fv(ctrlPoints[i]);
    glEnd();
}



// Called to draw scene
void RenderScene(void)
{
    int i;

    // 清空窗口颜色缓存值
    glClear(GL_COLOR_BUFFER_BIT);

    // 初始化 bezier 曲线
    // This actually only needs to be called once and could go in
    // the setup function
    glMap1f(GL_MAP1_VERTEX_3,	// 生成的数据类型
            0.0f,						// u 最小值
            100.0f,						// u 最大值
            3,							// 点间距
            nNumPoints,					// 控制点数量
            &ctrlPoints[0][0]);			// 控制点数组

    // 启用求值
    glEnable(GL_MAP1_VERTEX_3);

    // 用曲线链接各个点
    glBegin(GL_LINE_STRIP);
    for(i = 0; i <= 100; i++)
    {
        // 对该点的曲线求值
        glEvalCoord1f((GLfloat) i);
    }
    glEnd();

    // Use higher level functions to map to a grid, then evaluate the
    // entire thing.
    // Put these two functions in to replace above loop

    // Map a grid of 100 points from 0 to 100
    //glMapGrid1d(100,0.0,100.0);

    // Evaluate the grid, using lines
    //glEvalMesh1(GL_LINE,0,100);

    // 画出控制点
    DrawPoints();

    // 刷新画面
    glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    // Clear Window to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f );

    // Draw in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
}

///////////////////////////////////////
// Set 2D Projection
void ChangeSize(int w, int h)
{
    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10.0f, 10.0f, -10.0f, 10.0f);

    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Bezier Curve");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}
