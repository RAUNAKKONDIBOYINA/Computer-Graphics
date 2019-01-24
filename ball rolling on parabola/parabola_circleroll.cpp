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
#define PI 3.141
using namespace std;


void linerot(int x,int y,double alfa,int r)
{
    int x2=x+r*cos(alfa*PI/180.0);
    int y2=y+r*sin(alfa*PI/180.0);
    line(x,y,x2,y2);


}
void mid_parabola(int x,int y,double p)
{
    putpixel(x+100,y+100,WHITE);
    double d=1-p;

    while(x<p)
    {
        if(d<0)
        {
            d+=(2*x)+3;
        }
        else
        {
            d+=2*x-2*p+3;
            y--;
        }
        x++;

        putpixel(x+100,y+100,WHITE);
        putpixel(-1*x+100,y+100,WHITE);




    }
    d=pow(x+1/2,2)+(2*p*(y-1));

    while(y>-40)
    {
        if(d<0)
        {
            d+=2*x-2*p+2;
            x++;
        }
        else
        {
            d+=-2*p;

        }
        y--;

        putpixel(x+100,y+100,WHITE);
        putpixel(-1*x+100,y+100,WHITE);

    }

}

void circlemove()
{
    int xy[1000][2];
    int mxy[1000][2];
    xy[0][0]=0;
    xy[0][1]=-10;
    mxy[0][0]=0;
    mxy[0][1]=-10;

int x=0;int y=-10;
int x2=0,y2=0,r=10,alfa=0.0;

double p=50;
double d=1-p;

   while(1)
   {
       int w=1,z=1;
        //putpixel(x+100,y+100,WHITE);
    double d=1-p;

    while(x<p)
    {
        if(d<0)
        {
            d+=(2*x)+3;
        }
        else
        {
            d+=2*x-2*p+3;
            y--;
        }
        x++;

        circle(x+100,y+100,10);
        linerot(x+100,y+100,alfa,r);
        alfa+=5;
        xy[w][0]=x;
        xy[w][1]=y;
        w++;
        mxy[z][0]=-1*x;
        mxy[z][1]=y;
        z++;
        _sleep(10);
         cleardevice();
         mid_parabola(0,0,50);






    }
    d=pow(x+1/2,2)+(2*p*(y-1));

    while(y>-37)
    {
        if(d<0)
        {
            d+=2*x-2*p+2;
            x++;
        }
        else
        {
            d+=-2*p;

        }
        y--;

      circle(x+100,y+100,10);
      linerot(x+100,y+100,alfa,r);
      alfa+=5;
      xy[w][0]=x;
        xy[w][1]=y;
        w++;
         mxy[z][0]=-1*x;
        mxy[z][1]=y;
        z++;
      _sleep(10);
      cleardevice();
      mid_parabola(0,0,50);







    }

    for(int i=w-1;i>=0;i--)
    {
        circle(xy[i][0]+100,xy[i][1]+100,10);
        linerot(xy[i][0]+100,xy[i][1]+100,alfa,r);
        alfa-=5;
        _sleep(10);
      cleardevice();
      mid_parabola(0,0,50);
    }

    for(int i=0;i<z;i++)
    {
        circle(mxy[i][0]+100,mxy[i][1]+100,10);
        linerot(mxy[i][0]+100,mxy[i][1]+100,alfa,r);
        alfa-=5;
        _sleep(10);
      cleardevice();
      mid_parabola(0,0,50);
    }

    for(int i=z-1;i>=0;i--)
    {
        circle(mxy[i][0]+100,mxy[i][1]+100,10);
        linerot(mxy[i][0]+100,mxy[i][1]+100,alfa,r);
        alfa+=5;
        _sleep(10);
      cleardevice();
      mid_parabola(0,0,50);
    }

    x=0;y=-10;




    }


_getch();

}





int main()
{

     int gd = DETECT,gm;//,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

    //cout<<"ddd";
   //int gd = DETECT,gm;//,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;

   //initgraph(&gd, &gm, "C:\\TC\\BGI");
   mid_parabola(0,0,50);

   circlemove();



   closegraph();
   //getch();
   _getch();

   return 0;
}
