// Michael Mesquita
// November 12, 2019
// COP 2220 Ninth Program (prog9.c) Structs

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> //printf, scanf
#include <ctype.h>
#include <string.h> //strcpy

typedef struct{
    char heroName[25];
    char power[25];
    int id;
    double level;
} hero;

//Declare your struct here above the function prototypes
//the data type is your choice
//YOU MAY CHANGE THE FUNCTIONS TO REFLECT YOUR CHOSEN TOPIC
//ask and get the users name
//Greet the user and explain the fields of the fruit structure
//input: (by reference) character array
void greeting(char name[]);

//declare a temp hero
//fills the data fields of a fruit one by one with user input
//return the filled hero
hero fillHero(void);

//input: hero with data
//displays all the information of one hero(all four fields)
void displayHero(hero heroStruct);

//Input: string changes all chars in string to upper case.
//Returns with pass by reference.
void toUpperString(char word[]);

int main(void){
    char name[25];
    // Ask + Get name and display greeting
    greeting(name);

    // Zero One hero instance. (Kamen Rider Zero One Rising Hopper)
    hero zero_one = {"Zero One", "JUMP", 2101, 7.5};

    // Vulcan hero instance generation. (Kamen Rider Vulcan Shooting Wolf)
    hero vulcan;
    strcpy(vulcan.heroName, "Vulcan");
    strcpy(vulcan.power, "BULLET");
    vulcan.id = 2102;
    vulcan.level = 7.2;

    // Hero generation explanation.
    printf("To enter a new hero, you must enter a codename, a power, an ID, and a threat level.\n");
    printf("Now accepting values for three new heroes:\n");
    printf("\n");

    // ASK + Get info for new Heroes
    hero hero3 = fillHero();
    hero hero4 = fillHero();
    hero hero5 = fillHero();

    // Displaying Hero information
    printf("Information on %s\n", zero_one.heroName);
    printf("\n");
    displayHero(zero_one);

    printf("Information on %s\n", vulcan.heroName);
    printf("\n");
    displayHero(vulcan);

    printf("Information on %s\n", hero3.heroName);
    printf("\n");
    displayHero(hero3);

    printf("Information on %s\n", hero4.heroName);
    printf("\n");
    displayHero(hero4);

    printf("Information on %s\n", hero5.heroName);
    printf("\n");
    displayHero(hero5);

    printf("Goodbye %s.\n", name);

    return 0;
}
void greeting(char name[])
{
    // Ask + Get name
    printf("What is your name?\n");
    printf("> ");
    scanf(" %s", name);
    printf("\n");

    // Print ASCII Art, because why not?
    printf(" "
           "   __  __                      ____          __          __\n"
           "   / / / /___   _____ ____     / __ \\ ____ _ / /_ ____ _ / /_   ____ _ _____ ___\n"
           "  / /_/ // _ \\ / ___// __ \\   / / / // __ `// __// __ `// __ \\ / __ `// ___// _ \\\n "
           "/ __  //  __// /   / /_/ /  / /_/ // /_/ // /_ / /_/ // /_/ // /_/ /(__  )/  __/\n"
           "/_/ /_/ \\___//_/    \\____/  /_____/ \\__,_/ \\__/ \\__,_//_.___/ \\__,_//____/ \\___/\n");

    printf("\n");

    // Welcome message
    printf("Hello %s, welcome to the Hero Database program.\n", name);
    printf("\n");
}

void displayHero(hero heroStruct)
{
    printf("\t%s:\n", heroStruct.heroName);
    printf("\t\tID: %d\n", heroStruct.id);
    printf("\t\tPower: %s\n", heroStruct.power);
    printf("\t\tThreat Level: %.2f\n", heroStruct.level);
    printf("\n");
}

hero fillHero(void){
    hero tempHero;
    char userInput[100];

    printf("Recording information for new Hero.\n");
    printf("\n");

    // Ask + Get Hero Name
    printf("\tPlease enter the name of the Hero.\n");
    printf("\t> ");
    scanf(" %s", userInput);
    strcpy(tempHero.heroName, userInput);
    printf("\n");

    // Ask + Get Hero Power
    printf("\tPlease enter %s's power.\n", tempHero.heroName);
    printf("\t> ");
    scanf(" %s", userInput);
    toUpperString(userInput);
    strcpy(tempHero.power, userInput);
    printf("\n");

    // Ask + Get Hero ID
    printf("\tPlease enter a four digit id for %s.\n", tempHero.heroName);
    printf("\t> ");
    scanf("%d", &tempHero.id);
    printf("\n");

    // Ask + Get Hero level
    printf("\tPlease enter %s's threat level on a scale of 10.\n", tempHero.heroName);
    printf("\t> ");
    scanf("%lf", &tempHero.level);
    printf("\n");

    printf("Saved %s's data.\n", tempHero.heroName);
    printf("\n");

    return tempHero;
}

void toUpperString(char word[])
{
    int len = strlen(word);
    int i;

    // Iterates through string and apples toupper() to each character.
    for(i = 0; i < len; i++)
    {
        word[i] = toupper(word[i]);
    }
}

// Signed Midlight25 2019