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

void drawparabola(int a,int b,double p)
{
    int x=0,y=0;
    putpixel(x+a,y+b,WHITE);
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

        putpixel(x+a,y+b,WHITE);
        putpixel(-1*x+a,y+b,WHITE);




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

        putpixel(x+a,y+b,WHITE);
        putpixel(-1*x+a,y+b,WHITE);

    }

}

int main()
{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   cout<<"enter x,y,e"<<endl;
   int x,y;
   double e;
   cin>>x;
   cin>>y;
   cin>>e;

   drawparabola(x,y,e);



   //closegraph();
   getch();
   //_getch;

   return 0;
}
