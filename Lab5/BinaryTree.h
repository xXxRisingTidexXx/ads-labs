#ifndef LAB5_BINARYTREE_H
#define LAB5_BINARYTREE_H

#include "Student.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BinaryTree {
private:
    class Node {
    private:
        Student *value;
        Node *parent;
        Node *left;
        Node *right;

    public:
        explicit Node(Student *);
        Student *get_value();
        void set_value(Student *);
        Node *get_parent();
        void set_parent(Node *);
        Node *get_left();
        void set_left(Node *);
        void put_left(Student *);
        Node *get_right();
        void set_right(Node *);
        void put_right(Student *);
    };

    Node *root;

    void put(Student *, Node *);
    Node *get_node(unsigned int);
    Node *get_min(Node *);
    void untie(Node *);
    Student *remove(unsigned int);
    Node *rearrange(queue<Node *> *);

public:
    explicit BinaryTree(Student *);
    void put(Student *);
    Student *get(unsigned int);
    vector<Student *> *get();
    void filter();
    friend ostream &operator<<(ostream &, BinaryTree &);
    ~BinaryTree();
};


#endif
