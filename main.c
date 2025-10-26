#include <stdio.h>
#include "main.h"
#define MAXROWS 100
#define MAXCOLUMNS 100

int main() {

    int arr1[MAXROWS][MAXCOLUMNS], arr2[MAXROWS][MAXCOLUMNS];
    int rows, columns, realI, realJ;

    printf("enter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    printf("input for matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        printf("data for matrix1[%d][0] to matrix1[%d][%d] ", i, i, columns - 1);
        for (int j = 0; j < columns; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    
    printf("input for matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        printf("data for matrix2[%d][0] to matrix2[%d][%d] ", i, i, columns - 1);
        for (int j = 0; j < columns; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nprinting matrix 1:\n");
    displayMatrix(arr1, rows, columns);
    printf("printing matrix 2:\n");
    displayMatrix(arr2, rows, columns);

    printf("\nprinting max per row for matrix 1:\n");
    findMaxPerRow(arr1, rows, columns);

    printf("\nprinting lower left triangle of matrix 1:\n");
    printLLTriangle(arr1, rows, columns);

    printf("\nprinting upper right triangle for matrix 1:\n");
    printURTriangle(arr1, rows, columns);

    int results[rows][columns];
    printf("\nmatrix 1 + matrix 2 is:\n");
    addMatrix(arr1, arr2, results, rows, columns);
    displayMatrix(results, rows, columns);

    printf("enter i and j for calculating sum of surrounding: ");
    scanf("%d %d", &realI, &realJ);
    while (realI >= 0) {
        if (realI < 0 || realJ < 0)
            break;

        int result = sumSurrounding(arr1, rows, columns, realI, realJ);
        printf("sum of surrounding is %d", result);
        printf("\nenter i and j for calculating sum of surrounding: ");
        scanf("%d %d", &realI, &realJ);
    }
    
    if (realI < 0 || realJ < 0)
            printf("Exit");

    return 0;
}

void displayMatrix(int arr[][MAXCOLUMNS], int rows, int columns) {

    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

void findMaxPerRow(int arr[][MAXCOLUMNS], int rows, int columns) {

    //printf("\n%d %d", rows, columns);

    for (int i = 0; i < rows; i++) {
        int max = arr[0][0];
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
        printf("max of row %d is %d", i, max);
        printf("\n");
    }
}

void printLLTriangle(int arr[][MAXCOLUMNS], int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%4d", arr[i][j]);
        }
        for (int x = rows - 1; x > i; x--) {
            printf("%4d", 0);
        }
        printf("\n");
    }
}

void printURTriangle(int arr[][MAXCOLUMNS], int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%4d", 0);
        }
        for (int x = i; x < rows; x++) {
            printf("%4d", arr[i][x]);
        }
        printf("\n");
    }
}

void addMatrix(int M1[][MAXCOLUMNS], int M2[][MAXCOLUMNS], int R[][MAXCOLUMNS], int r, int c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = M1[i][j] + M2[i][j]; 
        }
    }
}

int sumSurrounding(int arr[][MAXCOLUMNS], int rows, int columns, int i, int j) {

    int result = 0, positionI = i, positionJ = j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (positionI < 0 || positionJ < 0) {
                continue;
            }
            else if (positionI > rows || positionJ > columns) {
                continue;
            }
            else if (i == positionI && j == positionJ) {
                continue;
            }
            else if (i > positionI + 1 || j > positionJ + 1) {
                continue;
            }
            else if (i < positionI - 1 || j < positionJ - 1) {
                continue;
            }
            else {
                result += arr[i][j]; 
            }
            //printf("\n%d | %d", arr[i][j], result);
            
        }
        
    }
    return result;

}