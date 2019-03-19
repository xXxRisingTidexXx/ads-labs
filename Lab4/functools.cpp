#include "functools.h"
#include <cmath>

using namespace std;

bool equal(float a, float b) {
    return fabs(a - b) < EPSILON;
}

unsigned int hashcode(float key) {
    return ((unsigned int) ceil(key * HASH_FACTOR)) % MOD;
}
