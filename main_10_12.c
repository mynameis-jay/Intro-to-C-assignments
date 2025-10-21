/* Jalen Jarrett
COP 3223C
Oct 12, 2025
This program prompts the user to enter in a value and will take the 
sum of the factorial of the number and divide it by the sum of the power
of the number. Then, it'll display the final sum
*/

#include <stdio.h> // including input/output library and math.h header
#include "main_10_12.h"

int main(void) {
    
    int n; // creating the variable that saves the number n and prompting the user to enter the number
    double fact, pow, sum = 0;
    printf("Enter your n:\n");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) { // loop calls the factorial and power functions for as long as i is not greater than n
        fact = factorial(i); // caling each function using i as a formal parameter
        pow = power(i, i);

        sum += pow / fact; // divides the returned values from the factorial and power functions and adds them to the sum variable
    }

    printf("\nSummation of the series from 1 to %d is: %.2lf", n, sum); // prints the final sum

    return 0; // returning to the system
}

long long factorial(int num) { // creating the factorial function

    long long fact = 1, sum = 1; // declaring the factorial and sum variables as long long integer

    for (int i = 1; i <= num; i++) { // determines the factorial of the num variable 
        for (int j = 1; j <= i; j++) {
            fact *= j; // whatever the current number j is will be multiplied by the current factorial value
        }

        sum = fact; // saves the factorial varible to the sum variable before setting the factorial variable back to 1
        fact = 1; // when the loop repeats, it will ensure the factorial variable has been wiped of its previous value
    }
    
    return sum; // returning the sum as a long long integer
}

long long power(int x, int y) { // creating the power function

    long long pow = 1, sum = 0; // declaring the power variable and setting it equal to x

    for (int i = 1; i <= y; i++) { // for as long as i is less than the value of y, the power variable will be multiplied by x
        pow *= x;
    }
    
    return pow; // returning the power as a long long integer
}