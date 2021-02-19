#include <cstdio>
#include <iostream>
#include <random>
using namespace std;
const int maxn = 10010;
struct node {
    int ls, rs;
    int val, prikey;
    int size;
} fhq[maxn];
int cnt, root;
std::mt19937 rnd(233);
int newnode(int val) {
    fhq[++cnt].val = val;
    fhq[cnt].prikey = rnd();
    fhq[cnt].size = 1;
    return cnt;
}
void update(int x) {
    fhq[x].size = fhq[fhq[x].ls].size + fhq[fhq[x].rs].size;
}
void split(int rt, int key, int& x, int& y) {
    if (!rt)
        x = y = 0;
    if (fhq[rt].val <= key) {
        x = rt;
        split(fhq[rt].rs, key, fhq[rt].rs, y);
    } else {
        y = rt;
        split(fhq[rt].ls, key, x, fhq[rt].ls);
    }
    update(rt);
}
int merge(int x, int y) {
    if (!x || !y)
        return x + y;
    if (fhq[x].prikey >= fhq[y].prikey) {
        fhq[x].rs = merge(fhq[x].rs, y);
        update(x);
        return x;
    } else {
        fhq[y].ls = merge(x, fhq[y].ls);
        update(y);
        return y;
    }
}
// insert, delete, rank, kth, bef, nxt
// insert()