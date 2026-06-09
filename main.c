#include <stdio.h>

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
    for(int i = x; i < x + height; i++)
    {
        for(int j = y; j < y + width; j++)
        {
            canvas[i][j] = '*';
        }
    }
}
int main()
{
    initCanvas();
    drawRectangle(2, 5, 10, 4);
    displayCanvas();

    return 0;
}