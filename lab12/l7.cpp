    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>
    #include <locale.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>

    #include "input1.cpp"
    #include "input2.cpp"
    #include "output1.cpp"
    #include "output2.cpp"
    #include "findmax.cpp"
    #include "findsum.cpp"

    int main()
    {
        setlocale(LC_ALL, "Russian");
        int a[20];
        int b[5][4];
        int maxodd = 0;
        int summa = 0;

        srand(time(NULL));

        input1(&a[0], 20);
        output1(&a[0], 20);
        maxodd = findmax(&a[0], 20);
        printf("\nМакс. нечетный элемент: %d\n", maxodd);
        printf("\n");
        printf("\n");
        printf("\n");
        input2(&b[0][0], 5, 4);
        output2(&b[0][0], 5, 4);
        summa = findsum(&b[0][0], 5, 4);
        printf("\nСумма элементов матрицы: %d\n", summa);
        return 0;
    }
