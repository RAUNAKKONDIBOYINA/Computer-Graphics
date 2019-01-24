#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void hermite(float p0x, float p0y, float p1x, float p1y, float t0x, float t0y, float t1x, float t1y)
{
float gx[4],gy[4],a,b,tempx[4],tempy[4];
gx[0]=p0x;
gx[1]=p1x;
gx[2]=t0x;
gx[3]=t1x;
gy[0]=p0y;
gy[1]=p1y;
gy[2]=t0y;
gy[3]=t1y;

tempx[0]=2*(gx[0]-gx[1]) + gx[2] + gx[3];
tempx[1]=-3*(gx[0]-gx[1]) -(2*gx[2]) -(gx[3]);
tempx[2]=gx[2];
tempx[3]=gx[0];
tempy[0]=2*(gy[0]-gy[1]) + gy[2] + gy[3];
tempy[1]=-3*(gy[0]-gy[1]) -(2*gy[2]) -(gy[3]);
tempy[2]=gy[2];
tempy[3]=gy[0];


for(float t=0;t<=1;t+=0.0001)
{
a=(tempx[0]*t*t*t)+ (tempx[1]*t*t)+ (tempx[2]*t)+ (tempx[3]);
b=(tempy[0]*t*t*t)+ (tempy[1]*t*t)+ (tempy[2]*t)+ (tempy[3]);
putpixel(a,b,WHITE);
}
}
int main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");

hermite(50,200,100,100,150,-25,-50,-50);
hermite(150,200,100,100,-150,-25,50,-50);

hermite(100,150,150,125,150,135,-150,50);
hermite(100,150,150,125,0,0,150,-150);

hermite(100,150,50,125,50,135,-150,50);
hermite(100,150,50,125,0,0,-150,-150);

hermite(100,150,100,200,0,0,0,0);


//r
hermite(150,200,150,100,150,150,-180,100);
hermite(150,100,250,125,150,150,300,125);

hermite(250,125,250,200,200,150,200,175);

//a
hermite(350,125,350,200,-300,150,200,50);
hermite(350,125,350,200,0,-100,0,-150);

//u
hermite(400,125,425,200,0,200,500,0);
hermite(425,200,450,125,500,0,0,0);






getch();
closegraph();
}
