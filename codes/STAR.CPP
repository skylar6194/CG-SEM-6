
#include <iostream.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xorigin = 150, yorigin = 150, length = 30;

    int x1 = 0, y1 = length,                // top
        x2 = length, y2 = 0,                // right
        x3 = 0, y3 = -length,               // down
        x4 = -length, y4 = 0,               // left
        x5 = length / 2, y5 = length / 2,   // top right
        x6 = length / 2, y6 = -length / 2,  // down right
        x7 = -length / 2, y7 = -length / 2, // down left
        x8 = -length / 2, y8 = length / 2;  // top left

    line(xorigin + x1, yorigin - y1, xorigin + x3, yorigin - y3); // top down
    line(xorigin + x4, yorigin - y4, xorigin + x2, yorigin - y2); // left right

    line(xorigin + x5, yorigin - y5, xorigin + x7, yorigin - y7); // top right to down left
    line(xorigin + x6, yorigin - y6, xorigin + x8, yorigin - y8); // down right to top left

    getch();
    closegraph();

    return 0;
}
