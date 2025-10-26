/* Jalen Jarrett
COP 3223C
Oct 26, 2025
This program prompts the user to enter the amount of rows and columns in a 2D array,
then lets them input each individual element in the array. Finally, it prints out
each array, and mulitplies the values in the first row of the first array by the 
values of the first column of the second array, finally printing out those values to 
one last array
*/

#include <stdio.h> // including input/output library, main.h header, and defining rows and columns variables
#include "main_10_26#1.h"
#define ROWS 10
#define COLUMNS 10

int main() {

    int arr1[ROWS][COLUMNS], arr2[ROWS][COLUMNS], row1, column1, row2, column2;

    printf("Working for Matrix 1\nEnter number of rows and columns: "); // prompting the user to enter the rows and columns for each array
    scanf("%d %d", &row1,  &column1);
    FillData(arr1, row1, column1); // calls the FillData function to take in the values entered into each array
    
    printf("Working for Matrix 2\nEnter number of rows and columns: ");
    scanf("%d %d", &row2,  &column2);
    FillData(arr2, row2, column2);

    printf("\nDisplaying Matrix 1:\n"); // displaying both arrays after values have been saved
    Display(arr1, row1, column1); // calls the display function to print out each array

    printf("\nDisplaying Matrix 2:\n");
    Display(arr2, row2, column2);

    Multiply(arr1, row1, column1, arr2, row2, column2); // calling the multiply function with each array

    return 0; // returning to the system
}

void FillData(int arr[][COLUMNS], int r, int c) { // function that saves data into each array

    int i, j;

    printf("Enter data for %dx%d matrix:\n", r, c); // prompting the user to enter data for current array

    for (i = 0; i < r; i++) { // saves each value entered into the current 2D array
        for (j = 0; j < c; j++) {
             scanf("%d", &arr[i][j]);
        }
    }

}

void Display(int arr[][COLUMNS], int r, int c) { // function that displays each array

    int i, j;

    for (i = 0; i < r; i++) { // loop prints out each element in the array with a tab in between each digit
        for (j = 0; j < c; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

}

void Multiply(int M1[][COLUMNS], int r1, int c1, int M2[][COLUMNS], int r2, int c2) { // function that multiplies

    int result[ROWS][COLUMNS]; // declaring a final result array

if (c1 != r2) { // if the size of the first column doesn't equal the size of the second row
        printf("Not valid dimensions for multiplication"); // it will print an invalid statement and return to the main function
        return;
    }

    for (int i = 0; i < r1; i++) { // loop multiplies the values in the first row of the first 2D array by the
        for (int j = 0; j < c2; j++) { // values in the first column of the second 2D array
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += M1[i][k] * M2[k][j]; // saving each multiplied value  to the result array
            }
        }
    }
    printf("\nDisplaying Result Matrix:\n"); // calling the display array to display the final 2D array
    Display(result, r1, c2);
    
}