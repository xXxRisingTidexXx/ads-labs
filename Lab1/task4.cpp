#include <iostream>
#include <cstdio>
#include <cmath>
#include "common_tasks.h"
#include "task4.h"

using namespace std;

pair<float, int> get_sum_and_amount(float * *matrix, const int *m, const int *n) {
    float sum = 0;
    int amount = 0;
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            float tmp = *(*(matrix + i) + j);
            if (tmp > 0) {
                sum += cos(tmp);
            } else if (tmp < 0) {
                amount++;
            }
        }
    }
    return make_pair(sum, amount);
}

void task4_main() {
    int *m = get_n();
    int n = *m + 1;
    float * *matrix = get_matrix(m, &n);
    pair<float, int> pair = get_sum_and_amount(matrix, m, &n);
    printf("cos sum = %.4f, negative amount = %d", pair.first, pair.second);
    delete_matrix(matrix, m);
}