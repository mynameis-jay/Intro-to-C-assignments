/* Jalen Jarrett
COP 3223C
Oct 29, 2025
This program will prompt the user to enter the odometer reading, fuel gauge, miles per gallon,
and distance wanted to travel, then calculate how far the driver can go before running out of fuel
*/

#include <stdio.h> // including input/output and main.h header
#include "main_10_29.h"

void drive(double* odomPtr, double* flelPtr, double mpg, double distance) {

    double fuelTemp = *flelPtr; // a temp variable that holds the value of the fuel pointer for later arithmetic

    *flelPtr = ((*flelPtr * mpg) - distance) / mpg; // finds the fuel per mile, subtracts the product from the distance traveled, and finally converts the difference back into the current fuel level
    if (*flelPtr <= 0) { // if the fuel pointer reaches 0 or goes below it
        *flelPtr = 0; // the pointer will automatically equal zero, or indicate that the vehicle has ran out of fuel
        *odomPtr += fuelTemp * mpg; // adding the last few miles you can travel to the odometer pointer
    }
    else {
        *odomPtr += distance; // else, add the distance traveled to the odometer pointer
    }
}

int main() {

    double odom, fuel, mpg, distance;

    printf("Enter odometer reading, fuel gauge reading and mpg: "); // prompting the user to enter odometer reading, fuel, miles per gallon, and desired distance to travel
    scanf("%lf %lf %lf", &odom, &fuel, &mpg);
    printf("\nEnter the distance you want to drive: ");
    scanf("%lf", &distance);

    while (fuel > 0) { // while there's still fuel in the vehicle
        drive(&odom, &fuel, mpg, distance); // calling the drive function using the aforementioned variables

        printf("\nCurrent reading odometer = %.2lf, fuel = %.2lf\n", odom, fuel); // printing the current readings
        
        if (fuel <= 0) // if fuel gets to 0, will continue back to the beginning of the loop, consequently breaking the loop
            continue;
        printf("\nEnter the distance you want to drive: "); // prompting the user to enter their desired distance
        scanf("%lf", &distance);
    }
    printf("\n\nNo more fuel!"); // once the fuel has ran out, will print "No more fuel!"

    return 0; // returning to the system
}