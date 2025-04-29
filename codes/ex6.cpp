#include <iostream.h>

#include <conio.h>

#include <graphics.h>

void main()

{

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");
    int x1, y1, x2, y2, x3, y3;

    cout << "Enter the coordinates of the triangle:\n";
    cout << "Point 1: ";
    cin >> x1 >> y1;
    cout << "Point 2: ";
    cin >> x2 >> y2;
    cout << "Point 3: ";
    cin >> x3 >> y3;
    int m = getmaxx();
    int n = getmaxy();

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 + 10, "Original Triangle");

    setcolor(4);
    line((m / 2), 0, (m / 2), n);
    line(0, (n / 2), m, (n / 2));
    setcolor(3);
    int c1 = (n / 2) - y1;
    int d1 = (n / 2) - y2;
    int e1 = (n / 2) - y3;
    y1 = y1 + (c1 * 2);
    y2 = y2 + (d1 * 2);
    y3 = y3 + (e1 * 2);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 + 10, "Reflection along X-axis");

    setcolor(YELLOW);
    int a1 = (m / 2) - x1;
    int b1 = (m / 2) - x2;
    int c2 = (m / 2) - x3;
    x1 = x1 + (a1 * 2);
    x2 = x2 + (b1 * 2);
    x3 = x3 + (c2 * 2);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x2 - 20, y2 + 10, "Reflection along Y-axis");
    getch();
    closegraph();
}