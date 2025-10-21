/* Jalen Jarrett
COP 3223C
Sep 4, 2025
This program will prompt the user to enter in the cost
and selling price into the terminal and will tell them whether they've 
had a profit or loss, and how much money they might've profited or 
lost
*/

#include <stdio.h>// including input/output library

int main() { // creating a main function to run the program

    float price, cost; // creating variables for profit and cost input
    
    printf("Enter the cost price and selling price: "); // prompting user to input cost and selling price
    scanf("%f %f", &cost, &price);
    
    float profit_or_loss = price - cost; // creating a variable to determine profit or loss
    
    if (profit_or_loss > 0) { // if the prof_or_loss variable is greater than 0, indicates a profit
        printf("You made a profit.\nThe amount of profit is $%.2f", profit_or_loss); // prints out profit amount with two decimals
    }
    
    else if (profit_or_loss < 0) { // if prof_or_loss variable is less than 0, indicates a loss
        printf("You incurred loss.\nThe amount of loss is $%.2f", profit_or_loss * -1); // prints out loss amount with two decimals
    }                                                                                  // will mulitply the loss by -1 to produce a positive numerical outcome
    
    else { // any other value (a value of 0) will print nothing

    }

    return 0; // returning to the system
}