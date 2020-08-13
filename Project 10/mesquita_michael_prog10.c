// Michael Mesquita
// November 15, 2019
// COP 2220 Tenth Program (prog10.c) Pointers

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SPEEDLIMIT 70

//function prototypes

//Greet the user
void greeting();

//Calculations for one road trip
void calculateTheTotal();

//get input (1 (YES) or 0 (NO)) to continue
//return (BY REFERENCE) the users selection
void anotherRoadTrip(int *againPtr);

//Calculate the cost of the gas on a trip
//declare, ask, and get the price per gallon and the mpg
//calculate and return (BY REFERENCE) the cost of gas
//for the number of miles passed to the function
void gasCost(double miles, double *gasCostPtr);

//using a 70 MPH speed limit and the miles passed to the function
//calculate and return (BY REFERENCE) the total time it will take as a double
//Also calculate and print the number of hours and number of minutes
void tripTime(double miles, double *totalTimePtr);

int main(void)
{
    greeting();

    calculateTheTotal();

    return 0;
}

void greeting(void)
{
    // Print road trip ASCII art
    printf("    ____                     __   ______       _\n"
           "   / __ \\ ____   ____ _ ____/ /  /_  __/_____ (_)____      \n"
           "  / /_/ // __ \\ / __ `// __  /    / /  / ___// // __ \\     \n"
           " / _, _// /_/ // /_/ // /_/ /    / /  / /   / // /_/ /     \n"
           "/_/ |_| \\____/ \\__,_/ \\__,_/    /_/  /_/   /_// .___/      \n"
           "   ______        __              __        __/_/           \n"
           "  / ____/____ _ / /_____ __  __ / /____ _ / /_ ____   _____\n"
           " / /    / __ `// // ___// / / // // __ `// __// __ \\ / ___/\n"
           "/ /___ / /_/ // // /__ / /_/ // // /_/ // /_ / /_/ // /    \n"
           "\\____/ \\__,_//_/ \\___/ \\__,_//_/ \\__,_/ \\__/ \\____//_/ \n");
    printf("\n");

    // Print welcome message.
    printf("Welcome to the road trip calculator.\n");
    printf("*All calculations are based on an average speed of 70 MPH.\n");
    printf("\n");
}

// Main processing function, calculates and displays gas cost and time cost.
void calculateTheTotal()
{
    // Initialized variables for miles (input), user choice for repeat (input), total calculated gas and time (output)
    int miles, goAgain;
    double totalGasCost, totalTime;

    // Main processing loop
    do
    {
        // ASK + GET miles
        printf("How many miles is your trip?\n");
        printf("> ");
        scanf("%d", &miles);
        printf("\n");

        // Calculate total cost of gas from miles
        gasCost(miles, &totalGasCost);

        // Print total gas cost
        printf("Your total gas bill will be %.2f dollars this trip.\n", totalGasCost);
        printf("\n");

        // Calculate total time taken based on miles and SPEEDLIMIT
        tripTime(miles, &totalTime);

        //ASK user if they would like to try another calculation.
        anotherRoadTrip(&goAgain);

    } while(goAgain != 0);

}

// ASK + GET user if they would like to try another calculations
// Returns by reference, (1) if yes and (0) if no.
void anotherRoadTrip(int *againPtr)
{
    do {

        // ASK + GET user choice for repeat
        printf("Would you like to go again? (1) Yes or (0) No\n");
        printf("> ");
        scanf("%d", againPtr);
        printf("\n");

        // If user enters an invalid selection, they do not exit the program by accident.
        if (*againPtr != 0 && *againPtr != 1)
        {
            printf("Invalid Input, please enter a valid selection.\n");
            printf("\n");
        }

    } while(*againPtr != 0 && *againPtr != 1);
}

// Calculates total gas cost based on miles Input
// Returns by reference total gas cost as a double.
void gasCost(double miles, double *gasCostPtr)
{
    double price, milesPerGallon;

    // ASK + GET price per gallon
    printf("What is the price of gas per gallon at the pump?\n");
    printf("> ");
    scanf("%lf", &price);
    printf("\n");

    // ASK + GET car millage in miles.
    printf("What's your car's mileage?\n");
    printf("> ");
    scanf("%lf", &milesPerGallon);
    printf("\n");

    // If the car millage does not equal zero.
    if(milesPerGallon > 0)
    {
        *gasCostPtr = (miles / milesPerGallon) * price;
    }
    else
    {
        *gasCostPtr = 0.0;
    }
}

// Calculates total time cost based on input
// Returns by reference, total time in hours as double.
void tripTime(double miles, double *totalTimePtr)
{
    // Variable for displaying minutes
    int minutesTotal;

    // Calculates total time in hours and places it into pointer address for pass by reference.
    *totalTimePtr = miles / SPEEDLIMIT;

    // Calculates total time in minutes from remainder of total time in hours.
    minutesTotal = (*totalTimePtr - (int)*totalTimePtr) * 60;

    // Display total time broken up into hours and minutes.
    printf("The total time of your trip is going to be %d hours and %d minutes.\n", (int)*totalTimePtr, minutesTotal);
    printf("\n");
}