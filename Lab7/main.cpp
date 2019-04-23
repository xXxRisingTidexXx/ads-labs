#include <iostream>
#include "sort.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

void output(vector<int> &nums) {
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned) time(nullptr));
    const int SIZE = 20;
    vector<int> nums;
    nums.reserve(SIZE);
    for (int i = 0; i < SIZE; i++) {
        nums.push_back(rand() % 80);
    }
    output(nums);
    bubble_sort(nums);
    output(nums);
    return 0;
}