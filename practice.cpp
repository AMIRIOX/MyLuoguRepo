#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
int val[maxn], ls[maxn], rs[maxn];
int cnt[maxn], siz[maxn], sum;

void print(int o) {
    if (!o)
        return;

    print(ls[o]);
    for (int i = 1; i <= cnt[o]; i++)
        printf("%d ", val[o]);
    printf("\n");
    print(rs[o]);
}
int getmin(int o) {
    if (!ls[o])
        return val[o];
    return getmin(ls[o]);
}
int getmax(int o) {
    if (!rs[o])
        return val[o];
    return getmax(rs[o]);
}
void insert(int& o, int v) {
    if (!o) {
        val[o = ++sum] = v;
        siz[o] = cnt[o] = 1;
        return;
    }
    siz[o]++;
    if (val[o] == v) {
        cnt[o]++;
        return;
    }
    if (v > val[o])
        insert(rs[o], v);
    if (v < val[o])
        insert(ls[o], v);
}
int delmin(int& o) {
    if (!ls[o]) {
        int u = o;
        o = rs[o];
        return u;
    }
    int u = delmin(ls[o]);
    siz[o] -= cnt[u];
    return u;
}

void del(int& o, int v) {
    siz[o]--;
    if (val[o] == v) {
        if (cnt[o] > 1) {
            cnt[o]--;
            return;
        } else {
            if (ls[o] && rs[o])
                o = delmin(rs[o]);
            else
                o = ls[o] | rs[o];
            return;
        }
    }
    if (v > val[o])
        del(rs[o], v);
    if (v < val[o])
        del(ls[o], v);
}

int rnk(int o, int v) {
    if (val[o] == v)
        return siz[ls[o]] + 1;
    if (v < val[o])
        return rnk(ls[o], v);
    if (v > val[o])
        return rnk(rs[o], v) + cnt[o] + siz[ls[o]];
}
int kth(int o, int k) {
    if (siz[ls[o]] >= k)
        return kth(ls[o], k);
    if (siz[ls[o]] < k - cnt[o])
        return kth(rs[o], k - cnt[o] - siz[ls[o]]);
    return val[o];
}