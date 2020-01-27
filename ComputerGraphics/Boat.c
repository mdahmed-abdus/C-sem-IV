#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void bresLine(int x1, int y1, int x2, int y2, int colour);

void main()
{
    int graphDriver = DETECT;
    int graphMode;
    initgraph(&graphDriver, &graphMode, "c:\\TURBOc3\\bgi");

    clrscr();

    // boat bottom body
    bresLine(60, 240, 420, 240, RED);
    bresLine(60, 240, 120, 300, RED);
    bresLine(120, 300, 360, 300, RED);
    bresLine(360, 300, 420, 240, RED);

    // boat top pole
    bresLine(225, 90, 255, 90, RED);
    bresLine(225, 90, 225, 240, RED);
    bresLine(255, 90, 255, 240, RED);

    // boat sail
    bresLine(255, 90, 420, 240, RED);
    bresLine(255, 210, 420, 240, RED);

    getch();
}

void bresLine(int x1, int y1, int x2, int y2, int colour)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x, y, p;
    int xend, yend;

    if (dx > dy)
    {
        if (x1 > x2)
        {
            x = x2;
            y = y2;
            xend = x1;
        }
        else
        {
            x = x1;
            y = y1;
            xend = x2;
        }

        p = 2 * dy - dx;
        putpixel(x, y, colour);

        while (x <= xend)
        {
            if (p < 0)
                p = p + 2 * dy;
            else
            {
                y++;
                p = p + 2 * (dy - dx);
            }
            putpixel(x, y, colour);
            x++;
        }
    }
    else
    {
        if (y1 > y2)
        {
            x = x2;
            y = y2;
            yend = y1;
        }
        else
        {
            x = x1;
            y = y1;
            yend = y2;
        }

        p = 2 * dx - dy;
        putpixel(x, y, colour);

        while (y <= yend)
        {
            if (p < 0)
                p = p + 2 * dx;
            else
            {
                if ((x2 > x1 && y2 < y1) || (x2 < x1 && y2 > y1))
                    x--;
                else
                    x++;
                p = p + 2 * (dx - dy);
            }
            putpixel(x, y, colour);
            y++;
        }
    }
}
