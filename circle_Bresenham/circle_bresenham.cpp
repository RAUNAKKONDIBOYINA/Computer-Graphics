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

void drawcircle(int x1,int y1, int r)
{
    int di=3-2*r;
    int x=0,y=r;
    /*putpixel(x+100,y+100,WHITE);
    putpixel(x+100,-y+100,WHITE);
    putpixel(-x+100,y+100,WHITE);
    putpixel(-x+100,-y+100,WHITE);
    putpixel(y+100,x+100,WHITE);
    putpixel(y+100,-x+100,WHITE);
    putpixel(-y+100,x+100,WHITE);
    putpixel(-y+100,-x+100,WHITE);*/

    putpixel(x+x1,y+y1,WHITE);
    putpixel(x+x1,-y+y1,WHITE);
    putpixel(-x+x1,y+y1,WHITE);
    putpixel(-x+x1,-y+y1,WHITE);
    putpixel(y+x1,x+y1,WHITE);
    putpixel(y+x1,-x+y1,WHITE);
    putpixel(-y+x1,x+y1,WHITE);
    putpixel(-y+x1,-x+y1,WHITE);

    while(x<=y)
    {
        if(di<=0)
        {
            di=di+4*x+6;
            x++;

        }
        else{
            di=di+4*(x-y)+10;
            x++;
            y--;
        }
   /* putpixel(x+100,y+100,WHITE);
    putpixel(x+100,-y+100,WHITE);
    putpixel(-x+100,y+100,WHITE);
    putpixel(-x+100,-y+100,WHITE);
    putpixel(y+100,x+100,WHITE);
    putpixel(y+100,-x+100,WHITE);
    putpixel(-y+100,x+100,WHITE);
    putpixel(-y+100,-x+100,WHITE);*/


    putpixel(x+x1,y+y1,WHITE);
    putpixel(x+x1,-y+y1,WHITE);
    putpixel(-x+x1,y+y1,WHITE);
    putpixel(-x+x1,-y+y1,WHITE);
    putpixel(y+x1,x+y1,WHITE);
    putpixel(y+x1,-x+y1,WHITE);
    putpixel(-y+x1,x+y1,WHITE);
    putpixel(-y+x1,-x+y1,WHITE);


    }

}

int main()

{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   cout<<"enter centre-x,y and radius r.........(better if x=100,y=100,r=25)"<<endl;
   int x,y,r;
   cin>>x;
   cin>>y;
   cin>>r;

   drawcircle(x,y,r);


   //closegraph();
   getch();
   //_getch;

   return 0;
}
