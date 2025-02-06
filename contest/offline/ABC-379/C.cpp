#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = n * 1LL * (n + 1) / 2;
    vector<pair<ll, ll>> in(m);
    for (auto &&p : in)
        cin >> p.first;
    for (auto &&p : in)
        cin >> p.second;
    sort(in.begin(), in.end());
    ll rem = 0, lst = 1;
    for(int i = 0; i < m; i++) {
        rem -= (in[i].first - lst);
        if(rem < 0) {
            cout << -1 << '\n';
            return;
        }
        rem += in[i].second;
        lst = in[i].first;
    }
    rem -= (n - lst + 1);
    if(rem != 0) {
        cout << -1 << '\n';
        return;
    }
    for(auto &&p : in) ans -= p.first * 1LL * p.second;
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
