#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void Draw(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void Translate(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int tx, int ty)
{
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;
}

void Scale(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float sx, float sy)
{
    x1 = int(x1 * sx);
    y1 = int(y1 * sy);
    x2 = int(x2 * sx);
    y2 = int(y2 * sy);
    x3 = int(x3 * sx);
    y3 = int(y3 * sy);
}

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
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 150, y3 = 50;
    Draw(x1, y1, x2, y2, x3, y3, WHITE);
    getch();

    int c;
    do
    {
        cout << "\n*** Choose Operation ***: \n1. Translate\n2. Scale\n3. Rotate\n4. EXIT\nEnter choice: ";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            int tx, ty;
            cout << "Enter translation (Tx Ty): ";
            cin >> tx >> ty;
            Translate(x1, y1, x2, y2, x3, y3, tx, ty);
            Draw(x1, y1, x2, y2, x3, y3, GREEN);
            break;
        }
        case 2:
        {
            float sx, sy;
            cout << "Enter Scaling Factor (Sx Sy): ";
            cin >> sx >> sy;
            Scale(x1, y1, x2, y2, x3, y3, sx, sy);
            Draw(x1, y1, x2, y2, x3, y3, RED);
            break;
        }
        case 3:
        {
            float angle;
            cout << "Enter Rotation Angle (in degrees): ";
            cin >> angle;
            Rotate(x1, y1, x2, y2, x3, y3, angle);
            Draw(x1, y1, x2, y2, x3, y3, YELLOW);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (c != 4);

    getch();
    closegraph();
    return 0;
}