# Intro to Programming in C
## Prog 3: Conditions
### Assignment Purpose
To compile, build, and execute an interactive program with using characters, integers, doubles, simple calculations and conditions for decisions in program flow and interaction.

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
The assignment will be due Sep 18, 2019 at 11:59pm. (It will be on a Wednesday.)
*It is recommended that you submit your work by 9:00 p.m. as no assistance will be provided after 9:00 p.m. should you encounter any technical difficulties.*

### Libraries
This assignment will require the standard input-output C library.

```C
#include <stdio.h> //printf, scanf
```

### Skills
- Conditional Formatting
- Type-casting
- Simple math
- Input/Output

### Instructions
- Print “Hello, welcome to the number letter converter” onto the screen.
  - Ask the user if they would like to create a letter from a number (Enter 1)
  - Or a number from a letter (Enter 2)
  - Get the choice from the user (1 or 2)
  - You may assume the user will enter an integer for the choice
- If the user enters a 1 ask and get another number from the user
  - Create a letter from that number
  ```C
    //EXAMPLE: char letter = (char)inputNumber;
  ```
  - Add 10 to the number that was entered
  - Change the new number to a letter
  - Print all 4 onto the screen (2 numbers and 2 letters)
- If the user enters a 2 ask and get a letter (character) from the user
  - Create a number from that letter
  ```C
    //EXAMPLE: int number = (int)inputLetter;
  ```
  - Add 15 to the number that was just created
  - Change the new number to a letter
  - Print all 4 onto the screen (2 numbers and 2 letters)
- If the user enters any number other than 1 or 2 print the message “please enter a 1 or 2” onto the screen
  - Test your program before submitting

Go break some eggs

-M