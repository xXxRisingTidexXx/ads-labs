#ifndef LAB2_SPARSE_MATRIX_H
#define LAB2_SPARSE_MATRIX_H

#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

class SparseMatrix {
private:
    int m;
    int n;
    int nonnull;
    float *elements;
    int *rows;
    int *columns;

public:
    SparseMatrix(float * *, int &, int &);
    float get(int &, int &);
    SparseMatrix &operator+(SparseMatrix &);
    SparseMatrix &operator*(SparseMatrix &);
    explicit operator string();
    ~SparseMatrix();
};


#endif