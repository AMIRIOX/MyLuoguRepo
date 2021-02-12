// 配对堆 带decrease-key
// TODO
#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
    int v;
    Node* xd;
    Node* ch;
    Node* fa;
    Node(int x) {
        v = x;
        ch = nullptr;
        ch = nullptr;
        fa = nullptr;
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
    a->fa = nullptr;
    b->fa = nullptr;

    b->xd = a->ch;
    if (a->ch != nullptr)
        a->ch->fa = b;
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
