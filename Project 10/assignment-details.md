# Intro to Programming in C: Prog 10 (Pointers)
## Assignment Purpose
To compile, build, and execute an interactive program using loops, user defined functions with pointer arguments (pass by reference) vs. pass by copy.

## Assignment Details
- One source code file (unformatted text) will be submitted
- The file name must match the assignment
- The code should be tested and run on a Microsoft compiler before it is uploaded onto Canvas
- The code must be submitted on time in order to receive credit (11:59 PM on the due date)
- Late submissions will not be accepted or graded
- All programming assignments are individual work, sharing code is considered cheating
- Code needs to be tested with the Microsoft Compiler before being submitted
- Code needs to be submitted with **lastname_firstname_prog10.c** syntax

## Assignment Due Date
This assignment will be due Nov 20th, 2019 at 11:59PM (It will be on a Wednesday.) *It is recommended that you submit your work by 9:00 p.m. as no assistance will be provided after 9:00 p.m. should you encounter any technical difficulties.*

## Libraries and Skills
This assignment will require the standard input-output C library.
This assignment will require knowledge of pointers.

## Functions and Required Code
```C
//Road trip
//preprocessor directives
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SPEEDLIMIT 70

//function prototypes
//Greet the user
void Greeting();

//Calculations for one road trip
void CalculateTheTotal();

//get input (1 (YES) or 0 (NO)) to continue
//return (BY REFERENCE) the users selection
void AnotherRoadTrip(int *againPtr);

//Calculate the cost of the gas on a trip
//declare, ask, and get the price per gallon and the mpg
//calculate and return (BY REFERENCE) the cost of gas
//for the number of miles passed to the function
void GasCost(double miles, double *gasCostPtr);

//using a 70 MPH speed limit and the miles passed to the function
//calculate and return (BY REFERENCE) the total time it will take as a double
//Also calculate and print the number of hours and number of minutes
void TripTime(double miles, double *totalTimePtr);
```

## Instructions
### This program will calculate some of the costs of a road trip.

The user will enter the number of miles, the cost of gas per gallon, and the miles per gallon(mpg) of the car.

    - Calculate the cost of gas and the time it will take for a road trip.
    - Assume the user will drive an average of 70 MPH.
    - The user will enter the number of miles, the cost of gas per gallon, and the miles per gallon(mpg) of the car.

### Additional Requirements

    - Use function prototypes.
    - Write comments for each function that will appear before each prototype and again before each function
    -efinition.
    - Be sure to comment your code adequately.
    - Be sure to indent properly.
    - Use meaningful variable names.
    - NO Late Submission