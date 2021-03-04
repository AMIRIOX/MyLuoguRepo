#include <cstdio>
#include <iostream>
#include <random>
using namespace std;
mt19937 rnd(233);
const int maxn = 10010;
struct node {
    int ls, rs;
    int val, key;
    int size, cnt;
} treap[maxn];
int tot, root;
int newnode(int val) {
    treap[++tot].val = val;
    treap[tot].key = rnd();
    treap[tot].cnt = treap[tot].size = 1;
    return tot;
}
void up(int t) {
    treap[t].size = treap[treap[t].ls].size + treap[treap[t].rs].size + 1;
}
void Rrotate(int& rt) {
    int t = treap[rt].ls;
    treap[rt].ls = treap[t].rs;
    treap[t].rs = rt;
    treap[t].size = treap[t].size;
    up(rt);
    rt = t;
}
void Lrotate(int& rt) {
    int t = treap[rt].rs;
    treap[rt].rs = treap[t].ls;
    treap[t].ls = rt;
    treap[t].size = treap[rt].size;
    up(rt);
    rt = t;
}
void insert(int val, int& rt) {
    if (!rt) {
        rt = newnode(val);
        return;
    }
    treap[rt].size++;
    if (val == treap[rt].val) {
        treap[rt].cnt++;
    } else if (val < treap[rt].val) {
        insert(val, treap[rt].ls);
        if (treap[treap[rt].ls].key < treap[rt].key) {
            Rrotate(rt);
        }
    } else if (val > treap[rt].val) {
        insert(val, treap[rt].rs);
        if (treap[treap[rt].rs].key < treap[rt].key) {
            Lrotate(rt);
        }
    }
}
void delnum(int val, int& rt) {
    if (!rt)
        return;
    if (treap[rt].val == val) {
        if (treap[rt].cnt > 1)
            treap[rt].cnt--;
        if (treap[rt].ls * treap[rt].rs)
            rt = treap[rt].ls + treap[rt].rs;
        else if (treap[treap[rt].ls].key < treap[rt].key) {
            Rrotate(rt);
            delnum(val, rt);
        } else {
            Lrotate(rt);
            delnum(val, rt);
        }
    }
    treap[rt].size--;
    if (val < treap[rt].val) {
        delnum(val, treap[rt].ls);
    } else {
        delnum(val, treap[rt].rs);
    }
}
int main() {
    // hold
    return 0;
}