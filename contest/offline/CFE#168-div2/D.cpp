#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<int>> g(n);
    ll A = 0;
    for (auto &i : a) {
        cin >> i;
        A = max(A, i);
    }
    for (int i = 1; i < n; i++) {
        int p = 0;
        cin >> p;
        g[p - 1].push_back(i);
    }

    auto check = [&](auto &&self, int u, ll x) -> bool {
        if (x > A) return false;
        if (g[u].empty()) return x <= a[u];
        bool ok = true;
        if(u) x += max(0LL, x - a[u]);
        for (auto &v : g[u]) {
            ok &= self(self, v, x);
            if(!ok) return false;
        }
        return ok;
    };
    ll l = 0, r = A;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(check, 0, mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << a[0] + l << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
