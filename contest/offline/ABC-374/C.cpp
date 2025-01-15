#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

void solve() {
    int n = 0;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    ll ans = 0;
    auto dfs = [&](auto &&self, int p, int sum) {
        if(p > n) {
            if(abs(tot / 2 - sum) < abs(tot / 2 - ans))
                ans = sum;
            return;
        }
        self(self, p + 1, sum);
        self(self, p + 1, sum + a[p]);
    };
    dfs(dfs, 1, 0);
    cout << max(ans, tot - ans) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
