#include <stdio.h>
#include <ctype.h>
#include <string.h>

void AverageAge(int a, int b, int c, double *aPtr);

void LetterGrade(double grade1, double grade2, char *letterPtr);

void FillArray(int aPtr[]);

int main(void)
{
    char fruit[20] = "PgPgsSpGBShB";
    int count = (int)strlen(fruit);
    int i;
    int papaya = 0, guava = 0, banana = 0;
    char compareFruit;

    for(i = 0; i < count; i++)
    {
        compareFruit = tolower(fruit[i]);

        /*
        switch(compareFruit)
        {
            case 'p':
                papaya += 1;
                break;
            case 'g':
                guava += 1;
                break;
            default:
                banana += 1;
        }
        */

        if (compareFruit == 'p')
        {
            papaya += 1;
        }
        else if (compareFruit == 'g')
        {
            guava += 1;
        }
        else
        {
            banana += 1;
        }

    }

    // printf("Papaya = %d \nGuava = %d \nBanana = %d", papaya, guava, banana);


    int total = 0;
    count = 50;
    int arrayForInts[100];

    for(i = 0; i < count; i++)
    {
        arrayForInts[i] = i + 1;
    }

    for(i = 0; i < count; i++)
    {
        total += arrayForInts[i];
    }

    // printf("%d", total);

    int numberArray[100];

    FillArray(numberArray);
    printf("%d", numberArray[1]);
    return 0;
}

void LetterGrade(double grade1, double grade2, char *letterPtr)
{
    double avg = (grade1 + grade2) / 2;

    if (avg > 90.0)
    {
        *letterPtr = 'A';
    }
    else if (avg > 70.0)
    {
        *letterPtr = 'S';
    }
    else
    {
        *letterPtr = 'U';
    }

}

void Larger(int a, int b, int c, int *aPtr)
{
    *aPtr = a;
    if (*aPtr < b)
    {
        *aPtr = b;
    }
    if (*aPtr < c)
    {
        *aPtr = c;
    }

}

void FillArray(int aPtr[])
{
    int exit = 1;
    int userInput;
    int count = 0;

    do
    {
        // ASK + GET User Input (INT)
        printf("Please enter a number, or enter zero to exit.\n");
        printf("> ");
        scanf("%d", &userInput);
        printf("\n");

        if (userInput != 0)
        {
            aPtr[count] = userInput;
            count += 1;
        }
        else
        {
            exit = 0;
        }

    } while(exit != 0);

    printf("The user entered %d numbers.", count);
}
