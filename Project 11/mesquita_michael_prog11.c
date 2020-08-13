// Michael Mesquita
// November 20, 2019
// COP 2220 Eleventh Program (prog11.c) Pointers, Strings, and structs

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 25
#define INVENTORYSIZE 100
#define SPEEDLIMIT 70.0

typedef struct {
    int vin;
    char type[SIZE];
    char make[SIZE];
    char model[SIZE];
    double mpg;
} car;

//Greets the user
void Greeting(char fname[], char lname[]);

//fill the inventory with 4 cars
void FourCars(car inventory[]);

//input: car with data
//displays all the information of one car
void DisplayCar(car anyCar);

//prints the inventory of cars onto the screen
//use the Display car function
void PrintInventory(car inventory[], int count);

//prints the Menu options onto the screen
void MenuOptions();

//declare a temp car
//fills the data fields of a car one by one with user input
//return the filled car
car FillCar();

//Ask the user how many cars they want to add
//add the cars to the inventory
//Use the Fillcar function
//update the count (by reference)
void AddCars(car inventory[], int *count);

//Display the VIN numbers and the car model
//ask the user which car they want to access
//find and return the location (index) by reference
//if the VIN number is not found in the array the index returned will be -1
void LocateCar(car inventory[], int count, int *index);

//Ask and get the number of miles for the trip
//Ask and get the price of gas at the pump
//Using the mpg field of the car, calculate and print the
//time it will take and the cost of gas
void RoadTrip(car inventory[], int index);

/* Deletes data at position of |index| and returns |count| - 1 by reference.

   Implementation:
        Imports inventory[] and count as Pointers. | Imports index as copy.
        Inventory is the array that you wish to modify, count is the variable used to keep track
        of how many array indecies that are filled, index is the index of the data that you wish to
        delete.
        After user confirms the deletion, the function then "shifts" all the data ahead of the index
        back by one "position" and subtracts one from count.

    How it works:
        The function uses a loop to iterate only through the positions of the array that need to be modified.
        At any position, the function will copy the data that is one index ahead into the current iteration or "position".
        The result is that the current index is overwritten by the data that is infront of it, then the index that is one
        ahead will be overwritten by the data that is ahead of it, and so on an so forth until the function reaches the
        end of the array that is given by |count|. The function will then subtract 1 from count to reflect the deleted data from
        the array.

    Considerations:
        Because of the way that this function is written, the end result is two copies of one index at the end position
        of the array, but because |count| is subtracted by 1 at the end, any function that uses |count| to determine how many
        indecies are used in this array will ignore the second copy of the last index because count will no longer reach that far.
        The copy is still there, but because |count| is subtracted by one it is unavailable to access; unless |count| is incremented by
        one. However, if |count| is ever incremented by one, the second copy of the last index is very likely to be overwritten
        because the functions that increment count will usually replace that second copy with new data.
        */
void DeleteCar(car inventory[], int *count, int index);

int main(void)
{
    // Menu + Loop Control Variable
    char userChoice;
    // User's Name Variable, size 25
    char fname[SIZE], lname[SIZE];
    // Array of car datatype, size 100
    car inventory[INVENTORYSIZE];
    // Partially filled array control Variable for inventory
    int count;
    // Input variable for car selection
    int index;

    // ASK + GET user name and welcome message.
    Greeting(fname, lname);

    //Initialize 4 cars into inventory and update count.
    FourCars(inventory);
    count = 4;

    do
    {
        // Print Menu Options
        MenuOptions();

        // ASK + GET User choice from menu
        printf("What would you like to do?\n");
        printf("> ");
        scanf(" %c", &userChoice);
        printf("\n");

        // Change user choice to uppercase for logic
        userChoice = toupper(userChoice);

        // Main Menu logic
        switch(userChoice)
        {
            // If user presses 'Q', quits program. userChoice becomes an exit flag for loop.
            case 'Q':
                printf("Now Quiting: Goodbye!\n");
                printf("\n");
                break;
            // If user presses 'P', prints inventory onto screen
            case 'P':
                printf("Scanning Inventory:\n");
                printf("\n");
                PrintInventory(inventory, count);
                break;
            // If user presses 'A', adds car to inventory.
            case 'A':
                printf("Booting Car Addition Subroutine\n");
                printf("\n");
                // Adds # of cars determined by user input to inventory array, updates count.
                AddCars(inventory, &count);
                printf("Ending Car Addition Subroutine\n");
                printf("\n");
                break;
            // If user presses 'R', removes user selected car from inventory.
            case 'R':
                printf("Booting Car Removal Subroutine\n");
                printf("\n");
                // ASK + GET user for car from inventory
                LocateCar(inventory, count, &index);
                // If LocateCar didn't return an error, delete car in inventory.
                if (index != -1)
                {
                    // Removes car determined by index, updates count.
                    DeleteCar(inventory, &count, index);
                }
                printf("Ending Car Removal Subroutine\n");
                printf("\n");
                break;
            // If user presses 'K', opens road trip function with user selected car.
            case 'K':
                printf("Booting Road Trip Calculation Subroutine\n");
                printf("\n");
                // ASK + GET user for car from inventory
                LocateCar(inventory, count, &index);
                // If LocateCar didn't return an error, launch RoadTrip with user selected car.
                if (index != -1)
                {
                    // Self-contained program, calculates gas cost and total time for distance in miles.
                    // Imports inventory and index for car in inventory.
                    RoadTrip(inventory, index);
                }
                printf("Ending Road Trip Calculation Subroutine\n");
                printf("\n");
                break;
            // If user did not select a valid menu item, asks them to try again.
            default:
                printf("Input unrecognize please enter a valid choice from the menu.\n");
                printf("\n");
                break;
        }

    } while (userChoice != 'Q');

    return 0;
}

//Greets the user
void Greeting(char fname[], char lname[])
{
    //ASK + GET user's first name.
    printf("What is your first name?\n");
    printf("> ");
    scanf(" %s", fname);
    printf("\n");

    // ASK + GET user's last name.
    printf("What is your last name?\n");
    printf("> ");
    scanf(" %s", lname);

    // Prints ASCII Art Title (Standard Font)
    printf(
"  ____               ____               _          _ \n"
" / ___| __ _  _ __  |  _ \\  ___  _ __  | |_  __ _ | |\n"
"| |    / _` || '__| | |_) |/ _ \\| '_ \\ | __|/ _` || |\n"
"| |___| (_| || |    |  _ <|  __/| | | || |_| (_| || |\n"
" \\____|\\__,_||_|    |_| \\_\\\\___||_| |_| \\__|\\__,_||_|\n"
" ____          _          _                          \n"
"|  _ \\   __ _ | |_  __ _ | |__    __ _  ___   ___    \n"
"| | | | / _` || __|/ _` || '_ \\  / _` |/ __| / _ \\   \n"
"| |_| || (_| || |_| (_| || |_) || (_| |\\__ \\|  __/   \n"
"|____/  \\__,_| \\__|\\__,_||_.__/  \\__,_||___/ \\___|   \n"
            );
    printf("\n");

    // Prints welcome message
    printf("Welcome %s %s, to the Car Rental Management System.\n", fname, lname);
    printf("Every car here has a unique VIN, there are 4 cars in the system currently.\n");
    printf("\n");
}

//fill the inventory with 4 cars
void FourCars(car inventory[]){
    // Creates Car #1
    car temp1 = {2343, "Compact", "Ford", "Focus", 40.2};
    inventory[0] = temp1;

    // Creates Car #2
    inventory[1].vin = 4565;
    strcpy(inventory[1].type, "Compact");
    strcpy(inventory[1].make, "BMW");
    strcpy(inventory[1].model, "x5");
    inventory[1].mpg = 32.5;

    // Creates Car #3
    car temp2 = {3652, "Coupe", "DeLorean", "DMC-12", 35.2};
    inventory[2] = temp2;

    // Creates Car #4
    car temp3 = {2222, "Sports", "Chevrolet", "Camaro", 15.2};
    inventory[3] = temp3;
}

//input: car with data
//displays all the information of one car
void DisplayCar(car anyCar)
{
    // Print car's make for easy identification in list.
    printf("Printing %s car:\n", anyCar.make);
    printf("\n");

    // Print car info offset by tab for easier reading in list.
    printf("\tVIN: %d\n", anyCar.vin);
    printf("\tTYPE: %s\n", anyCar.type);
    printf("\tMAKE: %s\n", anyCar.make);
    printf("\tMODEL: %s\n", anyCar.model);
    printf("\tMILEAGE: %.2f MPG\n", anyCar.mpg);
    printf("\n");
}

//prints the inventory of cars onto the screen
//use the Display car function
void PrintInventory(car inventory[], int count)
{
    // Iteration control variable
    int i;

    // Lets the user know how many cars there are in database.
    printf("There are currently %d cars in the database.\n", count);
    printf("\n");

    // Car display loop
    for(i = 0; i < count; i++)
    {
        // Calls DisplayCar with index from loop, stopping when count has been reached.
        DisplayCar(inventory[i]);
    }

    // For spacing and better readability.
    printf("\n");
}

//prints the Menu options onto the screen
void MenuOptions()
{
    // Prints Menu Options
    printf("Main Menu:\n");
    printf("\t(P) - Print the rental car inventory\n");
    printf("\t(A) - Add car(s) to the inventory\n");
    printf("\t(R) - Remove a car from the inventory (3 POINT BONUS)\n");
    printf("\t(K) - Calculate the gas cost and time for a Road trip for a car in the current inventory\n");
    printf("\t(Q) - Quit the program\n");
    printf("\n");
}

//declare a temp car
//fills the data fields of a car one by one with user input
//return the filled car
car FillCar(){
    // Declares tempcar Variable
    // Will be returned later
    car tempCar;

    printf("Creating new car:\n");

    // ASK + GET car VIN
    printf("\tWhat is this car's VIN?\n");
    printf("\t> ");
    scanf("%d", &tempCar.vin);

    // ASK + GET car type
    printf("\tWhat is this car's type?\n");
    printf("\t> ");
    scanf(" %s", tempCar.type);

    // ASK + GET car make
    printf("\tWhat is this car's make?\n");
    printf("\t> ");
    scanf(" %s", tempCar.make);

    // ASK + GET car model
    printf("\tWhat is this car's model?\n");
    printf("\t> ");
    scanf(" %s", tempCar.model);

    // ASK + GET car MPG
    printf("\tWhat is this car's mileage?\n");
    printf("\t> ");
    scanf("%lf", &tempCar.mpg);
    printf("\n");

    // Prints confirmation message
    printf("New %s car saved to database.\n", tempCar.make);
    printf("\n");

    // Returns created temp car.
    return tempCar;
}

//Ask the user how many cars they want to add
//add the cars to the inventory
//Use the Fillcar function
//update the count (by reference)
void AddCars(car inventory[], int *count)
{
    // Variable for user input
    int numberToFill;

    // Loop Control Variable
    int i;

    // ASCII Art because it's the last program so why not?
    printf(
"    ___       __    __   ______               \n"
"   /   | ____/ /___/ /  / ____/___ ___________\n"
"  / /| |/ __  / __  /  / /   / __ `/ ___/ ___/\n"
" / ___ / /_/ / /_/ /  / /___/ /_/ / /  (__  ) \n"
"/_/  |_\\__,_/\\__,_/   \\____/\\__,_/_/  /____/\n"
            );
    printf("\n");

    // ASK + GET number of cars user wants to add
    printf("How many cars would you like to add today?\n");
    printf("> ");
    scanf("%d", &numberToFill);
    printf("\n");

    // Iterate loop and appends to the last position in the array new car from FillCar().
    for(i = 0; i < numberToFill; i++)
    {
        inventory[*count + i] = FillCar();
    }

    // Updates count for outside functions through pass by reference.
    *count += numberToFill;
}

//Display the VIN numbers and the car model
//ask the user which car they want to access
//find and return the location (index) by reference
//if the VIN number is not found in the array the index returned will be -1
void LocateCar(car inventory[], int count, int *index)
{
    // Loop Control Variable
    int i;
    // User input variable
    int vinInput;

    // Sets default index as -1
    // Will return this if no cars are found in the database that match VIN user input
    *index = -1;

    // Let's the user know how many choices they have
    printf("There are %d cars in the database.\n", count);
    printf("\n");

    // Iterative print of car information, including VIN
    for(i = 0; i < count; i++)
    {
        printf("\tMAKE: %s", inventory[i].make);
        printf("\tVIN: %d\n", inventory[i].vin);
    }
    printf("\n");

    // ASK + GET user selection of VIN
    printf("Please enter the VIN of your car:\n");
    printf("> ");
    scanf("%d", &vinInput);
    printf("\n");

    // Iteratively searches through the array to see if car with matching VIN exists
    // Updates index pointer if matching VIN is found
    // Limitation: will only return the first car that it finds with the matching VIN
    for(i = 0; i < count; i++)
    {
        if (inventory[i].vin == vinInput)
        {
            *index = i;
        }
    }

    // Prints confirmation message if car with matching VIN is found
    if (*index >= 0)
    {
        printf("Selecting the %s\n", inventory[*index].make);
    }
    // Prints error message if no car with matching VIN is found
    else
    {
        printf("Unable to select a car with that VIN.\n");
    }

}

//Ask and get the number of miles for the trip
//Ask and get the price of gas at the pump
//Using the mpg field of the car, calculate and print the
//time it will take and the cost of gas
void RoadTrip(car inventory[], int index)
{
    // Input variable for distance
    int miles;
    // Output variable for time taken
    int totalHours, totalMinutes;
    // Input variable for price of gas per gallon
    double gasPrice;
    // Output variable for total gas cost
    double totalGasCost;

    // Printing "Road Trip" ASCII art
    printf(
"    ____                  __   ______     _     \n"
"   / __ \\____  ____ _____/ /  /_  __/____(_)___ \n"
"  / /_/ / __ \\/ __ `/ __  /    / / / ___/ / __ \\\n"
" / _, _/ /_/ / /_/ / /_/ /    / / / /  / / /_/ /\n"
"/_/ |_|\\____/\\__,_/\\__,_/    /_/ /_/  /_/ .___/ \n"
"                                       /_/      \n"
            );
    printf("\n");

    // ASK + GET Distance of Road Trip
    printf("How many miles is your trip?\n");
    printf("> ");
    scanf("%d", &miles);
    printf("\n");

    // ASK + GET Price of Gas
    printf("What is the price of per gallon?\n");
    printf("> ");
    scanf("%lf", &gasPrice);
    printf("\n");

    // Calculates total gas price based on car's mileage and cost of gas.
    totalGasCost = (miles / inventory[index].mpg) * gasPrice;
    // Calculates total time in hours based on speed limit and distance
    totalHours = miles / SPEEDLIMIT;
    // Calculates remainder of time in minutes from # of hours and speed limit.
    totalMinutes = (((double)miles / (double)SPEEDLIMIT) - totalHours) * 60;

    // Displays total gas price and total time in hours and minutes to user.
    printf("Total Gas Cost: $%.2f\n", totalGasCost);
    printf("Total Time: %d hours and %d minutes\n", totalHours, totalMinutes);
    printf("\n");

}

/* Deletes data at position of |index| and returns |count| - 1 by reference.
   Implementation:
        Imports inventory[] and count as Pointers / Imports index as copy.
        Inventory is the array that you wish to modify, count is the variable used to keep track
        of how many array indecies that are filled, index is the index of the data that you wish to
        delete.
        After user confirms the deletion, the function then "shifts" all the data ahead of the index
        back by one "position" and subtracts one from count.
    How it works:
        The function uses a loop to iterate only through the positions of the array that need to be modified.
        At any position, the function will copy the data that is one index ahead into the current iteration or "position".
        The result is that the current index is overwritten by the data that is infront of it, then the index that is one
        ahead will be overwritten by the data that is ahead of it, and so on an so forth until the function reaches the
        end of the array that is given by |count|. The function will then subtract 1 from count to reflect the deleted data from
        the array.
    Considerations:
        Because of the way that this function is written, the end result is two copies of one index at the end position
        of the array, but because |count| is subtracted by 1 at the end, any function that uses |count| to determine how many
        indecies are used in this array will ignore the second copy of the last index because count will no longer reach that far.
        The copy is still there, but because |count| is subtracted by one, it is unavailable to access unless |count| is incremented by
        one. However, if |count| is ever incremented by one, the second copy of the last index is very likely to be overwritten
        because the functions that increment count will usually replace that second copy with new data.
        */
void DeleteCar(car inventory[], int *count, int index)
{
    // Loop control variable
    int i;
    // Input, user confirmation
    char userConfirmation;

    printf(
"    ____                                    ______          \n"
"   / __ \\___  ____ ___  ____ _   _____     / ____/___ ______\n"
"  / /_/ / _ \\/ __ `__ \\/ __ \\ | / / _ \\   / /   / __ `/ ___/\n"
" / _, _/  __/ / / / / / /_/ / |/ /  __/  / /___/ /_/ / /    \n"
"/_/ |_|\\___/_/ /_/ /_/\\____/|___/\\___/   \\____/\\__,_/_/     \n"
            );
    printf("\n");

    do
    {
        // ASK + GET User confirmation of deletion with car make.
        printf("Are you sure that you want to remove the %s?\n", inventory[index].make);
        printf("  (Y)es\n");
        printf("  (N)o\n");
        printf("> ");
        scanf(" %c", &userConfirmation);
        printf("\n");

        // Changes userConfirmation to uppercase for logic.
        userConfirmation = toupper(userConfirmation);

        // If user confirms deletion, deletes selected car from inventory. Exits loop with exitFLag
        if (userConfirmation == 'Y')
        {
            // Prints confirmation message with car's make.
            printf("Removal of the %s confirmed\n", inventory[index].make);
            // Removes car by copying the data of the car in front of it into the first car's slot
            // Repeats for all datablocks infront of index of deleted car.
            for(i = index; i < *count; i++)
            {
                inventory[i] = inventory[i + 1];
            }
            // Updates count to reflect deleted car.
            *count -= 1;
        }
        // If user rejects deletion, prints error message and exits loop with exit flag.
        else if (userConfirmation == 'N')
        {
            printf("Canceling the removal\n");
        }
        // If user does not confirm or reject deletion, askes them to choose an option and continues loop
        else
        {
            printf("Invalid input: please enter a valid selection.\n");
        }
        printf("\n");

        // Exits loop if user confirms or denies deletion
    } while (userConfirmation != 'Y' && userConfirmation != 'N');
}

// Signed Midlight25 2019