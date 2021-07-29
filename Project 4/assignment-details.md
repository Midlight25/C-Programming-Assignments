# Intro to Programming in C
# Prog 4: Loops
### Assignment Purpose
To compile, build, and execute an interactive program with using characters, integers, and a loop for
repetition.


### Libraries
This assignment will require the standard input-output C library and the C-Type library.

```C
#include <stdio.h> //printf, scanf
#include <ctype.h> //toupper, tolower
```

### Instructions
- Print “Hello, let’s find out the numerical value of lowercase and uppercase letters and/or keyboard
characters” onto the screen.
- Ask the user how many characters they would like to enter
  - You may assume the user will enter an integer for the choice
- The number the user enters will determine how many characters the user will be entering
- You will use a counting loop (for loop or while loop)
  - Remember to initialize, test, and update
  
Inside the loop body:
  - Ask and get a letter from the user (the user can enter any character on the keyboard)
  - Create an uppercase version of the character that was entered
    ```C
    char upperLetter = toupper(inputLetter);
    ```
  - Get the corresponding integer value of the uppercase letter.
    ```C
    int num1 = (int)upperLetter;
    ```
  - Create a lowercase version of the character that was entered
    ```C
    char lowerLetter = tolower(inputLetter);
    ```
  - Get the corresponding integer value of the lowercase letter.
    ```C
    int num2 = (int)lowerLetter;
    ```
  - Print all four onto the screen telling the user what numbers correspond to which
  characters (2 characters and 2 numbers )
- Test your program before submitting