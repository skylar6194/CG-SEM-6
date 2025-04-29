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
    int p = 1 - rad; // Midpoint decision parameter initialization

    plotPoints(xc, yc, x, y);

    while (x < y)
    {
        x++;

        if (p < 0)
            p = p + 2 * x + 1; // No change in y
        else
        {
            y--;
            p = p + 2 * (x - y) + 1; // y decreases
        }

        plotPoints(xc, yc, x, y);
    }
}

void CircleGenerator(int xc, int yc, int rad)
{
    int x = 0;
    int y = rad;
    int d = 3 - 2 * rad; // Decision parameter initialization

    plotPoints(xc, yc, x, y);

    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + 4 * x + 6; // No change in y
        }
        else
        {
            d = d + 4 * (x - y) + 10; // y decreases
            y--;
        }
        x++;
        plotPoints(xc, yc, x, y);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    outtextxy(150, 450, "Name: Gaganjot Singh | UID: 22BCS14843");

    int choice, rad, xc, yc;

    do
    {
        cout << "Enter Radius of the Circle: ";
        cin >> rad;

        cout << "\nEnter X(center) of the Circle: ";
        cin >> xc;

        cout << "\nEnter Y(center) of the Circle: ";
        cin >> yc;

        cout << "\n** Enter Choice **\n1. Draw using Circle-Generator\n2. Draw using Midpoint-Circle Algorithm\n3. EXIT\n";
        cin >> choice; // Prompt for choice

        switch (choice)
        {
        case 1:
            CircleGenerator(xc, yc, rad);
            break;
        case 2:
            MidPoint(xc, yc, rad);
            break;
        case 3:
            cout << "Exiting Program!! Bye";
            break;

        default:
            cout << "\nEnter ONLY one of the choices";
            break;
        }

    } while (choice != 3);

    getch();
    closegraph();
    return 0;
}
