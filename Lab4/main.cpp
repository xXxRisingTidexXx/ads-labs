#include <iostream>
#include <vector>
#include "Parallelogram.h"
#include "HashTable.h"

using namespace std;

int main() {
    unsigned int capacity;
    cout << "Enter HashTable capacity: ";
    cin >> capacity;
    HashTable ht(capacity);
    auto values = vector<Parallelogram *>();
    for (int i = 0; i < capacity; i++) {
        values.push_back(new Parallelogram());
        ht.put(values[i]);
    }
    cout << ht << endl;
    float square;
    cout << "Enter target square: ";
    cin >> square;
    ht.filter(square);
    cout << ht << endl;
    for (int i = 0; i < capacity; i++) {
        delete values[i];
    }
    return 0;
}