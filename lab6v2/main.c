#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
   setlocale(LC_ALL, "Russian");

// 1
    int mas[10];
    int i, h, k;
    int *m;

    srand(time(NULL));
    for(i = 0; i < 10; i++) {
        *(mas+i) = rand() % 100;
        printf("%d\t", *(mas+i));
        }
        printf("\n");


    for(i = 0; i < 10; i++)
    {
        if (*(mas+i) % 10 == 0)
        {
        printf("%d\t\n", i);
        }
    }
        printf("\n");
// 2
    int mas2[6][5];
    m = &mas2[0][0];
    int total = 0;
    int min_i, max_i;
    int max = 0;
    int min = 1000000;


    for(i = 0; i < 6; i++)
        {
        for(k = 0; k < 5; k++)
        {
        *(m + 6 * i + k) = rand() % 100;
        printf("%d\t", *(m + 6 * i + k));
        total = total + *(m + 6 * i + k);
        }
        printf("\n");


    if (max < total)
    {
        max = total;
        max_i = i;
    }

    if (min > total)
    {
        min = total;
        min_i = i;

    }

    total = 0;
    }

    printf("Максимум = %d - %d спортсмен \n", max, max_i + 1);
    printf("Минимум = %d - %d спортсмен\n", min, min_i + 1);


    return 0;
}
