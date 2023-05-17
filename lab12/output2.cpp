#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void output2(int* b, int p, int k) {
    char str[5] = { 'A', 'B', 'C', 'D', 'F' };

    for (int i = 0; i < p; i++) {
        printf("%c ", str[i]);
        for (int j = 0; j < k; j++) {
            printf("%d ", *(b + 4 * i + j));
        }
        printf("\n");
    }
}

