#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
void line_dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float x = x1, y = y1;
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    for (int i = 0; i <= steps; ++i)
    {
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
    }
}
int main()
{
    initwindow(800, 500);
    int x1, y1, x2, y2;
    cout << "Enter the x and y coordinates of the first point: ";
    cin >> x1 >> y1;
    cout << "Enter the x and y coordinates of the second point: ";
    cin >> x2 >> y2;
    line_dda(x1, y1, x2, y2);
    getch();
    return 0;
}
