#include <iostream>
#include <iomanip>
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

void SparseMatrix::set_fields(float * *_matrix) {
    nonnull = calculate_nonnull(_matrix, m, n);
    elements = new float[nonnull];
    rows = new int[m];
    columns = new int[nonnull];
    int k = 0;
    for (int i = 0; i < m; i++) {
        *(rows + i) = 0;
        for (int j = 0; j < n; j++) {
            float f = *(*(_matrix + i) + j);
            if (f != 0) {
                *(elements + k) = f;
                *(rows + i) += 1;
                *(columns + k) = j;
                k++;
            }
        }
    }
}

SparseMatrix::SparseMatrix() {
    m = get_int();
    n = get_int();
    auto * *matrix = get_matrix(m, n);
    set_fields(matrix);
    delete_matrix(matrix, m);
}

SparseMatrix::SparseMatrix(float * *_matrix, int &_m, int &_n) {
    m = _m;
    n = _n;
    set_fields(_matrix);
}

float SparseMatrix::get(int &i, int &j) const {
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
    return f;
}

SparseMatrix SparseMatrix::operator+(SparseMatrix &other) {
    auto * *matrix = get_empty_matrix(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = get(i, j) + other.get(i, j);
        }
    }
    SparseMatrix sm = SparseMatrix(matrix, m, n);
    delete_matrix(matrix, m);
    return sm;
}

SparseMatrix SparseMatrix::operator*(SparseMatrix &other) {
    int k = other.n;
    auto * *matrix = get_empty_matrix(m, k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int r = 0; r < n; r++) {
                *(*(matrix + i) + j) += get(i, r) * other.get(r, j);
            }
        }
    }
    SparseMatrix sm = SparseMatrix(matrix, m, k);
    delete_matrix(matrix, m);
    return sm;
}

ostream &operator<<(ostream &out, SparseMatrix &sparse_matrix) {
    out << fixed << setprecision(2);
    for (int i = 0; i < sparse_matrix.m; i++) {
        for (int j = 0; j < sparse_matrix.n; j++) {
            out << sparse_matrix.get(i, j) << " ";
        }
        out << endl;
    }
    return out;
}

SparseMatrix::~SparseMatrix() {
    delete [] elements;
    delete [] rows;
    delete [] columns;
}