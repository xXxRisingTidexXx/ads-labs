#include <iostream>
#include <cstdio>
#include "common_tasks.h"

using namespace std;

int *get_int() {
    static int n;
    cout << "Enter int: ";
    cin >> n;
    return &n;
}

float * *get_matrix(int &m, int &n) {
    auto * *matrix = new float *[m];
    for (int i = 0; i < m; i++) {
        *(matrix + i) = new float[n];
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            cin >> *(*(matrix + i) + j);
        }
    }
    return matrix;
}

float * *get_empty_matrix(int &m, int &n) {
    auto * *matrix = new float *[m];
    for (int i = 0; i < m; i++) {
        *(matrix + i) = new float[n];
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = 0;
        }
    }
    return matrix;
}

void delete_matrix(float * *matrix, int &m) {
    for (int i = 0; i < m; i++) {
        delete [] *(matrix + i);
    }
    delete [] matrix;
}