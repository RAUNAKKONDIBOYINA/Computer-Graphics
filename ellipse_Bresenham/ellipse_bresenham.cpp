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

void drawellipse(int a,int b)
{
    int di=2*a*a-2*a*a*b;
    int x=0,y=b;

    putpixel(x+100,y+100,WHITE);
    putpixel(x+100,-y+100,WHITE);
    putpixel(-x+100,y+100,WHITE);
    putpixel(-x+100,-y+100,WHITE);

    while(b*b*x<=a*a*y)
    {
        if(di<=0)
        {
            di+=2*b*b*(2*x+3);
            x++;

        }
        else{
            di+=2*b*b*(2*x+3)+4*a*a*(1-y);
            x++;
            y--;
        }


    putpixel(x+100,y+100,WHITE);
    putpixel(x+100,-y+100,WHITE);
    putpixel(-x+100,y+100,WHITE);
    putpixel(-x+100,-y+100,WHITE);

    }
    while(/*a*a*y<=b*b*x*/y>0)
    {

        if(di<=0)
        {
            di+=2*a*a*(2*y+3);
            y--;

        }
        else{
            di+=2*a*a*(2*y+3)+4*b*b*(1-x);
            x++;
            y--;
        }

    putpixel(x+100,y+100,WHITE);
    putpixel(x+100,-y+100,WHITE);
    putpixel(-x+100,y+100,WHITE);
    putpixel(-x+100,-y+100,WHITE);
    }

}


int main()
{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   cout<<"enter a,b"<<endl;
   int a,b;
   cin>>a;
   cin>>b;

   drawellipse(a,b);


   //closegraph();
   getch();
   //_getch;

   return 0;
}
