// Michael Mesquita
// October 15, 2019
// COP 2220 Sixth Program (prog6.c) Functions

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf and scanf

void greeting(void);
int getUserChoice(void);
void numberToChar(int numberInput);
void charToNumber(char letterInput);

int main()
{
	int numberInput, userChoice;
	char letterInput;

    greeting();

    userChoice = getUserChoice();

	if (userChoice == 1)
	{
		printf("Enter a number\n");
        printf("> ");

		scanf("%d", &numberInput);

        printf("\n");

        numberToChar(numberInput);
	}

	else if (userChoice == 2)
	{
		printf("Enter a character\n");
        printf("> ");

		scanf(" %c", &letterInput);

        printf("\n");

        charToNumber(letterInput);
	}
	else printf("\nPlease enter a 1 or a 2\n\n");

	return 0;
}

void greeting(void)
{
    printf("Hello, welcome to the number letter converter\n");
    printf("\n");
}

int getUserChoice(void)
{
    int userChoice;

	printf("(ENTER 1) -- To enter a number and find the corresponding character\n");
	printf("(ENTER 2) --To enter a character and find the numerical value\n");

	scanf("%d", &userChoice);

    printf("\n");

    return userChoice;
}

void numberToChar(int numberInput)
{
    char letter1 = (char)numberInput;
    int number2 = numberInput + 10;
    char letter2 = (char)number2;

    printf("The number entered was %d and the corresponding character is %c.\n", numberInput, letter1);
    printf("The new number (plus 10) is %d and the corresponding character is %c\n", number2, letter2);
    printf("\n");
}

void charToNumber(char letterInput)
{
    int newNum = (int)letterInput;
    int newNum2 = newNum + 15;
    char newLetter = (char)newNum2;

    printf("The letter entered was %c and the corresponding number is %d\n", letterInput, newNum);
    printf("The new number (plus 15) is %d and the corresponding character is %c\n", newNum2, newLetter);
    printf("\n");
}

// Signed Midlight25 2019