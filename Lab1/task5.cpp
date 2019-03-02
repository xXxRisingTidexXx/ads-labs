#include <cstdio>
#include "common_tasks.h"
#include "task5.h"

void fill_matrix(float * *matrix, const int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            *(*(matrix + i) + j) = (j < *n - i) ? 1 : 0;
            printf("%2.0f", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void task5_main() {
    int *n = get_n();
    float * *matrix = get_square_matrix(n);
    fill_matrix(matrix, n);
    delete_matrix(matrix, n);
}