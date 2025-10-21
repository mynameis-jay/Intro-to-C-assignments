/* Jalen Jarrett
COP 3223C
Sept 23, 2025
This program will prompt the user to input the length and width of a room and a desk
and determine whether the desk will fit into the room or not
*/

#include <stdio.h> // including the input/output library and main.h header to run the program
#include "main_9_24#2.h"

int main(void) { // creating a main function to call the sizeCheck function and output the result
 
    int room_l, room_w, desk_l, desk_w; // creating variables to store the the value from the sizeCheck

    printf("Enter the length and width of the room: "); // prompting the user to enter the length and width of the room and desk
    scanf("%d %d", &room_l, &room_w);
    printf("Enter the length and width of the desk: ");
    scanf("%d %d", &desk_l, &desk_w);
    
    int does_it_fit = sizeCheck(room_l, room_w, desk_l, desk_w); // function's formal parameters

    (does_it_fit == 1) ? (printf("The desk will fit in the room.")) : (printf("The desk will not fit in the room."));
                // this if statement determines if that if the returned number is 1, the desk will fit, otherwise, the desk will not fit
}

int sizeCheck(int room_l, int room_w, int desk_l, int desk_w) { // creating a function to check the size of the room and desk respectively

    if (desk_l <= room_l || desk_l <= room_w) { // this if statement determines that if the lenght of the desk is 
        if (desk_w <= room_l || desk_w <= room_w) // less than the length or width of the room, we can determine the width
            return 1; // if the desk's width is also less than the length and width of the room, the desk must fit, so it'll return 1
        else
            return 0; // else, the desk is too big, so it'll return 0
    }
    else 
        return 0; // else, the desk is too big, so it'll return 0

}