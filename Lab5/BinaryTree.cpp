#include <iostream>
#include "BinaryTree.h"
#include "Student.h"
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef BinaryTree BT;
typedef Student S;

BT::Node::Node(S *_value) {
    value = _value;
    parent = left = right = nullptr;
}

S *BT::Node::get_value() {
    return value;
}

void BT::Node::set_value(S *_value) {
    value = _value;
}

BT::Node *BT::Node::get_parent() {
    return parent;
}

void BT::Node::set_parent(BT::Node *_parent) {
    parent = _parent;
}

BT::Node *BT::Node::get_left() {
    return left;
}

void BT::Node::set_left(Node *_left) {
    left = _left;
    left->set_parent(this);
}

void BT::Node::put_left(S *_value) {
    set_left(new Node(_value));
}

BT::Node *BT::Node::get_right() {
    return right;
}

void BT::Node::set_right(Node *_right) {
    right = _right;
    right->set_parent(this);
}

void BT::Node::put_right(S *_value) {
    set_right(new Node(_value));
}

void BT::put(S *value, BT::Node *node) {
    unsigned int key = node->get_value()->get_isic(), isic = value->get_isic();
    if (isic < key) {
        if (node->get_left() == nullptr) {
            node->put_left(value);
        } else {
            put(value, node->get_left());
        }
    } else if (isic > key) {
        if (node->get_right() == nullptr) {
            node->put_right(value);
        } else {
            put(value, node->get_right());
        }
    } else {
        node->set_value(value);
    }
}

BT::Node *BT::get_node(unsigned int key) {
    auto *current = root;
    unsigned int isic = current->get_value()->get_isic();
    while (current != nullptr && isic != key) {
        current = (isic < key) ? current->get_left() : current->get_right();
        if (current != nullptr) {
            isic = current->get_value()->get_isic();
        }
    }
    return current;
}

BT::Node *BT::get_min(BT::Node *node) {
    auto *min = node;
    while (min->get_left() != nullptr) {
        min = min->get_left();
    }
    return min;
}

void BT::untie(BT::Node *node) {
    auto *parent = node->get_parent(), *left = node->get_left(), *right = node->get_right();
    if (left == nullptr) {
        if (right != nullptr) {
            right->set_parent(parent);
        }
        if (parent != nullptr) {
            if (parent->get_left() == node) {
                parent->set_left(right);
            } else {
                parent->set_right(right);
            }
        }
    } else {
        left->set_parent(parent);
        if (parent != nullptr) {
            if (parent->get_left() == node) {
                parent->set_left(left);
            } else {
                parent->set_right(left);
            }
        }
    }
}

S *BT::remove(unsigned int key) {
    auto *node = get_node(key);
    if (node == nullptr) return nullptr;
    auto *value = node->get_value();
    if (node->get_left() != nullptr && node->get_right() != nullptr) {
        auto *min = get_min(node->get_right());
        node->set_value(min->get_value());
        node = min;
    }
    untie(node);
    delete node;
    return value;
}

BT::Node *BT::rearrange(queue<BT::Node *> *q) {
    auto *node = q->front();
    auto *left = node->get_left();
    auto *right = node->get_right();
    if (left != nullptr) {
        q->push(left);
    }
    if (right != nullptr) {
        q->push(right);
    }
    q->pop();
    return node;
}

BinaryTree::BinaryTree(S *value) {
    root = new Node(value);
}

void BT::put(S *value) {
    put(value, root);
}

S *BT::get(unsigned int key) {
    auto *node = get_node(key);
    return (node == nullptr) ? nullptr : node->get_value();
}

vector<S *> *BT::get() {
    auto *values = new vector<S *>();
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        auto *value = rearrange(&q)->get_value();
        if (value->get_gender() == 'F' && value->get_grade() == 5 &&
        value->get_address().find("Kyiv") != string::npos) {
            values->push_back(value);
        }
    }
    return values;
}

void BT::filter() {
    auto *values = get();
    for (auto *value: *values) {
        remove(value->get_isic());
    }
    delete values;
}

ostream &operator<<(ostream &out, BT &binary_tree) {
    queue<BT::Node *> q;
    q.push(binary_tree.root);
    while (!q.empty()) {
        out << *binary_tree.rearrange(&q)->get_value() << endl;
    }
    return out;
}

BT::~BinaryTree() {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        delete rearrange(&q);
    }
}
