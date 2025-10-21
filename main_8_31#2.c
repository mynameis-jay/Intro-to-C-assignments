/* Jalen Jarrett
COP 3223C
Aug 27, 2025
This program will test arithmetic, using subtraction, multiplication,
and division to convert fahrenheit to celsius
*/

#include <stdio.h> // importing standard library

int main () { // creating the main function for my program to run

    int fahr; // declaring fahrenheit as an integer and celsius as a float
    float cel;

    printf("Enter the temperature in Fahrenheit: "); // prompting user to input degrees in fahrenheit
    scanf("%d", &fahr);

    cel = (fahr - 32.0) * 5 / 9; // converts fahrenheit to celsius using conversion formula (subtracting by 32.0 for float output)

    printf("\nThe temperature in Celsius is: %f", cel); // printing out the final temperature after conversion
    
    return 0; // return to system

}