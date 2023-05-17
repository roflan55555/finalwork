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
int min_i,max_i;
int x[6][5];
int max = 0;
int min = 1000000;
int total = 0;
int n,p;
int summ=0;
int *m;
int i, j = 0;
int k = 1;
int *h;
int a[10];
int *c = a;

srand(time(NULL));

for (h = &a[0]; h < &a[10];h++ ) {
*h = rand() % 100; // диапазон случайных чисед от 0 до 100
printf("%d ", *h);
}
printf("\n");
for (h = &a[0]; c < &a[10]; c++)
{
if (*c % 10 == 0)
{
printf("%d\t", i);
}
i++;
}
printf("\n");
j = 0;


m = &x[0][0];


printf("Кол-во строк =");
scanf("%d", &n);
printf("Кол-во столбцов =");
scanf("%d", &p);



for (i = 0; i < n; i++) {
printf("%d - ",k++);
for (j = 0; j < p; j++) {
*(*(x+i)+j) = rand() % 90+10;
if (j == 2)
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
