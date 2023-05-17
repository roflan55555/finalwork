#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input2(int* b, int p, int k) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < k; j++) {
            *(b + 4 * i + j) = rand() % 100;;
        }
    }
}
