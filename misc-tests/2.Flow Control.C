#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main(void)
{
  int selection;
  do
  {
    printf("\nPlease select the program you want to run...\n");
    printf("(1) Odd Number Sum and Even Product Chain (forLoop)\n");
    printf("(2) (whileLoop)\n");
    printf(">");
    scanf("%d", &selection);
  } while(selection <= 0 || selection >= 3);

  if (selection == 1)
  {
    int num, sum = 0, prod = 1, i;

    //ask and get a number from the user and calculate a sum of all odd numbers
    //from 1 to num
    printf("\nEnter a number here please.\n");
    printf(">");
    scanf("%d", &num);

    printf("\nOdd Number Sum");
    for(i = 1; i < num; i+=2)
    {
      printf("\n  i is %d\n", i);
      sum += i;
      printf("  Sum is now %d\n", sum);
    }

    printf("\nEven Number Product Chain");
    for(i = 2; i < num; i += 2)
    {
      printf("\n  i is %d\n", i);
      prod *= i;
      printf("  Product Chain = %d\n", prod);
    }
  }
  else if (selection == 2)
  {
    int num, sum = 0, prod = 1, i;

    printf("Please enter a number that is less than 30.\n");
    printf(">");
    scanf("%d", &num);

    while(num > 30)
    {
      printf("This message should only show up if the loop was entered.");
      break;
    }
  }

  return 0;
}
