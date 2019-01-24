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
int pointdim[10][3];
int propoint[10][2];
int propointside[10][2];
int propointtop[10][2];
int pointiso[10][3];
double d=30;

int propointiso[10][3];
int propointdim[10][3];


double iso1=45.0,iso2=35.26;
double dimiso1=20.70,dimiso2=19.47;




double propointper[10][3];
double propointnewper[10][3];
double pointper[10][3];




double radianize(int theta)
{
    return ((theta*3.14)/180);
}

void rotatexper(double pointper[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double y=pointper[i][1],z=pointper[i][2], x=pointper[i][0];
        propointnewper[i][1]=(y)*cos(angle*PI/180.0)-z*sin(angle*PI/180.0);
        //point[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));

    }
}

void rotateyper(double pointper[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=pointper[i][0],z=pointper[i][2];
        propointnewper[i][0]=(x)*cos(angle*PI/180.0)+z*sin(angle*PI/180.0);
        //point[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));


    }
}

void rotatezper(double pointper[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=pointper[i][0],y=pointper[i][1];
        propointnewper[i][0]=(x)*cos(angle*PI/180.0)-y*sin(angle*PI/180.0);
        propointnewper[i][1]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));

    }
}


void drawper()
{
    line(propointper[0][0]+500,propointper[0][1]+400,propointper[1][0]+500,propointper[1][1]+400);
    line(propointper[1][0]+500,propointper[1][1]+400,propointper[2][0]+500,propointper[2][1]+400);
    line(propointper[2][0]+500,propointper[2][1]+400,propointper[3][0]+500,propointper[3][1]+400);
    line(propointper[3][0]+500,propointper[3][1]+400,propointper[0][0]+500,propointper[0][1]+400);
    line(propointper[0][0]+500,propointper[0][1]+400,propointper[4][0]+500,propointper[4][1]+400);
    line(propointper[1][0]+500,propointper[1][1]+400,propointper[4][0]+500,propointper[4][1]+400);
    line(propointper[2][0]+500,propointper[2][1]+400,propointper[4][0]+500,propointper[4][1]+400);
    line(propointper[3][0]+500,propointper[3][1]+400,propointper[4][0]+500,propointper[4][1]+400);

}


void perspective(int n,double d)
{
    for(int i=0;i<n;i++)
    {

        propointper[i][0]=(d*propointnewper[i][0])/(propointnewper[i][2]+d);
        propointper[i][1]=(d*propointnewper[i][1])/(propointnewper[i][2]+d);
        propointper[i][2]=0;

    }
}





void rotatexdim(int pointdim[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double y=pointdim[i][1],z=pointdim[i][2], x=pointdim[i][0];
        propointdim[i][1]=(y)*cos(angle*PI/180.0)-z*sin(angle*PI/180.0);
        propointdim[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

    }
}

void rotateydim(int pointdim[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=pointdim[i][0],z=pointdim[i][2];
        propointdim[i][0]=(x)*cos(angle*PI/180.0)+z*sin(angle*PI/180.0);

    }
}

void rotatezdim(int pointdim[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=pointdim[i][0],y=pointdim[i][1];
        propointdim[i][0]=(x)*cos(angle*PI/180.0)-y*sin(angle*PI/180.0);
        propointdim[i][1]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);

    }
}



void drawdim()
{
    line(propointdim[0][0]+300,propointdim[0][1]+400,propointdim[1][0]+300,propointdim[1][1]+400);
    line(propointdim[1][0]+300,propointdim[1][1]+400,propointdim[2][0]+300,propointdim[2][1]+400);
    line(propointdim[2][0]+300,propointdim[2][1]+400,propointdim[3][0]+300,propointdim[3][1]+400);
    line(propointdim[3][0]+300,propointdim[3][1]+400,propointdim[0][0]+300,propointdim[0][1]+400);
    line(propointdim[0][0]+300,propointdim[0][1]+400,propointdim[4][0]+300,propointdim[4][1]+400);
    line(propointdim[1][0]+300,propointdim[1][1]+400,propointdim[4][0]+300,propointdim[4][1]+400);
    line(propointdim[2][0]+300,propointdim[2][1]+400,propointdim[4][0]+300,propointdim[4][1]+400);
    line(propointdim[3][0]+300,propointdim[3][1]+400,propointdim[4][0]+300,propointdim[4][1]+400);

}
void isometricdim(int pointdim[][3],int n)
{

        for(int i=0;i<n;i++)
        {
            double x=propointdim[i][0],y=propointdim[i][1],z=propointdim[i][2];
            propoint[i][0]=(x)*cos(dimiso1*PI/180.0)+z*sin(dimiso1*PI/180.0);
            double newx=(x)*cos(dimiso1*PI/180.0)+z*sin(dimiso1*PI/180.0);
            double newz=z*cos(dimiso1*PI/180.0)-(x)*sin(dimiso1*PI/180.0);

            double newy=y*cos(dimiso2*PI/180.0)-(newz)*sin(dimiso2*PI/180.0);
            newz=y*sin(dimiso2*PI/180.0)+(newz)*cos(dimiso2*PI/180.0);
            propointdim[i][1]=newy;

            pointdim[i][0]=newx;
            pointdim[i][1]=newy;
            pointdim[i][2]=newz;

        }

}



void rotatexiso(int point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double y=point[i][1],z=point[i][2], x=point[i][0];
        propointiso[i][1]=(y)*cos(angle*PI/180.0)-z*sin(angle*PI/180.0);
        propointiso[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

    }
}

void rotateyiso(int point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=point[i][0],z=point[i][2];
        propointiso[i][0]=(x)*cos(angle*PI/180.0)+z*sin(angle*PI/180.0);

    }
}

void rotateziso(int point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=point[i][0],y=point[i][1];
        propointiso[i][0]=(x)*cos(angle*PI/180.0)-y*sin(angle*PI/180.0);
        propointiso[i][1]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);

    }
}



void drawiso()
{
    line(propointiso[0][0]+100,propointiso[0][1]+400,propointiso[1][0]+100,propointiso[1][1]+400);
    line(propointiso[1][0]+100,propointiso[1][1]+400,propointiso[2][0]+100,propointiso[2][1]+400);
    line(propointiso[2][0]+100,propointiso[2][1]+400,propointiso[3][0]+100,propointiso[3][1]+400);
    line(propointiso[3][0]+100,propointiso[3][1]+400,propointiso[0][0]+100,propointiso[0][1]+400);
    line(propointiso[0][0]+100,propointiso[0][1]+400,propointiso[4][0]+100,propointiso[4][1]+400);
    line(propointiso[1][0]+100,propointiso[1][1]+400,propointiso[4][0]+100,propointiso[4][1]+400);
    line(propointiso[2][0]+100,propointiso[2][1]+400,propointiso[4][0]+100,propointiso[4][1]+400);
    line(propointiso[3][0]+100,propointiso[3][1]+400,propointiso[4][0]+100,propointiso[4][1]+400);

}
void isometric(int pointiso[][3],int n)
{

        for(int i=0;i<n;i++)
        {
            double x=propointiso[i][0],y=propointiso[i][1],z=propointiso[i][2];
            propointiso[i][0]=(x)*cos(iso1*PI/180.0)+z*sin(iso1*PI/180.0);
            double newx=(x)*cos(iso1*PI/180.0)+z*sin(iso1*PI/180.0);
            double newz=z*cos(iso1*PI/180.0)-(x)*sin(iso1*PI/180.0);

            double newy=y*cos(iso2*PI/180.0)-(newz)*sin(iso2*PI/180.0);
            newz=y*sin(iso2*PI/180.0)+(newz)*cos(iso2*PI/180.0);
            propointiso[i][1]=newy;

            pointiso[i][0]=newx;
            pointiso[i][1]=newy;
            pointiso[i][2]=newz;

        }

}


void rotatex(int point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double y=point[i][1],z=point[i][2], x=point[i][0];
        propoint[i][1]=(y)*cos(angle*PI/180.0)-z*sin(angle*PI/180.0);
        //point[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));
        propointside[i][0]=(y)*cos(angle*PI/180.0)-z*sin(angle*PI/180.0);
        propointside[i][1]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);



        propointtop[i][1]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);
    }
}

void rotatey(int point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=point[i][0],z=point[i][2];
        propoint[i][0]=(x)*cos(angle*PI/180.0)+z*sin(angle*PI/180.0);
        //point[i][2]=(y)*sin(angle*PI/180.0)+z*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));
        propointside[i][1]=z*cos(angle*PI/180.0)-(x)*sin(angle*PI/180.0);

        propointtop[i][1]=z*cos(angle*PI/180.0)-(x)*sin(angle*PI/180.0);
        propointtop[i][0]=(x)*cos(angle*PI/180.0)+z*sin(angle*PI/180.0);

    }
}

void rotatez(int point[][3],int angle,int n)
{

    for(int i=0;i<n;i++)
    {
        double x=point[i][0],y=point[i][1];
        propoint[i][0]=(x)*cos(angle*PI/180.0)-y*sin(angle*PI/180.0);
        propoint[i][1]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);

        //point[i][1]=y*cos(radianize(angle))-z*sin(radianize(angle));
        //point[i][2]=y*sin(radianize(angle))+z*cos(radianize(angle));
        propointside[i][0]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);

        propointtop[i][0]=(x)*cos(angle*PI/180.0)-y*sin(angle*PI/180.0);
        propointtop[i][1]=(x)*sin(angle*PI/180.0)+y*cos(angle*PI/180.0);
    }
}

/*void draw()
{
    line(propoint[0][0]+100,propoint[0][1]+100,propoint[1][0]+100,propoint[1][1]+100);
    line(propoint[1][0]+100,propoint[1][1]+100,propoint[2][0]+100,propoint[2][1]+100);
    line(propoint[2][0]+100,propoint[2][1]+100,propoint[3][0]+100,propoint[3][1]+100);
    line(propoint[3][0]+100,propoint[3][1]+100,propoint[0][0]+100,propoint[0][1]+100);
    line(propoint[4][0]+100,propoint[4][1]+100,propoint[5][0]+100,propoint[5][1]+100);
    line(propoint[5][0]+100,propoint[5][1]+100,propoint[6][0]+100,propoint[6][1]+100);
    line(propoint[6][0]+100,propoint[6][1]+100,propoint[7][0]+100,propoint[7][1]+100);
    line(propoint[7][0]+100,propoint[7][1]+100,propoint[4][0]+100,propoint[4][1]+100);

    line(propoint[0][0]+100,propoint[0][1]+100,propoint[4][0]+100,propoint[4][1]+100);
    line(propoint[7][0]+100,propoint[7][1]+100,propoint[3][0]+100,propoint[3][1]+100);
    line(propoint[5][0]+100,propoint[5][1]+100,propoint[1][0]+100,propoint[1][1]+100);
    line(propoint[6][0]+100,propoint[6][1]+100,propoint[2][0]+100,propoint[2][1]+100);
}*/

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

void draw2()
{
    line(propointside[0][0]+300,propointside[0][1]+100,propointside[1][0]+300,propointside[1][1]+100);
    line(propointside[1][0]+300,propointside[1][1]+100,propointside[2][0]+300,propointside[2][1]+100);
    line(propointside[2][0]+300,propointside[2][1]+100,propointside[3][0]+300,propointside[3][1]+100);
    line(propointside[3][0]+300,propointside[3][1]+100,propointside[0][0]+300,propointside[0][1]+100);
    line(propointside[0][0]+300,propointside[0][1]+100,propointside[4][0]+300,propointside[4][1]+100);
    line(propointside[1][0]+300,propointside[1][1]+100,propointside[4][0]+300,propointside[4][1]+100);
    line(propointside[2][0]+300,propointside[2][1]+100,propointside[4][0]+300,propointside[4][1]+100);
    line(propointside[3][0]+300,propointside[3][1]+100,propointside[4][0]+300,propointside[4][1]+100);

}

void draw3()
{
    line(propointtop[0][0]+500,propointtop[0][1]+100,propointtop[1][0]+500,propointtop[1][1]+100);
    line(propointtop[1][0]+500,propointtop[1][1]+100,propointtop[2][0]+500,propointtop[2][1]+100);
    line(propointtop[2][0]+500,propointtop[2][1]+100,propointtop[3][0]+500,propointtop[3][1]+100);
    line(propointtop[3][0]+500,propointtop[3][1]+100,propointtop[0][0]+500,propointtop[0][1]+100);
    line(propointtop[0][0]+500,propointtop[0][1]+100,propointtop[4][0]+500,propointtop[4][1]+100);
    line(propointtop[1][0]+500,propointtop[1][1]+100,propointtop[4][0]+500,propointtop[4][1]+100);
    line(propointtop[2][0]+500,propointtop[2][1]+100,propointtop[4][0]+500,propointtop[4][1]+100);
    line(propointtop[3][0]+500,propointtop[3][1]+100,propointtop[4][0]+500,propointtop[4][1]+100);

}

void frontview(int point[][3],int n)
{
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<2;j++)
       {
           propoint[i][j]=point[i][j];
       }
    }
}

void sideview(int point[][3],int n)
{
    for(int i=0;i<n;i++)
    {
       for(int j=1;j<3;j++)
       {
           propointside[i][j-1]=point[i][j];
       }
    }
}

void topview(int point[][3],int n)
{
    for(int i=0;i<n;i++)
    {

           propointtop[i][0]=point[i][0];
           propointtop[i][1]=point[i][2];

    }
}
int main()

{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   int point[10][3];
   int n;
   cout<<"enter no. of vertices(5 for pyramid)"<<endl;
   cin>>n;

   //double angle=60.0;
   double anglex=0.0,angley=0.0,anglez=0.0;


   cout<<"enter 5 vertices of pyramid in 3d"<<endl;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<3;j++)
       {
           cin>>point[i][j];
           pointiso[i][j]=point[i][j];
           propointiso[i][j]=point[i][j];

           pointdim[i][j]=point[i][j];
           propointdim[i][j]=point[i][j];

           pointper[i][j]=point[i][j];
           propointnewper[i][j]=point[i][j];


       }
       //iy[i]=point[i][1];
   }
   isometric(pointiso,n);
   isometricdim(pointdim,n);


   drawiso();
   drawdim();


   frontview(point,n);
   sideview(point,n);
   topview(point,n);
   draw();
   draw2();
   draw3();

   perspective(n,d);
   drawper();


   line(200,100,200,500);
   line(400,100,400,500);
   line(0,200,600,200);

   char x;
   for(int i=0;i<1000;i++)
   {
       x=getch();
       if(x=='x')
       {
           anglex+=5;
           rotatex(point,anglex,n);
           rotatexiso(pointiso,anglex,n);
           rotatexdim(pointdim,anglex,n);
           rotatexper(pointper,anglex,n);
           perspective(n,d);
           cleardevice();
           //translate(n,point);
           line(200,100,200,500);
   line(400,100,400,500);
   line(0,200,600,200);

           draw();
           draw2();
           draw3();
           drawiso();
           drawdim();
           drawper();

       }
       if(x=='y')
       {
           angley+=5;
           rotatey(point,angley,n);
           rotateyiso(pointiso,angley,n);
           rotateydim(pointdim,angley,n);
           rotateyper(pointper,angley,n);
           perspective(n,d);
           cleardevice();
           //translate(n,point);

           line(200,100,200,500);
   line(400,100,400,500);
   line(0,200,600,200);


           draw();
           draw2();
           draw3();
           drawiso();
           drawdim();
           drawper();

       }

       if(x=='z')
       {
           anglez+=5;
           rotatez(point,anglez,n);
           rotateziso(pointiso,anglez,n);
           rotatezdim(pointdim,anglez,n);
           rotatezper(pointper,anglez,n);
           perspective(n,d);
           cleardevice();
           //translate(n,point);

           line(200,100,200,500);
   line(400,100,400,500);
   line(0,200,600,200);


           draw();
           draw2();
           draw3();
           drawiso();
           drawdim();
           drawper();

       }



   }



   getch();
   //_getch;

   return 0;
}















