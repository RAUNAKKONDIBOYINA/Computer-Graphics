#include<iostream>
#include<graphics.h>
#include<conio.h>
#include <stdlib.h>
#include<math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
using namespace std;

#define PI 3.14159265

double propoint[10][3];
double propointnew[10][3];




double radianize(int theta)
{
    return ((theta*3.14)/180);
}

void rotatex(double point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double y=point[i][1],z=point[i][2], x=point[i][0];
        propointnew[i][1]=(y)*cos(angle*PI/180.0)-z*sin(angle*PI/180.0);
        //point[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));

    }
}

void rotatey(double point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=point[i][0],z=point[i][2];
        propointnew[i][0]=(x)*cos(angle*PI/180.0)+z*sin(angle*PI/180.0);
        //point[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));


    }
}

void rotatez(double point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=point[i][0],y=point[i][1];
        propointnew[i][0]=(x)*cos(angle*PI/180.0)-y*sin(angle*PI/180.0);
        propointnew[i][1]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));

    }
}


void draw()
{
    line(propoint[0][0]+100,propoint[0][1]+100,propoint[1][0]+100,propoint[1][1]+100);
    line(propoint[1][0]+100,propoint[1][1]+100,propoint[2][0]+100,propoint[2][1]+100);
    line(propoint[2][0]+100,propoint[2][1]+100,propoint[3][0]+100,propoint[3][1]+100);
    line(propoint[3][0]+100,propoint[3][1]+100,propoint[0][0]+100,propoint[0][1]+100);
    line(propoint[0][0]+100,propoint[0][1]+100,propoint[4][0]+100,propoint[4][1]+100);
    line(propoint[1][0]+100,propoint[1][1]+100,propoint[4][0]+100,propoint[4][1]+100);
    line(propoint[2][0]+100,propoint[2][1]+100,propoint[4][0]+100,propoint[4][1]+100);
    line(propoint[3][0]+100,propoint[3][1]+100,propoint[4][0]+100,propoint[4][1]+100);

}


void perspective(int n,double d)
{
    for(int i=0;i<n;i++)
    {

        /*propoint[i][0]=(d*propointnew[i][0])/(propointnew[i][2]+d);
        propoint[i][1]=(d*propointnew[i][1])/(propointnew[i][2]+d);
        propoint[i][2]=0;*/

        propoint[i][0]=(d*propointnew[i][0])/(d-propointnew[i][2]);
        propoint[i][1]=(d*propointnew[i][1])/(d-propointnew[i][2]);
        propoint[i][2]=0;

    }
}


int main()

{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   double point[10][3];
   int n;
   cin>>n;

   //double angle=60.0;
   double anglex=0.0,angley=0.0,anglez=0.0;


   for(int i=0;i<n;i++)
   {
       for(int j=0;j<3;j++)
       {
           cin>>point[i][j];
           propointnew[i][j]=point[i][j];


       }
       //iy[i]=point[i][1];
   }
   double d=30;

   perspective(n,d);


   //frontview(point,n);
   draw();
   char x;

   for(int i=0;i<1000;i++)
   {
       x=getch();
       if(x=='x')
       {
           anglex+=5;
           rotatex(point,anglex,n);
           perspective(n,d);

           cleardevice();

           draw();


       }
       if(x=='y')
       {
           angley+=5;
           rotatey(point,angley,n);
           perspective(n,d);
           cleardevice();
           draw();


       }

       if(x=='z')
       {
           anglez+=5;
           rotatez(point,anglez,n);
           perspective(n,d);
           cleardevice();
           draw();


       }



   }



   getch();
   //_getch;

   return 0;
}
