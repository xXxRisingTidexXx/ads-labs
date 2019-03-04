#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main() {
    SparseMatrix sm1;
    SparseMatrix sm2;
    cout << "\nsm1:\n" << sm1 << "\nsm2:\n" << sm2;
    SparseMatrix sm3 = sm1 + sm2;
    SparseMatrix sm4 = sm1 * sm2;
    cout << "\nsm3:\n" << sm3 << "\nsm4:\n" << sm4;
    return 0;
}