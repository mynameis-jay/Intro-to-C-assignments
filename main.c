#include <stdio.h>
#include "main.h"
#define ROWS 10
#define COLUMNS 10

int main() {

    int arr1[ROWS][COLUMNS], arr2[ROWS][COLUMNS], row1, column1, row2, column2;

    printf("Working for Matrix 1\nEnter number of rows and columns: ");
    scanf("%d %d", &row1,  &column1);
    FillData(arr1, row1, column1);
    
    printf("Working for Matrix 2\nEnter number of rows and columns: ");
    scanf("%d %d", &row2,  &column2);
    FillData(arr2, row2, column2);

    printf("\nDisplaying Matrix 1:\n");
    Display(arr1, row1, column1);

    printf("\nDisplaying Matrix 2:\n");
    Display(arr2, row2, column2);

    Multiply(arr1, row1, column1, arr2, row2, column2);

    return 0;
}

void FillData(int arr[][COLUMNS], int r, int c) {

    int i, j;

    printf("Enter data for %dx%d matrix:\n", r, c);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
             scanf("%d", &arr[i][j]);
        }
    }

}

void Display(int arr[][COLUMNS], int r, int c) {

    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

}

void Multiply(int M1[][COLUMNS], int r1, int c1, int M2[][COLUMNS], int r2, int c2) {

    int result[ROWS][COLUMNS];

if (c1 != r2) {
        printf("Not valid dimensions for multiplication");
        return;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    printf("\nDisplaying Result Matrix:\n");
    Display(result, r1, c2);

}