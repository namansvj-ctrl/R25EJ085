#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    for(int i = x; i < x + height && i < ROWS; i++)
    {
        for(int j = y; j < y + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        if((int)x >= 0 && (int)x < ROWS &&
           (int)y >= 0 && (int)y < COLS)
        {
            canvas[(int)x][(int)y] = '*';
        }

        x += xInc;
        y += yInc;
    }
}

void drawCircle(int cx, int cy, int r)
{
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < COLS; y++)
        {
            int d = (x - cx) * (x - cx)
                  + (y - cy) * (y - cy);

            if(abs(d - r * r) <= r)
            {
                canvas[x][y] = '*';
            }
        }
    }
}

void drawTriangle(int x, int y, int h)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(x + i < ROWS && y + j < COLS)
            {
                canvas[x + i][y + j] = '*';
            }
        }
    }
}

void clearCanvas()
{
    initCanvas();
}

int main()
{
    int choice;

    initCanvas();

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Display Canvas\n");
        printf("6. Clear Canvas\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawRectangle(2, 5, 10, 4);
                printf("Rectangle added.\n");
                break;

            case 2:
                drawLine(0, 0, 15, 20);
                printf("Line added.\n");
                break;

            case 3:
                drawCircle(10, 20, 5);
                printf("Circle added.\n");
                break;

            case 4:
                drawTriangle(5, 25, 6);
                printf("Triangle added.\n");
                break;

            case 5:
                displayCanvas();
                break;

            case 6:
                clearCanvas();
                printf("Canvas cleared.\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 0);

    return 0;
}