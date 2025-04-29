#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <dos.h>
#include <math.h>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int TARGET_RADIUS = 20;
const int SHOOTER_WIDTH = 50;
const int SHOOTER_HEIGHT = 10;
const int NUM_TARGETS = 5;

// Simple random number generator
int simpleRandom(int min, int max)
{
    return min + rand() % (max - min + 1);
}

struct Target
{
    int x, y;
    int dx, dy; // Direction of movement
};

void drawShooter(int x, int y)
{
    setcolor(WHITE);
    rectangle(x - SHOOTER_WIDTH / 2, y, x + SHOOTER_WIDTH / 2, y + SHOOTER_HEIGHT);
}

void drawTarget(Target &target)
{
    setcolor(RED);
    circle(target.x, target.y, TARGET_RADIUS);
    floodfill(target.x, target.y, RED);
}

void moveTargets(Target targets[], int numTargets)
{
    for (int i = 0; i < numTargets; i++)
    {
        targets[i].x += targets[i].dx;
        targets[i].y += targets[i].dy;

        // Bounce off the walls
        if (targets[i].x <= TARGET_RADIUS || targets[i].x >= WIDTH - TARGET_RADIUS)
        {
            targets[i].dx = -targets[i].dx;
        }
        if (targets[i].y <= TARGET_RADIUS || targets[i].y >= HEIGHT - TARGET_RADIUS)
        {
            targets[i].dy = -targets[i].dy;
        }
    }
}

bool isHit(Target &target, int bulletX, int bulletY)
{
    return (bulletX >= target.x - TARGET_RADIUS && bulletX <= target.x + TARGET_RADIUS &&
            bulletY >= target.y - TARGET_RADIUS && bulletY <= target.y + TARGET_RADIUS);
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(150, 90, "Name: Gaganjot Singh | Roll No: 22BCS14843");

    // Initialize random seed
    srand(12345); // Fixed seed for reproducibility

    // Create targets
    Target targets[NUM_TARGETS];
    for (int i = 0; i < NUM_TARGETS; i++)
    {
        targets[i].x = simpleRandom(TARGET_RADIUS, WIDTH - TARGET_RADIUS);
        targets[i].y = simpleRandom(TARGET_RADIUS, HEIGHT - TARGET_RADIUS);
        targets[i].dx = simpleRandom(1, 3) * (rand() % 2 == 0 ? 1 : -1); // Random speed
        targets[i].dy = simpleRandom(1, 3) * (rand() % 2 == 0 ? 1 : -1); // Random speed
    }

    int shooterX = WIDTH / 2;
    int shooterY = HEIGHT - 50;
    int score = 0;

    while (true)
    {
        cleardevice();

        // Draw shooter
        drawShooter(shooterX, shooterY);

        // Draw targets
        for (int i = 0; i < NUM_TARGETS; i++)
        {
            drawTarget(targets[i]);
        }

        // Display score
        setcolor(WHITE);
        char scoreText[20];
        sprintf(scoreText, "Score: %d", score);
        outtextxy(10, 10, scoreText);

        // Move targets
        moveTargets(targets, NUM_TARGETS);

        // Check for user input
        if (kbhit())
        {
            char ch = getch();
            if (ch == 27)
            { // ESC key to exit
                break;
            }
            else if (ch == 'a' || ch == 'A')
            {
                shooterX -= 10; // Move left
            }
            else if (ch == 'd' || ch == 'D')
            {
                shooterX += 10; // Move right
            }
            else if (ch == ' ')
            { // Space to shoot
                int bulletX = shooterX;
                int bulletY = shooterY;

                // Check for hits
                for (int i = 0; i < NUM_TARGETS; i++)
                {
                    if (isHit(targets[i], bulletX, bulletY))
                    {
                        score++;
                        // Reset target position
                        targets[i].x = simpleRandom(TARGET_RADIUS, WIDTH - TARGET_RADIUS);
                        targets[i].y = simpleRandom(TARGET_RADIUS, HEIGHT - TARGET_RADIUS);
                        targets[i].dx = simpleRandom(1, 3) * (rand() % 2 == 0 ? 1 : -1);
                        targets[i].dy = simpleRandom(1, 3) * (rand() % 2 == 0 ? 1 : -1);
                        break; // Exit loop after hitting a target
                    }
                }
            }
        }

        delay(30); // Control the frame rate
    }

    closegraph();
    return 0;
}