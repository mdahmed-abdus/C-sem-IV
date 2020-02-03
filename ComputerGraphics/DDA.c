#include <math.h>

void myDDA(int x1, int y1, int x2, int y2, int colour)
{
    int i;
    int dx = x2 - x1;
    int dy = y2 - y1;
    float x = x1;
    float y = y1;
    float xinc, yinc;

    int steps = abs(dy);
    if (abs(dx) > abs(dy))
        steps = abs(dx);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    putpixel(x, y, colour);
    for (i = 0; i < steps; i++)
    {
        x += xinc;
        y += yinc;
        putpixel(x, y, colour);
    }
}
