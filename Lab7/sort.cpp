#include "sort.h"
#include <vector>
#include <algorithm>

using namespace std;

void insertion_sort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        int key = nums[i], j = i - 1;
        for (; j >= 0 && nums[j] > key; j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = key;
    }
}

void shifting_sort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--) {
            swap(nums[j], nums[j + 1]);
        }
    }
}

void selection_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

void counting_sort(vector<int> &nums) {
    auto counts = vector<int>();
    auto max = (unsigned long) *max_element(nums.begin(), nums.end()) + 1;
    counts.reserve(max);
    for (int i = 0; i < max; i++) {
        counts.push_back(0);
    }
    for (auto num: nums) {
        counts[num]++;
    }
    for (int i = 0, j = 0; i < max; i++) {
        for (int k = 0; k < counts[i]; k++) {
            nums[j++] = i;
        }
    }
}

void bubble_sort(vector<int> &nums) {
    int n = int(nums.size()) - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}
