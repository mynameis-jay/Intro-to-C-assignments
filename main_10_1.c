/* Jalen Jarrett
COP 3223C
Sep 29, 2025
This program will prompt the user to input a minimum and maximum meal value, to then give
the estimated reccomented tip based on the price point, and finally determine how many
valid tip charts were generated
*/

#include <stdio.h> // including input/output library and main.h header to run the function
#include "main_10_1.h"

int main(void) { // creating the main function to call the tip chart function

    int min_price, max_price, chartCounter = 0; // creating variables to save the minimum and maximum price, and the number of charts generated
    
    printf("Enter the minimum and maximum meal values: "); // prompts the user to input the min and max meal values
    scanf("%d %d", &min_price, &max_price);

    printTipChart(min_price, max_price); // calls the tip chart function, passing the min and max values as actual parameters

    while (min_price && max_price) { // while the min and max variables have values, the loop will repeat
        if (min_price < 0 || max_price < 0) // if the min or max variables have a negative value, the loop will break
            break;
        
        else if (min_price <= max_price) { // if the min value is less than the max value, more values will be taken and stored for another tip chart
            printf("Enter the minimum and maximum meal values: ");
            scanf("%d %d", &min_price, &max_price);

            printTipChart(min_price, max_price);
            chartCounter++; // once a chart has been generated, the counter will increase by 1
        }
        else { // else (min value is greater than max value), more values will be taken, but no chart will be generated
            printf("Enter the minimum and maximum meal values: ");
            scanf("%d %d", &min_price, &max_price);

            printTipChart(min_price, max_price); // calling the chart generating function
        }
    }

    printf("You have printed total %d valid charts", chartCounter); // outputs the amount of valid charts created

    return 0; // returning to the system
}

void printTipChart(int min_price, int max_price) { // creating the function to generate the tip charts

    if (min_price < 0 || max_price < 0); // if the min or max variables have a negative value, nothing will be done

    else { // as long as the variables have positive values, a chart will be created
        while (min_price <= max_price) {
            printf("On a meal of $%d, the suggested tip amount $%.2f", min_price, min_price*TIP_RATE);
            printf("\n");
            min_price++;
            
        }
    }
}