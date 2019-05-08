#include <iostream>
#include <vector>
#include "sort.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include "merge.h"

using namespace std;

int main() {
    srand((unsigned) time(nullptr));
    const int SIZE = 20;
    vector<int> nums1;
    vector<int> nums2;
    nums1.reserve(SIZE);
    nums2.reserve(SIZE);
    for (int i = 0; i < SIZE; i++) {
        nums1.push_back(rand() % 80);
        nums2.push_back(rand() % 80 - i);
    }
    output(nums1);
    output(nums2);
    cout << endl;
    auto *merged = polyphase_merge(nums1, nums2);
    output(*merged);
    delete merged;
    return 0;
}