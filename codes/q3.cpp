#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to draw a triangle
void Draw(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to translate the triangle
void Translate(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int tx, int ty)
{
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;
}

// Function to scale the triangle
void Scale(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float sx, float sy)
{
    x1 = int(x1 * sx);
    y1 = int(y1 * sy);
    x2 = int(x2 * sx);
    y2 = int(y2 * sy);
    x3 = int(x3 * sx);
    y3 = int(y3 * sy);
}

// Function to rotate the triangle
void Rotate(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float angle)
{
    float radian = angle * 3.14159 / 180;
    int x1_new = int(x1 * cos(radian) - y1 * sin(radian));
    int y1_new = int(x1 * sin(radian) + y1 * cos(radian));

    int x2_new = int(x2 * cos(radian) - y2 * sin(radian));
    int y2_new = int(x2 * sin(radian) + y2 * cos(radian));

    int x3_new = int(x3 * cos(radian) - y3 * sin(radian));
    int y3_new = int(x3 * sin(radian) + y3 * cos(radian));

    x1 = x1_new;
    y1 = y1_new;

    x2 = x2_new;
    y2 = y2_new;

    x3 = x3_new;
    y3 = y3_new;
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Define the initial triangle vertices
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 150, y3 = 50;

    // Draw initial triangle
    Draw(x1, y1, x2, y2, x3, y3, WHITE);
    int prev_x, prev_y, c;

    // Loop to handle mouse and keyboard interactions
    do
    {
        // Check if a mouse button has been clicked
        if (ismouseclick(WM_LBUTTONDOWN)) // Left-click to move (translate)
        {
            prev_x = mousex();
            prev_y = mousey();
            clearmouseclick(WM_LBUTTONDOWN); // Clear mouse click event

            while (!ismouseclick(WM_LBUTTONUP)) // Wait until button is released
            {
                // Get the current mouse position and apply translation
                int current_x = mousex();
                int current_y = mousey();
                int tx = current_x - prev_x;
                int ty = current_y - prev_y;
                Translate(x1, y1, x2, y2, x3, y3, tx, ty);
                prev_x = current_x;
                prev_y = current_y;
                cleardevice(); // Clear screen for new drawing
                Draw(x1, y1, x2, y2, x3, y3, WHITE);
                delay(10);
            }
            clearmouseclick(WM_LBUTTONUP); // Clear mouse button up event
        }

        // Right-click for scaling
        if (ismouseclick(WM_RBUTTONDOWN))
        {
            prev_x = mousex();
            prev_y = mousey();
            clearmouseclick(WM_RBUTTONDOWN); // Clear mouse click event

            while (!ismouseclick(WM_RBUTTONUP)) // Wait until button is released
            {
                int current_x = mousex();
                int current_y = mousey();
                float sx = (float)(current_x - prev_x) / 100.0; // Scaling factor
                float sy = (float)(current_y - prev_y) / 100.0; // Scaling factor
                Scale(x1, y1, x2, y2, x3, y3, sx, sy);
                cleardevice(); // Clear screen for new drawing
                Draw(x1, y1, x2, y2, x3, y3, GREEN);
                delay(10);
            }
            clearmouseclick(WM_RBUTTONUP); // Clear mouse button up event
        }

        // Middle-click for rotation
        if (ismouseclick(WM_MBUTTONDOWN))
        {
            prev_x = mousex();
            prev_y = mousey();
            clearmouseclick(WM_MBUTTONDOWN); // Clear mouse click event

            while (!ismouseclick(WM_MBUTTONUP)) // Wait until button is released
            {
                int current_x = mousex();
                int current_y = mousey();
                float angle = atan2(current_y - 150, current_x - 150) * 180 / 3.14159; // Calculate angle
                Rotate(x1, y1, x2, y2, x3, y3, angle);
                cleardevice(); // Clear screen for new drawing
                Draw(x1, y1, x2, y2, x3, y3, BLUE);
                delay(10);
            }
            clearmouseclick(WM_MBUTTONUP); // Clear mouse button up event
        }

        delay(10); // Small delay for smooth performance

    } while (true); // Infinite loop for continuous interaction

    closegraph();
    return 0;
}
