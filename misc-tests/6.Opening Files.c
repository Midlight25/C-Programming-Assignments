#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE *inPtr;
    FILE *outPtr;
    int num, len, i;
    char name[25];
    char name2[25] = "MICHAEL";
    char word[30] = "Hello";
    char word2[20];

    // THis is not legal in C:
    // word2 = "bye";

    printf("Please enter your name\n");
    printf("> ");
    scanf(" %s", name);
    printf("\n");
    printf("Welcome %s\n", name);

    len = strlen(name);
    printf("Your name has %d characters\n", len);

    for(i = 0; i < len; i++)
    {
        name[i] = toupper(name[i]);
    }
    printf("Your name in uppercase is %s\n", name);

    if (strcmp(name,name2) == 0)
    {
        printf("Hey your name is the same as my name!");
    }

    inPtr = fopen("importme.txt", "r");

    fscanf(inPtr, "%d", &num);
    printf("\n");
    printf("The numbers are %d", num);

    outPtr = fopen("out.txt", "w");
    fprintf(outPtr, "This is the number, %d", num);
    return 0;
}
