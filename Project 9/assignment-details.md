# Intro to Programming in C: Prog 9 (Structs)
## Assignment Purpose
 To write, compile, build, and execute an interactive program with user defined structure types and user defined functions

## Libraries and Skills
This assignment will require the standard input-output C library and the string.h library.
This assignment will require knowledge of user-defined structs.

## Instructions
### The only modifications to this assignment should be the topic only. Suggested topics: students, athletes, songs, books, game, car, etc.

In this program, you will declare a struct called with 4 fields (2 character arrays, one integer, one double)
Here is an example using fruit:
1. A character array for the name of the fruit
2. A character array for the color of the fruit
3. An integer for the id of the fruit
4. A double for the price of the fruit

In the main function declare 5 instances of fruit (or your selected topic) and one character array for the
users name.
1. Be sure to Declare the name array in the main function, pass it to the Greeting function and ask and get
the name from inside the Greeting function. This is pass by reference and it will update the name in both
the Greeting function and the main function.
1. Initialize 1 of the instances of fruit (or your selected topic) when it is declared in the main function
    ```C
    //example
    fruit f5 = { "banana", "yellow", 1, 0.39 };
    ```
1. Fill the second instance by assigning values to all four fields. Note: YOU MUST USE the dot operator,
assignment statements, and strcpy to assign the values to the character arrays.
1. The other 3 instances will be filled field by field with user input by calling the FillFruit function 3
times.
1. Call the DisplayFruit function five times from the main function to display all the fruit data for all five
fruits onto the screen
1. Say goodbye to the user (by name) from the main function

## Functions and Required Code
```C
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> //printf, scanf
#include<string.h> //strcpy

//Declare your struct here above the function prototypes
//the data type is your choice
//YOU MAY CHANGE THE FUNCTIONS TO REFLECT YOUR CHOSEN TOPIC
//ask and get the users name
//Greet the user and explain the fields of the fruit structure
//input: (by reference) character array
void Greeting(char name[]);

//declare a temp fruit
//fills the data fields of a fruit one by one with user input
//return the filled fruit
fruit FillFruit( );

//input: fruit with data
//displays all the information of one fruit(all four fields)
void DisplayFruit(fruit anyFruit);
```