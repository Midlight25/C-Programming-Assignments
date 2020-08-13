// Michael Mesquita
// September 18, 2019
// COP 2220 Fourth Program  (prog4.c) Loops

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  //Establishment of variables
  int numOfCharacters;           //Input from user
  int num1, num2;                //Output from inputLetter
  char inputLetter;              //Input from user
  char upperLetter, lowerLetter; //Output from num1 and num2

  //User welcome screen
  printf("Counting Script Initializing...\n\n");
  printf("Hello, let's find out the numerical value of lowercase and uppercase letters and/or keyboard characters.\n");
  printf("How many characters would you like to test for this session? \n>");
  scanf("%d", &numOfCharacters);

  for (int i = 0; i < numOfCharacters; i++)
  {
    //ASK + GET inputLetter for processing
    printf("\nPlease type in a character.\n>");
    scanf(" %c", &inputLetter);

    //Performs typecasting and processing on the letter for output.
    printf("\nGot it! Please hold for processing...\n");
    upperLetter = toupper(inputLetter);
    num1 = (int)upperLetter;
    lowerLetter = tolower(inputLetter);
    num2 = (int)lowerLetter;
    printf("All Done!\n\n");

    //Displays output for user.
    printf("Your letter in uppercase was \"%c\" and it's associated int value is %d.\n", upperLetter, num1);
    printf("Your letter in lowercase was \"%c\" and it's associated int value is %d.\n", lowerLetter, num2);
  }

  return 0;
}

//Signed Midlight25 2019