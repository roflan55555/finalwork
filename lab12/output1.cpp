    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>

    void output1(int* a, int p) {
        for (int* i = &a[0]; i < &a[p]; i++) printf("%d ", *i);
    }
