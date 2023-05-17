#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>

int first()
{
    setlocale(LC_ALL, "Russian");
    int j;
    int i, h, k;
    int a[10];
    int* p;

    srand(time(NULL));

    for (h = 0; h < 10; h++) {
        a[h] = rand() % 100; // диапазон случайных чисед от 0 до 100
        printf("%d ", a[h]);
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        if (a[i] % 10 == 0)
        {
            printf("%d\t", i);
        }
    }

    getchar();
    getchar();
    return 0;
}
int second()
{
setlocale(LC_ALL, "Russian");
int min_i,max_i;
int x[6][5];
int max = 0;
int min = 1000000;
int total = 0;
int n,p;
int summ=0;
int *m;
int i, j;
int k = 1;
m = &x[0][0];



srand(time(NULL));
for (i = 1; i < n+1; i++) {
    printf("%d - ",k++);
    for (j = 1; j < p+1; j++) {
        *(m+n*i+j)  = rand() % 90+10;
        if (j == 3)
        {
            summ += *(m+n*i+j);

        }

printf("%d\t",*(m+n*i+j));
total = total + *(m+n*i+j);
}

if (max < total)
{
max = total;
max_i=i;
}

if (min > total)
{
min = total;
min_i = i;

}

total = 0;
printf("\n");

}

printf("Максимум = %d - %d спортсмен \n ", max,max_i+1);
printf("Минимум = %d - %d спортсмен\n", min,min_i+1);
printf("Сумма строк по третьему элементу: %d",summ);

return 0;
}
int main(void){first();second();return 0;}
