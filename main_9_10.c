/* Jalen Jarrett
COP 3223C
Sep 9, 2025
This code will prompt the user to enter in the ages of three people
and will determine which person is the youngest among the three
*/

#include <stdio.h> // importing input/output library

int main() { // creating a main function for the program to run

    int age1,age2,age3; // creating three variables for each age to be saved to

    printf("Enter ages of three people (person 1, person 2, and person 3): "); // prompts the user to input all three ages
    scanf("%d%d%d",&age1,&age2,&age3);

    if (age1<age3 && age1<age2) // each if statement checks to see if the current age is less than the others
        printf("Person 1 is youngest"); // if the current age is less than each other option, then it's the youngest age
    
    else if (age2<age1 && age2<age3)
        printf("Person 2 is youngest");

    else if (age3<age1 && age3<age2)
        printf("Person 3 is youngest");

    return 0; // returning to the system
}