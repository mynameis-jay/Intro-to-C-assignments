/* Jalen Jarrett
COP 3223C
Sep 25, 2025
This program will prompt the user to enter a four digit number into the terminal,
then return the reverse number, sum of each side, and determine if it's a palindrome
or not
*/

#include <stdio.h> // including input/output library and main.h header to run the program
#include "main_9_28.h"

int main(void) { // creating a main function to call all functions

    int number; // creating the variable the four digit number will be saved to

    printf("Enter a four digit number: "); // prompting the user to enter the four digit number
    scanf("%d", &number);

    int four_dig = isFourDigit(number); // calling the isFourDigit function; passing the number as an actual parameter

    int reverse_0_1 = reverse4Digit(number); // calling the reverse4Digit function; passing the number as an actual parameter
    
    if (reverse_0_1 == -1) // if the number from the reverse4Digit function = -1, the number is unable to be reversed
        printf("Invalid to reverse");

    else // else, the number can be reversed
        printf("Reverse is: %d", reverse_0_1);

    addSides4Digit(number); // calling the addSides4Digit function; passing the number as an actual parameter (doesn't return anything)

    int pal = isPalindrome4Digit(number); // calling the isPalindrome4Digit function; passing the number as an actual parameter

    if (pal == 1) // if the number from the isPalindrome4Digit function = 1, it's a palindrome
        printf("\nPalindrome");
    else if (pal == -1) // if the number = -1, it cannot be converted into a palindrome
        printf("\nInvalid input for palindrome checker");
    else // else, the number isn't a palindrome
        printf("\nNot palindrome");

}

int isFourDigit(int number) { // creating the function that determines if the number is a four digit number or not
    
    if (number >= 1000 && number <= 9999) // if the number greater than or equal to 1000 and less than or equal to 9999, it must be a four digit number
        return 1; // if the number is a four digit number, return 1
    return 0; // else, return 0

}

int reverse4Digit(int digit) { // creating the function to reverse the four digit number, using the four digit number as a formal parameter

    int number = isFourDigit(digit); // calling the isFourDigit number to determine if the number is four digits or not

    if (number == 0) // if the number called is = 0, return -1
        return -1;
    
    int num1, num2, num3, num4, num2_div, num3_div, num4_div; // creating the variables to save each digit seperately

    num1 = digit % 10; // each line takes the last digit from the four digit number and saves it individually
    num2_div = digit / 10;
    num2 = num2_div % 10;
    num3_div = num2_div / 10;
    num3 = num3_div % 10;
    num4_div = num3_div / 10;
    num4 = num4_div % 10;

    int reverseNum = num1 * 1000 + num2 * 100 + num3 * 10 + num4; // finally assembles the four digit number backwards

    return reverseNum; // returns the reversed number

}

int addSides4Digit(int digit) { // creating the function that adds the outside digits of the four digit number

    int number = isFourDigit(digit); // calling the isFourDigit number to determine if the number is four digits or not

    if (number == 0) // if the number called is = 0, the outside digits cannot be added
        printf("\nInvalid input to calculate sides");
    
    else { // otherwise, we'll add the outside numbers
        int num1, num2, sum; // creating the variables to save the outside numbers separately, and finally add them up

        num1 = digit % 10; // these lines separate the outside digits to then add them together, printing out the sum
        num2 = digit / 1000 % 10;
        sum = num1 + num2;
        printf("\nSum of sides is: %d", sum);
    } // returns nothing
}

int isPalindrome4Digit(int digit) { // creating the variable that determines if the number is a palindrome or not

    int reverse = reverse4Digit(digit); // calling the reverse4Digit function

    if (reverse == digit) // comparing the reversed number, as well as the original four digit number, to see if they're equal
        return 1; // if so, return 1
    else if (reverse == -1) // if the number isn't a four digit number, return -1
        return -1;
    else // else, return 0
        return 0;
}