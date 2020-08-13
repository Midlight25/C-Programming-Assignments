// Michael Mesquita
// September 13, 2019
// COP 2220 Third Program (prog3.c) Conditions

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
  int userChoice; //Input - user enters a number that coresponds to their desire.
  int userNumberChoice; //Input - number for processing with option 1
  char letterChoice1; //Output - letter created from number from choice 1.
  char letterChoice1Post; //Output - letter created post processing in choice 1.
  char userLetterChoice; //Input - number for processing with option 2
  int numberChoice2; //Output - number created from letter from choice 2
  char letterChoice2Post; //Output - Letter created from processing number choice 2.

  //Welcomes the user
  printf("Hello, welcome to the number letter converter.\n");

  //ASK and GET user choice for desired processing algorithm.
  printf("\nWould you like to:\n  (1) Create a letter from a number?\n");
  printf("  (2) Create a number from a letter?\n>");
  scanf("%d", &userChoice);

  if (userChoice == 1)
  {
    //ASK and Get number into userNumberChoice
    printf("\nPlease enter the number you want to create a letter from.\n>");
    scanf("%d", &userNumberChoice);
    printf("\nYou chose the number %d.\n", userNumberChoice);

    //Typecasts the number into the first letter in the output
    letterChoice1 = (char)userNumberChoice;
    printf("Your number became the letter \"%c\".\n", letterChoice1);

    //Adds 10 to the user's number
    userNumberChoice += 10;
    printf("Your number became the number %d.\n", userNumberChoice);

    //Typecasts the number into the second lettler in the output.
    letterChoice1Post = (char)userNumberChoice;
    printf("That number became the letter \"%c\".\n", letterChoice1Post);
  }
  else if (userChoice == 2)
  {

    //ASK and GET letter into userLetterChoice.
    printf("\nPlease enter the letter you want to create a number from.\n>");
    scanf(" %c", &userLetterChoice);
    printf("\nYour choice was letter \"%c\".\n", userLetterChoice);

    //Creates first number from user choice.
    numberChoice2 = (int)userLetterChoice;
    printf("Your letter turned into the number %d.\n", numberChoice2);

    //Adds 15 to first number
    numberChoice2 += 15;
    printf("Your number became the number %d.\n", numberChoice2);

    //Creates new letter from second number.
    letterChoice2Post = (char)numberChoice2;
    printf("Your number became the letter \"%c\".\n", letterChoice2Post);
  }
  else
  {

    //User fails to specify correct option from menu.
    printf("Please enter a 1 or 2");
  }

  //Signed Midlight25 2019
  return 0;
}