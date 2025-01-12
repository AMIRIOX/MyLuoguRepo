#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vector<ll> dt;
    ll cnt = 0;
    ll take = 0;
    ll mn = 2e16;
    for(int i = 0; i < n; i++) {
        if(a[i] < b[i]) {
            cnt++;
            take = b[i] - a[i];
        }else mn = min(mn, a[i] - b[i]);
    }
    if(cnt < 1 || ( cnt == 1 && mn >= take)) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
