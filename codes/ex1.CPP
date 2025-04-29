
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int main()
{

    int gd = DETECT, gm;                             // Graphics driver and mode
    initgraph(&gd, &gm,"C:\\TURBOC3\\BGI"); // Initialize graphics mode
    setbkcolor(7);                                   // Set background color

    // Draw title and barline at the top
    setcolor(15);                                                            // Set color for the text
    outtextxy(150, 10, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Draw barline below the title
    setcolor(15);
    line(0, 30, getmaxx(), 30);

    // Drawing a circle
    circle(100, 100, 50);
    outtextxy(75, 98, "Circle");

    // Drawing a rectangle
    rectangle(210, 60, 400, 140);
    outtextxy(270, 100,"Rectangle");

    // Drawing a line
    line(455, 85, 555, 85);
    outtextxy(490, 95,"Line");

    // Drawing an arc
    arc(80, 350, 10, 80, 100);
    outtextxy(100, 340,"Arc");

    // Drawing an ellipse
    ellipse(380, 300, 0, 360, 40, 80);
    outtextxy(355, 300,"Ellipse");

    getch();      // Wait for user input
    closegraph(); // Close the graphics mode
    return 0;
}
