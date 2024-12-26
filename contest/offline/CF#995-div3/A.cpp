#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i + 1])
            ans += (a[i] - b[i + 1]);
    }
    ans += a[n - 1];
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
