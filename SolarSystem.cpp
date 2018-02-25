#include <windows.h>
#include <vector>
#ifndef LABA
#include <GL/glut.h>
#endif LABA
#include "cmath"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


using namespace std;

#define PI 3.14

float   angleMoon=0.0,
        angleEarth=0.0,
        angleAstroid=0.0,
        angleMars=0.0,
        angleMercury=0.0,
        angleVenus=0.0,
        angleJupiter=0.0,
        angleSaturn=0.0,
        angleUranus=30.0,
        angleNeptune=60.0;

GLfloat sx=0.2,sy=0.2,sz=0.2;

int planet1;
//задаем цвета
GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
GLfloat white[]={1.0f,1.0f,1.0f,1.0f};
GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};
GLfloat er[]={0.0f,5.0f,0.9f,1.0f};
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};
GLfloat qAmb[]={0.1,0.1,0.1,1.0};
GLfloat qDif[]={1.0,1.0,1.0,1.0};
GLfloat qSpec[]={.50,.50,.50,.10};
GLfloat qPos[]={0,0,0,0.1};
GLfloat sc[8]={0.295 , 0.40,0.50, 0.60,0.80,1.0,1.05,1.13};
//угловая скорость
double ang=2*PI/300;
//угловая скорость
double angular=2*PI/50;

//задаем освещение
void initLighting()
{
    glEnable(GL_LIGHTING);//разрешаем освещение
    glEnable(GL_LIGHT7);//создаем 7 цветов

    glLightfv(GL_LIGHT7,GL_AMBIENT,qAmb);
    glLightfv(GL_LIGHT7,GL_DIFFUSE,qDif);
    glLightfv(GL_LIGHT7,GL_SPECULAR,qSpec);
}
//Инициализация
void myinit()
{
   glClearColor(0.0,0.0,0.0,0.0); //очистка экрана в черный цвет
   glPointSize(1.0);//задаем размер точки
   glLineWidth(2.0);//задаем ширину линий
}
//отрисовываем орбиты
void orbit()
{
    glColor3f(0.5,0.5,0.5);

    for(int i=0;i<8;i++)
    {
        glPushMatrix();

        if(i==5) {glRotatef(45,1.0,0.0,0.0);}
        else {glRotatef(63,1.0,0.0,0.0);}

        glScalef(sc[i],sc[i],sc[i]);

        glBegin(GL_POINTS);
        double ang1=0.0;
        for(int i=0;i<300;i++)
        {
            glVertex2d(cos(ang1),sin(ang1));
            ang1+=ang;
        }
        glEnd();
        glPopMatrix();
    }
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    orbit();
    glLoadIdentity();
    glPushMatrix();
    //разрешаем глубину цвета
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glPushMatrix();
    glColor3f(0.7,0.5,0.0);
    glScalef(sx,sy,sz);

    glLightfv(GL_LIGHT7,GL_POSITION,qPos);

    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);
    glutSolidSphere(1,50,50);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
    glPopMatrix();

    glScalef(0.2,0.2,0.2);

    glPushMatrix();
        glRotatef(angleMercury,0.0,1.0,-0.5);
        glTranslatef(1.5,0.0,0.0);
        glColor3f(1.0,0.9,0.0);
        glScalef(0.08,0.08,0.08);
        glutSolidSphere(1,50,50);
    glPopMatrix();

    glPushMatrix();
        glRotatef(angleVenus,0.0,1.0,-0.5);
        glTranslatef(2.0,0.0,0.0);
        glColor3f(0.9,0.1,0.0);
        glScalef(0.1,0.1,0.1);
        glutSolidSphere(1,50,50);
    glPopMatrix();

    glPushMatrix();
        glRotatef(angleEarth,0.0,1.0,-0.5);
        glTranslatef(2.5,0.0,0.0);
        glColor3f(0.0,0.1,0.7);
        glScalef(0.23,0.23,0.23);
        glutSolidSphere(1,50,50);
        glPushMatrix();
            glRotatef(angleMoon,0.0,0.1,0.05);
            glTranslatef(1.3,0.0,0.0);
            glColor3f(1.0,1.0,1.0);
            glScalef(0.5,0.5,0.5);
            glutSolidSphere(0.5,50,50);
        glPopMatrix();//moon made
    glPopMatrix();//earth made

    glPushMatrix();
        glRotatef(angleMars,0.0,1.0,-0.5);
        glTranslatef(-3.0,0.0,0.0);
        glColor3f(0.05,0.05,0.01);
        glScalef(0.17,0.17,0.17);
        glutSolidSphere(1,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(3.30,3.30,3.30);
             glRotatef(63,1.0,0.0,0.0);
             int j=0,i=0,div=90;float siz=2;
             float scl[4]={3.3,3.4,3.35,3.2};
             for(j=0;j<4;j++)
             {glPushMatrix();siz-=0.3;
             glPointSize(siz);
             glScalef(scl[j],scl[j],scl[j]);
             glBegin(GL_POINTS);
                double ang1=0.0 -angleAstroid,a=(2*PI)/div;
                for(i=0;i<div;i++)
                  {glVertex2d(cos(ang1),sin(ang1));
                   ang1+=a;  }
                   div+=10;
            glEnd();
            glPopMatrix();
             }
           glPopMatrix();//astroid made

    glPushMatrix();
        glRotatef(angleJupiter,0.0,1.0,-0.5);
        glTranslatef(-4.0,0.0,0.0);
        glColor3f(0.4,0.2,0.0);
        glScalef(0.5,0.5,0.5);
        glutSolidSphere(1,50,50);
        glPushMatrix();
            glRotatef(angleMoon,1.0,-0.5,0.0);
            glTranslatef(0.0,0,1.1);
            glColor3f(1.0,1.0,1.0);
            glScalef(0.1,0.1,0.1);
            glutSolidSphere(0.5,50,50);
        glPopMatrix();//moon made
    glPopMatrix();

    glPushMatrix();
    glRotatef(angleSaturn,0.0,1.0,-1.0);
    glTranslatef(-5.0,0.0,0.0);
    glColor3f(0.9,0.0,0.0);
    glScalef(0.4,0.4,0.4);
    glutSolidSphere(1,50,50);
         glPushMatrix();
             glRotatef(45,1.0,0.0,0.0);
             glPointSize(3);
             glColor3f(5.0,3.0,1.0);
             glScalef(1.2,1.2,1.2);
             glBegin(GL_POINTS);
                double ang1=0.0;
                for(int i=0;i<50;i++)
                  {glVertex2d(cos(ang1),sin(ang1));
                   ang1+=angular;  }
            glEnd();

            glPointSize(2);
           glPopMatrix();//ring made
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleUranus,0.0,1.0,-0.5);
         glTranslatef(5.2,0.0,0.0);
         glColor3f(0.0,0.5,0.9);
         glScalef(0.23,0.23,0.23);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleNeptune,0.0,1.0,-0.5);
         glTranslatef(-5.7,0.0,0.0);
         glColor3f(0.0,0.0,0.9);
         glScalef(0.2,0.2,0.2);
         glutSolidSphere(1,50,50);
       glPopMatrix();


glPopMatrix();
     glFlush();
}


void update(int value)
{
    if ((angleMoon>=0 && angleMoon<180))    {sx-=0.0003;sy-=0.0003;sz-=0.0003;}
    else                                    {sx+=0.0003;sy+=0.0003;sz+=0.0003;}

    angleMoon+=2;
    if(angleMoon>360){
        angleMoon-=360;}

    angleEarth+=0.7;
    if(angleEarth>360){
        angleEarth-=360;}

    angleMercury+=2;
    if(angleMercury>360){
        angleMercury-=360;}

    angleVenus+=0.9;
    if(angleVenus>360){
        angleVenus-=360;}

    angleMars+=0.5;
    if(angleMars>360){
        angleMars-=360;}

    angleJupiter+=0.2;
    if(angleJupiter>360){
        angleJupiter-=360;}

    angleSaturn+=0.1;
    if(angleSaturn>360){
        angleSaturn-=360;}

    angleUranus+=0.05;
    if(angleUranus>360){
        angleUranus-=360;}

    angleNeptune+=0.02;
    if(angleNeptune>360){
        angleNeptune-=360;}

    angleAstroid+=0.002;
    if(angleAstroid>360){
        angleAstroid-=360;}

    glutPostRedisplay();
    glutTimerFunc(20,update,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    //Задается размер окна
    glutInitWindowPosition(0,0);
    //Определяется позиции окна на рабочем столе
    glutInitWindowSize(700,700);
    glutCreateWindow("Модель Солнечной Системы.");
    //подключаем освещение
    initLighting();
    //подготовка фона
    myinit();
    //отрисовываем объекты
    glutDisplayFunc(draw);
    //первый запуск таймера
    glutTimerFunc(25,update,0);
    //Запускается оболочка GLUT
    glutMainLoop();
    return 0;
}
