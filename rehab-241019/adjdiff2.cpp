#include <bits/stdc++.h>
using namespace std;
int n, m;

// 按照 d 排序，挨个考虑合并相似区间。
// 每个区间进行差分

const int maxn = 1e5 + 10;
// 如果 d 相同，则排序 区间 
struct rop {
    int l, r, d;
    bool operator<(const rop& b) {
        if(this->d != b.d) return this->d < b.d;
        if(this->l != b.l) return this->l < b.l;
        return this->r < b.r;
    }
}ops[maxn];
int b[maxn];
signed main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> ops[i].l >> ops[i].r >> ops[i].d;
    }
    sort(ops + 1, ops + n + 1);
    int curl = ops[1].l, curr = ops[1].r;
    int lstw = ops[1].d;
    for(int i = 2; i <= m; i++) {
        if(ops[i].l > curr || ops[i].d != lstw) {
            b[curl]++;
            b[curr + 1]--;
            curl = ops[i].l;
            curr = ops[i].r;
            lstw = ops[i].d;
        }else {
            curr = max(curr, ops[i].r);
        }
    }
    b[curl]++;
    b[curr + 1]--;
    int a = 0, maxk = 0, pos = 0;
    for(int i = 1; i <= n; i++) {
        a += b[i];
        if(a > maxk) {
            pos = i;
            maxk = a;
        }
    }
    cout << pos << endl;
    return 0;
}