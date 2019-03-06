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

    void set_fields(float * *);

public:
    SparseMatrix();
    SparseMatrix(int &, int&);
    SparseMatrix(float * *, int &, int &);
    SparseMatrix(int &, int &, int &, float *, int *, int *);
    float get(int &, int &) const;
    SparseMatrix operator+(SparseMatrix &);
    SparseMatrix operator*(SparseMatrix &);
    friend ostream &operator<<(ostream &, SparseMatrix &);
    ~SparseMatrix();
};


#endif