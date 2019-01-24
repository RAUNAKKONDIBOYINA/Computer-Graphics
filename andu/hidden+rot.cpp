#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;


void mult(double a[][3],double b[][3],double res[][3])
{
     for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            res[i][j] =0;

            for (int k = 0; k < 3; k++)
            {
                res[i][j] += (a[i][k] * b[k][j]);
                cout << res[i][j] << " ";
            }
        }

}

void mult1by3(double a[][3],double b[][3],double res[][3])
{
     for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            res[i][j] =0;

            for (int k = 0; k < 1; k++)
            {
                res[i][j] += (a[i][k] * b[k][j]);
                cout << res[i][j] << " ";
            }
        }

}

void hermite(double x1,double y1,double x2,double y2,double r1,double r2,double r3,double r4, double cx, double cy, double i)
{
    double x,y,t,X,Y;

    for(t=0.0; t<=1.0; t+=.01)
    {
        x=(2*t*t*t-3*t*t+1)*x1+(-2*t*t*t+3*t*t)*x2+(t*t*t-2*t*t+t)*r1+(t*t*t-t*t)*r3;
        y=(2*t*t*t-3*t*t+1)*y1+(-2*t*t*t+3*t*t)*y2+(t*t*t-2*t*t+t)*r2+(t*t*t-t*t)*r4;

        x -= cx;
        y -= cy;

        X = x*cos(i) - y*sin(i);
        Y = x*sin(i) + y*cos(i);

        X += cx;
        Y += cy;
        putpixel(getmaxx()/2+X,getmaxy()/2-Y,WHITE);
    }
}


int main()
{
    initwindow(600,600);

    int page =0;



//    double rot[3][3] = {{cos(theta),sin(theta),0},
//                                {-sin(theta),cos(theta),0},
//                            {0,0,1}};
//
//      double transNeg[3][3] = {{1,0,0},
//                                {0,1,0},
//                                {100,-100,1}};
//        double transPos[3][3] = {{1,0,0},
//                                {0,1,0},
//                                {-100,-100,1}};
//
//    double cord1[1][3] = {{ 200,200,1 } };
//
//    double res1[3][3]={0};
//        double res2[3][3]={0};
//        double ans1[1][3] = {0};
//        mult(transNeg,rot,res1);
//            mult(res1,transPos,res2);
//
//            mult1by3(cord1,res2,ans1);
//
//            hermite(-100,-100,ans1[0][0],ans1[0][1],0,-100,0,100,0,0,0);

    double theta = 0.336674819;

    for(int i=0;i<100;i++)
    {
         setactivepage(page);
         setvisualpage((1-page));
         cleardevice();

        hermite(-40-160+i,0,-50-160+i,0,0,0,0,0,-200,0,theta);
        hermite(-40-160+i,0,-40-160+i,40,0,0,0,0,-200,0,theta);
        hermite(-40-160+i,40,-55-160+i,35,0,0,0,0,-200,0,theta);
        hermite(-50-160+i,0,-50-160+i,30,0,0,0,0,-200,0,theta);
        hermite(-50-160+i,30,-55-160+i,35,0,0,0,0,-200,0,theta);
         hermite(5-60-160+i,0,25-60-160+i,0,0,0,0,0,-200,0,theta);
        hermite(10-60-160+i,0,5-60+i-160,-5,0,0,0,0,-200,0,theta);
        hermite(20-60-160+i,0,25-60-160+i,-5,0,0,0,0,-200,0,theta);



        hermite(-5-160+i,40,-5+i-160,0,-90,90,90,90,-200,0,theta);
        hermite(-5-160+i,35,-5+i-160,10,-50,50,50,50,-200,0,theta);
        hermite(-5-160+i,40,-5+i-160,35,0,0,0,0,-200,0,theta);
        hermite(-5-160+i,10,-15+i-160,15,20,20,-20,-20,-200,0,theta);
        hermite(-5-160+i,0,-15+i-160,22,60,50,-50,-50,-200,0,theta);
        hermite(5-25+i-160,0-5,25+i-25-160,0-5,0,0,0,0,-200,0,theta);
        hermite(10-25+i-160,0-5,5+i-25-160,-5-5,0,0,0,0,-200,0,theta);
        hermite(20-25+i-160,0-5,25+i-25-160,-5-5,0,0,0,0,-200,0,theta);


        hermite(8-160+i,30,8-160+i,40,0,0,0,0,-200,0,theta);
        hermite(8-160+i,40,30-160+i,40,0,0,0,0,-200,0,theta);
        hermite(8-160+i,30,20-160+i,30,0,0,0,0,-200,0,theta);
        hermite(30-160+i,40,20-160+i,0,0,0,0,0,-200,0,theta);
        hermite(20-160+i,30,10-160+i,0,0,0,0,0,-200,0,theta);
        hermite(10-160+i,0,20-160+i,0,0,0,0,0,-200,0,theta);
        hermite(5-160+i,0,25-160+i,0,0,0,0,0,-200,0,theta);
        hermite(10-160+i,0,5-160+i,-5,0,0,0,0,-200,0,theta);
        hermite(20-160+i,0,25-160+i,-5,0,0,0,0,-200,0,theta);


         hermite(8+40-160+i,30,8+40+i-160,40,0,0,0,0,-200,0,theta);
        hermite(8+40-160+i,40,-160+i+30+40,40,0,0,0,0,-200,0,theta);
        hermite(8+40-160+i,30,20+i+40-160,30,0,0,0,0,-200,0,theta);
        hermite(30+40+i-160,40,20+i+40-160,0,0,0,0,0,-200,0,theta);
        hermite(20+40+i-160,30,10+i+40-160,0,0,0,0,0,-200,0,theta);
        hermite(10+40+i-160,0,20+i+40-160,0,0,0,0,0,-200,0,theta);
        hermite(5+40+i-160,0,25+i+40-160,0,0,0,0,0,-200,0,theta);
        hermite(10+40+i-160,0,5+i+40-160,-5,0,0,0,0,-200,0,theta);
        hermite(20+40+i-160,0,25+i+40-160,-5,0,0,0,0,-200,0,theta);



        hermite(-200,-40+30,200,100+30,0,0,0,0,0,0,0);
        hermite(-200,-80+30,200,60+30,0,0,0,0,0,0,0);
        hermite(-200,-40+30,-200,-80+30,0,0,0,0,0,0,0);
        hermite(200,100+30,200,60+30,0,0,0,0,0,0,0);




        //hermite(-15,35,-15,40,0,0,0,0,0,0,0);
        //hermite(-15,40,-15,0,-70,70,70,70,0,0,0);
        delay(0);
        page = 1-page;
    }



















    getchar();

}
