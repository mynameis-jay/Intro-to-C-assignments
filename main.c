/* Jalen Jarrett
COP 3223C
Nov 11, 2025
This program will prompt the user to enter in file names for an input text file they want
to read, and an output file they want to write on. Then, the program will open the input text file,
read it, write the contents of the input file onto the output file in all caps, and finally display some 
details about the input file
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_vowel(char letter) {
    switch(letter) { // checking the value of the letter character
        case 'A': // each case determines if the letter is a vowel
        case 'a':
            return 1; // if so, it'll return 1
        
        case 'E':
        case 'e':
            return 1;
        
        case 'I':
        case 'i':
            return 1;

        case 'O':
        case 'o':
            return 1;

        case 'U':
        case 'u':
            return 1;

        default: // if the letter is not a vowel, it will return 0
            return 0;
    }
}

int main() {
    FILE *iFilePtr, *oFilePtr; // declaring input and output file pointers
    int numOfChar = 0, numOfVow = 0, numOfDig = 0; // declaring counter variables
    char ch, str1[30], str2[30]; // declaring char variables and char strings

    scanf("%s %s", str1, str2); // prompting user to enter the files they want to open and write to

        iFilePtr = fopen(str1, "r"); // opening the first file in read mode
        oFilePtr = fopen(str2, "w"); // opening the second file in write mode


        while(!feof(iFilePtr)) {
            ch = fgetc(iFilePtr); // the char variable will take in the value of the first char(or sequential char) in the input text file
            if(ch == EOF) // once the program reaches the end of the file, the loop will break
                break;
            printf("%c", ch); // printing the current char from the input text file
            if(ch != '\n') // if the current char isn't a new line, char counter will increase by 1
                numOfChar++;
            if(is_vowel(ch) == 1) // calling the vowel function, passing the char into the function as an actual parameter
                numOfVow++; // if the returned value is 1, vowel counter will increase by 1
            if(ch >= '0' && ch <= '9') // if the char is between '0' and '9' (is a digit), digit counter will increase by 1
                numOfDig++;
            if(isalpha(ch)) // if the char is a letter, the char will be uppercased
                ch = toupper(ch);
            fputc(ch, oFilePtr); // printing the contents of the input file into the output file in uppercase
        }
        printf("\n\nNumber of characters: %d\nNumber of vowels: %d\nNumber of digits: %d", numOfChar, numOfVow, numOfDig); // displaying the details of the input file

        fclose(iFilePtr); // closing the input and output files
        fclose(oFilePtr);

    return 0;
}
