#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

char *palindrome(char *input);
char *evenodd(int input);
char *zeroone(int input);


char *palindrome(char *input)
{
    int n = strlen(input) - 1; 
    int i;
    for(i = 0; i < n; i++)
    {
        if(input[i] != input[n-i])
        {
            return"%s non è palindromo";
        }
    }
    printf("%s è palindromo/a", input);
}



