/* Jalen Jarrett
COP 3223C
Sep 9, 2025
This program will prompt the user to enter a character
into the terminal and will tell the user if it's a 
digit, letter, or special character. If letter, program will
determine if it's upper or lowercase, if digit, program will
take the square root of the number
*/

#include <stdio.h> // importing input/output library and math library for square root
#include <math.h>

int main() { // creating a main function to run the program

    char character; // creating a variable to save the character to

    printf("Enter a character: "); // prompts user to type character into the terminal
    scanf("%c",&character);

    if (character>='a' && character<='z') // determines if the character is lowercase letter and tells which placement in the alphabet letter is in
        printf("\n%c is a small case letter. The letter number is %d in the alphabet.",character,character-'a'+1);
   
    else if (character>='A' && character<='Z') // determines if the character is uppercase letter and tells which placement in the alphabet letter is in
        printf("\n%c is a capital letter. The letter number is %d in the alphabet.",character,character-'A'+1);

    else if (character>='0' && character<='9') // determines if the character is a digit and takes the square root of it
        printf("\n%c is a digit.\nThe square root of %c is %.2f",character,character,sqrt(character-'0'));

    else // if nothing else, character must be a special symbol
        printf("\n%c is a special symbol.",character);
    
    return 0; // returning to the system
}