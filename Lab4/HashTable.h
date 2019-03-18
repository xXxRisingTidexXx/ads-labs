#ifndef LAB4_HASHTABLE_H
#define LAB4_HASHTABLE_H

#include <iostream>
#include "LinkedList.h"
#include "Parallelogram.h"

using namespace std;

class HashTable {
private:
    LinkedList *buckets;
    unsigned int capacity;
    unsigned int size;
    static constexpr unsigned int AUGMENTATION_LIMIT = 2147483647;
    static constexpr float LOAD_FACTOR = 0.7;

public:
    explicit HashTable(unsigned int);
    Parallelogram *get(float);
    void put(Parallelogram *);
    Parallelogram *pop(float);
    friend ostream &operator<<(ostream &, HashTable &);
    ~HashTable();
};


#endif
