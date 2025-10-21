/* Jalen Jarrett
COP 3223C
Aug 27, 2025
This program will test variable declaration and input
allocation. After the user inputs two numbers into the
terminal, the program will swap the values
*/


#include <stdio.h> // importing the standard library

int main() { // creating a function for the program to run

    int input1, input2; // variable that stores user's input
    int temp_input_holder; // temporary holding place for one of values to be held while swapping
    
    scanf("%d%d", &input1, &input2); // takes in user input and prints them out as 'a' and 'b'
    printf("Before swapping, a is %d and b is %d", input1, input2);

    temp_input_holder = input2; // saves the value of the second input
    input2 = input1; // transfers the value of input 1 to input 2
    input1 = temp_input_holder; // transfers the saved value of input 2 to input 1

    printf("\nAfter Swapping, a is %d and b is %d\n", input1, input2); // prints out final values after swapping
    
    return 0; // returns to the system
}