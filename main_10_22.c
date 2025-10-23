/* Jalen Jarrett
COP 3223C
Oct 20, 2025
This program will prompt the user to enter in the row and column 
size of an array, then prompt them to enter in each individual element
in that array, then sort the array in numerical order using two different methods
*/

#include <stdio.h> // including input/output library, main.h header, and defining the MAX_SIZE varible
#include "main_10_22.h"
#define MAX_SIZE 50000

int main() {

	int size, arr[MAX_SIZE], arrCopy[MAX_SIZE]; // declaring the size variable and two arrays with the size of MAX_SIZE

	printf("How many numbers to sort?\n"); // prompting the user to enter the array size (amount of numbers to sort)
	scanf("%d", &size);

	for (int i = 0; i < size; i++) { // takes each number in the array, also makes a copy array
		printf("Enter number %d: ", i + 1);
		scanf("%d", &arr[i]);
		arrCopy[i] = arr[i];
	}

	printf("\nArray before sorting:\n"); // calls the display array function to print out the array
	display_array(arr, size);

    copy_array(arrCopy, arr, size); // passes the original array and the copy array to the copy array function

	return 0; // returning to the system
}

void copy_array(int destination[], int source[], int size) { // function that takes in the original array and copy array

    printf("\n\n"); // calling the bubble sort function and passing the original array into it
	bubble_sort(source, size);

    printf("\n\n"); // calling the selection sort function and passing the copy array into it
    selection_sort(destination, size);

}

void swap(int arr[], int index1, int index2) { // function that takes two array indexes and swaps them

    int temp = arr[index1]; // using a temp variable to save the index1 value, then swapping the indexes
    arr[index1] = arr[index2];
    arr[index2] = temp;

}

void bubble_sort(int arr[], int size) { // function that sorts the array using the bubble sort method

	int i;

	printf("Using Bubble sort\n\n");

    for (i = 0; i < size - 1; i++) { // ensures that at max, only rows 1-4 will be printed (index 0-3)
        printf("Iteration# %d\n", i + 1);

        for (int j = 0; j < size - i - 1; j++) { // will take the first max value in the array and keep sliding it down the columns until it's in its proper order
            
            if (arr[j] > arr[j + 1]) // determines that if the current element is greater than the one after it, it will be swapped with the proceeding element
                swap(arr, j, j + 1);

            display_array(arr, size); // displaying the array after each swap
            printf("\n");
        }
        
    }
    printf("\nSorted array using Bubble Sort:\n");
    display_array(arr, size); // prints the final array after sorting is done

}

void selection_sort(int arr[], int size) { // function that sorts the array using the selection sort method

    printf("Using Selection sort\n\n");

    for (int i = 0; i < size - 1; i++) { // ensures that at max, only rows 1-4 will be printed (index 0-3)
        int min = i;
        printf("Iteration# %d\n", i + 1);
        
        for (int j = i + 1; j < size; j++) { // finds the minimum value in the array and saves it to the min variable
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr, min, i); // swapping the minimum value and the current index value
        display_array(arr, size); // displays the updated array after each full swap
        printf("\n");
    }
    printf("\nSorted array using Selection Sort:\n");
    display_array(arr, size); // prints the final array after sorting

}

void display_array(int arr[], int size) { // function that displays arrays
    
    for (int i = 0; i < size; i++) // prints each array element one by one
		printf("%d ", arr[i]);
    
}