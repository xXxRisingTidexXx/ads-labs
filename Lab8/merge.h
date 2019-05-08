#ifndef LAB8_MERGE_H
#define LAB8_MERGE_H

#include <vector>

using namespace std;

void output(vector<int> &);

vector<int> *simple_merge(vector<int> &, vector<int> &);

vector<int> *natural_merge(vector<int> &);

vector<int> *polyphase_merge(vector<int> &, vector<int> &);

#endif
