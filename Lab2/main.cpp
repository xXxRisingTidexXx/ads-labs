#include <iostream>
#include "common_tasks.h"
#include "SparseMatrix.h"

using namespace std;

int main() {
    int m = *get_int();
    int n = *get_int();
    float * *matrix1 = get_matrix(m, n);
    SparseMatrix sparse_matrix1 = SparseMatrix(matrix1, m, n);
    cout << string(sparse_matrix1);
    delete_matrix(matrix1, m);
    return 0;
}