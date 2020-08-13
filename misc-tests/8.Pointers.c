#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define PI 3.141529

// ASK + GET diameter and returns it passbyreference.
void getRad(double *rPtr);

// Calculates area of a circle from the radius and returns it.
double areaCalc(double radius);

// Calculates area and perimeter of a circle.
// Returns: passbyreference
void calcCircle(double radius, double *aPtr, double *cPtr);

int main(void) {
    double r2;
    double radius, area, cir;

    getRad(&radius);
    getRad(&r2);

    area = areaCalc(r2);

    calcCircle(radius, &area, &cir);
    // printf("END OF THE LINE: %f, %f, %f", radius, area, cir);
    return 0;
}

void getRad(double *rPtr)
{
    printf("Enter radius:\n");
    printf("> ");
    scanf("%lf", rPtr);
}

double areaCalc(double radius)
{
    double area;
    area  = PI * radius * radius;
    return area;
}

void calcCircle(double radius, double *aPtr, double *cPtr)
{
    // Assigns radius
    *aPtr = areaCalc(radius);
    // Assigns perimeter
    *cPtr = PI * 2 * radius;
}
