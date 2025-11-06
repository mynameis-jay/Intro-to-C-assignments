/* Jalen Jarrett
COP 3223C
Nov 2, 2025
This program will prompt the user to enter the amount of characters they want to put into an array,
take each character into an array of that size, print out the frequency in which the letters in the
alphabet appear in the array, and finally reverse the array
*/

#include <stdio.h> // including input/output library, ctype library, main.h header, and defining MAXCHAR variable
#include <ctype.h>
#include "main_11_2.h"
#define MAXCHAR 50

int main(void) { // main function taken from assignment page
  int counters[26];
  char myArr[MAXCHAR]; //MAXCHAR was hash defined to 50
  int i, total_char;

  for(i=0; i<26; i++)
       counters[i] = 0;
 
  getData(myArr, &total_char, counters);
  displayArr(myArr, total_char);
  printf("\n");
  displayStat(counters, total_char);
  reverse(myArr, total_char);
  printf("Array reversed.\n");
  displayArr(myArr, total_char);

  return 0;
}

void getData(char arr[], int *n, int counters[26]) { // function that collects the characters into the array
  printf("How many characters? : "); // prompting the user to enter in the amount of characters to be collected
  char x;
  scanf("%d", n); // taking the number into a pointer
  for (int i = 0; i < *n; i++) {
    while((x = getchar()!='\n') && x!= EOF); // ensures no input will be skipped
    printf("Enter character %d: ", i + 1); // prompting to enter each element individually
    
    arr[i] = getchar();

    if((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z')) { // determines if the character is either uppercase or lowercase
      arr[i] = tolower(arr[i]); // sets the the character to a lowercase letter

      counters[arr[i] - 'a']++; // adding the current character to the counter array, saving the frequency of appearance
    }
  }
}

void displayStat(int *c, int total_char) { // function that displays the frequency of each character entered
  for(int i = 0; i < 26; i++) {
    printf("%c\t%d\t%.2f\n", 'a' + i, c[i], 100.00 * c[i] / total_char); // prints out the current character, frequency, and percentage
  }
}

void reverse(char a[], int size) { // funciton that reverses the array
  int last_index = size - 1;
  for(int i = 0; i < size/2; i++) { // calling the swap function for the current element, passing in the reference of the current index and the last index
    char_swap(&a[i], &a[last_index - i]);
  }
}

void char_swap(char *x, char *y) { // function that swaps two chars
  char temp = *x; // takes the reference of two char variables, stores one reference into a temp variable, then swaps the two
  *x = *y;
  *y = temp;
}

void displayArr(char *a, int size) { // function that displays the array
  printf("The char array: ");
  for(int i = 0; i < size; i++) { // displays each array element one by one
    printf("%c ", a[i]);
  }
}