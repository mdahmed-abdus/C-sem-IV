#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void myDDA(int x1, int y1, int x2, int y2, int colour);

void main()
{
    int graphDriver = DETECT;
    int graphMode;
    initgraph(&graphDriver, &graphMode, "c:\\TURBOc3\\bgi");

    clrscr();

    myDDA(50, 10, 30, 50, RED);
    myDDA(50, 10, 70, 50, RED);
    myDDA(30, 50, 0, 50, RED);
    myDDA(0, 50, 30, 80, RED);
    myDDA(70, 50, 100, 50, RED);
    myDDA(100, 50, 70, 80, RED);
    myDDA(70, 80, 90, 120, RED);
    myDDA(30, 80, 10, 120, RED);
    myDDA(10, 120, 50, 90, RED);
    myDDA(90, 120, 50, 90, RED);

    getch();
}

void myDDA(int x1, int y1, int x2, int y2, int colour)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float x = x1;
    float y = y1;

    int steps = abs(dy);
    if (abs(dx) > abs(dy))
        steps = abs(dx);

    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;

    putpixel(x, y, colour);
    for (int i = 0; i < steps; i++)
    {
        x += xinc;
        y += yinc;
        putpixel(x, y, colour);
    }
}
