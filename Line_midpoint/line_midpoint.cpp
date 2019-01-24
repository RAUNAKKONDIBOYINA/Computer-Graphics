#include<iostream>
#include<graphics.h>
#include<conio.h>
#include <stdlib.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
using namespace std;

void drawline(int x1,int y1,int x2,int y2)
{

int x=x1,y=y1;
int dx=x2-x1,dy=y2-y1;
int d=2*dy-dx;
putpixel(x,y,WHITE);
while(x<=x2)
{
    if(d<0)
    {
        d+=2*dy;
    }
    else{
        d+=2*(dy-dx);
        y++;
    }
    x++;
    putpixel(x,y,WHITE);
}

}

int main()
{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   cout<<"enter x1,y1,x2,y2"<<endl;
   int x1,y1,x2,y2;
   cin>>x1;
   cin>>y1;
   cin>>x2;
   cin>>y2;

   drawline(x1,y1,x2,y2);


   //closegraph();
   getch();
   //_getch;

   return 0;
}
