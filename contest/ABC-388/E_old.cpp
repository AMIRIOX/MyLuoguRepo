#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> paired(n);

    for (auto &i : a)
        cin >> i;

    ll ans = 0;
    for (int i = 0; i <= n / 2; i++) {
        if(paired[i]) continue;
        auto it = lower_bound(a.begin() + n / 2, a.end(), 2 * a[i]);
        if(it != a.end() && !paired[it - a.begin()]) {
            ans++;
            cout << "found " << a[i] << " paired with " << *it << '\n';
            paired[it - a.begin()] = 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}


