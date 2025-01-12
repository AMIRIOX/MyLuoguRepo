#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<ll> pa;
vector<ll> ppa;
vector<ll> pppa;
vector<ll> bss;

vector<ll> cp(vector<ll>& a) {
    vector<ll> ret(a.size() + 1, 0);
    for(int i = 1; i <= a.size(); i++) {
        ret[i] = ret[i - 1] + a[i - 1];
    }
    return std::move(ret);
}

inline pii convert(ll i) {
    int idx = upper_bound(bss.begin(), bss.end(), i) - bss.begin() - 1;
    return pii(idx, i - bss[idx]);
}

ll getseg(vector<ll> &pre, int l, int r) {
    return pre[r + 1] - pre[l];
}

inline ll clr(int b, int l, int r) {
    return getseg(ppa, b + l + 1, b + r + 1) - (r - l + 1) * pa[b];
}

ll query(ll bl, ll br) {
    ll ans = 0;
    auto [lb, lj] = convert(bl);
    auto [rb, rj] = convert(br);
    // sum lb[lj ~ end]
    ans += clr(lb, lj, n - lb - 1);
    // allsum blocks[lb + 1, rb - 1]
    assert(lb <= rb);
    if(lb == rb || lb + 1 <= rb - 1) ans += getseg(pppa, lb + 1, rb - 1);
    // sum rb[begi ~ rj]
    ans += clr(rb, 0, rj);

    return ans;
}

signed main() {
    cin >> n;
    bss.resize(n);
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    } 
    pa = cp(a);     // s[1, n]
    ppa = cp(pa);   

    pppa = {0};
    for(int i = 1; i <= n; i++) {
        int b = i - 1;
        pppa.push_back(pppa.back() + clr(b, 0, n - b - 1));
    }

    int nb = n;
    bss = {0};
    for(ll i = n; i > 1; i--) {
        bss.push_back(bss.back() + i);
    }

    int q; cin >> q;
    while(q--) {
        ll bl, br;
        cin >> bl >> br;
        cout << query(bl - 1, br - 1) << '\n';
    }
    return 0;
}
