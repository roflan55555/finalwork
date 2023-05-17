#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
int main()
{
setlocale(LC_ALL,"Russian");
FILE *out;
FILE *outb;
FILE *outmass;
FILE *vse;
int a[20];
int x[6][8];
int b = 0, i, c = 0, j, z, k, h;
int *p;
int *m;

srand(time(NULL));

p = &a;
vse = fopen("vse.txt","w+");
out = fopen("output.txt","w+");
    for (h = 0; h < 20; h++, p++) { //инициализация массива, его вывод и запись его в файлы

        *p = rand() % 100;
        printf("%d ", *p);

        fprintf(out, "%d ", *p);
        fprintf(vse, "%d ", *p);

    }

fclose(out);
fclose(vse);

    for (h = 0; h < 20; h++)
    {
        a[h] = 0;
    }

    out = fopen("output.txt","r+");
    outb = fopen("output1.txt","w+");

    for (h = 0; h < 20; h++) { //Вычесление закономерной суммы, чтение из файла и запись результата работы в другой файл

        fscanf(out, "%d" , &a[h]);

        b = b + pow(-1.0,h)*a[h];

        fprintf(outb,"%d\n", b);
    }
    fclose(out);
    fclose(outb);

    m = &x[0][0];

    printf("\n");
    printf("\n");

    outmass = fopen("outputmass.txt","w+");
    vse = fopen("itog.txt","a+");
    fprintf(vse, "\n");
    fprintf(vse, "\n");

    for (z = 0; z < 6; z++) //Инициализая двумерного массива, вывод его на экран и запись его в файлы
    {
        for (j = 0; j < 8; j++)
        {
        *m =rand()%100;

        fprintf(outmass,"%d\t", *m);
        fprintf(vse,"%d\t", *m);
        printf("%3d", *m);

        if (j == 7){
            fprintf(outmass,"\n");
            fprintf(vse,"\n");
        }

        }
        printf("\n");
    }

    fclose(outmass);
    fclose(vse);
    printf("Введите K: ");
    scanf("%d", &k);

    m = NULL;

    for (z = 0; z < 6; z++) //обнуление двумерного массива
    {
        for (j = 0; j < 8; j++)
        {
            x[z][j] = 0;
        }
    }
    outmass = fopen("outmass.txt","r");

    for (z = 0; z < 6; z++) //нахождение суммы элементов матрирцы, чтение из файла и запись в другой файл
    for (j = 0; j < 8; j++)
    {
        fscanf(outmass, "%d" , &x[z][j]);
        if (z + j == k)
            c += x[z][j];
    }
    fclose(outmass);
    printf ("\n");
    printf ("Закономерная сумма равна: %d \n", b);
    printf ("Сумма элементов матрирцы равна: %d ", c);


getchar();
getchar();
    return 0;
}
