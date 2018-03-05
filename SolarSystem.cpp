#include <iostream>
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
//углы поворота
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

int key;
int planet1;
int angleOrbit=0;
float angleSlopeOX=0, angleSlopeOY=0, angleSlopeOZ=0;
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
        else {glRotatef(63-angleOrbit,1.0,0.0,0.0);}

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

        glPushMatrix();//СОЛНЦЕ
            glColor3f(0.7,0.5,0.0);
            glScalef(sx,sy,sz);
            glLightfv(GL_LIGHT7,GL_POSITION,qPos);
            glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);
            glutSolidSphere(1,50,50);
            glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
        glPopMatrix();//СОЛНЦЕ

        glScalef(0.2,0.2,0.2);

        glPushMatrix();//МЕРКУРИЙ
            glRotatef(angleMercury,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
            glTranslatef(0.5,0.0,0.0);//сдвиг по осям
            glColor3f(1.0,0.9,0.0);
            glScalef(0.08,0.08,0.08);//форма и размер
            glutSolidSphere(1,50,50);
        glPopMatrix();//МЕРКУРИЙ

        glPushMatrix();//ВЕНЕРА
            glRotatef(angleVenus,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
            glTranslatef(2.0,0.0,0.0);//сдвиг по осям
            glColor3f(0.9,0.1,0.0);
            glScalef(0.1,0.1,0.1);//форма и размер
            glutSolidSphere(1,50,50);
        glPopMatrix();//ВЕНЕРА

        glPushMatrix();//ЗЕМЛЯ
            glRotatef(angleEarth,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
            glTranslatef(2.5,0.0,0.0);//сдвиг по осям
            glColor3f(0.0,0.1,0.7);
            glScalef(0.23,0.23,0.23);//форма и размер
            glutSolidSphere(1,50,50);
            glPushMatrix();//ЛУНА
                glRotatef(angleMoon,0.0+angleSlopeOX,0.1+angleSlopeOY,0.05);
                glTranslatef(1.3,0.0,0.0);//сдвиг по осям
                glColor3f(1.0,1.0,1.0);
                glScalef(0.5,0.5,0.5);//форма и размер
                glutSolidSphere(0.5,50,50);
            glPopMatrix();//ЛУНА
        glPopMatrix();//ЗЕМЛЯ

        glPushMatrix();//МАРС
            glRotatef(angleMars,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
            glTranslatef(-3.0,0.0,0.0);//сдвиг по осям
            glColor3f(0.05,0.05,0.01);
            glScalef(0.17,0.17,0.17);//форма и размер
            glutSolidSphere(1,50,50);
        glPopMatrix();//МАРС

        glPushMatrix();//ЮПИТЕР
            glRotatef(angleJupiter,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
            glTranslatef(-4.0,0.0,0.0);//сдвиг по осям
            glColor3f(0.4,0.2,0.0);
            glScalef(0.5,0.5,0.5);//форма и размер
            glutSolidSphere(1,50,50);
            glPushMatrix();//СПУТНИК ЮПИТЕРА
                glRotatef(angleMoon,1.0+angleSlopeOX,-0.5+angleSlopeOY,0.0);
                glTranslatef(0.0,0,1.1);//сдвиг по осям
                glColor3f(1.0,1.0,1.0);
                glScalef(0.1,0.1,0.1);//форма и размер
                glutSolidSphere(0.5,50,50);
            glPopMatrix();//СПУТНИК ЮПИТЕРА
        glPopMatrix();//ЮПИТЕР

        glPushMatrix();//САТУРН
            glRotatef(angleSaturn,0.0+angleSlopeOX,1.0+angleSlopeOY,-1.0-angleSlopeOZ);
            glTranslatef(-5.0,0.0,0.0);//сдвиг по осям
            glColor3f(0.9,0.0,0.0);
            glScalef(0.4,0.4,0.4);//форма и размер
            glutSolidSphere(1,50,50);
            glPushMatrix();//ПОЯС САТУРНА
                glRotatef(45,1.0+angleSlopeOX,0.0+angleSlopeOY,0.0);
                glPointSize(3);
                glColor3f(5.0,3.0,1.0);
                glScalef(1.2,1.2,1.2);//форма и размер
                glBegin(GL_POINTS);
                double ang1=0.0;
                for(int i=0;i<50;i++)
                {
                    glVertex2d(cos(ang1),sin(ang1));
                    ang1+=angular;
                }
                glEnd();
                glPointSize(2);
            glPopMatrix();//ПОЯС САТУРНА
        glPopMatrix();//САТУРН

           glPushMatrix();//УРАН
             glRotatef(angleUranus,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
             glTranslatef(5.2,0.0,0.0);//сдвиг по осям
             glColor3f(0.0,0.5,0.9);
             glScalef(0.23,0.23,0.23);//форма и размер
             glutSolidSphere(1,50,50);
           glPopMatrix();//УРАН

           glPushMatrix();//НЕПТУН
             glRotatef(angleNeptune,0.0+angleSlopeOX,1.0+angleSlopeOY,-0.5-angleSlopeOZ);
             glTranslatef(-5.7,0.0,0.0);//сдвиг по осям
             glColor3f(0.0,0.0,0.9);
             glScalef(0.2,0.2,0.2);//форма и размер
             glutSolidSphere(1,50,50);
           glPopMatrix();//НЕПТУН
    glPopMatrix();
    //ускорение работы освобождением буфера
    glFlush();
}

//отрисовка кадра
void update(int value)
{
//скорости поворота планет по окружности
    angleMoon+=2;
    if(angleMoon>360){
        angleMoon-=360;}

    angleEarth+=2.7;
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

    //обновление кадра
    glutPostRedisplay();
    //вызов таймера
    glutTimerFunc(20,update,0);
}

void Menu(void){
    system("cls");
    cout << "0. Выпоните выбор в активном окне анимации и введите значение в активное окно консоли.(например: r + 60 & z + 6)"<<endl<<endl;
    cout << "1. Введите 'r' для изменения угла наклона траекторий орбит."<<endl;
    cout << "2. Введите 'w' для изменения угла наклона планет по оси X."<<endl;
    cout << "3. Введите 'v' для изменения угла наклона планет по оси Y."<<endl;
    cout << "3. Введите 'z' для изменения угла наклона планет по оси Z."<<endl;
}
//функция событий клваиатуры
void Keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	else if (key=='r'){
        cout<<"Введите число(от-63 до63): ";
        cin>>angleOrbit;
        Menu();
    }
    else if (key=='w'){
        cout<<"Введите число(от 0.1 до 0.9): ";
        cin>>angleSlopeOX;
        Menu();
    }
    else if (key=='v'){
        cout<<"Введите число(от -1 до 1): ";
        cin>>angleSlopeOY;
        Menu();
    }
    else if (key=='z'){
        cout<<"Введите число(от 0 до 10): ";
        cin>>angleSlopeOZ;
        Menu();
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"rus");
    Menu();
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
    //регистрация обратного вызова для событий клавиатуры
    glutKeyboardFunc(Keyboard);
    //Запускается оболочка GLUT
    glutMainLoop();

    return 0;
}
