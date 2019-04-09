#ifndef LAB6_SEARCH_H
#define LAB6_SEARCH_H

#include <vector>
#include <string>

using namespace std;

int linear_search(vector<int> &, int &);

int binary_search(vector<int> &, int &);

int substring_search(string &, string &);

int kmp_search(string &str, string &img);

int bm_search(string &str, string &img);

#endif
