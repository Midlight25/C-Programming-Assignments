# Intro to Programming in C
## Project 2: Input and Math
### Assignment Purpose
To compile, build, and execute an Interactive program using functions from
stdio.h (printf and scanf), functions from ctype.h (tolower and toupper), and simple math in C.

### Instructions
Declare all variables.
1. Print “Hello my name is (add your name here)” onto the screen.
1. Prompt the user for a letter
1. Scan/read the letter (character) from the keyboard.
1. Change the letter to uppercase case //use toupper function from <ctype.h>
  ```C
  //EXAMPLE: char newLetter = toupper(inputLetter);
  ```
1. Print the original letter onto the screen.
1. Print the uppercase letter onto the screen
1. Change the uppercase letter to an integer.
  ```C
   //EXAMPLE: int number = (int)newLetter;
  ```
1. Multiply the number by 10.
1. Print the result onto the screen
1. Change the original letter to an integer.
  ```C
  //EXAMPLE: int number2 = (int)inputLetter;
  ```

1. Multiply the number2 by 10.
1. Print the result onto the screen
1. Test your program before submitting

### Footnote
This assignment will require use of the standard input-output C library and the string format library

```C
#include <stdio.h> //printf, scanf
#include <ctype.h> //toupper, tolower
```

Go break some eggs

-M