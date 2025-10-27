/* Jalen Jarrett
COP 3223C
Oct 26, 2025
This program will take two 2D arrays with user input, display each array,
display the lower left and upper right triangle values, add each corresponding 
index between arrays, and finally add the indexes surrounding the element the user
chooses
*/

#include <stdio.h> // including input/output library, main.h header, and declaring the rows and columns
#include "main_10_26#2.h"
#define MAXROWS 100
#define MAXCOLUMNS 100

int main() {

    int arr1[MAXROWS][MAXCOLUMNS], arr2[MAXROWS][MAXCOLUMNS];
    int rows, columns, realI, realJ;

    printf("enter number of rows and columns: "); // prompts the user to input the number of rows and columns in the array
    scanf("%d %d", &rows, &columns);

    printf("input for matrix 1:\n"); // loop takes in each element of the first 2D array
    for (int i = 0; i < rows; i++) {
        printf("data for matrix1[%d][0] to matrix1[%d][%d] ", i, i, columns - 1);
        for (int j = 0; j < columns; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    
    printf("input for matrix 2:\n"); // loop takes in each element of the second 2D array
    for (int i = 0; i < rows; i++) {
        printf("data for matrix2[%d][0] to matrix2[%d][%d] ", i, i, columns - 1);
        for (int j = 0; j < columns; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nprinting matrix 1:\n"); // displaying each 2D array using the display function
    displayMatrix(arr1, rows, columns);
    printf("printing matrix 2:\n");
    displayMatrix(arr2, rows, columns);

    printf("\nprinting max per row for matrix 1:\n"); // calling the max function to find the max element for each row in the first array
    findMaxPerRow(arr1, rows, columns);

    printf("\nprinting lower left triangle of matrix 1:\n"); // calling the LL triangle function to print the lower left triangle
    printLLTriangle(arr1, rows, columns);

    printf("\nprinting upper right triangle for matrix 1:\n");// calling the UR triangle function to print the upper right triangle
    printURTriangle(arr1, rows, columns);

    int results[rows][columns]; // calls the add and display functions
    printf("\nmatrix 1 + matrix 2 is:\n");
    addMatrix(arr1, arr2, results, rows, columns);
    displayMatrix(results, rows, columns);

    printf("enter i and j for calculating sum of surrounding: "); // taking the i and j values for the surrounding sum function
    scanf("%d %d", &realI, &realJ);
    while (realI >= 0) { // while the i value is greater or equal to zero, the loop will start
        if (realI < 0 || realJ < 0) // if either i or j becomes negative, the loop will break
            break;

        int result = sumSurrounding(arr1, rows, columns, realI, realJ); // calling the surrounding sum function
        printf("sum of surrounding is %d", result);
        printf("\nenter i and j for calculating sum of surrounding: ");
        scanf("%d %d", &realI, &realJ);
    }
    
    if (realI < 0 || realJ < 0) // if either i or j is negative, prints "Exit"
            printf("Exit");

    return 0; // returning to the system
}

void displayMatrix(int arr[][MAXCOLUMNS], int rows, int columns) { // function that displays the arrays

    int i, j;

    for (i = 0; i < rows; i++) { // prints out each array element one by one
        for (j = 0; j < columns; j++) {
            printf("%4d", arr[i][j]); // using %4d for easier reading
        }
        printf("\n");
    }
}

void findMaxPerRow(int arr[][MAXCOLUMNS], int rows, int columns) { // function that takes the max per row

    for (int i = 0; i < rows; i++) { // entire loop combs through the 2D array
        int max = arr[0][0]; // setting the max to the first index immediately
        for (int j = 0; j < columns; j++) { // if the current index is greater than max, max will become the current index
            if (arr[i][j] > max)
                max = arr[i][j];
        }
        printf("max of row %d is %d", i, max); // printing the max of that row
        printf("\n");
    }
}

void printLLTriangle(int arr[][MAXCOLUMNS], int rows, int columns) { // function that prints the lower left triangle

    for (int i = 0; i < rows; i++) { // combs through the function again
        for (int j = 0; j <= i; j++) { // prints the elements in order, but only capturing the lower triangle of the array
            printf("%4d", arr[i][j]);
        }
        for (int x = rows - 1; x > i; x--) { // prints zeroes in place of the missing elements
            printf("%4d", 0);
        }
        printf("\n");
    }
}

void printURTriangle(int arr[][MAXCOLUMNS], int rows, int columns) { // function that prints the upper right triangle

    for (int i = 0; i < rows; i++) {
        for (int j = 1; j <= i; j++) { // prints zeroes in the lower right corner
            printf("%4d", 0);
        }
        for (int x = i; x < rows; x++) { // prints the elements in order, but only showing the upper right corner of elements
            printf("%4d", arr[i][x]);
        }
        printf("\n");
    }
}

void addMatrix(int M1[][MAXCOLUMNS], int M2[][MAXCOLUMNS], int R[][MAXCOLUMNS], int r, int c) { // function that adds

    for (int i = 0; i < r; i++) { // takes the current index of array 1 and adds it up with the corresponding element of array 2
        for (int j = 0; j < c; j++) {
            R[i][j] = M1[i][j] + M2[i][j]; 
        }
    }
}

int sumSurrounding(int arr[][MAXCOLUMNS], int rows, int columns, int i, int j) { // function that sums up all elements surrounding the chosen index

    int result = 0, positionI = i, positionJ = j; // declaring variables that save the value of i and j
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) { // writing conditions
            if (positionI < 0 || positionJ < 0) { // any indexes less than 0 are out of bounds
                continue;
            }
            else if (positionI > rows || positionJ > columns) { // any indexes greater than the value of rows and columns are out of bounds
                continue;
            }
            else if (i == positionI && j == positionJ) { // won't add the current index to the final result
                continue;
            }
            else if (i > positionI + 1 || j > positionJ + 1) { // any indexes that are more than one index away are out of reach
                continue;
            }
            else if (i < positionI - 1 || j < positionJ - 1) { // same as previous else if statement
                continue;
            }
            else {
                result += arr[i][j]; // all indexes within reach will be added to the result variable
            }
        }
    }
    return result; // returning the final result

}