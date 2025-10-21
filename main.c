#include <stdio.h>
#include "main.h"
#define MAX_SIZE 50000

int main() {

    int size, arr[MAX_SIZE], arrCopy[MAX_SIZE];

    printf("How many numbers to sort?\n");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        arrCopy[i] = arr[i];
    }

    printf("\nArray before sorting:\n");

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    bubble_sort(arr, size);

    return 0;
}

int bubble_sort(int arr[], int size) {

    int bubble[size][size];

    printf("Using Bubble sort\n\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j ++) {
            bubble[i][j] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", bubble[i][j]);
        }
        printf("\n");
    }

}