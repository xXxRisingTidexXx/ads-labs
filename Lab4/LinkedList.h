#ifndef LAB4_SINGLYLINKEDLIST_H
#define LAB4_SINGLYLINKEDLIST_H

#include <iostream>
#include "Parallelogram.h"

using namespace std;

class LinkedList {
private:
    class Node {
    private:
        Parallelogram *value;
        Node *previous;
        Node *next;

    public:
        Node(Parallelogram *, Node *, Node *);
        Parallelogram *get_value();
        void set_value(Parallelogram *);
        Node *get_previous();
        void set_previous(Node *);
        Node *get_next();
        void set_next(Node *);
    };

    Node *first;
    Node *last;

    Node *get_node(float);

public:
    LinkedList();
    void push(Parallelogram *value);
    Parallelogram *get(float);
    Parallelogram *remove(float);
    bool empty();
    friend ostream &operator<<(ostream &, LinkedList &);
    ~LinkedList();
};


#endif
