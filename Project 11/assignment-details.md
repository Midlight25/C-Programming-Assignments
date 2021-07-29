# Intro to Programming in C: Prog 11 (Pointers, Strings, and Structs)
## Assignment Purpose
To compile, build, and execute an interactive program broken up into user defined functions using structs, input/output parameters, and arrays

## Libraries and Skills
This assignment will require the standard input-output C library.
This assignment will require knowledge of pointers, arrays, structs, menu creation, and strings.

### Required Functions
```C
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
```

## Instructions
### Intro
The focus of your topic is rental cars. You also need to create a menu.

  - (P)....Print the rental car inventory onto the screen
  - (A)....Add car(s) to the inventory
  - (R)....Remove a car from the inventory (3 POINT BONUS)
  - (K)....Calculate the gas cost and time for a Road trip for a car in the current inventory
  - (Q)....QUIT

### Body
- You will use structs and an array to organize the data in the program. Your struct must contain at the
following kinds of information:
  - 1 integer –
    - VIN (unique for each instance)
  - 3 strings (character arrays) –
    - Type of rental (NO WHITE SPACE) – DO NOT USE class, it is a reserved word in C
    - Make of the car (NO WHITE SPACE) – Example Ford
    - Model of the car (NO WHITE SPACE) – example Mustang
The size of all 3 arrays will be 25
Use #define SIZE 25
  - 1 double
    - mpg
- When you add new car the program will ask how many cars to be added and then prompt the user for
each of the fields on a separate line for the number of cars to be entered. (see the prog11.exe
example)
- When you display the cars on the screen, all of the information stored for each entry will be labeled
and displayed. (see the prog11.exe example)
- When you calculate the gas cost and time the roadtrip will take, the program will ask for the VIN
number, locate the entry in the array, and the user will then input the number of miles, and the cost
of gas per gallon. The total gas cost for the trip will be calculated along with the total time and the
hours and minutes for the trip based on 70 MPH Speedlimit. The calculation will be made using the mpg of the car with the same VIN number:
  ```C
  inventory[index].mpg;
  ```
- When you remove a car from the from the list the program will ask you for the integer VIN of the entry to be deleted, locate the entry in the array and remove all of the data for that entry.
  - The list does not need to be sorted
  - To remove an entry, you move the last item in the list to the location of the deleted entry.
  - **Remove is 3 Bonus Points**

### Danger
Be careful to check if the LocateCar function returns a -1 there is no index of -1 so if you try to access inventory[-1]. It does not exist, use a condition to make sure your program never tries to access inventory[-1].
The RemoveCars function may either remove a car by swapping out the last car in the inventory as in the example provided OR you may keep the inventory in order. Please add a comment on your assignment submission about your RemoveCars implementation.
If you did not implement the RemoveCars function, please add the following printf statement for when the user selects the letter R:
  ```C
  printf("\nA car has been rented.");
  ```

### Additional Notes
- You must use the function prototypes provided and they MAY NOT BE MODIFIED
- Your program must start up with 4 valid cars.
- Use function prototypes and NO GLOBAL VARIABLES (penalty)
- Use a #define to set the upper bound of the character array to 25 letters and the inventory to 100 entries.
- Your code should be well designed, well commented and written with good style.

### Hints
- Start work on this as soon as possible.
- It is your responsibility to request this help in the form of specific questions.
- When you ask a question, it should be specific, and you should provide me with the current version of your program.
- The current version of your program should be neatly formatted and commented. It should also be properly indented and use meaningful variable and function names. This will make it easier for anyone helping you to understand what you are trying to do.