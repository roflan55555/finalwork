#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define max100
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

int main()
{
setlocale(LC_ALL, "Russian");
FILE *q;
FILE *w;
FILE *e;
FILE *r;
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
int h;
int a[10];
int* c = a;

srand(time(NULL));

q = fopen("itog.txt","w+");
w = fopen("output.txt","w+");
for (h = 0; h < 10; h++) {
*(c+h) = rand() % 100; // �������� ��������� ����� �� 0 �� 100
printf("%d ", *(c+h));

    fprintf(q, "%d ", *(c+h));
        fprintf(w, "%d ", *(c+h));
}
printf("\n");
fclose(q);
fclose(w);

w = fopen("output.txt","a");
for (i = 0; i < 10; i++)
{
if (*(c+i) % 10 == 0)
{
printf("%d\t", i);
}
}

printf("\n");
j = 0;

m = &x[0][0];

printf("���-�� ����� =");
scanf("%d", &n);
printf("���-�� �������� =");
scanf("%d", &p);



for (i = 0; i < n; i++) {
printf("%d - ",k++);
for (j = 0; j < p; j++) {
*(m+n*i+j) = rand() % 90+10;
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

printf("�������� = %d - %d ��������� \n ", max,max_i+1);
printf("������� = %d - %d ���������\n", min,min_i+1);
printf("����� ����� �� �������� ��������: %d",summ);




return 0;
}
