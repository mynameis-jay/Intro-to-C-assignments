/* Jalen Jarrett
COP 3223C
Oct 5, 2025
This program will instruct the user to enter an integer as a max value
and will create a pyramid using the range of said number
*/

#include <stdio.h> // including input/output library and declaring the print_triangle function for the main function to call
#include "main_10_5#1.h"

int main(void) { // creating the function that runs the program

    int max_value, choice, triCount = 1; // declaring each variable needed, triCount is set to 1 assuming at least one pyramid will be made

    printf("Enter max value: "); // prompting the user to enter the max value
    scanf("%d", &max_value);

    print_triangle(max_value); // passing the max value into the print_triangle function as an actual parameter

    printf("Enter 0 for exit or any other digit to continue: "); // start of the menu-based selection
    scanf("%d", &choice);

    while (choice != 0) { // while any number beside 0 is chosen, the user can create more pyramids
        printf("Enter max value: ");
        scanf("%d", &max_value);

        print_triangle(max_value);

        printf("Enter 0 for exit or any other digit to continue: ");
        scanf("%d", &choice);
        
        triCount++; // each pyramid created increases the triCount value
    }

    printf("Total triangle printed: %d", triCount); // once 0 is selected, pyramids will no longer be created; will print the amount of pyramids made

    return 0; // returning to the system
}

int print_triangle(int max_value) { // creating the function that makes the pyramids

    for (int i = 1; i <= max_value; i++) { // these loops ensures each column of the pyramid is printed given the amount of rows there are
        for (int space = 1; space <= max_value - i; space++) // prints spaces before the current digit based on distance from the bottom column
            printf(" ");

        for (int j = 1; j <= i; j++) { // prints the numbers proceeding the max number
            printf("%d", j);
        }
        for (int x = i - 1; x >= 1; x--) { // prints the numbers following the max number
            printf("%d", x);
        }
        printf("\n"); // goes to the new line after the column has been printed
    }   
}