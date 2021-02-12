// 配对堆
#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
    int v;
    Node* xd;
    Node* ch;
    Node(int x) {
        v = x;
        ch = nullptr;
        ch = nullptr;
    }
};
Node* root;
Node* merge(Node* a, Node* b) {
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    if (a->v > b->v)
        swap(a, b);
    b->xd = a->ch;
    a->ch = b;
    return a;
}

void insert(int x) {
    Node* xr = new Node(x);
    root = merge(root, xr);
}

int minv() {
    return root->v;
}

Node* merges(Node* x) {
    if (x == nullptr || x->xd == nullptr)
        return nullptr;
    Node *a = x->xd, *b = a->xd;
    x->xd = a->xd = nullptr;
    return merge(merge(x, a), merges(b));
}

void deleteMin() {
    root = merges(root->ch);
}

