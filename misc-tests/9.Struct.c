#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct{
    char name[25];
    int id;
    double gpa;
} student;

void fillSPtr(student *sPtr);

int main(void)
{
    student s1;
    fillSPtr(&s1);
    printf("%s %d %.2f", s1.name, s1.id, s1.gpa);
    return 0;
}

void fillSPtr(student *sPtr)
{
    printf("Name:");
    scanf(" %s", (*sPtr).name);
    printf("\nID:");
    scanf("%d", &(*sPtr).id);
    printf("\nGPA:");
    scanf("%lf", &sPtr -> gpa);
}
