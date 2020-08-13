# Intro to Programming in C: Prog 6 (Functions)
## Assignment Purpose
To compile, build, and execute an interactive program with using characters, integers, simple math, and develop user defined functions.

## Assignment Details
- One source code file (unformatted text) will be submitted
- The file name must match the assignment
- The code should be tested and run on a Microsoft compiler before it is uploaded onto Canvas
- The code must be submitted on time in order to receive credit (11:59 PM on the due date)
- Late submissions will not be accepted or graded
- All programming assignments are individual work, sharing code is considered cheating
- Code needs to be tested with the Microsoft Compiler before being submitted
- Code needs to be submitted with **lastname_firstname_prog6.c** syntax

## Assignment Due Date
The assignment will be due Oct 16, 2019 at 11:59pm. (It will be on a Wednesday.)
*It is recommended that you submit your work by 9:00 p.m. as no assistance will be provided after 9:00 p.m. should you encounter any technical difficulties.*

## Libraries and Skills
This assignment will require the standard input-output C library.
This assignment will require these skills:
- printf
- scanf
- simple math
- type casting (char to integer)
- type casting (integer to char)

## Instructions
### Take the code from prog3 and break it up into one main function and 4 user defined functions.

- Declare all variables.
- Use descriptive function names
- Use function prototypes above the main function
- Use function definitions below the main function
- Call all 4 functions from inside the body of the main function

### Function 1:
*Takes no arguments and has a void return type*

1. Print “Hello, welcome to the number letter converter” onto the screen

### Function 2:
*Takes no arguments and returns an integer*

1. Ask the user if they would like to create a number from a letter (Enter 1) or a letter from a number (Enter 2)
2. Get the choice from the user (1 or 2) (return the user input to the main function)
    *You may assume the user will enter an integer for the choice*
3. If the user enters a 1 ask and get another number from the user (pass the number to function 3)
### Function 3:
*Takes one argument, the number input by the user and has a void return type*

1. Create a letter from that number
1. Add 10 to the number that was entered
1. Change the new number to a letter
1. Print all 4 onto the screen (2 numbers and 2 letters)
1. If the user enters a 2 ask and get a letter (character) from the user (pass the character to function 4)

### Function 4:
*Takes one argument, the character input by the user and has a void return type*

1. Create a number from that letter
1. Add 15 to the number that was just created
1. Change the new number to a letter
1. Print all 4 onto the screen (2 numbers and 2 letters)
1. If the user enters any number other than 1 or 2 print the message “please enter a 1 or 2” onto the screen
1. Test your program before submitting