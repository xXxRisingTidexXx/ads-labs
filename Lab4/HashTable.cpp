#include "HashTable.h"
#include <iostream>
#include "LinkedList.h"
#include "Parallelogram.h"
#include "functools.h"

using namespace std;

typedef HashTable HT;
typedef Parallelogram P;

HT::HashTable(unsigned int _capacity) {
    buckets = new LinkedList[_capacity];
    capacity = _capacity;
    size = 0;
}

P *HT::get(float key) {
    return (buckets + hashcode(key))->get(key);
}

void HT::put(P *value) {
    unsigned int i = hashcode(value->get_perimeter());
    float load = (float) size / capacity;
    if (load > LOAD_FACTOR || equal(load, LOAD_FACTOR)) {
        auto old_capacity = capacity;
        capacity = (capacity <= AUGMENTATION_LIMIT) ? capacity << 1 : AUGMENTATION_LIMIT;
        auto *new_buckets = new LinkedList[capacity];
        for (int j = 0; j < old_capacity; j++) {
            *(new_buckets + j) = *(buckets + j);
        }
        delete [] buckets;
        buckets = new_buckets;
    }
    size++;
    (buckets + i)->push(value);
}

P *HT::pop(float key) {
    auto *value = (buckets + hashcode(key))->remove(key);
    if (value != nullptr) {
        size--;
    }
    return value;
}

ostream &operator<<(ostream &out, HT &hash_table) {
    cout << "HashTable {" << endl;
    for (int i = 0; i < hash_table.capacity; i++) {
        cout << *(hash_table.buckets + i);
    }
    out << "}" << endl;
    return out;
}

HT::~HashTable() {
    delete [] buckets;
}
