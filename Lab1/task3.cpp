#include <iostream>
#include <cstdio>
#include "common_tasks.h"
#include "task3.h"

using namespace std;

float *get_avg() {
    static float avg;
    cout << "Enter avg: ";
    cin >> avg;
    return &avg;
}

int get_avg_row_count(float * *matrix, const int *m, const int *n, const float *avg) {
    int avg_count = 0;
    for (int i = 0; i < *m; i++) {
        float sum = 0;
        for (int j = 0; j < *n; j++) {
            sum += *(*(matrix + i) + j);
        }
        avg_count += (sum / *n < *avg) ? 1 : 0;
    }
    return avg_count;
}

void make_triangular(float * *matrix, const int *m, const int *n) {
    for (int i = 0; i < *m - 1; i++) {
        if (*(*(matrix + i) + i) != 0) {
            for (int j = i + 1; j < *m; j++) {
                float first = *(*(matrix + j) + i);
                for (int k = i; k < *n; k++) {
                    *(*(matrix + j) + k) -= *(*(matrix + i) + k) * first / *(*(matrix + i) + i);
                }
            }
        }
    }
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            printf("%6.2f", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void task3_main() {
    int *m = get_n();
    int n = *m + 1;
    float * *matrix = get_matrix(m, &n);
    float *avg = get_avg();
    printf("average row count = %d\n", get_avg_row_count(matrix, m, &n, avg));
    make_triangular(matrix, m, &n);
    delete_matrix(matrix, m);
}