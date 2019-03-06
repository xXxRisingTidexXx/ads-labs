#include <iostream>
#include "SparseMatrix.h"
#include "common_tasks.h"

using namespace std;

float *get_elements(int &n) {
    auto *elements = new float[n];
    for (int i = 0; i < n; i++) {
        cout << "elements[" << i << "]: ";
        cin >> *(elements + i);
    }
    return elements;
}

int *get_indices(int &n) {
    auto *indices = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "indices[" << i << "]: ";
        cin >> *(indices + i);
    }
    return indices;
}

int main() {
    SparseMatrix sm1;
    int m = get_int(), n = get_int(), nonnull = get_int();
    float * elements = get_elements(nonnull);
    int *rows = get_indices(m);
    int *columns = get_indices(nonnull);
    SparseMatrix sm2(m, n, nonnull, elements, rows, columns);
    cout << "\nsm1:\n" << sm1 << "\nsm2:\n" << sm2;
    SparseMatrix sm3 = sm1 + sm2;
    SparseMatrix sm4 = sm1 * sm2;
    cout << "\nsm3:\n" << sm3 << "\nsm4:\n" << sm4;
    return 0;
}