#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

// Question 5
double AverageAge(int age1, int age2, int age3);

// Question 6
char LetterGrade(double grade1, double grade2);

// Question 7
char GetL(void);
double GetD(void);

int main(void)
{
    // Question 1
    char fruit = 'G';
    int papaya = 0;
    int guava = 0;
    int bananas = 0;
    switch(fruit)
    {
        case 'P':
            papaya++;
            break;
        case 'G':
            guava++;
            break;
        default: bananas++;
    }

    printf("Papaya: %d, Guava: %d, Bananas: %d \n", papaya, guava, bananas);
    printf("\n");

    // Question 2
    int num1 = 24, num2 = 45, num3 = 100;
    int large = num1;

    if (num2 > large)
    {
        large = num2;
    }
    if (num3 > large)
    {
        large = num3;
    }
    printf("The largest number is %d. \n", large);
    printf("\n");

    // Question 3
    int i, total = 0;

    for (i = 1; i <= 100; i++)
    {
        // printf("%d squared is equal to %d.\n", i, i * i);
        total += (i * i);
    }

    printf("The sum of the square of first %d whole numbers is %d.\n", i - 1, total);
    printf("\n");

    // Question 4
    total = 1;
    int userInput = 1;

    do
    {
        total *= userInput;

        printf("Please enter a number to multiply to the total, or type 0 to quit.\n");
        printf("> ");

        scanf("%d", &userInput);

        printf("\n");

    } while(userInput != 0);

    printf("    The product of all your numbers is %d.\n", total);
    printf("\n");

    // Question 5
    double age = AverageAge(20, 20, 3);

    printf("The average age of these three groups is %.3f.\n", age);
    printf("\n");

    // Question 6
    printf("Enter Grade 1");
    scanf("%d", &grd2)
    printf("")

    char grade = LetterGrade(grd1, grd2);
    printf("You got a '%c' in your math class today!\n", grade);
    printf("\n");

    //Question 7
    char userChar = GetL();
    double userDoub = GetD();

    printf("The char input was '%c', the double input was %.2f\n", userChar, userDoub);
    printf("\n");

    return 0;
}

// Question 5 part 2
double AverageAge(int age1, int age2, int age3)
{
    double average = age1 + age2 + age3;
    average /= 3;

    return average;
}

// Question 6
char LetterGrade(double grade1, double grade2)
{
    double grade = (grade1 + grade2) / 2;

    if (grade > 90)
    {
        return 'E';
    }
    else if (grade <= 90 && grade >= 70)
    {
        return 'S';
    }
    else
    {
        return 'U';
    }
}

// Question 7
char GetL(void)
{
    char userInput;

    printf("Please enter a character:\n");
    printf("> ");

    scanf(" %c", &userInput);

    printf("\n");

    return userInput;
}

double GetD(void)
{
    double userInput;

    printf("Please enter a double:\n");
    printf("> ");

    scanf("%lf", &userInput);

    printf("\n");

    return userInput;
}
