#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>

//Greets the user
void greeting();

//Asks, gets, and returns an integer
int getInteger();

//Takes in three integers agruments and returns the sum.
int calcSum(int a, int b, int c);

//Takes two double arguements and returns the quotient
double divide(double a, double b);

//Takes one integer arguement and one double arguement
//and prints them onto the screen
void printResult(int a, double b);

int main(void)
{
    int userInput1, userInput2, userInput3, cupsSum;
    double cupsAverage;
    greeting();

    userInput1 = getInteger();
    userInput2 = getInteger();
    userInput3 = getInteger();

    cupsSum = calcSum(userInput1, userInput2, userInput3);
    cupsAverage = divide(cupsSum, 3.0);

    printResult(cupsSum, cupsAverage);
    return 0;
}

void greeting()
{
    printf("Welcome to the coffee cup average calculator\n");
    printf("\n");
}

int getInteger()
{
    int userInput;

    printf("Please enter an integer:\n");
    printf("> ");

    scanf("%d", &userInput);

    printf("\n");

    return userInput;
}

int calcSum(int a, int b, int c)
{
    int sum = a + b + c;
    return sum;
}

double divide(double a, double b)
{
    double quotient = a / b;
    return quotient;
}

void printResult(int a, double b)
{
    printf("According to our data:\n");
    printf("You've had %d cups of coffee total.\n", a);
    printf("And your average cups per day is %.3f.\n", b);
    printf("Have a nice day!\n");
}
