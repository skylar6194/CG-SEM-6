#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

/* Define the structure to store the edges */
struct edge
{
    int x1, y1, x2, y2, flag;
};

void main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    struct edge ed[3], temped; // For a triangle, we need 3 edges
    float dx, dy, m[3], x_int[3], inter_x[3];
    int x[3], y[3];
    int ymax = 0, ymin = 480, yy, temp;

    initgraph(&gd, &gm, "");

    // Hardcoded vertices of the triangle
    x[0] = 200;
    y[0] = 100; // Vertex 1
    x[1] = 100;
    y[1] = 300; // Vertex 2
    x[2] = 300;
    y[2] = 300; // Vertex 3

    // Store the edge information
    for (int i = 0; i < 3; i++)
    {
        ed[i].x1 = x[i];
        ed[i].y1 = y[i];
        ed[i].x2 = x[(i + 1) % 3]; // Connect to the next vertex
        ed[i].y2 = y[(i + 1) % 3];
        ed[i].flag = 0;

        // Update ymax and ymin
        if (y[i] > ymax)
            ymax = y[i];
        if (y[i] < ymin)
            ymin = y[i];
    }

    // Check for y1 > y2, if not interchange y1 and y2
    for (i = 0; i < 3; i++)
    {
        if (ed[i].y1 < ed[i].y2)
        {
            temp = ed[i].x1;
            ed[i].x1 = ed[i].x2;
            ed[i].x2 = temp;
            temp = ed[i].y1;
            ed[i].y1 = ed[i].y2;
            ed[i].y2 = temp;
        }
    }

    // Draw the triangle
    for (i = 0; i < 3; i++)
    {
        line(ed[i].x1, ed[i].y1, ed[i].x2, ed[i].y2);
    }

    // Sorting of edges in the order of y1, y2, x1
    for (i = 0; i < 3 - 1; i++)
    {
        for (int j = 0; j < 3 - 1; j++)
        {
            if (ed[j].y1 < ed[j + 1].y1)
            {
                temped = ed[j];
                ed[j] = ed[j + 1];
                ed[j + 1] = temped;
            }
            if (ed[j].y1 == ed[j + 1].y1)
            {
                if (ed[j].y2 < ed[j + 1].y2)
                {
                    temped = ed[j];
                    ed[j] = ed[j + 1];
                    ed[j + 1] = temped;
                }
                if (ed[j].y2 == ed[j + 1].y2)
                {
                    if (ed[j].x1 < ed[j + 1].x1)
                    {
                        temped = ed[j];
                        ed[j] = ed[j + 1];
                        ed[j + 1] = temped;
                    }
                }
            }
        }
    }

    // Calculating 1/slope of each edge and storing top
    for (i = 0; i < 3; i++)
    {
        dx = ed[i].x2 - ed[i].x1;
        dy = ed[i].y2 - ed[i].y1;
        if (dy == 0)
        {
            m[i] = 0;
        }
        else
        {
            m[i] = dx / dy;
        }
        inter_x[i] = ed[i].x1;
    }

    // Making the actual edges
    yy = ymax;
    while (yy > ymin)
    {
        for (i = 0; i < 3; i++)
        {
            if (yy > ed[i].y2 && yy <= ed[i].y1)
            {
                ed[i].flag = 1;
            }
            else
            {
                ed[i].flag = 0;
            }
        }

        int j = 0;
        for (i = 0; i < 3; i++)
        {
            if (ed[i].flag == 1)
            {
                if (yy == ed[i].y1)
                {
                    x_int[j] = ed[i].x1;
                    j++;
                    if (ed[i - 1].y1 == yy && ed[i - 1].y1 < yy)
                    {
                        x_int[j] = ed[i].x1;
                        j++;
                    }
                    if (ed[i + 1].y1 == yy && ed[i + 1].y1 < yy)
                    {
                        x_int[j] = ed[i].x1;
                        j++;
                    }
                }
                else
                {
                    x_int[j] = inter_x[i] + (-m[i]);
                    inter_x[i] = x_int[j];
                    j++;
                }
            }
        }

        // Sorting the x intersections
        for (i = 0; i < j; i++)
        {
            for (int k = 0; k < j - 1; k++)
            {
                if (x_int[k] > x_int[k + 1])
                {
                    temp = (int)x_int[k];
                    x_int[k] = x_int[k + 1];
                    x_int[k + 1] = temp;
                }
            }
        }

        // Extracting pairs of values to draw lines
        for (i = 0; i < j; i += 2)
        {
            line((int)x_int[i], yy, (int)x_int[i + 1], yy);
        }
        yy--;
        delay(150); // Delay for visualization
    }

    getch();
    closegraph();
}