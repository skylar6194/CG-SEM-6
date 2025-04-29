// Apply the Cohen-Sutherland Line Clipping algorithm to clip a line intersecting at:
// two or more points with a given window.

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>

void main()

{

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    int i, xmax, ymax, xmin, ymin, x1, y1, x2, y2, m;
    int start[4], end[4], code[4];

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Set fixed viewport coordinates
    xmin = 100; // Bottom-left x
    ymin = 100; // Bottom-left y
    xmax = 300; // Top-right x
    ymax = 300; // Top-right y

    // Display the coordinates of the viewport
    printf("Viewport coordinates:\n");
    printf("Bottom-left: (%d, %d)\n", xmin, ymin);
    printf("Top-right: (%d, %d)\n", xmax, ymax);

    // Get line coordinates from user
    printf("\nEnter the coordinates for starting point of line: ");
    scanf("%d %d", &x1, &y1);
    printf("\nEnter the coordinates for ending point of line: ");
    scanf("%d %d", &x2, &y2);

    // Initialize start and end codes
    for (i = 0; i < 4; i++)
    {
        start[i] = 0;
        end[i] = 0;
    }

    // Calculate slope
    m = (y2 - y1) / (x2 - x1);

    // Determine visibility codes for start and end points
    if (x1 < xmin)
        start[0] = 1; // Left
    if (x1 > xmax)
        start[1] = 1; // Right
    if (y1 > ymax)
        start[2] = 1; // Above
    if (y1 < ymin)
        start[3] = 1; // Below

    if (x2 < xmin)
        end[0] = 1; // Left
    if (x2 > xmax)
        end[1] = 1; // Right
    if (y2 > ymax)
        end[2] = 1; // Above
    if (y2 < ymin)
        end[3] = 1; // Below

    // Calculate combined visibility code
    for (i = 0; i < 4; i++)
    {
        code[i] = start[i] && end[i];
    }

    // Check visibility
    if ((code[0] == 0) && (code[1] == 0) && (code[2] == 0) && (code[3] == 0))
    {
        if ((start[0] == 0) && (start[1] == 0) && (start[2] == 0) && (start[3] == 0) &&
            (end[0] == 0) && (end[1] == 0) && (end[2] == 0) && (end[3] == 0))
        {
            cleardevice();
            printf("\n\t\tThe line is totally visible\n\t\tand not a clipping candidate");
            rectangle(xmin, ymin, xmax, ymax);
            line(x1, y1, x2, y2);
            getch();
        }
        else
        {
            cleardevice();
            printf("\n\t\tLine is partially visible");
            rectangle(xmin, ymin, xmax, ymax);
            line(x1, y1, x2, y2);
            getch();

            // Clipping logic
            if ((start[2] == 0) && (start[3] == 1))

            {

                x1 = x1 + (ymin - y1) / m;

                y1 = ymin;
            }

            if ((end[2] == 0) && (end[3] == 1))

            {

                x2 = x2 + (ymin - y2) / m;

                y2 = ymin;
            }

            if ((start[2] == 1) && (start[3] == 0))

            {

                x1 = x1 + (ymax - y1) / m;

                y1 = ymax;
            }

            if ((end[2] == 1) && (end[3] == 0))

            {

                x2 = x2 + (ymax - y2) / m;

                y2 = ymax;
            }

            if ((start[1] == 0) && (start[0] == 1))

            {

                y1 = y1 + m * (xmin - x1);

                x1 = xmin;
            }

            if ((end[1] == 0) && (end[0] == 1))

            {

                y2 = y2 + m * (xmin - x2);

                x2 = xmin;
            }

            if ((start[1] == 1) && (start[0] == 0))

            {

                y1 = y1 + m * (xmax - x1);

                x1 = xmax;
            }

            if ((end[1] == 1) && (end[0] == 0))

            {

                y2 = y2 + m * (xmax - x2);

                x2 = xmax;
            }

            clrscr();

            cleardevice();

            printf("\n\t\tAfter clippling:");

            rectangle(xmin, ymin, xmax, ymax);

            line(x1, y1, x2, y2);

            getch();
        }
    }

    else

    {

        clrscr();

        cleardevice();

        printf("\nLine is invisible");

        rectangle(xmin, ymin, xmax, ymax);
    }

    getch();

    closegraph();
}
