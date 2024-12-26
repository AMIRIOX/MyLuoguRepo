// Binary Search Tree
// 二叉搜索树
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
int cnt[maxn], ls[maxn], rs[maxn];
int siz[maxn], val[maxn], sum;
void print(int r) {
    if (!r)
        return;
    print(ls[r]);
    for (int i = 1; i <= cnt[r]; i++)
        printf("%d ", val[r]);
    print(rs[r]);
}
int getmax(int o) {
    if (!rs[o])
        return val[o];
    return getmax(rs[o]);
}
int getmin(int o) {
    if (!ls[o])
        return val[o];
    return getmin(ls[o]);
}
void insert(int& rt, int vl) {
    if (!rt) {
        val[rt = ++sum] = vl;
        siz[rt] = cnt[rt] = 1;
        return;
    }
    siz[rt]++;
    if (val[rt] == vl) {
        cnt[rt]++;
        return;
    }
    if (vl > val[rt])
        insert(rs[rt], vl);
    else if (vl < val[rt])
        insert(ls[rt], vl);
}
int delmin(int& o) {
    if (!ls[o]) {
        int u = o;
        o = rs[o];
        return u;
    } else {
        int u = delmin(ls[o]);
        siz[o] -= cnt[u];
        return u;
    }
}
void del(int& o, int v) {
    siz[o]--;
    if (val[o] == v) {
        if (cnt[o] > 1) {
            cnt[o]--;
            return;
        }
        // 判断是否二胎
        if (ls[o] && rs[o])
            o = delmin(rs[o]);
        else
            o = (ls[o] | rs[o]);
        return;
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
int main() {
    //TODO
    return 0;
}
