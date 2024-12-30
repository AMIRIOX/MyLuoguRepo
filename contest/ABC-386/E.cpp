#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    auto dfs = [&](auto self, ll idx, ll rem, ll val) {
        if(rem == 0) {
            ans = max(ans, val);
            return;
        }
        if(idx > n) return;
        self(self, idx + 1, rem - 1, val ^ a[idx]);
        self(self, idx + 1, rem, val);
    };
    if(k < n / 2) {
        dfs(dfs, 1, k, 0);
    }else {
        ll all_xor = 0;
        for(ll i = 1; i <= n; i++) {
            all_xor ^= a[i];
        }
        dfs(dfs, 1, n - k, all_xor);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
