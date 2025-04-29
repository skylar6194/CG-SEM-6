#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void plotPoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void MidPoint(int xc, int yc, int rad)
{
    int x = 0;
    int y = rad;
    int p = 1 - rad;

    plotPoints(xc, yc, x, y);

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

        plotPoints(xc, yc, x, y);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc = 150, yc = 150, r = 30;

    do
    {
        MidPoint(xc, yc, r);
        r = r + 5;
    } while (r < 50);

    getch();
    closegraph();
    return 0;
}
