# Intro to Programming in C
# Prog 5: Cumulative
### Assignment Purpose
To compile, build, and execute an interactive program with using characters, integers, and a loop for repetition.

### Libraries
This assignment will require the standard input-output C library and the C-Type library.

```C
#include <stdio.h> //printf, scanf
#include <ctype.h> //toupper, tolower
```

### Instructions
1. Welcome the user to a number/character converter and have them choose between two options
    1. Number to character conversion
    2. Character to number conversion
    3. Or have them press 0 to quit.
        - *The menu should use an int input for selection*
        - *The menu should tell the user if they did not enter an acceptable input*

2. If user chooses option (1)
    1. Ask the user how many numbers that they would like to enter
    2. Reply with a feedback message and instructions:
        1. User will enter the numbers one by one
        2. Computer will respond with the converted number at each iteration
    3. Loop This:
        1. Have the user enter a number
        2. Reply with the converted character
        3. *Add the number to a sum and report the sum to the user*
    4. After the loop, tell the user:
        1. The number of inputs the user passed
        2. The sum of all user inputs
        3. The average of all user inputs

3. If the user chooses option (2)
    1. Ask the user the number of character they would like to input
    2. Reply with a feedback message and instructions:
        1. User will enter the characters one by one
        2. Computer will respond with the converted number at each iteration
    3. Loop This:
        1. Have the user enter a character
        2. Reply with the character in uppercase and the corresponding value
        3. Reply with the character in lowercase and the corresponding value
        4. Reply with the current sum of all the lowercase letters at **THIS** iteration.
    4. After the loop, tell the user:
        1. The number of inputs user passed
        2. The sum of all the lowercase values *(typecast into int)*
        3. The average of all the lowercase values *(typecast into int)*

4. After the processing has been completed, the menu should loop back to the beginning until the user exits the loop with option (0)