#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x = 0; cin >> x;
    ll ans = 1;
    while(x != 1) {
        ans++;
        x /= ans;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

