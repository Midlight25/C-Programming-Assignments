// Michael Mesquita
// October 29, 2019
// COP 2220 Eighth Program (prog8.c) Cumulative

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Great the user and explain the game
// Input: the user's first name
void greeting(char name[]);

// Input: 3 character arrays, (the solution, the scrambled solution, the name)
// This function calls the compare function.
// Returns (1) if they match and (2) if they don't.
int getGuess(char scrambled[], char solution[], char name[]);

// Input: 2 character arrays (solution, guess, and name)
// Return: (1)if they match (2) if they do not match
int compare(char solution[], char guess[], char name[]);

// Input: characer array
// Result (by reference): character array with all capital letters
void toUpperCaseWord(char word[]);

int main(void) {
    // Character Arrays
    char name[25], userChoice;
    char solutionWord[25], scrambledWord[25];

    // Loop control variables
    int currentlyRunning = 1;
    int exitControl = 1;

    // File Pointer
    FILE *inputFile;

    // Ask + Get name
    printf("What is your name?\n");
    printf("> ");
    scanf(" %s", name);
    printf("\n");

    // Do greeting with entered name and open file for first time.
    greeting(name);
    inputFile = fopen("input.txt", "r");

    do
    {
        // Resets exitControl so that the loop performs correctly
        exitControl = 1;

        // Reads Question+Answer pair from Input File and formats them for logic.
        fscanf(inputFile, " %s", solutionWord);
        fscanf(inputFile, " %s", scrambledWord);
        toUpperCaseWord(solutionWord);
        toUpperCaseWord(scrambledWord);

        // Asks user for answer and lets them do this twice.
        getGuess(scrambledWord, solutionWord, name);

        do
        {
            // Asks user if they would like to try another word.
            printf("Would you like to go again? (Y)es or (N)o\n");
            printf("> ");
            scanf(" %c", &userChoice);
            printf("\n");

            // Formats choice for logic below
            userChoice = toupper(userChoice);

            // Exits if user says no.
            if(userChoice == 'N')
            {
                //Sets exit flags for main loop and this question loop
                currentlyRunning = 0;
                exitControl = 0;
            }
            // Continues the loop if user says yes.
            else if (userChoice == 'Y')
            {
                // Sets exit flag for this question loop
                exitControl = 0;
            }
            // Triggered if user did not input a valid answer.
            else
            {
                // Does not set any exit flag, just end message.
                printf("That is not a valid selection, please enter a valid selection.\n");
                printf("\n");
            }

            // End of "Restart?" question loop
        } while (exitControl != 0);

        // End of main loop
    } while(currentlyRunning == 1);

    printf("Now Quiting");
    return 0;
}

// Greets the user with their name
void greeting(char name[]){
    printf("Welcome, %s\n", name);
    printf("This is a guessing game. I'll give you a scrambled word, you try to work out what it is.\n");
    printf("You get two shots at this now, but don't slack off now.\n");
    printf("\n");
}

// Changes the letters in a string to uppercase
// Return with pass-by-reference
void toUpperCaseWord(char word[])
{
    // Find length of string
    int len = strlen(word);
    int i;

    // Iterates through character array applying toUpper as it goes.
    for(i = 0; i < len; i++)
    {
        word[i] = toupper(word[i]);
    }

}

// ASK + GET user guess, calls compare() for the answer.
// Let's the user try twice to get the correct answer.
// If the user does not get it right after two tries, gives user answer and exits the function
// Returns INT, 1 if user answered correctly and 2 if user answers incorrectly.
int getGuess(char scrambled[], char solution[], char name[])
{
    // User Guess character array
    char userGuess[25];
    // Loop control variable
    int timesGuessed = 0;

    do
    {
        // ASK + Get user's guess
        printf("Alright %s, here's the word:\n", name);
        printf("    %s\n", scrambled);
        printf("What is your guess?\n");
        printf("> ");
        scanf(" %s", userGuess);
        printf("\n");

        // Format's user for logic
        toUpperCaseWord(userGuess);

        // If user answered correctly
        if (compare(solution, userGuess, name) == 1)
        {
            // Lets user know they answered correctly and exits function
            // Returns 1
            printf("Congratulations %s, you got it right!\n", name);
            printf("\n");
            return 1;
        }
        // If user did not answer correctly and this is not their first guess.
        else if (compare(solution, userGuess, name) == 2 && timesGuessed > 0)
        {
            // Lets user know answer and increases the timesGuessed counter.
            printf("Sorry %s, you didn't get it right either.\n", name);
            printf("\n");
            printf("The correct answer is %s", solution);
            printf("\n");
            timesGuessed++;
        }
        // If user didn not answer correctly
        else
        {
            // Lets user know they answered incorrectly and increases the timesGuessed counter
            printf("Sorry %s, you didn't get it right.\n", name);
            printf("\n");
            printf("Here's a hint though, it starts with an \"%c\"\n", solution[0]);
            printf("\n");
            timesGuessed++;
        }

        // End of ASK+GET Guess loop
    } while(timesGuessed < 2);

    // Returns 2 if user did not answer correctly
    return 2;
}

// Compare's user's guess to solution
// Returns INT, 1 if solution and guess match, 2 if solution and guess do not match.
int compare(char solution[], char guess[], char name[])
{
    if (strcmp(solution, guess) == 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}