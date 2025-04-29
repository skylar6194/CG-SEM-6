#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>

const int WIDTH = 640;
const int HEIGHT = 480;
const float R = 100.0f; // Distance from the center of the torus to the center of the tube
const float r = 30.0f;  // Radius of the tube

// Function to project 3D points to 2D
void projectAndDraw(float x, float y, float z, float d)
{
    int projectedX = (int)(d * x / (z + d) + WIDTH / 2);
    int projectedY = (int)(d * y / (z + d) + HEIGHT / 2);
    putpixel(projectedX, projectedY, WHITE);
}

// Function to draw the torus
void drawTorus()
{
    float u, v;
    float d = 200.0f; // Distance from the viewer

    for (u = 0; u < 2 * M_PI; u += 0.1)
    {
        for (v = 0; v < 2 * M_PI; v += 0.1)
        {
            float x = (R + r * cos(v)) * cos(u);
            float y = (R + r * cos(v)) * sin(u);
            float z = r * sin(v);
            projectAndDraw(x, y, z, d);
        }
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Draw the torus
    drawTorus();

    getch(); // Wait for a key press
    closegraph();
    return 0;
}