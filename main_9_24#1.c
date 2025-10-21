/* Jalen Jarrett
COP 3223C
Sept 23, 2025
This program will prompt the user to type in three exam scores, then add up
their respective percentages to determine the overall letter grade. This program
uses three different functions to do so.
*/

#include <stdio.h> // including input/output library and main.h header to run the program
#include "main_9_24#1.h"

int main(void) { // creating a main function to call other functions

    float score = getScore(); // calling the getScore function
    
    printf("You got %c", getLetterGrade(score)); // calling the getLetterGrade function and outputting letter grade
                                // also uses the score value from the getScore function as an actual parameter to output letter grade

}

float getScore() { // creating the function that creates the score

    float score1, score2, score3; // these three variables will take in the exam scores as floats
    printf("Enter scores for exam1, exam2, and exam3: ");
    scanf("%f %f %f", &score1, &score2, &score3);

    float final_score = (score1*.2) + (score2*.3) + (score3*.5); // adds up each score based on their weight
    
    return final_score; // returns the final score as a float, passes the value back into the main function

}

char getLetterGrade(float score) { // creating the function to determine the final letter grade, takes in the score value as a formal parameter

    if (score >= 90) // each if / else if / else statement determines what the score value held is and will return the specific
        return 'A'; // letter grade based on the final score
    else if (score < 90 && score >= 80)
        return 'B'; // writing return statements since it's quicker to write :D
    else if (score < 80 && score >= 70)
        return 'C';
    else if (score < 70 && score >= 60)
        return 'D';
    else
        return 'F';

}