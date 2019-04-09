#include <iostream>
#include <vector>
#include <string>
#include "search.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int main() {
    srand((unsigned) time(nullptr));
    const int SIZE = 60;
    vector<int> nums1;
    nums1.reserve(SIZE);
    vector<int> nums2;
    nums2.reserve(SIZE);
    for (int i = 0; i < SIZE; i++) {
        nums1.push_back(rand() % 80 - 2 * i);
        nums2.push_back(rand() % 80 - i);
    }
    sort(nums2.begin(), nums2.end());
    for (int i = 0; i < SIZE; i++) {
        cout << nums1[i] << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < SIZE; i++) {
        cout << nums2[i] << " ";
    }
    cout << "\n\nEnter num: ";
    int num;
    cin >> num;
    cout << "num index at nums1: " << linear_search(nums1, num) <<
    "\nnum index at nums2: " << binary_search(nums2, num) << endl;
    string str, img;
    cout << "\nEnter str: ";
    cin >> str;
    cout << "Enter img: ";
    cin >> img;
    cout << "img starts at str at(linear/KMP/BM): " << substring_search(str, img) <<
    ", " << kmp_search(str, img) << ", " << bm_search(str, img);
    return 0;
}