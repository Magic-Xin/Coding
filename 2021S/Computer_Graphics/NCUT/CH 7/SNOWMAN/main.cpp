// Snowman.c
// Demonstrates using Quadric Objects
// OpenGL SuperBible
// Richard S. Wright Jr.

// #include "../../Common/OpenGLSB.h"	// System and OpenGL Stuff
// #include "../../Common/GLTools.h"   // GLTools

#include "GLUT/glut.h"

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


////////////////////////////////////////////////////////////////////////////
// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// This function does any needed initialization on the rendering
// context.  Here it sets up and initializes the lighting for
// the scene.
void SetupRC()
{
    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat	 lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);	// Hidden surface removal
    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);		// Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f );
}

// Respond to arrow keys
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    xRot = (GLfloat)((const int)xRot % 360);
    yRot = (GLfloat)((const int)yRot % 360);

    // Refresh the Window
    glutPostRedisplay();
}


// Called to draw scene
void RenderScene(void)
{
    GLUquadricObj *pObj;	// 创建二次曲面对象

    // 清除窗口色彩值缓存
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 保存矩阵状态，做旋转变换
    glPushMatrix();
    // 向后移动物体，并旋转
    glTranslatef(0.0f, -1.0f, -5.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    // 绘制曲面
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    // 主体
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj, .40f, 26, 13);  // 底部

    glTranslatef(0.0f, .550f, 0.0f); // 中部
    gluSphere(pObj, .3f, 26, 13);

    glTranslatef(0.0f, 0.45f, 0.0f); // 头部
    gluSphere(pObj, 0.24f, 26, 13);

    // 眼睛
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.1f, 0.1f, 0.21f);
    gluSphere(pObj, 0.02f, 26, 13);

    glTranslatef(-0.2f, 0.0f, 0.0f);
    gluSphere(pObj, 0.02f, 26, 13);

    // 鼻子
    glColor3f(1.0f, 0.3f, 0.3f);
    glTranslatef(0.1f, -0.12f, 0.0f);
    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
    glPopMatrix();

    // 帽子
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 1.17f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 0.17f, 0.17f, 0.4f, 26, 13);

    // 帽檐
    glDisable(GL_CULL_FACE);
    gluDisk(pObj, 0.17f, 0.28f, 26, 13);
    glEnable(GL_CULL_FACE);

    glTranslatef(0.0f, 0.0f, 0.40f);
    gluDisk(pObj, 0.0f, 0.17f, 26, 13);
    glPopMatrix();

    // 还原矩阵状态
    glPopMatrix();

    // 刷新窗口
    glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Modeling with Quadrics");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}
    
    
  