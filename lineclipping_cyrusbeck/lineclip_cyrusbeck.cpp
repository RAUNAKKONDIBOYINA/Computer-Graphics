#include<iostream>
#include<graphics.h>
using namespace std;

struct Point{
int x;
int y;
};

struct vectors{
    double x;
    double y;
};
void clipping(Point p1,Point p2,Point minxy,Point maxxy);
int main()
{
    int gd= DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    Point minxy,maxxy,p1,p2;
    //outtextxy(235,120,"Cyrus Becker Line clipping");
    p1.x=180;
    p1.y=180;
    p2.x=480;
    p2.y=240;

    minxy.x=220;
    minxy.y=160;
    maxxy.x=420;
    maxxy.y=320;
    line(minxy.x,minxy.y,minxy.x,maxxy.y);
    line(minxy.x,minxy.y,maxxy.x,minxy.y);
    line(minxy.x,maxxy.y,maxxy.x,maxxy.y);
    line(maxxy.x,minxy.y,maxxy.x,maxxy.y);

    clipping(p1,p2,minxy,maxxy);
    getch();
    closegraph();
    return 0;
}

double dotproduct(vectors a,vectors b)
{
    return a.x*b.x + a.y*b.y;
}

vectors createVectors(Point a,Point b)
{
    vectors temp;
    temp.x = a.x-b.x;
    temp.y = a.y-b.y;
    return temp;
}
void clipping(Point p1,Point p2,Point minxy,Point maxxy)
{
    vectors Nab,Nbc,Ncd,Nda;
    Nab.x = -1*abs(maxxy.y - minxy.y);
    Nab.y = 0;

    Nbc.x = 0;
    Nbc.y = abs(maxxy.x - minxy.x);

    Ncd.x = abs(minxy.y - maxxy.y);
    Ncd.y = 0;

    Nda.x = 0;
    Nda.y = -1*abs(minxy.x - maxxy.x);

    vectors p2p1 = createVectors(p2,p1);
    double t[4][2];
    Point temp;
    temp.x = minxy.x;
    temp.y = maxxy.y;
    t[0][1] = dotproduct(Nab,p2p1);
    if(t[0][1]!=0)
        t[0][0] = (-1) *(dotproduct(Nab,createVectors(p1,temp))/dotproduct(Nab,p2p1));
    else
        t[0][0] = -1;

    temp.x = maxxy.x;
    temp.y = maxxy.y;
    t[1][1] = dotproduct(Nbc,p2p1);
    if(t[1][1]!=0)
        t[1][0] = (-1) *(dotproduct(Nbc,createVectors(p1,temp))/dotproduct(Nbc,p2p1));
    else
        t[1][0] = -1;

    temp.x = maxxy.x;
    temp.y = minxy.y;
    t[2][1] = dotproduct(Ncd,p2p1);
    if(t[2][1]!=0)
        t[2][0] = (-1) *(dotproduct(Ncd,createVectors(p1,temp))/dotproduct(Ncd,p2p1));
    else
        t[2][0] = -1;

    temp.x = minxy.x;
    temp.y = minxy.y;
    t[3][1] = dotproduct(Nda,p2p1);
    if(t[3][1]!=0)
        t[3][0] = (-1) *(dotproduct(Nda,createVectors(p1,temp))/dotproduct(Nda,p2p1));
    else
        t[3][0] = -1;


    float t1=0,t2=1;
    for(int i=0;i<4;i++)    /**ENTRY**/
    {
        if(t[i][1]<0)
        {
            if(t[i][0]>t1)
                t1 =t[i][0];
        }
    }
    for(int i=0;i<4;i++)       /**EXIT**/
    {
        if(t[i][1]>0)
        {
            if(t[i][0]<t2)
                t2 =t[i][0];
        }
    }

    Point res1,res2;
    res1.x = p1.x + (p2.x-p1.x)*t1;
    res1.y = p1.y + (p2.y-p1.y)*t1;

    res2.x = p1.x + (p2.x-p1.x)*t2;
    res2.y = p1.y + (p2.y-p1.y)*t2;
    if(t1<=1 && t1 >=0 && t2<=1 && t2>=0)
        line(res1.x,res1.y,res2.x,res2.y);

    cout<<t[0][0]<<" "<<t[1][0]<<" "<<t[2][0]<<" "<<t[3][0]<<endl;
    cout<<t[0][1]<<" "<<t[1][1]<<" "<<t[2][1]<<" "<<t[3][1]<<endl;
}
