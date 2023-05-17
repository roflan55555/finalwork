#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findmax(int* a, int p) {
    int maxx = 0;
    for (int* i = &a[0]; i < &a[p]; i++) {
        if ((*i % 2 == 1) && (*i > maxx)) maxx = *i;
    }

    return maxx;
}
