#ifndef LAB3_LINKEDLIST_H
#define LAB3_LINKEDLIST_H
#include <iostream>

using namespace std;

class LinkedList {
public:
    class Node {
    private:
        int value;
        Node *previous;
        Node *next;

    public:
        Node(int &, Node *, Node *);
        int get_value();
        Node *get_previous();
        void set_previous(Node *);
        Node *get_next();
        void set_next(Node *);
    };

private:
    int size;
    Node *first;
    Node *last;

public:
    LinkedList();
    int get_size();
    int get_front();
    void push_front(int);
    int pop_front();
    int get_back();
    void push_back(int);
    int pop_back();
    bool is_empty();
    ~LinkedList();
};


#endif