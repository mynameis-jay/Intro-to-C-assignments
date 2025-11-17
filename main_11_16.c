/* Jalen Jarrett
COP 3223C
Nov 11, 2025
This program will prompt the user to enter a file name, open up a text file containing various student information,
and take each piece of information into strings, creating a grade report for each student, show the student with the
highest total score, and allow the user to search for any student on the list. If the student can be found, their information
will be displayed
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main_11_16.h"
#define MAXSTD 100 // defining the max variables
#define MAXQZ 10
#define MAXLEN 51

int main() {
    FILE *in, *out; // creating the file pointers, char and float strings, and two integers to save the number of students and number of quiz grades
    char ids[MAXSTD][MAXLEN], names[MAXSTD][MAXLEN], filename[MAXLEN];
    float grades[MAXSTD][MAXQZ], totals[MAXSTD], midterm[MAXSTD], final[MAXSTD];
    int n, g;

    scanf("%s", filename); // prompting the user to enter in the text file name

    in = fopen(filename, "r"); // opening the text file in read mode and a report text file in write mode
    out = fopen("report.txt", "w");

    if(in == NULL || out == NULL) { // if the files cannot be opened, will print "Cannot open file"
        printf("Cannot open file\n");
        exit(1);
    }
    
    fscanf(in, "%d %d", &n, &g); // taking in the number of students and the number of quiz grades from the text file

    for(int i=0; i<n; i++) {
        float sum = 0, avg;
        fscanf(in, "%s %s %f %f", &ids[i], &names[i], &midterm[i], &final[i]); // taking in the ids, names, midterm, and final grade from the text file
        for(int j=0; j<g; j++) {
            fscanf(in, "%f", &grades[i][j]); // taking in the final four quiz grades from the text file
            sum += grades[i][j]; // adding each grade to the sum variable
        }
        avg = sum/g; // taking the average of the quiz grades by dividing the sum by the number of quizzes
        totals[i] = (midterm[i]*0.35)+(final[i]*0.4)+(avg*0.25); // saving each total based on 35% of the midterm grade + 40% of the final grade + 25% of the
    }                                                            // average of quiz grades
    writeData(out, ids, names, totals, n); // calling the writeData function

    char key[MAXLEN]; // declaring a key string
    printf("\nEnter a last name to search: "); // prompting the user to enter a name
    scanf(" %[^\n]s", key); // will keep taking in chars until the user presses enter
    for(int i=0; key[i] != '\0'; i++)
        key[i] = tolower(key[i]); // makes each char in the string lowercase
            
    int look = lookup(names, key, n); // calling the lookup function and saving the value to an int

    if(look == -1) { // if lookup returns -1, cannot find the name on the summary
        key[0] = toupper(key[0]); // capitalizes the first letter of the name
        printf("%s not found in the list.", key);
    }
    else { // else, the name was found; will continue to print out the student's information
        printf("%s was found in the list. Here is the details:\nID: %s Lname: %s Total: %.2f\n", key, ids[look], names[look], totals[look]);
        printf("Grades:\nMidterm: %.2f, Final term: %.2f, quizzes:\n", midterm[look], final[look]);
        for(int i=look; i<look+1; i++) {
            for(int j=0; j<g; j++) {
                printf("%.2f ", grades[i][j]);
            }
        }
    }

    fclose(in); // closing the text files
    fclose(out);

    return 0;
}

char getLetterGrade(float score) {
    if(score >= 90.00) // determines what letter grade each student gets based on their total scores
        return 'A';
    else if(score <= 89.99 && score >= 80.00)
        return 'B';
    else if(score <= 79.99 && score >= 70.00)
        return 'C';
    else
        return 'F';
}

int getMaxTotalIdx(float totals[], int n) {
    int maxIndex; // creating a variable that saves the index
    float max = totals[0]; // setting the max to the first element of the totals array
    for(int i=0; i<n; i++) {
        if(totals[i] > max) { // searching the entire array to find the absolute max value
            max = totals[i];
            maxIndex = i; // once the max is found, the index will be saved
        }
    }
    return maxIndex; // returning the max index
}

void writeData(FILE *out, char ids[][MAXLEN], char names[][MAXLEN], float totals[], int n) {
    printf("Summary of students:\n========\n"); // printing out the summary of students to the terminal and to teh report.txt file
    fprintf(out, "Summary of students:\n========\n");
    for(int i=0; i<n; i++) {
        char grade = getLetterGrade(totals[i]); // calling the getLetterGrade function and saving the value returned
        printf("ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i], totals[i], grade); // summarizing the student's id, name, total score, and letter grade
        fprintf(out, "ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i], totals[i], grade);
    }
    int maxTotal = getMaxTotalIdx(totals, n); // calling the getMaxTotalIdx function and saving the value returned
    printf("\n========\nFirst student with the highest total is %s %s %.2f", ids[maxTotal], names[maxTotal], totals[maxTotal]); // printing the student with the highest
    fprintf(out, "\n========\nFirst student with the highest total is %s %s %.2f", ids[maxTotal], names[maxTotal], totals[maxTotal]); // total score
    printf("\nThe summary is stored. Please check report.txt file.");
}

int lookup(char names[][MAXLEN], char key[MAXLEN], int n) {
    int found; // creating a variable that saves the current index
    for(int i=0; i<n; i++) {
        if(strcmp(names[i], key) == 0) { // if keyword is the same as the current index of the names array
            found = i; // will save the current index and break the loop
            break;
        }
        else // if the keyword cannot be found in the array
            found = -1; // will save found as -1
    }
    return found; // returning the value of found
}