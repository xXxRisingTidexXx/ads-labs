#include "HashTable.h"
#include <iostream>
#include "LinkedList.h"
#include "Parallelogram.h"
#include "functools.h"

using namespace std;

typedef HashTable HT;
typedef LinkedList LL;
typedef Parallelogram P;

unsigned int HT::hash(float key) {
    return hashcode(key) & (capacity - 1);
}

void HT::extend() {
    unsigned int old_capacity = capacity;
    capacity = (capacity <= AUGMENTATION_LIMIT) ? capacity << 1 : AUGMENTATION_LIMIT;
    auto *new_buckets = new LL[capacity];
    size = 0;
    for (int i = 0; i < old_capacity; i++) {
        auto *values = buckets[i].get_values();
        for (auto *value: *values) {
            quick_put(value, new_buckets);
        }
        delete values;
    }
    delete [] buckets;
    buckets = new_buckets;
}

void HT::quick_put(P *value, LL *_buckets) {
    auto *bucket = _buckets + hash(value->get_perimeter());
    if (bucket->empty()) {
        size++;
    }
    bucket->push(value);
}

HT::HashTable(unsigned int _capacity) {
    buckets = new LL[_capacity];
    capacity = _capacity;
    size = 0;
}

P *HT::get(float key) {
    return buckets[hash(key)].get(key);
}

void HT::put(P *value) {
    float load = (float) size / capacity;
    if (load > LOAD_FACTOR || equal(load, LOAD_FACTOR)) {
        extend();
    }
    quick_put(value, buckets);
}

P *HT::pop(float key) {
    auto *bucket = buckets + hash(key);
    auto *value = bucket->remove(key);
    if (value != nullptr && bucket->empty()) {
        size--;
    }
    return value;
}

void HT::filter(float square) {
    for (int i = 0; i < capacity; i++) {
        auto *values = (buckets + i)->get_values();
        for (auto *value: *values) {
            if (value->get_square() < square) {
                pop(value->get_perimeter());
            }
        }
        delete values;
    }
}

ostream &operator<<(ostream &out, HT &hash_table) {
    out << "HashTable {";
    for (int i = 0; i < hash_table.capacity; i++) {
        auto *bucket = hash_table.buckets + i;
        out << *bucket;
        if (i != hash_table.capacity - 1 && !bucket->empty()) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}

HT::~HashTable() {
    delete [] buckets;
}
