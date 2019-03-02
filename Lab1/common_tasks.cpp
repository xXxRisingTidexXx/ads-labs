#include <iostream>
#include <cstdio>
#include "common_tasks.h"

using namespace std;

int *get_n() {
    static int n;
    cout << "Enter n: ";
    cin >> n;
    return &n;
}

float *get_array(const int *n) {
    auto *array = new float[*n];
    for (int i = 0; i < *n; i++) {
        printf("array[%d]: ", i);
        cin >> *(array + i);
    }
    return array;
}

float * *get_matrix(const int *m, const int *n)
{
    auto * *matrix = new float*[*m];
    for (int i = 0; i < *m; i++) {
        *(matrix + i) = new float[*n];
        for (int j = 0; j < *n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            cin >> *(*(matrix + i) + j);
        }
    }
    return matrix;
}

void delete_matrix(float * *matrix, const int *m) {
    for (int i = 0; i < *m; i++) {
        delete [] *(matrix + i);
    }
    delete [] matrix;
}

float * *get_square_matrix(const int *n)
{
    auto * *matrix = new float*[*n];
    for (int i = 0; i < *n; i++) {
        *(matrix + i) = new float[*n];
    }
    return matrix;
}