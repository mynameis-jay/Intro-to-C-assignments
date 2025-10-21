/* Jalen Jarrett
COP 3223C
Sep 6, 2025
This program will prompt the user to type in three sets
of points into the terminal, then determine whether
or not all points fall on the same straight line
*/

#include <stdio.h> // importing the input/output library and
#include <math.h> // the math library to take the absolute value of each slope

int main() { // creating a main function to run the program

    float input_x1, input_x2, input_x3, input_y1, input_y2, input_y3; // creating each point as a float

    printf("Enter coordinates (x1, y1): "); // instructing user to input all six x and y values
    scanf("%f %f", &input_x1, &input_y1); // saves them to a float
    printf("Enter coordinates (x2, y2): ");
    scanf("%f %f", &input_x2, &input_y2);
    printf("Enter coordinates (x3, y3): ");
    scanf("%f %f", &input_x3, &input_y3);

    float slope1 = fabs((input_y2 - input_y1) / (input_x2 - input_x1)); // calculates the absolute value of the first slope
    float slope2 = fabs((input_y3 - input_y1) / (input_x3 - input_x1)); // calculates the absolute value of the second slope
    
    if (slope1 == slope2) { // if slope 1 and 2 equal the same value, program will print 
        printf("They fall on one straight line"); // each slope falls on the same straight line
    }

    else { // otherwise, program will print they don't fall on the same straight line
        printf("They do not fall on one straight line");
    }

    return 0; // returning to the system
}