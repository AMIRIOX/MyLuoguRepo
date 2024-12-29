#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a;

    ll mx = 0, one = 0;
    for (ll i = 0, tmp = 0; i < n; i++) {
        cin >> tmp;
        if (tmp != 1) {
            a.push_back(tmp);
        } else
            one++;
        mx = max(mx, tmp);
    }
    if (n == 1) {
        cout << -1 << '\n';
        return;
    }
    if(a.empty()) cout << 0 << '\n';
    else if(a.size() == 1) cout << a[0] - 1 << '\n';
    else cout << mx << '\n';
        // accumulate(a.begin(), a.end(), 0ll, [&](ll acc, ll x) { return (x != mn) ? acc + x : acc;
        // });
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
