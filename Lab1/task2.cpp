#include <cstdio>
#include "common_tasks.h"
#include "task2.h"

using namespace std;

void rearrange_zeros_and_ones(float *array, const int *n) {
    int i = 0, count = 0;
    while (i < *n - count) {
        float a = *(array + i);
        if (a == 0 || a == 1) {
            for (int j = i; j < *n - 1; j++) {
                *(array + j) = *(array + j + 1);
            }
            *(array + *n - 1) = a;
            count++;
        } else {
            i++;
        }
    }
    for (i = 0; i < *n; i++) {
        printf("array[%d] = %.2f\n", i, *(array + i));
    }
}

void task2_main() {
    int *n = get_n();
    auto *array = get_array(n);
    rearrange_zeros_and_ones(array, n);
    delete [] array;
}