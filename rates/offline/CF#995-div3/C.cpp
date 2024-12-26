#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    vector<ll> q(k + 1);
    map<ll, int> mp;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++) {
        cin >> q[i];
        mp[q[i]]++;
    }

    if(k < n - 1) {
        for(int i = 1; i <= m; i++) cout << 0;
        cout << '\n';
        return;
    }
    if(k >= n) {
        for(int i = 1; i <= m; i++) cout << 1;
        cout << '\n';
        return;
    }

    ll sp = 0;
    for(int i = 1; i <= n; i++) if(!mp[i]) { sp = i; break; }
    for(int i = 1; i <= m; i++) cout << "01"[a[i] == sp];
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
