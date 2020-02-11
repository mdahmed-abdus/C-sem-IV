#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int round(float num);
void viral(int xc, int yc, int x, int y, int colour);
void midEllipse(int xc, int yc, int x, int y, int colour);

void main()
{
    int graphDriver = DETECT;
    int graphMode;
    initgraph(&graphDriver, &graphMode, "c:\\TURBOc3\\bgi");

    clrscr();

    // Beryllium atom
    midEllipse(200, 200, 100, 50, RED); // horizontal orbit
    midEllipse(200, 200, 50, 100, RED); // vertical orbit
    midEllipse(200, 200, 20, 20, RED);  // nucleus

    midEllipse(200, 100, 5, 5, RED); // top electron
    midEllipse(200, 300, 5, 5, RED); // bottom electron

    midEllipse(100, 200, 5, 5, RED); // left electron
    midEllipse(300, 200, 5, 5, RED); // right electron

    getch();
}

void viral(int xc, int yc, int x, int y, int colour)
{
    putpixel(xc + x, yc + y, colour);
    putpixel(xc - x, yc + y, colour);
    putpixel(xc + x, yc - y, colour);
    putpixel(xc - x, yc - y, colour);
}

int round(float num)
{
    return (int)(num + 0.5);
}

void midEllipse(int xc, int yc, int rx, int ry, int colour)
{
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int trx2 = 2 * rx2;
    int try2 = 2 * ry2;

    int x = 0;
    long int y = ry;
    long int p;
    long int px = 0;
    long int py = trx2 * y;

    viral(xc, yc, x, y, colour);

    p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py)
    {
        x++;
        px = px + try2;

        if (p < 0)
            p = p + ry2 + px;
        else
        {
            y--;
            py = py - trx2;
            p = p + ry2 + px - py;
        }

        viral(xc, yc, x, y, colour);
    }

    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) - rx2 * ry2);
    while (y > 0)
    {
        y--;
        py = py - trx2;

        if (p > 0)
            p = p + rx2 - py;
        else
        {
            x++;
            px = px + try2;
            p = p + rx2 - py + px;
        }

        viral(xc, yc, x, y, colour);
    }
}
