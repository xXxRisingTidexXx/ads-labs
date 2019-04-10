#include "search.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

int linear_search(vector<int> &nums, int &num) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == num) {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<int> &nums, int &num) {
    int low = 0, high = int(nums.size()) - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] > num) {
            high = mid - 1;
        } else if (nums[mid] < num) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int substring_search(string &str, string &img) {
    int str_length = int(str.length()), img_length = int(img.length());
    for (int i = 0; i <= str_length - img_length; i++) {
        for (int j = 0; j < img_length && str[i + j] == img[j]; j++) {
            if (j + 1 == img_length) {
                return i;
            }
        }
    }
    return -1;
}

int calculate_shift(string &img, int &i) {
    int shift = 0, j;
    for (j = 1; j < i && img[j] != img[0]; j++);
    if (j < i) {
        int k = j;
        for (; k < i && img[k] == img[k - j]; k++);
        if (k == i) {
            shift = i - j;
        }
    }
    return shift;
}

vector<int> *calculate_kmp_shifts(string &img) {
    auto *shifts = new vector<int>();
    shifts->reserve(img.length());
    for (int i = 0; i < img.length(); i++) {
        shifts->push_back((img[i] == img[0]) ? -1 : calculate_shift(img, i));
    }
    return shifts;
}

int kmp_search(string &str, string &img) {
    auto *shifts = calculate_kmp_shifts(img);
    int str_length = int(str.length()), img_length = int(img.length()), i = 0;
    while (i <= str_length - img_length) {
        int j = 0;
        for (; j < img_length && str[i + j] == img[j]; j++) {
            if (j + 1 == img_length) {
                return i;
            }
        }
        i += j - (*shifts)[j];
    }
    delete shifts;
    return -1;
}

map<char, int> *calculate_bm_shifts(string &img) {
    int img_length = int(img.length());
    auto *shifts = new map<char, int>();
    for (int i = 0; i < 256; i++) {
        shifts->insert(pair<char, int>(char(i), img_length));
    }
    for (int i = 0; i < img_length - 1; i++) {
        (*shifts)[img[i]] = img_length - i - 1;
    }
    return shifts;
}

int bm_search(string &str, string &img) {
    int str_length = int(str.length()), img_length = int(img.length());
    if (str_length < img_length) {
        return -1;
    }
    auto *shifts = calculate_bm_shifts(img);
    int i = img_length - 1, j = i, k = i;
    while (j >= 0 && i < str_length) {
        for (j = img_length - 1, k = i; j >= 0 && str[k] == img[j]; k--, j--);
        i += (*shifts)[str[i]];
    }
    delete shifts;
    return (k >= str_length - img_length) ? -1 : k + 1;
}
