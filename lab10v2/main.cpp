#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
setlocale(LC_ALL, "Russian");

// 1
int mas[10];
int i, h, k;
int* m;
char name1[20];
char name2[20];
srand(time(NULL));


scanf("%s", name1);
strcat(name1, ".txt");
FILE* vse = fopen(name1, "w+");


for (i = 0; i < 10; i++) {
*(mas + i) = rand() % 100;
printf("%d\t", *(mas + i));


fprintf(vse, "%d\t", *(mas + i));
}
printf("\n");

fclose(vse);
scanf("%s", name2);
strcat(name2, ".txt");

FILE* output1 = fopen(name2, "w+");
int* y = &mas[0];
for (i = 0; i < 10; i++)
{
if (*(y + i) % 10 == 0)
{
printf("Элемент, оканчивающийся на ноль - %d\t\n ", *(y + i));
fprintf(output1, "%d\t", i);
printf( "Номер элемента, оканчивающегося на ноль %d\t\n", i+1);
}

}


fclose(output1);
printf("\n");
// 2
int mas2[6][5];
m = &mas2[0][0];
int total = 0;
int min_i, max_i;
int max = 0;
int min = 1000000;


vse = fopen(name1, "a+");
output1 = fopen(name2, "a+");
fprintf(vse, "\n");
fprintf(vse, "\n");
int poz = ftell(vse);

for (i = 0; i < 6; i++)
{
for (k = 0; k < 5; k++)
{
*(m + 5 * i + k) = rand() % 100;


fprintf(vse, "%d\t", *(m + 5 * i + k));
printf("%d\t", *(m + 5 * i + k));

if (k == 5) {

fprintf(vse, "\n");
}


total = total + *(m + 5 * i + k);
}
printf("\n");


fprintf(vse, "\n");

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
fprintf(output1, "\n");
fprintf(output1, "Максимум = %d - %d спортсмен \n", max, max_i + 1);
fprintf(output1, "Минимум = %d - %d спортсмен\n", min, min_i + 1);
fclose(vse);
int temp = 0;
scanf("%s", name2);
strcat(name2, ".txt");
while ((vse = fopen(name2, "r+")) == NULL)
{
printf("Не удалось открыть файл\n");
scanf("%s", name2);
strcat(name2, ".txt");
}

fseek(vse, poz, SEEK_SET);
for (int i = 1; i < 31; i++) {
fscanf(vse, "%d ", &temp);
printf("%d\t", temp);
printf(" ");
if (i % 5 == 0) {

printf( "\n");
}
}
fclose(vse);
fclose(output1);


printf("Максимум = %d - %d спортсмен \n", max, max_i + 1);
printf("Минимум = %d - %d спортсмен\n", min, min_i + 1);


return 0;
}
