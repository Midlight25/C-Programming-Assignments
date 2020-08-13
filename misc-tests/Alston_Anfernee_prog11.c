//Anfernee Alston prog 11 11/27/19

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 25
#define INVENTORYSIZE 100
#define SPEEDLIMIT 70.0

typedef struct {
	int VIN;
	char type[25];
	char make[25];
	char model[25];
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
//Using the mpg field of the car,  calculate and print the
//time it will take and the cost of gas
void RoadTrip(car inventory[], int index);

//remove the car from the inventory (3 POINT BONUS only if it is successful)
//update count (by reference) if a car was successfully removed
void RemoveCars(car inventory[], int index, int *count);

int main()
{
	//declare variables
	char fname[25], lname[25];
	char option;
	car inventory[INVENTORYSIZE];
	int count = 0;

	Greeting(fname, lname);

	//add 4 to the inventory
	FourCars(inventory);
	count = 4;

	option = 'A';

	while (option != 'Q')
	{
		MenuOptions();

		printf("Please enter an option: \n");
		scanf(" %c", &option);
		option = toupper(option);

		if (option == 'P')
		{
			PrintInventory(inventory, count);
		}

		else if (option == 'A')
		{
			AddCars(inventory, &count);
		}


	}

	//{
	//conditions for each choice


	//}
	return 0;
}

//function definition
//Greets the user

void Greeting(char fname[], char lname[])
{
	printf("Enter your first name: ");
	scanf("%s", fname);

	printf("Enter your last name: ");
	scanf("%s", lname);

	printf("Hello %s %s and welcome to the rental car inventory\n", fname, lname);

	printf("This program manages an inventory of cars\n");
	printf("Each car has a unique integer VIN number\n");
	printf("\nThere are 4 cars already located into the array\n");

}


//fill the inventory with 4 cars
void FourCars(car inventory[])
{

	car temp1 = { 1011, "Compact", "Ford","Focus", 40.2 };
	inventory[0] = temp1;

	car temp2 = { 3421, "Compact", "Chevrolet", "Cruze", 32.8 };
	inventory[1] = temp2;

	car temp3 = { 7086, "Compact", "Nissan", "Altima", 22.4 };
	inventory[2] = temp3;

	car temp4 = { 5478, "Premium", "Honda", "Pilot", 30 };
	inventory[3] = temp4;


}

//input: car with data
//displays all the information of one car
void DisplayCar(car anyCar)
{
	printf("The car VIN is %d\n", anyCar.VIN);
	printf("The car type is %s\n", anyCar.type);
	printf("The car make is %s\n", anyCar.make);
	printf("The car model is %s\n", anyCar.model);
	printf("The car mpg is %.2f\n", anyCar.mpg);
}

//Ask the user how many cars they want to add
//add the cars to the inventory
//Use the Fillcar function
//update the count (by reference)
void AddCars(car inventory[], int *count)
{
	int i;
	int number;
	printf("How many cars would you like to add? \n");
	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		printf("Enter the VIN number: \n");
		scanf("%d", &inventory[i].VIN);

		printf("Enter the car make: \n");
		scanf(" %s", inventory[i].make);

		printf("Enter the car model: \n");
		scanf(" %s", inventory[i].model);


		*count += 1;
	}
}

//prints the inventory of cars onto the screen
//use the Display car function
void PrintInventory(car inventory[], int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("The car VIN is %d\n", inventory[i].VIN);
		printf("The car type is %s\n", inventory[i].type);
		printf("The car make is %s\n", inventory[i].make);
		printf("The car model is %s\n", inventory[i].model);
		printf("The car mpg is %.2f\n", inventory[i].mpg);
	}

}

//prints the Menu options onto the screen
void MenuOptions()
{

	printf("\nEnter 'P' to print the rental car inventory onto the screen \n");
	printf("Enter 'A' to add car(s) to the inventory\n");
	printf("Enter 'R' to remove a car from the inventory\n");
	printf("Enter 'K' to Calculate the gas and time for a Road trip for a car in the current inventory\n");
	printf("Enter 'Q' to quit\n");

}
