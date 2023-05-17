#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
void random1(int *z)
{
   for (int h = 0; h < 10; h++) {
        *(z+h) = rand() % 100; // диапазон случайных чисед от 0 до 100
        printf("%d ", *(z+h));
}

}
void crat10(int *z)
{
    for (int i = 0; i < 10; i++)
{
    if (*(z+i) % 10 == 0)
    {
    printf("%d\t", i);
    }
}
}
int mas(int *m, int k,int n , int p, int total, int max, int min, int max_i, int min_i)
{
    for (int i = 0; i < n; i++) {
        printf("%d - ",k++);
    for (int j = 0; j < p; j++) {
        *(m+n*i+j) = rand() % 90+10;
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

}





int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int min_i,max_i;
int x[6][5];
int max = -123123;
int min = 123123;
int total = 0;
int n,p;
int *m;
int i, j;
int k = 1;
int h;
int total1;
int a[10];
int* c = a;

srand(time(NULL));

random1(c);
printf("\n");
crat10(c);
printf("\n");
j = 0;

m = &x[0][0];

printf("Кол-во строк =");
scanf("%d", &n);
printf("Кол-во столбцов =");
scanf("%d", &p);
mas(&x[0][0],k,n ,p, total,max,min,min_i,max_i);




printf("\n");



return 0;
}
