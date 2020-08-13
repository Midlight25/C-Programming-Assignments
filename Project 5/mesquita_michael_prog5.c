// Michael Mesquita
// September 25, 2019
// COP 2220 Fifth Program (prog5.c) Cumulative

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main(void){

    int selection; //Stores the option that the user selects in the main menu.
    int sassCount; //Stores how many times the user entered an invalid input.
    int countInput; //How many inputs the user wants to process
    int i, userNumInput, sum, upperCharValue, lowerCharValue; //Variables for processing loops
    int currentlyRunning = 1; //controls main menu loop
    char charOutput, userCharInput, upperChar, lowerChar; //Variables for processing loops
    double averagedInput; //Stores average of user inputs

    //Welcomes the user to the program
    printf("Midlight25 Prog5 Assignment\n");\
    printf("\n");
    printf("Welcome to this number/character converter!\n");

    //Simulates controling loops with boolean values.
        //"How in the hell does C not have integrated boolean values? It's like the most basic
        //data type that a computer can have!" -Michael
    while (currentlyRunning == 1)
    {
        //Initiates sass value to zero, only at the start of the program and nevermore.
        sassCount = 0;

        printf("\n");
        printf("Main Menu:\n");

        do
        {
            printf("\n");
            printf("Please make a selection:\n");
            printf("    (1) Number to Character Conversion\n");
            printf("    (2) Character to Number Conversion\n");
            printf("    (0) Quit the program\n");
            printf("> ");

            scanf("%d", &selection);


            //If the user has not entered a valid input 3x
            if (!(selection >=0 && selection <= 2) && sassCount == 3)
            {
                printf("\n");
                printf("It's been three loops, there are three choices, it shouldn't be this hard.\n");
                printf("Please enter a number between 0 and 2!\n");

                //Sets sass to 0 so that this message can appear again.
                sassCount = 0;
            }
            //If user has not enetered a valid input
            else if (!(selection >= 0 && selection <=2))
            {
                printf("\n");
                printf("Invalid input, please make a valid selection from the list above.\n");

                //raises sass value
                sassCount++;
            }

        //Loop will only exit if there has been a valid selection
        //Tested at the end of the loop.
        } while(!(selection >= 0 && selection <= 2));

        //Quits the program
        if (selection == 0)
        {
            printf("\n");
            printf("Quiting the program...\n");
            printf("Goodbye\n");

            //Sets "boolean" value to "False" therby causing the loop to exit
            currentlyRunning = 0;
        }
        //Initiates option 1
        else if (selection == 1)
        {
            //Initiates sum to 0 for this session
            sum = 0;

            printf("\n");
            printf("How many numbers would you like to convert today?\n");
            printf("> ");

            scanf("%d", &countInput);

            printf("\n");
            printf("Ok, we will be converting %d numbers today.\n", countInput);
            printf("You must enter the numbers one-by-one, and I will reply with the conversion after each one.\n");

            for (i = 0; i < countInput; i++)
            {
                printf("\n");
                printf("Please enter number (%d)\n", i + 1);
                printf("> ");

                scanf("%d", &userNumInput);

                //typecast int to char and adds int to sum
                charOutput = (char)userNumInput;
                sum += userNumInput;

                printf("\n");
                printf("Your input was %d\n", userNumInput);
                printf("The character converted from your input was \"%c\"\n", charOutput);
                printf("The current sum after (%d) inputs is %d\n", i + 1, sum);
            }

            //averages all the inputs by dividing sum by the number of inputs given by the user.
            averagedInput = (double)sum / (double)countInput;

            printf("\n");
            printf("Reminder: you entered %d inputs.\n", countInput);
            printf("The sum of all the inputs was %d\n", sum);
            printf("The average of all the inputs was %.3f\n", averagedInput);

        }
        //Initiates option 2
        else if (selection == 2)
        {
            //Initiates sum to 0 for this sesssion
            sum = 0;

            printf("\n");
            printf("How many characters would you like to convert today?\n");
            printf("> ");

            scanf(" %d", &countInput);

            printf("\n");
            printf("Ok, we will be converting %d characters today!\n", countInput);
            printf("You enter the characters one by one.\n");
            printf("And I will report the upper and lower case versions of those characters at each iteration.\n");

            for(i = 0; i < countInput; i++)
            {
                printf("\n");
                printf("Please enter character %d:\n", i + 1);
                printf("> ");

                scanf(" %c", &userCharInput);

                //Changes char input to both upper and lower values and typecasts to int
                upperChar = toupper(userCharInput);
                upperCharValue = (int)upperChar;
                lowerChar = tolower(userCharInput);
                lowerCharValue = (int)lowerChar;

                //Adds lowercase int value to sum
                sum += lowerCharValue;

                printf("\n");
                printf("The user entered: \"%c\"\n", userCharInput);
                printf("The char in uppercase is \"%c\"\n", upperChar);
                printf("The value for the uppercase char is %d\n", upperCharValue);
                printf("The char in lowercase is \"%c\"\n", lowerChar);
                printf("The value for the lowercase char is %d\n", lowerCharValue);
                printf("The current sum of lowercase values @ %d iterations is %d\n", i + 1, sum);
            }

            //Averages lowercase char values by dividing it with the number of inputs the user gave.
            averagedInput = (double)sum / (double)countInput;

            printf("\n");
            printf("You entered %d inputs\n", countInput);
            printf("The sum of all the lowercase values is %d\n", sum);
            printf("The average of all the lowercase values is %.3f\n", averagedInput);
        }

    }

    //Signed Midlight25 2019
    return 0;
}