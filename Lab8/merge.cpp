#include "merge.h"
#include <vector>
#include <iostream>

using namespace std;

void output(vector<int> &nums) {
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

void finish(vector<int> &res, vector<int> &surplus, int &stop) {
    for (int i = stop; i < surplus.size(); i++) {
        res.push_back(surplus[i]);
    }
}

void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &res) {
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            res.push_back(nums1[i++]);
            res.push_back(nums2[j++]);
        } else if (nums1[i] < nums2[j]) {
            if (i < nums1.size() - 1 && nums1[i] <= nums1[i + 1]) {
                res.push_back(nums1[i++]);
            } else {
                res.push_back(nums1[i++]);
                res.push_back(nums2[j++]);
            }
        } else if (nums1[i] > nums2[j]) {
            if (j < nums2.size() - 1 && nums2[j] <= nums2[j + 1]) {
                res.push_back(nums2[j++]);
            } else {
                res.push_back(nums2[j++]);
                res.push_back(nums1[i++]);
            }
        }
    }
    if (i != nums1.size()) {
        finish(res, nums1, i);
    }
    if (j != nums2.size()) {
        finish(res, nums2, j);
    }
}

vector<int> *simple_merge(vector<int> &nums1, vector<int> &nums2) {
    auto *res = new vector<int>();
    res->reserve(nums1.size() + nums2.size());
    merge(nums1, nums2, *res);
    return res;
}

bool is_sorted(vector<int> &res) {
    if (res.size() > 1) {
        for (int i = 1; i < res.size(); i++) {
            if (res[i] < res[i - 1]) {
                return false;
            }
        }
    }
    return true;
}

void split(vector<int> &nums, vector<int> &tape1, vector<int> &tape2) {
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] >= nums[i - 1]) {
            tape1.push_back(nums[i]);
        } else {
            tape2.push_back(nums[i]);
        }
    }
}

vector<int> *natural_merge(vector<int> &nums) {
    auto *res = new vector<int>(nums);
    vector<int> tapes[2];
    while (!is_sorted(*res)) {
        split(*res, tapes[0], tapes[1]);
        res->clear();
        merge(tapes[0], tapes[1], *res);
        output(*res);
        tapes[0].clear();
        tapes[1].clear();
    }
    return res;
}

vector<int> *polyphase_merge(vector<int> &nums1, vector<int> &nums2) {
    auto *tape1 = new vector<int>(nums1);
    auto *tape2 = new vector<int>(nums2);
    vector<int> temp;
    temp.reserve(nums1.size() + nums2.size());
    while (!tape1->empty() && !tape2->empty()) {
        merge(*tape1, *tape2, temp);
        output(temp);
        tape1->clear();
        tape2->clear();
        split(temp, *tape1, *tape2);
        temp.clear();
    }
    if (tape1->empty()) {
        delete tape1;
        return tape2;
    }
    delete tape2;
    return tape1;
}