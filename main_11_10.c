/* Jalen Jarrett
COP 3223C
Nov 9, 2025
This program will take a string array of names, display the names using lowercase letters, sort
the names in alphabetical order, and allow the user to search for names using a few keys
*/

#include <stdio.h> // including necessary libraries, main.h header, and defining max variables
#include <ctype.h>
#include <string.h>
#include "main_11_10.h"
#define MAXSTRINGS 100
#define MAXLENGTH 51

int main() {
    int numOfNames;
    char names[MAXSTRINGS][MAXLENGTH], x;

    printf("Enter how many names: "); // prompting the user to enter the number of names
    scanf("%d", &numOfNames);

    for(int i = 0; i < numOfNames; i++) { // taking in each name into the string array
        while((x = getchar() != '\n') && x != EOF); // makes sure no inputs get skipped

        printf("Name %d: ", i + 1); // takes in chars until the user presses the enter key
        scanf("%[^\n]s", names[i]);
    }

    for(int i = 0; i < numOfNames; i++) // converts each name into lowercase
        lower_str_converter(names[i]);

    selection_sort(names, numOfNames); // calling the selection sort function using the string array and length variable as actual parameters
    printf("Sorted Names:\n"); // prints each name sorted on a new line
    for(int i = 0; i < numOfNames; i++)
        printf("%s\n", names[i]);
    
    char key[MAXLENGTH]; // declaring a key string

    printf("\n");
    while(1) {
        int found = 0; // declaring a flag/counter variable
        while((x = getchar() != '\n') && x != EOF);
        printf("Enter search string: "); // prompting the user to enter string search input
        scanf("%[^\n]s", key);
        lower_str_converter(key); // converting the key into lowercase

        if(strcmp(key, "exit") == 0) // if the user types "exit," the loop will break
            break;
        
        for(int i = 0; i < numOfNames; i++) { // searches through the array and determines if any names match up with the key
            if(strstr(names[i], key) != NULL) { // if so, all found names will be printed and the found variable will increase
                printf("%s\n", names[i]);
                found++;
            }
        }
        if(!found) // if the found variable remains false (no names were found) will print "not found"
            printf("not found\n");
    }
    printf("\nbye!"); // once the loop is broken, will print "bye!"

    return 0; // returning to the system
}

void selection_sort(char str[][MAXLENGTH], int numOfStrings) {
    for(int i = 0; i < numOfStrings; i++) { // searches through the entire string
        int min = i; // declaring the minimum variable as equal to 0
        for(int j = i + 1; j < numOfStrings; j++) {
            if(strcmp(str[min], str[j]) > 0) // compares the first index/minimum index, and the current indext
                min = j; // if the minimum index is greater than the current index, the minimum variable will equal to j
        }
        swap(str[min], str[i]); // swapping the minimum index and the current index using the swap function
    }
}

void lower_str_converter(char *str) {
    for(int i = 0; str[i] != '\0'; i++) { // as long as the string hasn't reached its end, each char in the string will be converted to lowercase
        str[i] = tolower(str[i]);
    }
}

void swap(char *str1, char *str2) {
    char temp[MAXLENGTH]; // declaring a temp string
    
    strcpy(temp, str1); // copying string 1 into the temp string
    strcpy(str1, str2); // then copying string 2 into string 1
    strcpy(str2, temp); // finally copying the saved string 1 value into string 2
}