#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9 + 7;

ll qp(ll a, ll p) {
    ll res = 1;
    while(p) {
        if(p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}
void solve() {
    int t = 0; cin >> t;
    vector<ll> n(t + 1);
    vector<ll> k(t + 1);
    for(int i = 1; i <= t; i++) cin >> n[i];
    for(int i = 1; i <= t; i++) cin >> k[i];
    for(int i = 1; i <= t; i++) {
        cout << qp(2, k[i]) << '\n';
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
