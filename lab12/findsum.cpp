#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findsum(int* b, int p, int k) {
    int summ = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < k; j++) {
            summ += *(b + 4 * i + j);
        }
    }

    return summ;
}
