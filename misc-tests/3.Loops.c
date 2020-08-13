#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void){

    int num, i, input, smallest;
    int largest = 0;
    char inputLetter;

    //Great User and Grab Number of Inputs
    printf("Hello Sir\n");
    printf("How many numbers do you want to input?\n");
    printf(">");
    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        printf("\nEnter Number (%d)\n", i + 1);
        printf(">");
        scanf("%d", &input);
        if (input > largest)
        {
            largest = input;
        }
    }

    printf("Your Largest Number was: %d\n", largest);

    printf("\n");
    printf("Would you like to quit?\n");
    printf(">");
    scanf(" %c", &inputLetter);
    inputLetter = toupper(inputLetter);

    while (inputLetter != 'Q')
    {
        printf("\nEnter a number:\n");
        printf(">");
        scanf("%d", &input);

        if (input < smallest)
        {
            smallest = input;
        }

        printf("\nWould you like to quit?\n");
        printf(">");
        scanf(" %c", &inputLetter);
        inputLetter = toupper(inputLetter);
    }

    printf("\nThe smallest number is %d\n", smallest);
    return 0;
}
