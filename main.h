#define MAXROWS 100
#define MAXCOLUMNS 100
void displayMatrix(int arr[][MAXCOLUMNS], int rows, int columns);
void findMaxPerRow(int arr[][MAXCOLUMNS], int rows, int columns);
void printLLTriangle(int arr[][MAXCOLUMNS], int rows, int columns);
void printURTriangle(int arr[][MAXCOLUMNS], int rows, int columns);
void addMatrix(int M1[][MAXCOLUMNS], int M2[][MAXCOLUMNS], int R[][MAXCOLUMNS], int r, int c);
int sumSurrounding(int arr[][MAXCOLUMNS], int rows, int columns, int i, int j);