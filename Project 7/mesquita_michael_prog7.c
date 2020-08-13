// Michael Mesquita
// October 21, 2019
// COP 2220 Seventh Program (prog7.c) Strings

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Great the user and explain the game
// Input: the user's first name
void greeting(char name[]);

// Input: 2 character arrays (solution and guess)
// Return: (1)if they match (0) if they do not match
int checkGuess(char solution[], char guess[]);

// Input: characer array
// Result (by reference): character array with all capital letters
void toUpperCaseWord(char word[]);

int main(void) {
    char name[25];
    char solutionWord[25], userGuess[25], scrambledWord[25];
    FILE *inputFile;

    printf("What is your name?\n");
    printf("> ");
    scanf(" %s", name);
    printf("\n");

    greeting(name);

    inputFile = fopen("input.txt", "r");
    fscanf(inputFile, " %s", scrambledWord);
    fscanf(inputFile, " %s", solutionWord);
    fclose(inputFile);

    toUpperCaseWord(solutionWord);
    toUpperCaseWord(scrambledWord);

    printf("Alright, here's the word:\n");
    printf("    %s\n", scrambledWord);
    printf("What is your guess?\n");
    printf("> ");
    scanf(" %s", userGuess);
    printf("\n");

    toUpperCaseWord(userGuess);

    if (checkGuess(solutionWord, userGuess) == 1)
    {
        printf("%s, you got it right!\n", name);
        printf("Congratulations!\n");
    }
    else
    {
        printf("Sorry %s, that's wrong.\n", name);
        printf("\n");
        printf("The correct answer is \"%s\"\n", solutionWord);
    }

    printf("\n");
    printf("Now Quiting");

    return 0;
}

void greeting(char name[]){
    printf("Welcome, %s\n", name);
    printf("This is a guessing game. I'll give you a scrambled word, you try to work out what it is.\n");
    printf("You've got one shot at this though, so make it count.\n");
    printf("\n");
}

void toUpperCaseWord(char word[])
{
    int len = strlen(word);
    int i;

    for(i = 0; i < len; i++)
    {
        word[i] = toupper(word[i]);
    }
}

int checkGuess(char solution[], char guess[])
{
    if (strcmp(solution, guess) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}