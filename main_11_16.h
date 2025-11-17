/* Jalen Jarrett
COP 3223C
Nov 16, 2025
Defining each variable and calling each function from main.c
*/

#define MAXSTD 100
#define MAXQZ 10
#define MAXLEN 51
char getLetterGrade(float score);
int getMaxTotalIdx(float totals[], int n);
void writeData(FILE *out, char ids[][MAXLEN], char names[][MAXLEN], float totals[], int n);
int lookup(char names[][MAXLEN], char key[MAXLEN], int n);