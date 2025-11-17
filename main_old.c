#include <stdio.h>
#include <ctype.h>
#include "main_old.h"
#define MAX_LENGTH 101

int main(void) {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    char x;
    printf("Enter a string: ");
    scanf("%[^\ns", s1);

    while ((x = getchar() != '\n') && x != EOF);

    printf("Enter a string: ");
    scanf("%[^\ns", s2);


}

int is_palindrome(char s[]) {
    copy_s[MAX_LENGTH];
    // call copy function
    // call reverse function
    // use if statement to call is equal to determine if its a palindrome
}

void str_copy(char dest[], char source[]) {
    // run a while or for loop through the source
        // save char from source into dest
    // dest[i] = '/0'
}

void str_reverse(char s[]) {
    // get len of string useing get length function

    // run for loop through half of the array
        // swap on each iteration
}

int getLength(char s[]) {
    int count = 0;

    // run a loop through string using '/0'
        // on each iteration ++ count

    // return count;
}

int is_equal(char s1[], char s2[]) {
    // run loop and check each index to see if they are equal
        // on each iteration check and see if you've reached '/0' on one or both string
            // this means they are not equal
    
    // once loop terminates check and see if both are at '/0' this means they are equal
}