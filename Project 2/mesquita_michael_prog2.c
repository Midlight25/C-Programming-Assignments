//Michael Mesquita
//August 30, 2019
//COP 2220 Second Program (prog2.c)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char letter; //Input - Letter for processing
  char upper_letter; //Output - Letter typecast to uppercase
  int number_letter; //Output - Letter typecast to ASCII value
  int upper_number_letter; //Output - Uppercase letter typecast to ASCII value.

  //Introduces the program and prompts user for a letter
  printf("Hello my name is Michael.\n");
  printf("Please type one letter -> ");
  scanf(" %c", &letter);

  //Uppercase processing on input and pushed to output with original data.
  upper_letter = toupper(letter);
  printf("\nYour original letter was \"%c\", but I changed it to \"%c\".\n\n", letter, upper_letter);

  //Uppercase number typecast into ASCII value and multiplied by 10.
  upper_number_letter = (int)upper_letter;
  upper_number_letter = upper_number_letter * 10;
  printf("Your letter converted to upper-case is \"%c\". Did you know the ASCII value of that letter times 10 is %d?\n\n", upper_letter, upper_number_letter);

  //Lower-case letter typecast into ASCII value and multiplied by 10.
  number_letter = (int)letter;
  number_letter = number_letter * 10;
  printf("One more! Your original character was \"%c\", the ASCII value for that letter multiplied by 10 is %d. \n\n", letter, number_letter);

  //Program outro and exit
  printf("End of the line. Program quiting. \n");
  return 0;
}