#include <iostream>
#include <vector>
#include <algorithm>
#include "LinkedList.h"

using namespace std;

typedef LinkedList LL;
typedef LinkedList::Node LLN;

int get_int(const string &prompt) {
    int i;
    cout << prompt;
    cin >> i;
    return i;
}

LL *get_linked_list() {
    int n = get_int("Enter list size: ");
    LL *linked_list = new LinkedList();
    for (int i = 0; i < n; i++) {
        linked_list->push_back(get_int("Enter value: "));
    }
    return linked_list;
}

vector<int> *get_even_positive_numbers(LL* linked_list) {
    auto *nums = new vector<int>();
    auto *node = linked_list->begin();
    while (node != linked_list->end()) {
        int val = node->get_value();
        auto *current = node;
        node = node->get_next();
        if (val > 0 && val % 2 == 0) {
            nums->push_back(linked_list->remove(current));
        }
    }
    return nums;
}

int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] >= pivot) {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[++i], nums[high]);
    return i;
}

void quicksort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        quicksort(nums, low, pivot - 1);
        quicksort(nums, pivot + 1, high);
    }
}

void quicksort(vector<int> &nums) {
    quicksort(nums, 0, int(nums.size()) - 1);
}

LL *get_linked_list(vector<int> *nums) {
    LL *ll = new LinkedList();
    for (auto i: *nums) {
        ll->push_back(i);
    }
    return ll;
}

int main() {
    LL *ll1 = get_linked_list();
    auto *nums = get_even_positive_numbers(ll1);
    quicksort(*nums);
    LL *ll2 = get_linked_list(nums);
    cout << "ll1: " << *ll1 << endl;
    cout << "ll2: " << *ll2 << endl;
    delete ll1;
    delete nums;
    delete ll2;
    return 0;
}