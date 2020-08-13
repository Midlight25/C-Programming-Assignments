#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
/*
    int thisArray[5];

    printf("> ");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &thisArray[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        printf("%d", thisArray[i]);
    }
*/
    int thatArray[60];

    for(int i = 0; i < 30; i++)
    {
        thatArray[i] = i + 1;
    }

    for(int i = 0; i < 60; i++)
    {
        printf("%d\n", thatArray[i]);
    }

    // After you reach past the point that you used an array for, the array becomes
    // filled with garbage characters. No way to pragmatically track how many spaces
    // that you've filled an array with.


    return 0;
}
