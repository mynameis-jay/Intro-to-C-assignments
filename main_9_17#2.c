/*Jalen Jarrett
COP 3223C
Sep 16, 2025
This program will prompt the user to type in the
center point of a circle, and the radius. It will then
generate a random point and determine whether or not the
point lies within the circle
*/

#include <stdio.h> // including the libraries
#include <math.h> // using math for square root
#include <stdlib.h> // using stdlib for random number
#include <time.h> // using time to produce random number after each run


int main() { // creating a main function to run the program

    int x,y,radius; // declaring the x, y, and radius as integers

    printf("Enter Center x,y coordinate and radius\n"); // prompts the user to type in the x, y, and radius into the terminal
    scanf("%d %d",&x,&y);
    scanf("%d",&radius);

    srand(time(0)); // creates a random number after each run
    int gen_x= 1+rand()%(x+radius+3); // creates random a random point whose x and y 
    int gen_y= 1+rand()%(y+radius+3); // will be between 1 and x/y+radius+3

    printf("The generated coordinate is: (%d, %d)\n",gen_x,gen_y); // outputs the random point generated
    int distance = sqrt(((x-gen_x)*(x-gen_x))+((y-gen_y)*(y-gen_y))); // calculates the distance of the generate point from the origin
    (distance>radius) ? (printf("Point is outside the circle")) : (printf("Point is on the circle")); // if the distance of the point is greater
                                                                // than the radius, the point is not in the circle, else, the point is inside of the circle

    return 0; // returning to the system
}