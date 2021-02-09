#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define IT set<node>::iterator
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
ll n, m, seed, vmax;
ll a[maxn];
ll qpow(ll a, ll ni, ll mod) {
    ll ans = 1;
    a = a % mod;
    while (ni) {
        if (ni & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        ni >>= 1;
    }
    return ans;
}
// ------------------------------------------------
struct node {
    int l, r;
    mutable ll v;
    node(int _l, int _r = -1, ll _v = 0) : l(_l), r(_r), v(_v) {}
    bool operator<(const node& o) const { return this->l < o.l; }
};
set<node> s;
IT split(int pos) {
    IT itr = s.lower_bound(node(pos));
    if (itr != s.end() && itr->l == pos)
        return itr;
    --itr;
    int OL = itr->l, OR = itr->r;
    ll OV = itr->v;
    s.erase(itr);
    s.insert(node(OL, pos - 1, OV));
    return s.insert(node(pos, OR, OV)).first;
}
void assign(int nl, int nr, ll val = 0) {
    // 区间赋值
    IT itr = split(nr + 1), itl = split(nl);
    s.erase(itl, itr);
    s.insert(node(nl, nr, val));
}
void add(int nl, int nr, ll val = 1) {
    // 区间加
    IT itr = split(nr + 1), itl = split(nl);
    while (itl != itr) {
        itl->v += val;
        itl++;
    }
}
ll kth(int nl, int nr, int k) {
    // 排名第k
    IT itr = split(nr + 1), itl = split(nl);
    vector<pair<ll, int> > vp;
    while (itl != itr) {
        vp.push_back({itl->v, itl->r - itl->l + 1});
        itl++;
    }
    sort(vp.begin(), vp.end());
    for (vector<pair<ll, int> >::iterator it = vp.begin(); it != vp.end();
         it++) {
        k -= it->second;
        if (k <= 0)
            return it->first;
    }
    return -1ll;  // not found
}
ll sum(int nl, int nr, int x, int y) {
    // 区间幂次和   x指数  y模数
    ll res = 0;
    IT itr = split(nr + 1), itl = split(nl);
    while (itl != itr) {
        res = (res + (itl->r - itl->l + 1) * qpow(itl->v, x, y)) % y;
        itl++;
    }
    return res;
}
// ------------------------------------------------
ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}
int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &seed, &vmax);
    for (int i = 1; i <= n; i++) {
        a[i] = (rnd() % vmax) + 1;
        s.insert(node(i, i, a[i]));
    }
    s.insert(node(n + 1, n + 1, 0));
    // cout << "input ok" << endl;
    for (int i = 1; i <= m; i++) {
        /*
            op = (rnd() mod 4) + 1
            l = (rnd() mod n) + 1
            r = (rnd() mod n) + 1

            if (l > r):
                 swap(l, r)

            if (op == 3):
                x = (rnd() mod (r - l + 1)) + 1
            else:
                x = (rnd() mod vmax) + 1

            if (op == 4):
                y = (rnd() mod vmax) + 1
        */
        ll op = (rnd() % 4) + 1;
        ll L = (rnd() % n) + 1;
        ll R = (rnd() % n) + 1;
        ll x, y;
        if (L > R)
            swap(L, R);
        if (op == 3)
            x = (rnd() % (R - L + 1)) + 1;
        else
            x = (rnd() % vmax) + 1;

        if (op == 4)
            y = (rnd() % vmax) + 1;

        // cout << op << ": ";
        // cout.flush();
        if (op == 1) {
            add(L, R, x);
        } else if (op == 2) {
            assign(L, R, x);
        } else if (op == 3) {
            printf("%lld\n", kth(L, R, x));
        } else if (op == 4) {
            printf("%lld\n", sum(L, R, x, y));
        }
    }
    return 0;
}