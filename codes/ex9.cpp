#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to draw a tree in the given coordinates
void drawTree(int baseX, int baseY)
{
    // Tree trunk
    setcolor(BROWN);
    rectangle(baseX + 20, baseY - 60, baseX + 40, baseY);

    // Tree leaves (circle clusters)
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(baseX + 30, baseY - 70, 30, 30);
    fillellipse(baseX + 10, baseY - 50, 25, 25);
    fillellipse(baseX + 50, baseY - 50, 25, 25);
}

// Function to draw clouds in the given coordinates
void drawCloud(int cx, int cy)
{
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(cx, cy, 20, 20);
    fillellipse(cx + 20, cy - 10, 25, 25);
    fillellipse(cx + 40, cy, 20, 20);
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    outtextxy(150, 350, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Define window and viewport coordinates
    float wxmin = 10, wymin = 10, wxmax = 150, wymax = 250;
    float vxmin = 200, vymin = 10, vxmax = 600, vymax = 250;

    // Draw window and viewport rectangles
    setcolor(WHITE);
    rectangle(wxmin, wymin, wxmax, wymax);
    rectangle(vxmin, vymin, vxmax, vymax);
    outtextxy(60, 260, "Window");
    outtextxy(360, 260, "Viewport");

    // Scaling factors
    float sx = (vxmax - vxmin) / (wxmax - wxmin);
    float sy = (vymax - vymin) / (wymax - wymin);

    // --- Draw Scene in Window ---

    // Draw tree in window
    drawTree(30, 200);

    // Draw clouds in window
    drawCloud(60, 80);
    drawCloud(100, 50);

    // --- Draw Transformed Scene in Viewport ---
    // Now draw the same shapes but scaled

    // Tree base (30, 200)
    int tx = 30, ty = 200;
    int tx_view = sx * (tx - wxmin) + vxmin;
    int ty_view = sy * (ty - wymin) + vymin;
    drawTree(tx_view, ty_view);

    // Cloud 1 (60, 80)
    int cx1 = 60, cy1 = 80;
    int cx1_view = sx * (cx1 - wxmin) + vxmin;
    int cy1_view = sy * (cy1 - wymin) + vymin;
    drawCloud(cx1_view, cy1_view);

    // Cloud 2 (100, 50)
    int cx2 = 100, cy2 = 50;
    int cx2_view = sx * (cx2 - wxmin) + vxmin;
    int cy2_view = sy * (cy2 - wymin) + vymin;
    drawCloud(cx2_view, cy2_view);

    getch();
    closegraph();
}
