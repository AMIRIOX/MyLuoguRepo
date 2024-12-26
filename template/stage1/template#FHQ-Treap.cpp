#include <cstdio>
#include <iostream>
#include <random>
using namespace std;
mt19937 rnd(233);
const int maxn = 2e5 + 10;
struct node {
    int ls, rs;
    int val, size;
    int prikey;
} fhq[maxn];
int root, cnt;
int newnode(int val) {
    fhq[++cnt].val = val;
    fhq[cnt].prikey = rnd();
    fhq[cnt].size = 1;
    return cnt;
}
void update(int x) {
    fhq[x].size = fhq[fhq[x].ls].size + fhq[fhq[x].rs].size + 1;
}
void split(int now, int key, int& x, int& y) {
    if (!now)
        x = y = 0;
    else {
        if (fhq[now].val <= key) {
            x = now;
            split(fhq[now].rs, key, fhq[now].rs, y);
        } else {
            y = now;
            split(fhq[now].ls, key, x, fhq[now].ls);
        }
        // printf("++%d\n", fhq[0].size);
        update(now);
        // printf("++%d\n", fhq[0].size);
    }
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
int x, y, z;
void insert(int val) {
    split(root, val, x, y);
    root = merge(merge(x, newnode(val)), y);
}
void del(int val) {
    split(root, val, x, z);
    split(x, val - 1, x, y);
    y = merge(fhq[y].ls, fhq[y].rs);
    root = merge(merge(x, y), z);
}
int getrank(int val) {
    split(root, val - 1, x, y);
    int res = fhq[x].size + 1;
    root = merge(x, y);
    return res;
}
int kth(int k) {
    int now = root;
    // printf("__%d\n", fhq[fhq[now].ls].size);
    while (now) {
        if (fhq[fhq[now].ls].size + 1 == k)
            break;
        else if (fhq[fhq[now].ls].size >= k)
            now = fhq[now].ls;
        else {
            k -= fhq[fhq[now].ls].size + 1;
            now = fhq[now].rs;
        }
    }
    return fhq[now].val;
}
int pre(int vg) {
    split(root, vg - 1, x, y);
    int now = x;
    while (fhq[now].rs) {
        now = fhq[now].rs;
    }
    int res = fhq[now].val;
    root = merge(x, y);
    return res;
}
int nxt(int vg) {
    split(root, vg, x, y);
    int now = y;
    while (fhq[now].ls) {
        now = fhq[now].ls;
    }
    int res = fhq[now].val;
    root = merge(x, y);
    return res;
}
int n, cmd, _x;
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &cmd, &_x);
        if (cmd == 1) {
            insert(_x);
        } else if (cmd == 2) {
            del(_x);
        } else if (cmd == 3) {
            printf("%d\n", getrank(_x));
        } else if (cmd == 4) {
            printf("%d\n", kth(_x));
        } else if (cmd == 5) {
            printf("%d\n", pre(_x));
        } else if (cmd == 6) {
            printf("%d\n", nxt(_x));
        }
    }
    return 0;
}