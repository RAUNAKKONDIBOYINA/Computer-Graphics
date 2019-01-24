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

int x1,x2;
int y1,y2;

void drawellipse(int a,int b,int f,int z,int c)
{
    int di=2*a*a-2*a*a*b;
    int x=0,y=b;

    putpixel(x+z,y+c,WHITE);
    putpixel(x+z,-y+c,WHITE);
    putpixel(-x+z,y+c,WHITE);
    putpixel(-x+z,-y+c,WHITE);

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


    putpixel(x+z,y+c,WHITE);
    putpixel(x+z,-y+c,WHITE);
    putpixel(-x+z,y+c,WHITE);
    putpixel(-x+z,-y+c,WHITE);

    }
    if(f==1){
    x1=x;
    y1=y;
    }
    else{
        x2=x;
        y2=y;
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

    putpixel(x+z,y+c,WHITE);
    putpixel(x+z,-y+c,WHITE);
    putpixel(-x+z,y+c,WHITE);
    putpixel(-x+z,-y+c,WHITE);
    }

}


int main()
{

   int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   /*cout<<"enter a,b"<<endl;
   int a,b;
   cin>>a;
   cin>>b;*/

   //drawellipse(20,10,1);
   //drawellipse(40,20,2);
   int flag=1;
   int x=100,y=100;
   while(1)
   {
       if(flag==1){
            drawellipse(20,10,1,x,y);
            drawellipse(40,20,2,x,y);
        line(0+x,-10+y,0+x,-20+y);
        line(0+x,10+y,0+x,20+y);
        line(20+x,0+y,40+x,0+y);
        line(-20+x,0+y,-40+x,0+y);

       line(10+x,19+y,10+x,40+y);
        line(-10+x,19+y,-10+x,40+y);
        line(-10+x,40+y,10+x,40+y);

        flag=0;
        _sleep(500);
       }
       else
       {
           cleardevice();
           drawellipse(20,10,1,x,y);
            drawellipse(40,20,2,x,y);
           line(x1+x,y1+y,x2+x,y2+y);
            line(x1+x,-y1+y,x2+x,-y2+y);
            line(-x1+x,y1+y,-x2+x,y2+y);
            line(-x1+x,-y1+y,-x2+x,-y2+y);

            line(10+x,19+y,10+x,40+y);
        line(-10+x,19+y,-10+x,40+y);
        line(-10+x,40+y,10+x,40+y);


            flag=1;
            _sleep(500);
       }
       cleardevice();
       x+=5;
       y+=5;
   }



   //closegraph();
   getch();
   //_getch;

   return 0;
}
