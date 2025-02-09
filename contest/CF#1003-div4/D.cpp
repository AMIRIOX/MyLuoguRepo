#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 临项交换要算的是两项共同作用的答案不是单项答案比较。。。
void solve() {
    int n, m; cin >> n >> m;
    vector in(n, vector<ll>(m));
    vector<ll> sz;
    sz.reserve(n);
    for(auto &p : in) {
        ll sumi = 0;
        for(auto &q : p) {
            cin >> q;
            sumi += q;
        }
        sz.push_back(sumi);
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    vector<ll> ansv;
    ansv.reserve(n * m + 1);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return sz[i] > sz[j]; });
    for(int i = 0; i < n; i++) {
        // cout << "push " << ord[min(n, 5) - idx] << " in.\n";
        for(const auto &p : in[ord[i]]) 
            ansv.push_back(p);
    } 
    vector<ll> p(ansv.size());
    p[0] = ansv[0];
    for(size_t i = 1; i < ansv.size(); i++) {
        p[i] = p[i - 1] + ansv[i];
    }
    ll ans = 0;
    for(size_t i = 0; i < p.size(); i++) {
        ans += p[i];
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
