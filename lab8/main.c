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

void qwerty(int *m, int k, int n, int p){
    for (int i = 0; i < n; i++) {
        printf("%d - ",k++);
    for (int j = 0; j < p; j++) {
        *(m+n*i+j) = rand() % 90+10;
    }

    }

    }

void pupupu(int *m, int n, int i, int j, int k, int p){
 for (int i = 0; i < n; i++) {
        printf("%d - ",k++);
    for (int j = 0; j < p; j++) {
        *(m+n*i+j) = rand() % 90+10;
            printf("%d\t", *(m+n*i+j));}
                    printf("\n");
        }

    }

void popopo(int n, int i, int j, int *m, int total, int max, int min, int max_i, int min_i){

    total = total + *(m+n*i+j);
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
printf("\n");}



void papapa(int max, int min, int max_i, int min_i){
    printf("Максимум = %d -%d спортсмен \n ", max,max_i+1);
    printf("Минимум = %d -%d спортсмен\n", min,min_i+1);
    }


int mas(int *m, int k,int n , int p, int total, int max, int min, int max_i, int min_i)
{

}


int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int max = -123123;
int min = 123123;
int total = 0;
int n, p, h, i, j, total1, k = 1, a[10], *m, *c = a, x[6][5], min_i, max_i;


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
mas(m, k, n, p, total, max, min, min_i, max_i);

qwerty(m,0,n,p);
printf("\n");
pupupu(m,n, i, j, 0, p);
printf("\n");
popopo(n, i, j, *m, total, max, min, max_i, min_i);
printf("\n");
papapa(max, min, max_i, min_i);
printf("\n");
mas(*m, k, n , p, total, max, min, max_i, min_i);
printf("\n");

printf("\n");

return 0;
}
