#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SPEEDLIMIT 70
#define TOLLRATE .04
#define FOODCOST 12.00

// Greets the user
void greeting();

// Calculates total time of road trip using miles(input) and Avg Mph(constant)
double tripTimeCalc(double miles);

// Calculates total cost of gas for trip using miles and cost of gas (ask and get)
double gasCost(double miles);

// Calculate cost of food based on time.
double foodCost(double timeOfTrip);

// Calculate and return total cost from cost of tolls, cost of food, cost of gas
double calcTotalCost(double miles, double gasTotal, double foodCost);

// Asks if user would like to calculate another trip. FAKE BOOL
int AnotherRoadTrip();

int main(void)
{
    // Controls main loop
    int currentlyRunning = 1;
    double numberOfMiles, totalTripTime, totalGasCost, totalFoodCost, completeCost;

    do
    {
        greeting();

        printf("How far is your destination in miles?\n");
        printf("> ");

        scanf("%lf", &numberOfMiles);

        printf("\n");

        totalGasCost = gasCost(numberOfMiles);

        printf("You will spend about $%.2f of gas on this trip.\n", totalGasCost);
        printf("\n");

        totalTripTime = tripTimeCalc(numberOfMiles);

        printf("Your trip will take about %.1f hours.\n", totalTripTime);
        printf("\n");

        currentlyRunning = AnotherRoadTrip();
    } while (currentlyRunning != 0);

    return 0;
}

void greeting()
{
    printf("Welcome to your Road Trip Calculator!\n");
    printf("\n");
}

double tripTimeCalc(double miles)
{
    int hours, minutes;
    double totalTimeHours = miles / SPEEDLIMIT;

    hours = (int)totalTimeHours;
    minutes = hours * 60;

    printf("This trip will take %d hours total and %d minutes total.\n", hours, minutes);
    printf("\n");

    return totalTimeHours;
}

double gasCost(double miles)
{
    double gasPricePerGallon, totalGasPrice, mpg;

    printf("What is the current price per gallon?\n");
    printf("> ");

    scanf("%lf", &gasPricePerGallon);

    printf("\n");
    printf("How many miles can you go on one gallon of gas?\n");
    printf("> ");

    scanf("%lf", &mpg);

    printf("\n");

    if (mpg != 0)
    {
        totalGasPrice = (gasPricePerGallon * miles) / mpg;
    }

    return totalGasPrice;
}

// Calculate cost of food based on time.
double foodCost(double timeOfTrip)
{
    int adjustedTime = timeOfTrip / 3;
    double totalFoodCost = FOODCOST * (double)adjustedTime;
    return totalFoodCost;
}

// Calculate and return total cost from cost of tolls, cost of food, cost of gas
double calcTotalCost(double miles, double gasTotal, double foodTotal)
{
    double tollCost = TOLLRATE * miles;
    double totalCost;

    printf("The toll that you will pay for this trip is %.2f.\n", tollCost);
    printf("\n");

    totalCost = tollCost + gasTotal + foodTotal;

    return totalCost;
}

// Asks if user would like to calculate another trip. FAKE BOOL
int AnotherRoadTrip()
{
    int selection;

    printf("Would you like to calculate another trip? 1 (yes) or 0 (no)\n");
    printf("> ");

    scanf("%d", &selection);

    printf("\n");

    return selection;
}
