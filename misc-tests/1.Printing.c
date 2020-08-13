#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main(void){
  //GET age from USER
  int age;
  printf("Enter your age.\n>");
  scanf("%d", &age);

  if (age >= 21)
  {
    printf("\nLET's McFREAKING LOSE IT.\n");
  }
  else 
  {
    printf("\nGo back to elementary school.\n");
  }

  return 0;
}
