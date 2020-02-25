#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#include "DDA.c"

void viral(int xc, int yc, int x, int y, int colour);
void bresCircle(int xc, int yc, int radius, int colour);
void midCircle(int xc, int yc, int radius, int colour);

void main()
{
    int graphDriver = DETECT;
    int graphMode;
    initgraph(&graphDriver, &graphMode, "c:\\TURBOc3\\bgi");

    clrscr();

    midCircle(160, 160, 120, RED); // outer circle
    bresCircle(160, 80, 10, RED);  // inner circle

    myDDA(175, 100, 135, 120, RED); // top slant line
    myDDA(135, 120, 155, 120, RED); // top horizontal line
    
    myDDA(175, 100, 175, 210, RED); // right large vertical line
    myDDA(155, 120, 155, 210, RED); // left large vertical line
    myDDA(195, 220, 195, 210, RED); // right bottom vertical line
    myDDA(135, 210, 135, 220, RED); // left bottom vertical line
    
    myDDA(175, 210, 195, 210, RED); // right bottom small horizontal line
    myDDA(135, 210, 155, 210, RED); // left bottom small horizontal line
    myDDA(135, 220, 195, 220, RED); // bottom large horizontal line

    getch();
}

void viral(int xc, int yc, int x, int y, int colour)
{
    putpixel(xc + x, yc + y, colour);
    putpixel(xc - x, yc + y, colour);
    putpixel(xc + x, yc - y, colour);
    putpixel(xc - x, yc - y, colour);

    putpixel(xc + y, yc + x, colour);
    putpixel(xc - y, yc + x, colour);
    putpixel(xc + y, yc - x, colour);
    putpixel(xc - y, yc - x, colour);
}

void bresCircle(int xc, int yc, int radius, int colour)
{
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;

    viral(xc, yc, x, y, colour);
    while (x < y)
    {
        x++;
        if (p < 0)
            p = p + 4 * x + 6;
        else
        {
            y--;
            p = p + 4 * (x - y) + 10;
        }
        viral(xc, yc, x, y, colour);
    }
}

void midCircle(int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    viral(xc, yc, x, y, color);
    while (x < y)
    {
        x++;
        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        viral(xc, yc, x, y, color);
    }
}
