#include <iostream>
#include "LinkedList.h"

using namespace std;

typedef LinkedList::Node LLN;
typedef LinkedList LL;

LLN::Node(int &_value, LLN *_previous, LLN *_next) {
    value = _value;
    previous = _previous;
    next = _next;
}

int LLN::get_value() {
    return value;
}

LLN *LLN::get_previous() {
    return previous;
}

void LLN::set_previous(LLN *_previous) {
    previous = _previous;
}

LLN *LLN::get_next() {
    return next;
}

void LLN::set_next(LLN *_next) {
    next = _next;
}

LL::LinkedList() {
    first = last = nullptr;
    size = 0;
}

int LL::get_size() {
    return size;
}

int LL::get_front() {
    if (size == 0) {
        throw "The list is empty.";
    }
    return first->get_value();
}

void LL::push_front(int value) {
    Node *node = new Node(value, nullptr, first);
    if (size == 0) {
        last = node;
    } else {
        first->set_previous(node);
    }
    first = node;
    size++;
}

int LL::pop_front() {
    if (size == 0) {
        throw "The list is empty.";
    }
    Node *front = first;
    int value = front->get_value();
    first = front->get_next();
    if (size == 1) {
        last = nullptr;
    }
    delete front;
    size--;
    return value;
}

int LL::get_back() {
    if (size == 0) {
        throw "The list is empty.";
    }
    return last->get_value();
}

void LL::push_back(int value) {
    Node *node = new Node(value, last, nullptr);
    if (size == 0) {
        first = node;
    } else {
        last->set_next(node);
    }
    last = node;
    size++;
}

int LL::pop_back() {
    if (size == 0) {
        throw "The list is empty.";
    }
    Node *back = last;
    int value = back->get_value();
    last = back->get_previous();
    if (size == 1) {
        first = nullptr;
    }
    delete back;
    size--;
    return value;
}

bool LL::is_empty() {
    return size == 0;
}

LLN *LL::begin() {
    return first;
}

LLN *LL::end() {
    return (last != nullptr) ? last->get_next() : last;
}

int LL::remove(LLN *node) {
    int value = node->get_value();
    auto *previous = node->get_previous();
    auto *next = node->get_next();
    if (previous != nullptr) {
        previous->set_next(next);
    } else {
        first = next;
    }
    if (next != nullptr) {
        next->set_previous(previous);
    } else {
        last = previous;
    }
    delete node;
    size--;
    return value;
}

ostream &operator<<(ostream &out, LinkedList &linked_list) {
    for (auto *node = linked_list.begin(); node != linked_list.end(); node = node->get_next()) {
        out << node->get_value() << " ";
    }
    out << endl;
    return out;
}

LL::~LinkedList() {
    Node *current = first;
    while (current != nullptr) {
        Node *next = current->get_next();
        delete current;
        current = (next != nullptr) ? next : nullptr;
    }
}
