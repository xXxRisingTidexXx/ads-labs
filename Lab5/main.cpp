#include <iostream>
#include "Student.h"
#include "BinaryTree.h"
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter students' number: ";
    cin >> n;
    auto students = vector<Student *>();
    BinaryTree bt;
    for (int i = 0; i < n; i++) {
        students.push_back(new Student());
        bt.put(students[i]);
    }
    cout << bt << endl;
    auto *graduates = bt.get();
    for (auto *graduate: *graduates) {
        cout << *graduate << endl;
    }
    delete graduates;
    cout << endl;
    bt.filter();
    cout << bt;
    return 0;
}