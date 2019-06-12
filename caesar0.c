#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

void PrintCiphertext(string, int);
void PrintCharacter(char, int, int);

int main(int argc, char* const argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar NUMBER (A number between 1 and 25)\n");
        return 1;
    }

    int key = atoi(argv[1]);
    if (key > 26)
    {
        key %= 26;
    }

    string plaintext = GetString();
    PrintCiphertext(plaintext, key);

    return 0;
}

void PrintCiphertext(string input, int key)
{
    int i = 0;
    char character;

    while(input[i])
    {
        character = input[i];
        if(isalpha(character))
        {
            if islower(character)
            { // 3rd argument is the upper bound
                PrintCharacter(character, key, 122);
            }
            if isupper(character)
            {
                PrintCharacter(character, key, 90);
            }
        }
        else
        {
            printf("%c", character);
        }
        i++;
    }
    printf("\n");
}

void PrintCharacter(char letter, int key, int boundary)
{
    if (letter+key > boundary)
    { // wraparound
        printf("%c", letter+key - 26);
    }
    else
    { // straight case
        printf("%c", letter+key);
    }
}
