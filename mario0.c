
#include <stdio.h>
#include <cs50.h>

void PrintPyramid(int);

int main(void)
{
    int height;
    do
    {
        printf("height: ");
        height = GetInt();
    }
    while(height < 0  || height > 23);

    PrintPyramid(height);
}

void PrintPyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height - i - 1); j++)
        { 
            printf(" ");
        }
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
