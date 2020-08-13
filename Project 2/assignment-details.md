# Intro to Programming in C
## Prog 2: Input and Math
### Assignment Purpose
To compile, build, and execute an Interactive program using functions from
stdio.h (printf and scanf), functions from ctype.h (tolower and toupper), and simple math in C.

### Assignment Details
- One source code file (unformatted text) will be submitted
- The file name must match the assignment
- The code should be tested and run on a Microsoft compiler before it is uploaded onto Canvas
- The code must be submitted on time in order to receive credit (11:59 PM on the due date)
- Late submissions will not be accepted or graded
- All programming assignments are individual work, sharing code is considered cheating
- Code needs to be tested with the Microsoft Compiler before being submitted
- Code needs to be submitted with **lastname_firstname_prog1.c** syntax

### Assignment Due Date
The assignment will be due Sep 6, 2019 at 11:59pm. (It will be on a friday.)
*It is recommended that you submit your work by 9:00 p.m. as no assistance will be provided after 9:00 p.m. should you encounter any technical difficulties.*

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