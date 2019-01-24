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

  int main() {

        int gdriver = DETECT, gmode, err;

        int radius = 10, x, y, midy;


        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
        err = graphresult();

        if (err != grOk) {
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        x = 50;
        midy = getmaxy() / 2;
        y = midy - 100;

        while (x < getmaxx() - 25) {

                cleardevice();

                //setlinestyle(SOLID_LINE, 1, 3);

                line(0, midy, getmaxx(), midy);


                circle(x, y, radius);
                line(x, y + radius, x, y + radius + 50);


                line(x, y + radius + 50, x - 10, midy);
                line(x, y + radius + 50, x + 10, midy - 30);
                line(x + 10, midy - 30, x + 10, midy);


                line(x, y + radius + 10, x - 15, y + radius + 30);
                line(x - 15, y + radius + 30, x + 15, y + radius + 40);
                delay(150);


                cleardevice();


                x++;

                //setlinestyle(SOLID_LINE, 1, 3);
                line(0, midy, getmaxx(), midy);
                circle(x, y, radius);
                line(x, y + radius, x, y + radius + 50);


                line(x, y + radius + 50, x - 15, midy);
                line(x, y + radius + 50, x + 10, midy - 30);
                line(x + 10, midy - 30, x + 10, midy);


                line(x, y + radius + 5, x - 10, y + radius + 20);
                line(x - 10, y + radius + 20, x - 10, y + radius + 45);
                line(x, y + radius + 5, x + 5, y + radius + 25);
                line(x + 5, y + radius + 25, x + 15, y + radius + 45);
                delay(100);


                cleardevice();
                //setlinestyle(SOLID_LINE, 1, 3);
                line(0, midy, getmaxx(), midy);
                x++;
                circle(x, y, radius);
                line(x, y + radius, x, y + radius + 50);


                line(x, y + radius + 50, x - 20, midy);
                line(x, y + radius + 50, x + 20, midy);


                line(x, y + radius + 5, x - 20, y + radius + 20);
                line(x - 20, y + radius + 20, x - 20, y + radius + 30);
                line(x, y + radius + 5, x + 20, y + radius + 25);
                line(x + 20, y + radius + 25, x + 30, y + radius + 30);
                delay(150);


                cleardevice();
                x++;
                //setlinestyle(SOLID_LINE, 1, 3);
                line(0, midy, getmaxx(), midy);
                circle(x, y, radius);
                line(x, y + radius, x, y + radius + 50);


                line(x, y + radius + 50, x - 8, midy - 30);
                line(x - 8, midy - 30, x - 25, midy);
                line(x, y + radius + 50, x + 10, midy - 30);
                line(x + 10, midy - 30, x + 12, midy);


                line(x, y + radius + 5, x - 10, y + radius + 10);
                line(x - 10, y + radius + 10, x - 10, y + radius + 30);
                line(x, y + radius + 5, x + 15, y + radius + 20);
                line(x + 15, y + radius + 20, x + 30, y + radius + 20);
                delay(100);


                cleardevice();
                x++;
                //setlinestyle(SOLID_LINE, 1, 3);
                line(0, midy, getmaxx(), midy);
                circle(x, y, radius);
                line(x, y + radius, x, y + radius + 50);


                line(x, y + radius + 50, x + 3, midy);
                line(x, y + radius + 50, x + 8, midy - 30);
                line(x + 8, midy - 30, x - 20, midy);


                line(x, y + radius + 5, x - 15, y + radius + 10);
                line(x - 15, y + radius + 10, x - 8, y + radius + 25);
                line(x, y + radius + 5, x + 15, y + radius + 20);
                line(x + 15, y + radius + 20, x + 30, y + radius + 20);
                delay(150);
                x++;
        }

        getch();

        closegraph();

        return 0;
  }
