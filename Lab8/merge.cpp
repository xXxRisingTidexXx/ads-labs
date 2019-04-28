#include "merge.h"
#include <vector>

using namespace std;

void finish(vector<int> *nums, vector<int> &surplus, int &stop) {
    for (int i = stop; i < surplus.size(); i++) {
        nums->push_back(surplus[i]);
    }
}

vector<int> *merge(vector<int> &nums1, vector<int> &nums2) {
    auto *nums = new vector<int>();
    nums->reserve(nums1.size() + nums2.size());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            nums->push_back(nums1[i++]);
        } else if (nums1[i] > nums2[j]) {
            nums->push_back(nums2[j++]);
        } else {
            nums->push_back(nums1[i++]);
            nums->push_back(nums2[j++]);
        }
    }
    if (i != nums1.size()) {
        finish(nums, nums1, i);
    }
    if (j != nums2.size()) {
        finish(nums, nums2, j);
    }
    return nums;
}