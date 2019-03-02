#include <iostream>
#include <cstdio>
#include "common_tasks.h"
#include "task1.h"

using namespace std;

float get_abs_max(const float *array, const int *n) {
    float max = *array;
    for (int i = 1; i < *n; i++) {
        float abs_ai = abs(*(array + i));
        max = (abs_ai > max) ? abs_ai : max;
    }
    return max;
}

pair<int, int> get_indices(const float *array, const int *n)
{
    int f_pos_i = -1, s_pos_i = -1;
    for (int i = 0; i < *n && (f_pos_i == -1 || s_pos_i == -1); i++) {
        if (*(array + i) > 0) {
            if (f_pos_i == -1) {
                f_pos_i = i;
            } else {
                s_pos_i = i;
            }
        }
    }
    return make_pair(f_pos_i, s_pos_i);
}

float get_sum_between_positives(const float *array, const int *n) {
    pair<int, int> indices = get_indices(array, n);
    float sum = 0;
    for (int i = indices.first + 1; i < indices.second; i++) {
        sum += *(array + i);
    }
    return sum;
}

void task1_main() {
    int *n = get_n();
    auto *array = get_array(n);
    printf("absolute max = %.2f\n", get_abs_max(array, n));
    printf("sum between positives = %.2f", get_sum_between_positives(array, n));
    delete [] array;
}