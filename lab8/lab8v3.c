#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
//1
void ran(int *mas, int i)
{
     for(i = 0; i < 10; i++) {
        *(mas+i) = rand() % 100;
}
}

void find0(int *mas, int i)
{
   for(i = 0; i < 10; i++)
    {
        if (*(mas+i) % 10 == 0)
        {

        }
}
}
void output1(int *mas, int i)
{
    printf("%d\t", *(mas+i));
        printf("\n");

    printf("%d\t\n", i);
        printf("\n");
}
//2

typedef struct {
    int row;
    int total;
} pair;

void random_array (int [][COLS], int, int);
void printf_array (int [][COLS], int, int);
int  sum_elements (int [], int);
pair constructor  (int, int);
void minmax_array (int [][COLS], int, int, pair *, pair *);

int main (void) {
#include <stdio.h>
#include <stdlib.h>
enum {ROWS = 6, COLS = 5}
    int a[ROWS][COLS];
    random_array(a, ROWS, COLS);

    pair min, max;
    minmax_array(a, ROWS, COLS, &min, &max);

    printf_array(a, ROWS, COLS);
    printf("min = %d, athlete %d\n", min.total, min.row + 1);
    printf("max = %d, athlete %d\n", max.total, max.row + 1);
    return 0;
}
// -------------------------------------------------------------
void random_array (int a[][COLS], int rows, int columns) {
    srand((unsigned) time(NULL) / 2);
    for (int i = 0; i < rows; i++)
        for (int k = 0; k < columns; k++)
            a[i][k] = rand() %100;      // a[i][k] <=> *( *(a + i)  + k)
}
// -------------------------------------------------------------
void printf_array (int a[][COLS], int rows, int columns) {
    for (int i = 0; i < rows; i++, puts(""))
        for (int k = 0; k < columns; k++)
            printf("%4d", a[i][k]);
    puts("");
}
// -------------------------------------------------------------
int sum_elements (int a[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i];
    return sum;
}
// -------------------------------------------------------------
pair constructor (int row, int total) {
    return (pair) {row, total};
}
// -------------------------------------------------------------
void minmax_array (int a[][COLS], int rows, int columns, pair * min, pair * max) {
    for (int i = 0; i < rows; i++) {
        int total = sum_elements(a[i], columns);
        if (i < 1 || total > max->total)
            *max = constructor(i, total);   // max->row = i; max->total = total;
        if (i < 1 || total < min->total)
            *min = constructor(i, total);
    }
}
// -------------------------------------------------------------
