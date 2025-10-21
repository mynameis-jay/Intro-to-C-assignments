/* Jalen Jarrett
COP 3223C
Sep 1, 2025
This program will prompt the user to input a 
five-digit number into the terminal, to then
print out the number in reverse, and finally
print the sum of all five numbers
*/

#include <stdio.h> // including input/output library

int main() { //creating a main function for system to use

    int five_dig_num; //creating the varible that will hold the five-digit number

    printf("Enter a five digit number: "); //prompts user to type in number
    scanf("%d", &five_dig_num);

    int num1, num2, num3, num4, num5; // creating variables to hold each individual number
    int num2_div, num3_div, num4_div, num5_div;

    num1 = five_dig_num % 10; // each line takes one number from the five-digit
    num2_div = five_dig_num / 10; // number and saves them to their own variable
    num2 = num2_div % 10;
    num3_div = num2_div / 10;
    num3 = num3_div % 10;
    num4_div = num3_div / 10;
    num4 = num4_div % 10;
    num5_div = num4_div / 10;
    num5 = num5_div % 10;

    int reverse_number = num1 * 10000 + num2 * 1000 + num3 * 100 + num4 * 10 + num5; // creating the variable that reverses the number, omits leading zeroes

    printf("Reverse Number: %d", reverse_number); // prints out five-dig number in reverse

    int sum_of_digits; // creating the variable to take the sum of all five numbers

    sum_of_digits = num1 + num2 + num3 + num4 + num5;

    printf("\nSum of digits: %d + %d + %d + %d + %d = %d", num5, num4, num3, num2, num1, sum_of_digits); // prints out all five numbers + the sum
    
    return 0; // returns to the system
}