#include <iostream>
#include "SparseMatrix.h"
#include "common_tasks.h"

int calculate_nonnull(float * *matrix, int &m, int &n) {
    int nonnull = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(matrix + i) + j) != 0) {
                nonnull++;
            }
        }
    }
    return nonnull;
}

SparseMatrix::SparseMatrix(float * *matrix, int &m, int &n) {
    this->m = m;
    this->n = n;
    this->nonnull = calculate_nonnull(matrix, m, n);
    this->elements = new float[nonnull];
    this->rows = new int[m];
    this->columns = new int[nonnull];
    int k = 0;
    for (int i = 0; i < m; i++) {
        *(rows + i) = 0;
        for (int j = 0; j < n; j++) {
            float f = *(*(matrix + i) + j);
            if (f != 0) {
                *(elements + k) = f;
                *(rows + i) += 1;
                *(columns + k) = j;
                k++;
            }
        }
    }
}

float SparseMatrix::get(int &i, int &j) {
    float f = 0;
    if (*(rows + i) > 0) {
        int k = -1;
        for (int x = 0; x < i; x++) {
            k += *(rows + x);
        }
        int l = k + *(rows + i);
        for (k = k + 1; k <= l; k++) {
            if (*(columns + k) == j) {
                f = *(elements + k);
                break;
            }
        }
    }
    cout << f;
    return f;
}

SparseMatrix &SparseMatrix::operator+(SparseMatrix &other) {
    auto * *matrix = get_empty_matrix(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = get(i, j) + other.get(i, j);
        }
    }
    static SparseMatrix sparse_matrix = SparseMatrix(matrix, m, n);
    delete_matrix(matrix, m);
    return sparse_matrix;
}

//SparseMatrix &SparseMatrix::operator*(SparseMatrix &other) {
//}

SparseMatrix::operator string() {
    string sparse_matrix;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sparse_matrix += " " + to_string(get(i, j));
        }
        sparse_matrix += "\n";
    }
    return sparse_matrix;
}

SparseMatrix::~SparseMatrix() {
    delete [] elements;
    delete [] rows;
    delete [] columns;
}