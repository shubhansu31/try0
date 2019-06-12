#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("Error: None or more than one command-line argument entered\n");
        return 1;
    }
    string k = argv[1];
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Error: Please enter only alpha characters as command-line argument.\n");
            return 1;
        }
    }
    
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
   
    for (int i = 0, j = 0, n = strlen(p), m = strlen(k); i < n; i++)
    {
        if (j >= m)
        {
           j = 0;
        }
      
        if (isalpha(p[i]))
        {
            int poffset = isupper(p[i]) ? 65 : 97;
            int koffset = isupper(k[j]) ? 65 : 97;
            int letter = (((p[i] - poffset) + (k[j] - koffset)) % 26);
            int c = letter + poffset;
            printf("%c", c);
            j++;
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
