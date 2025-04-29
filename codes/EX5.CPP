#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>

void Draw(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void Rotate(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float angle)
{
    float radian = angle * M_PI / 180;

    float cx = (x1 + x2 + x3) / 3.0; // Centroid calcualtion
    float cy = (y1 + y2 + y3) / 3.0;

    x1 -= cx;
    y1 -= cy; // Translation to Origin
    x2 -= cx;
    y2 -= cy;
    x3 -= cx;
    y3 -= cy;

    // Rotate around the origin (0, 0)
    int x1_new = int(x1 * cos(radian) - y1 * sin(radian));
    int y1_new = int(x1 * sin(radian) + y1 * cos(radian));

    int x2_new = int(x2 * cos(radian) - y2 * sin(radian));
    int y2_new = int(x2 * sin(radian) + y2 * cos(radian));

    int x3_new = int(x3 * cos(radian) - y3 * sin(radian));
    int y3_new = int(x3 * sin(radian) + y3 * cos(radian));

    x1 = x1_new + cx;
    y1 = y1_new + cy;

    x2 = x2_new + cx;
    y2 = y2_new + cy;

    x3 = x3_new + cx;
    y3 = y3_new + cy;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    outtextxy(150, 450, "Name: Gaganjot Singh | UID: 22BCS14843");

    int x1, y1, x2, y2, x3, y3;

    // Input triangle vertices
    cout << "Enter the coordinates of the triangle vertices:\n";
    cout << "Vertex 1 (x y): ";
    cin >> x1 >> y1;
    cout << "Vertex 2 (x y): ";
    cin >> x2 >> y2;
    cout << "Vertex 3 (x y): ";
    cin >> x3 >> y3;

    Draw(x1, y1, x2, y2, x3, y3, WHITE);

    float angle;
    int direction;

    int c;
    do
    {
        cout << "\nEnter the Angle of Rotation: \n";
        cin >> angle;
	cout << "*** Enter Rotation Direction ***\n1. for Clockwise\n2. for Anticlockwise\n3. for Exiting";
        cin >> c;

        switch (c)
        {
        case 1:
            angle = -angle; // Clockwise rotation
            Rotate(x1, y1, x2, y2, x3, y3, angle);
            Draw(x1, y1, x2, y2, x3, y3, YELLOW);
            break;
        case 2:
            Rotate(x1, y1, x2, y2, x3, y3, angle); // Anticlockwise rotation
            Draw(x1, y1, x2, y2, x3, y3, RED);
            break;
        case 3:
            cout << "Exiting program.";
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    } while (c != 3);

    getch();
    closegraph();
    return 0;
}