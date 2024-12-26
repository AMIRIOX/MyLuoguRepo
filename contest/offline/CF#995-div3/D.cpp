#include <bits/stdc++.h>
#include <cwchar>
using namespace std;
using ll = long long;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    ll ans = 0, sum = accumulate(a.begin(), a.end(), 0ll);

    vector<ll> p = a;
    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        // p.erase(lower_bound(p.begin(), p.end(), a[i]));
        ll vmx = sum - a[i] - x;
        ll vmn = sum - a[i] - y;
        auto mx = upper_bound(p.begin(), p.end(), vmx);
        auto mn = lower_bound(p.begin(), p.end(), vmn);

        if(mn <= mx) ans += mx - mn;
        if(vmn <= a[i] && a[i] <= vmx) ans--;
    }
    cout << ans / 2 << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
