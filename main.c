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
	display_array(arr, size);

	printf("\n\n");
	bubble_sort(arr, size);

    printf("\n\n");
    selection_sort(arrCopy, size);

	return 0;
}

void copy_array(int destination[], int source[], int size) {

}

void swap(int arr[], int index1, int index2) {

    // printf("%d %d ", arr[index1], arr[index2]);

    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;

}

void bubble_sort(int arr[], int size) {

	int i;

	printf("Using Bubble sort\n\n");

    for (i = 0; i < size - 1; i++) {
        printf("Iteration# %d\n", i + 1);

        for (int j = 0; j < size - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                // printf("%d %d ", arr[j], arr[j + 1]);
                display_array(arr, size);
            }
            
            // printf("%d %d", arr[j], arr[j+1]);
            printf("\n");
        }
        
    }
    printf("\nSorted array using Bubble Sort:\n");
    display_array(arr, size);

}

void selection_sort(int arr[], int size) {

    printf("Using Selection sort\n\n");

    for (int i = 0; i < size - 1; i++) {
        int min = arr[i];
        printf("Iteration# %d\n", i + 1);
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < min)
                // min = arr[j];
        
                swap(arr, min, arr[i + 1]);
        }
        display_array(arr, size);
        printf("\n");
        
    }

}

void display_array(int arr[], int size) {
    
    for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
    
}