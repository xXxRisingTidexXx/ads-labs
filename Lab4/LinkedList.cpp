#include "LinkedList.h"
#include <iostream>
#include "functools.h"

using namespace std;

typedef LinkedList LL;
typedef Parallelogram P;

LL::Node::Node(P *_value, LL::Node *_previous, LL::Node *_next) {
    value = _value;
    previous = _previous;
    next = _next;
}

P *LL::Node::get_value() {
    return value;
}

void LL::Node::set_value(P *_value) {
    value = _value;
}

LL::Node *LL::Node::get_previous() {
    return previous;
}

void LL::Node::set_previous(LL::Node *_previous) {
    previous = _previous;
}

LL::Node *LL::Node::get_next() {
    return next;
}

void LL::Node::set_next(LL::Node *_next) {
    next = _next;
}

LL::Node *LL::get_node(float key) {
    for (auto *current = first; current != nullptr; current = current->get_next()) {
        if (equal(key, current->get_value()->get_perimeter())) {
            return current;
        }
    }
    return nullptr;
}

LL::LinkedList() {
    first = last = nullptr;
}

LL::LinkedList(const LL &obj) {
    first = nullptr;
    last = nullptr;
}

void LL::push(P *value) {
    auto *node = get_node(value->get_perimeter());
    if (node != nullptr) {
        node->set_value(value);
    } else {
        node = new Node(value, last, nullptr);
        if (empty()) {
            first = node;
        } else {
            last->set_next(node);
        }
        last = node;
    }
}

P *LL::get(float key) {
    auto *node = get_node(key);
    return (node != nullptr) ? node->get_value() : nullptr;
}

P *LL::remove(float key) {
    auto *node = get_node(key);
    if (node == nullptr) {
        return nullptr;
    }
    auto *value = node->get_value();
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
    return value;
}

bool LL::empty() {
    return first == nullptr;
}

vector<P *> *LL::get_values() {
    auto *parallelograms = new vector<P *>();
    for (auto *current = first; current != nullptr; current = current->get_next()) {
        parallelograms->push_back(current->get_value());
    }
    return parallelograms;
}

ostream &operator<<(ostream &out, LL &linked_list) {
    for (auto *current = linked_list.first; current != nullptr; current = current->get_next()) {
        auto *value = current->get_value();
        out << value->get_perimeter() << ": " << *value;
        if (current->get_next() != nullptr) {
            out << ", ";
        }
    }
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
