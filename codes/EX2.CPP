#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to implement Simple DDA Algorithm
void simpleDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++)
    {
	putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
	x += xInc;
	y += yInc;
    }
}

// Function to implement Symmetrical DDA Algorithm
void symmetricalDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++)
    {
	putpixel((int)(x + 0.5), (int)(y + 0.5), YELLOW);
	x += xInc;
	y += yInc;
    }
}

// Function to implement Bresenham’s Line Drawing Algorithm
void bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1)
    { // Loop until the condition to stop
	putpixel(x1, y1, GREEN);
	if (x1 == x2 && y1 == y2)
	    break;
	int e2 = 2 * err;
	if (e2 > -dy)
	{
	    err -= dy;
	    x1 += sx;
	}
	if (e2 < dx)
	{
	    err += dx;
	    y1 += sy;
	}
    }
}

// Main function
void main()
{   int c;
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    int x1, y1, x2, y2;
    outtextxy(150, 450, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Input points for the line
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

do {
        cout << "Choose the line drawing algorithm:\n";
        cout << "1. Simple DDA\n";
        cout << "2. Symmetrical DDA\n";
        cout << "3. Bresenham's Algorithm\n";
        cout << "4. Exit\n"; // Option to exit
        cout << "Enter your choice (1-4): ";
        cin >> c;

        switch (c) {
            case 1:
                // Simple DDA
                simpleDDA(x1, y1, x2, y2);
                break;
            case 2:
                // Symmetrical DDA
                symmetricalDDA(x1, y1, x2, y2);
                break;
            case 3:
                // Bresenham’s Algorithm
                bresenham(x1, y1, x2, y2);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option (1-4)." << endl;
                break;
        }
    } while (c != 4); // Continue until the user chooses to exit



    getch();
    closegraph();
}
