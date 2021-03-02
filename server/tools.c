#include <stdio.h>

void printN(char *str, int len)
{
    int i = 0;
    while (i < len)
    {
        printf("\x1b[32m + [%s]\x1b[0m\n", str);
        i++;
    }
}