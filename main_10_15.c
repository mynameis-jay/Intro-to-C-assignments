/* Jalen Jarrett
COP 3223C
Oct 14, 2025
This program will ask the user to enter in two integers, which will be the size
of two separate arrays. It will then prompt the user to enter in the data for each array,
determine if there are prime numbers in them, find any matching numbers, and finally find
the largest and smallest number of the second array
*/

#include <stdio.h> // including input/output library, math.h header, and defining 200 as SIZE
#include "main_10_15.h"
#define SIZE 200

int main() {

    int n, m, small, large;
    
    printf("Enter n and m: "); // prompts the user to enter integers that'll determine each array size
    scanf("%d %d", &n, &m);

    int arr1[n], arr2[m]; // declaring the arrays using the size variables

    printf("Enter data for first list: "); // prompting the user to enter the data for the first array
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
   
    printf("Enter data for second list: "); // prompting the user to enter the data for the second array 
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    PrimeMatching(arr1, n, arr2, m); // calling the matching function and passing the arrays, and size of the arrays, as actual parameters

    small = smallest(arr2, m); // calling the smallest function to determine the smallest number in the second array
    printf("\nSmallest number in the second list: %d", small);
    large = largest(arr2, m); // calling the largest function to determine the largest number in the second array
    printf("\nLargest number in the second list: %d", large);

    return 0;
}

int isPrime(int n) { // creating the function that determines if a number is prime or not

    int primeOrNot;

    if (n == 1) // 1 is not a prime number, but 2 is, only special cases for those two integers
        return 0;

    else if (n == 2)
        return 1;

    for (int i = 2; i < n; i++) { // will divide the imported integer by each number from 2 to that integer
        primeOrNot = n % i; // and save the value to the primeOrNot variable

        if (primeOrNot == 0) // determines that if the number is prime, the loop will break
            break;
    }

    switch (primeOrNot) { // in the case of primeOrNot

        case 0: // if primeOrNot = 0, return 0; the number is not prime
            return 0;
            break;
        
        default: // otherwise, return 1; the number is prime
            return 1;
    }
}

int PrimeMatching (int arr1[], int size1, int arr2[], int size2) { // creating the prime matching function

    int primeCount = 0;

    printf("Common prime numbers are: "); // will display the common prime numbers

    for (int i = 0; i < size1; i++){ // first loop checks to see if the given array element is prime by calling the isPrime function
        int primeOrNot = isPrime(arr1[i]);

        if (primeOrNot == 1) { // if the isPrime function returns 1, the element is prime
            for (int j = 0; j < size2; j++) { // the second loop checks to see if any elements from the second array match
                
                if (arr1[i] == arr2[j]) { // if the element from the second array matches the first, it will immediately print
                    printf("%d ", arr2[j]);
                    primeCount++; // adding 1 to the prime counter
                    break;
                }
            }
        }
    }

    printf("\nCommon count: %d", primeCount); // prints out the amount of common prime numbers between arrays

}

int smallest (int arr2[], int size) { // creating the function that returns the smallest number in the second array

    int small = arr2[0]; // setting the small variable to equal the first element immediately

    for (int i = 0; i < size; i++) { // checks each element to see if it's less than the small variable
        if (arr2[i] < small)
            small = arr2[i]; // if so, the small variable takes on the new smallest value
    }

    return small; // returning the smallest element
}

int largest (int arr2[], int size) { // creating the function that returns the largest number in the second array

    int large = arr2[0]; // does the same exact thing as the last function, except determines if the current element is larger than the last

    for (int i = 0; i < size; i++) { // 
        if (arr2[i] > large)
            large = arr2[i];
    }
    
    return large; // returning the largest element
}