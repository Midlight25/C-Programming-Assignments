#include <stdio.h>
#include <ctype.h>
#include <string.h>

void GetLetPtr(char *storagePtr);

void GetIntPtr(int *storagePtr);

void FixGrades(double gradeArray[], int count);

int main(void)
{
    int i, count;
    // char input;
    // int numInput;
    double gradeArray[50];

    // GetLetPtr(&input);
    // GetIntPtr(&numInput);
    // printf("The char you entered was: \"%c\" and the number you entered was %d\n", input, numInput);

    count = 25;
    for(i = 0; i < count; i++)
    {
        gradeArray[i] = (double)i + 10;
    }

    for(i = 0; i < count; i++)
    {
        printf("%.2f\n", gradeArray[i]);
    }

    FixGrades(gradeArray, count);

    for(i = 0; i < count; i++)
    {
        printf("%.2f\n", gradeArray[i]);
    }

    return 0;
}

void GetLetPtr(char *storagePtr)
{
    printf("Please enter a character\n");
    printf("> ");
    scanf(" %c", storagePtr);
    printf("\n");
}

void GetIntPtr(int *storagePtr)
{
    printf("Please enter an integer\n");
    printf("> ");
    scanf("%d", storagePtr);
    printf("\n");
}

void FixGrades(double gradeArray[], int count)
{
    int i;
    double bonus;

    printf("What is the bonus ammount?\n");
    printf("> ");
    scanf("%lf", &bonus);
    printf("\n");

    for(i = 0; i < count; i++)
    {
        gradeArray[i] += bonus;
    }

    printf("Finished\n");
    printf("\n");
}
