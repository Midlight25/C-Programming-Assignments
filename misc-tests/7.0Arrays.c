#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int fillArray(int array[]);
int fillArrayRecursively(int array[]);

int main(void)
{
    int ar[50];
    int count;

    /* count = fillArray(ar);
    count = fillArrayRecursively(ar);
    */

    printf("This is how many slots in the array have been populated: %d", count);
    return 0;
}

int fillArray(int array[])
{
    int i, userChoice;
    printf("Fill to how many slots?\n");
    printf("> ");
    scanf("%d", &userChoice);
    printf("\n");

    for(i = 0; i < userChoice; i++)
    {
        printf("Enter number %d:\n", i + 1);
        printf("> ");
        scanf("%d", &array[i]);
        printf("\n");
    }

    return userChoice;
}

int fillArrayRecursively(int array[])
{
    int i, userChoice;
    printf("Fill to how many slots, recursively?\n");
    printf("> ");
    scanf("%d", &userChoice);
    printf("\n");

    for(i = 0; i < userChoice; i++)
    {
        array[i] = i + 1;
        /*
        printf("%d\n", array[i]);
        printf("\n");
        */
    }

    return userChoice;
}
