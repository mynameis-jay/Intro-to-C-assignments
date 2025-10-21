/* Jalen Jarrett
COP 3223C
Oct 5, 2025
This program will prompt the user to type numbers into the terminal and will continue taking
numbers until -100 is typed. Then, the program will return the number of positive and negative numbers,
and zeros
*/

#include <stdio.h> // including input/output library

int main(void) { // creating the function to run the program

    int number, posNum, negNum, zero; // creating the variables to save each number and classify each value to
    posNum = negNum = zero = 0; // by default, all counters are set to 0

    printf("Input the number:\n"); // prompting user to input numbers
    scanf("%d", &number);

    while (number != -100) { // while -100 (the loop breaking number) hasn't been typed, more numbers will be taken

        if (number > 0) // if the number is greater than zero, it must be positive, positive counter increases
            posNum++;
        
        else if (number < 0) // if the number is less than zero, it must be negative, negative counter increases
            negNum++;
        
        else // else, it must be a zero, zero counter increases
            zero++;
        
            scanf("%d", &number);
    }
    // once the loop is broken, the program will print out the final number of positve and negative numbers, and zeros
    printf("\nNumber of positive numbers: %d\nNumber of Negative numbers: %d\nNumber of Zero: %d", posNum, negNum, zero);

    return 0; // returning to the system
}
