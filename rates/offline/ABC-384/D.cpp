#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(2 * n + 2, 0), presum(2 * n + 2, 0);
    unordered_map<ll, bool> cntfront;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    for(int i = n + 1; i <= 2 * n; i++) {
        a[i] = a[i - n];
        presum[i] = presum[i - 1] + a[i];
    }
    for (int i = 2 * n; i >= 1; i--)
        cntfront[presum[n] - presum[i - 1]] = true;

    for (int i = 1; i <= 2 * n; i++) {
        ll tmp = presum[i - 1];
        if (s < tmp)
            break;
        if (cntfront[(s - tmp) % presum[n]]) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
