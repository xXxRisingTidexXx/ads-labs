#include "sort.h"
#include <vector>
#include <iostream>
#include "merge.h"

using namespace std;

const int RADIX = 10;

void cocktail_sort(vector<int> &nums) {
    int left = 0, right = int(nums.size()) - 1, comparisons = 0, swaps = 0;
    while (left < right) {
        for (int i = left; i < right; i++) {
            comparisons++;
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                swaps++;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            comparisons++;
            if (nums[i - 1] > nums[i]) {
                swap(nums[i - 1], nums[i]);
                swaps++;
            }
        }
        left++;
    }
    cout << "comparisons: " << comparisons << ", swaps: " << swaps << endl;
}

void shell_sort(vector<int> &nums) {
    int n = int(nums.size()), comparisons = 0, rearrangements = 0;
    for (int i = n >> 1; i > 0; i = i >> 1) {
        for (int j = 0; j < i; j++) {
            for (int k = j + i; k < n; k += i) {
                int current = nums[k], position = k;
                while (position >= i && nums[position - i] > current) {
                    nums[position] = nums[position - i];
                    position -= i;
                    comparisons++;
                    rearrangements++;
                }
                nums[position] = current;
            }
        }
    }
    cout << "comparisons: " << comparisons << ", rearrangements: " << rearrangements << endl;
}

int partition(vector<int> &nums, int low, int high) {
    int pivot = high, i = low - 1;
    for (int j = low; j < pivot; j++) {
        if (nums[j] < nums[pivot]) {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[++i], nums[pivot]);
    return i;
}

void quick_sort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        quick_sort(nums, low, pivot - 1);
        quick_sort(nums, pivot + 1, high);
    }
}

void quick_sort(vector<int> &nums) {
    quick_sort(nums, 0, int(nums.size()) - 1);
}

void count_sort(vector<int> &nums, int exp) {
    vector<int> output, counts;
    output.reserve(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        output.push_back(0);
    }
    counts.reserve(RADIX);
    for (int i = 0; i < RADIX; i++) {
        counts.push_back(0);
    }
    for (int num : nums) {
        counts[(num / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        counts[i] += counts[i - 1];
    }
    for (int i = (unsigned) nums.size() - 1; i >= 0; i--) {
        int position = (nums[i] / exp) % 10;
        output[counts[position] - 1] = nums[i];
        counts[position]--;
    }
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = output[i];
    }
}

void radix_sort(vector<int> &nums) {
    int maximum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maximum = max(maximum, nums[i]);
    }
    for (int exp = 1; maximum / exp > 0; exp *= 10) {
        count_sort(nums, exp);
    }
}

void sift_down(vector<int> &heap, int i, int n) {
    while (2 * i + 1 < n) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int j = (right < n && heap[right] > heap[left]) ? right : left;
        if (heap[i] >= heap[j]) {
            return;
        }
        swap(heap[i], heap[j]);
        i = j;
    }
}

void build_heap(vector<int> &nums, int &n) {
    for (int i = n / 2; i >= 0; i--) {
        sift_down(nums, i, n);
    }
}

void heap_sort(vector<int> &nums) {
    int n = int(nums.size());
    build_heap(nums, n);
    int heap_size = n;
    for (int i = 0; i <= n - 2; i++) {
        swap(nums[0], nums[n - i - 1]);
        heap_size--;
        sift_down(nums, 0, heap_size);
    }
}

vector<int> *divide(vector<int> *nums, unsigned long start, unsigned long size) {
    auto *half = new vector<int>();
    half->reserve(size);
    for (unsigned long i = start; i < start + size; i++) {
        half->push_back((*nums)[i]);
    }
    return half;
}

vector<int> *sort(vector<int> *nums) {
    if (nums->size() <= 1) {
        return nums;
    }
    unsigned long mid = nums->size() >> 1;
    auto *nums1 = divide(nums, 0, mid);
    auto *nums2 = divide(nums, mid, nums->size() - mid);
    auto *sorted1 = sort(nums1);
    auto *sorted2 = sort(nums2);
    auto *merged = merge(*sorted1, *sorted2);
    if (nums1->size() > 1) {
        delete sorted1;
    }
    delete nums1;
    if (nums2->size() > 1) {
        delete sorted2;
    }
    delete nums2;
    return merged;
}

void merge_sort(vector<int> &nums) {
    if (nums.size() > 1) {
        auto *sorted = sort(&nums);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (*sorted)[i];
        }
        delete sorted;
    }
}