#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double grades[10];
    int count = 0;
    int i;

    printf("How many,\n");
    printf("> ");
    scanf("%d", &count);
    printf("\n");

    for(i = 0; i < count; i++)
    {
        printf("Enter grade\n");
        printf("> ");

        scanf("%lf", &grades[i]);
        printf("\n");
    }

    for(i = 0; i < count; i++)
    {
        printf("The grade for person %d is %.2f.\n", i + 1, grades[i]);
    }
}
