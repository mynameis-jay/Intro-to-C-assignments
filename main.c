#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_vowel(char letter) {
    // printf(" %c ", letter);
    int x;
    switch(letter) {
        case 'A':
        case 'a':
            return 1;
        
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

        default:
            return 0;
    }
}

int main() {
    FILE *iFilePtr, *oFilePtr;
    int numOfChar = 0, numOfVow = 0, numOfDig = 0;
    char ch, str1[30], str2[30], x;

    // scanf("%s %s", str1, str2);

    // if(str1 == "input.txt" && str2 == "output.txt") {
        iFilePtr = fopen("input.txt", "r");
        oFilePtr = fopen("output.txt", "w");


        while(!feof(iFilePtr)) {
            ch = fgetc(iFilePtr);
            if(ch == EOF)
                break;
            printf("%c", ch);
            if(ch != '\n')
                numOfChar++;
            if(is_vowel(ch) == 1)
                numOfVow++;
            if(ch >= '0' && ch <= '9')
                numOfDig++;
            if(isalpha(ch))
                ch = toupper(ch);
            fputc(ch, oFilePtr);
        }
        printf("\n\nNumber of characters: %d\nNumber of vowels: %d\nNumber of digits: %d", numOfChar, numOfVow, numOfDig);

        fclose(iFilePtr);
        fclose(oFilePtr);
    // }

    return 0;
}