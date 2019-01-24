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
int xmin=100,ymin=100,xmax=200,ymax=200;


int gencode(int x1,int y1)
{
    int code=0;

    if(y1<ymin)
    {
        code|=4;
    }
    if(y1>ymax)
    {
        code|=8;
    }
    if(x1<xmin)
    {
        code|=1;
    }
    if(x1>xmax)
    {
       code|=2;
    }
    return code;
}
/*void gencode(int x1,int y1,int a[])
{
    if(y1<ymin)
    {
        a[0]=1;
    }
    if(y1>ymax)
    {
        a[1]=1;
    }
    if(x1<xmin)
    {
        a[3]=1;
    }
    if(x1>xmax)
    {
        a[2]=1;
    }

}*/

void cohen(int x1,int y1,int x2,int y2,int a,int b)
{

    while(1)
    {
        //cout<<"1"<<endl;

        if(a==0 && b==0)
    {
        line(x1,y1,x2,y2);
        break;
    }
    else if(a&b)
        break;
    else
    {
        int x,y;
        int code_out;
        if(a!=0)
            code_out=a;
        else
            code_out=b;

        if(code_out&8)
        {
            x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
        }
        else if(code_out&4)
        {
            x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
        }
        else if(code_out&2)
        {
            y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
        }
        else if(code_out&1)
        {
           y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
        }

        if (code_out == a)
            {
                x1 = x;
                y1 = y;
                a = gencode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                b = gencode(x2, y2);
            }

    }


    }

}

int main()
{

int gd = DETECT,gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   cout<<"xmin,ymin,xmax,ymax"<<endl;

    cin>>xmin;
    cin>>ymin;
    cin>>xmax;
    cin>>ymax;

    line(xmin,ymin,xmax,ymin);
    line(xmin,ymin,xmin,ymax);
    line(xmax,ymax,xmax,ymin);
    line(xmax,ymax,xmin,ymax);

    cout<<"x1,y1,x2,y2"<<endl;

    int x1,y1,x2,y2;
    cin>>x1;
    cin>>y1;
    cin>>x2;
    cin>>y2;

    int a=gencode(x1,y1);
    int b=gencode(x2,y2);

    cohen(x1,y1,x2,y2,a,b);

    /*for(int i=0;i<4;i++)
    {
        cout<<a[i];
    }*/

     getch();
   //_getch;

   return 0;


}
