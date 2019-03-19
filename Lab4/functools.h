#ifndef LAB4_FUNCTOOLS_H
#define LAB4_FUNCTOOLS_H

static const float EPSILON = 0.000000001;
static const float HASH_FACTOR = 1000;
static const unsigned int MOD = 4294967295;

bool equal(float, float);

unsigned int hashcode(float);

#endif
