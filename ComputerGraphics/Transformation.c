#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include "DDA.C"

int translate(int p, int t);
int scale(int p, float s);
int rotate(int x, int y, float angle, int rotateX);

void main()
{
      int xmax, ymax;
      int xo, yo;
      int angle;
      int tx, ty;
      float s;

      int graphDriver = DETECT, graphMode;
      initgraph(&graphDriver, &graphMode, "C:\\TURBOC3\\BGI");
      setbkcolor(WHITE);

      xmax = getmaxx();
      ymax = getmaxy();
      xo = xmax / 2;
      yo = ymax / 2;
      angle = -40;
      tx = 41;
      ty = -87;
      s = 1.55;

      // X - Axis
      myDDA(0, yo, xmax, yo, BROWN);
      // Y - Axis
      myDDA(xo, 0, xo, ymax, BROWN);

      // Triangle
      myDDA(xo + 100, yo - 100, xo + 200, yo - 100, RED);
      myDDA(xo + 100, yo - 100, xo + 150, yo - 150, RED);
      myDDA(xo + 150, yo - 150, xo + 200, yo - 100, RED);

      // Scaled triangle
      myDDA(xo + scale(100, s), yo - scale(100, s),
            xo + scale(200, s), yo - scale(100, s), MAGENTA);
      myDDA(xo + scale(100, s), yo - scale(100, s),
            xo + scale(150, s), yo - scale(150, s), MAGENTA);
      myDDA(xo + scale(150, s), yo - scale(150, s),
            xo + scale(200, s), yo - scale(100, s), MAGENTA);

      // Translated triangle
      myDDA(xo + translate(100, tx), yo - translate(100, ty),
            xo + translate(200, tx), yo - translate(100, ty), BLUE);
      myDDA(xo + translate(100, tx), yo - translate(100, ty),
            xo + translate(150, tx), yo - translate(150, ty), BLUE);
      myDDA(xo + translate(150, tx), yo - translate(150, ty),
            xo + translate(200, tx), yo - translate(100, ty), BLUE);

      // Line
      myDDA(xo + 0, yo - 0, xo + 100, yo - 100, GREEN);

      // Rotated line
      myDDA(xo + 0, yo - 0, xo + rotate(100, 100, angle, 1),
            yo - rotate(100, 100, angle, 0), GREEN);

      getch();
}

int translate(int p, int t)
{
      return p + t;
}

int scale(int p, float s)
{
      return p * s;
}

int rotate(int x, int y, float angle, int rotateX)
{
      angle *= 3.14 / 180;

      if (rotateX == 1)
            return ceil(x * cos(angle) - y * sin(angle));

      return ceil(x * sin(angle) + y * cos(angle));
}
