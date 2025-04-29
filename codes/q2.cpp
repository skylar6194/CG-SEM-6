#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>

struct Point
{
    int x, y;
};

// Function to calculate the Bezier point at parameter t
Point bezier(Point p0, Point p1, Point p2, Point p3, float t)
{
    Point result;
    float u = 1 - t;
    result.x = (int)(pow(u, 3) * p0.x + 3 * pow(u, 2) * t * p1.x + 3 * u * pow(t, 2) * p2.x + pow(t, 3) * p3.x);
    result.y = (int)(pow(u, 3) * p0.y + 3 * pow(u, 2) * t * p1.y + 3 * u * pow(t, 2) * p2.y + pow(t, 3) * p3.y);
    return result;
}

// Function to draw the Bezier curve
void drawBezier(Point p0, Point p1, Point p2, Point p3)
{
    for (float t = 0; t <= 1; t += 0.01)
    {
        Point p = bezier(p0, p1, p2, p3, t);
        putpixel(p.x, p.y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Define control points
    Point p0 = {100, 300};
    Point p1 = {200, 100};
    Point p2 = {400, 100};
    Point p3 = {500, 300};

    // Draw control points
    circle(p0.x, p0.y, 5);
    circle(p1.x, p1.y, 5);
    circle(p2.x, p2.y, 5);
    circle(p3.x, p3.y, 5);

    // Draw control lines
    line(p0.x, p0.y, p1.x, p1.y);
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);

    // Draw the Bezier curve
    drawBezier(p0, p1, p2, p3);

    getch(); // Wait for a key press
    closegraph();
    return 0;
}